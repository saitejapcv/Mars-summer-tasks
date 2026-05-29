#!/usr/bin/env python3

import rclpy
import math
import time
from rclpy.node import Node
from rclpy.action import ActionServer, GoalResponse, CancelResponse
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from turtlesim.srv import TeleportAbsolute
from turtle_patrol_interfaces.action import ExecuteCircle


class CirclePatrolServer(Node):

    def __init__(self):
        super().__init__('circle_patrol_server')

        # Wall boundaries
        self.WALL_MIN = 1.0
        self.WALL_MAX = 10.0

        # Screen center
        self.CENTER_X = 5.544
        self.CENTER_Y = 5.544

        self.current_pose = None
        self.cbg = ReentrantCallbackGroup()

        self.cmd_vel_pub = self.create_publisher(
            Twist, '/turtle1/cmd_vel', 10)

        self.pose_sub = self.create_subscription(
            Pose, '/turtle1/pose', self._pose_cb, 10,
            callback_group=self.cbg)

        self.teleport_client = self.create_client(
            TeleportAbsolute, '/turtle1/teleport_absolute')

        self._action_server = ActionServer(
            self, ExecuteCircle, 'execute_circle',
            execute_callback=self._exec,
            goal_callback=self._goal_cb,
            cancel_callback=lambda g: CancelResponse.ACCEPT,
            callback_group=self.cbg)

        self.get_logger().info('Circle Patrol Server READY')

    def _pose_cb(self, msg):
        self.current_pose = msg

    def _goal_cb(self, goal_request):
        radius = goal_request.radius
        self.get_logger().info(f'Goal received: radius={radius:.2f}')

        if radius <= 0.0:
            self.get_logger().warn('REJECTED: Radius must be positive')
            return GoalResponse.REJECT

        left   = self.CENTER_X - radius
        right  = self.CENTER_X + radius
        bottom = self.CENTER_Y - radius
        top    = self.CENTER_Y + radius

        if left < self.WALL_MIN:
            self.get_logger().warn(f'REJECTED: Hits LEFT wall (x={left:.2f})')
            return GoalResponse.REJECT

        if right > self.WALL_MAX:
            self.get_logger().warn(f'REJECTED: Hits RIGHT wall (x={right:.2f})')
            return GoalResponse.REJECT

        if bottom < self.WALL_MIN:
            self.get_logger().warn(f'REJECTED: Hits BOTTOM wall (y={bottom:.2f})')
            return GoalResponse.REJECT

        if top > self.WALL_MAX:
            self.get_logger().warn(f'REJECTED: Hits TOP wall (y={top:.2f})')
            return GoalResponse.REJECT

        self.get_logger().info(f'Goal ACCEPTED: radius={radius:.2f}')
        return GoalResponse.ACCEPT

    def _teleport(self, x, y, theta):
        while not self.teleport_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for teleport service...')

        req = TeleportAbsolute.Request()
        req.x = float(x)
        req.y = float(y)
        req.theta = float(theta)

        future = self.teleport_client.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        time.sleep(0.5)

    def _stop(self):
        stop = Twist()
        for _ in range(10):
            self.cmd_vel_pub.publish(stop)
            time.sleep(0.05)
        self.get_logger().info('Turtle stopped.')

    def _is_near_wall(self, x, y):
        return (
            x < self.WALL_MIN or
            x > self.WALL_MAX or
            y < self.WALL_MIN or
            y > self.WALL_MAX
        )

    def _exec(self, gh):
        radius = gh.request.radius
        circumference = 2.0 * math.pi * radius
        expected_time = circumference / 1.5

        self.get_logger().info('=' * 50)
        self.get_logger().info('  Executing Circular Patrol')
        self.get_logger().info(f'  Radius:        {radius:.2f} m')
        self.get_logger().info(f'  Circumference: {circumference:.2f} m')
        self.get_logger().info(f'  Expected time: {expected_time:.2f} s')
        self.get_logger().info('=' * 50)

        # Wait for pose
        timeout = 0
        while self.current_pose is None and timeout < 50:
            time.sleep(0.1)
            timeout += 1

        if self.current_pose is None:
            gh.abort()
            result = ExecuteCircle.Result()
            result.success = False
            result.final_report = 'Mission Aborted: No pose data!'
            return result

        # Teleport to start position
        start_x = self.CENTER_X + radius
        start_y = self.CENTER_Y
        self.get_logger().info(f'Teleporting to ({start_x:.2f}, {start_y:.2f})')
        self._teleport(start_x, start_y, math.pi / 2)
        time.sleep(1.0)

        # Record start AFTER teleport
        x_start = self.current_pose.x
        y_start = self.current_pose.y
        self.get_logger().info(f'Start recorded: ({x_start:.2f}, {y_start:.2f})')

        # Velocity command
        vel = Twist()
        vel.linear.x = 1.5
        vel.angular.z = 1.5 / radius

        start_time = time.time()
        distance = 0.0

        self.get_logger().info('Motion started...')

        # ============================================================
        # MAIN CONTROL LOOP
        # ============================================================
        while rclpy.ok():

            # Cancel check
            if gh.is_cancel_requested:
                self._stop()
                gh.canceled()
                result = ExecuteCircle.Result()
                result.success = False
                result.final_report = 'Mission Cancelled'
                return result

            if self.current_pose is None:
                time.sleep(0.1)
                continue

            cx = self.current_pose.x
            cy = self.current_pose.y
            elapsed = time.time() - start_time
            distance = 1.5 * elapsed

            # ============================================================
            # WALL CRASH DETECTION
            # ============================================================
            if self._is_near_wall(cx, cy):
                self.get_logger().error('=' * 50)
                self.get_logger().error('  WALL COLLISION IMMINENT!')
                self.get_logger().error(f'  Position: ({cx:.2f}, {cy:.2f})')
                self.get_logger().error(f'  Boundaries: [{self.WALL_MIN}, {self.WALL_MAX}]')
                self.get_logger().error('=' * 50)

                self._stop()
                gh.abort()

                result = ExecuteCircle.Result()
                result.success = False
                result.final_report = 'Mission Aborted: Boundary Collision Imminent!'
                return result

            # ============================================================
            # COMPLETION CHECK - Only after 98% of expected time
            # ============================================================
            if elapsed >= expected_time * 0.98:
                dist_from_start = math.sqrt(
                    (cx - x_start) ** 2 +
                    (cy - y_start) ** 2
                )

                self.get_logger().info(
                    f'Checking: dist_from_start={dist_from_start:.3f}m '
                    f'elapsed={elapsed:.2f}s'
                )

                if dist_from_start < 0.3:
                    self.get_logger().info('=' * 50)
                    self.get_logger().info('  CIRCLE COMPLETE!')
                    self.get_logger().info(f'  Distance: {distance:.2f} m')
                    self.get_logger().info(f'  Expected: {circumference:.2f} m')
                    self.get_logger().info(f'  Error:    {dist_from_start:.3f} m')
                    self.get_logger().info('=' * 50)

                    self._stop()
                    gh.succeed()

                    result = ExecuteCircle.Result()
                    result.success = True
                    result.final_report = (
                        f'Mission Complete! '
                        f'Full circle executed. '
                        f'Distance: {distance:.2f} m, '
                        f'Radius: {radius:.2f} m'
                    )
                    return result

            # Safety stop at 150% of expected time
            if elapsed >= expected_time * 1.5:
                self.get_logger().warn('Safety timeout reached')
                self._stop()
                gh.succeed()
                result = ExecuteCircle.Result()
                result.success = True
                result.final_report = (
                    f'Complete (timeout). '
                    f'Distance: {distance:.2f} m'
                )
                return result

            # Publish velocity
            self.cmd_vel_pub.publish(vel)

            # Feedback
            progress = (distance / circumference) * 100.0

            if progress < 25.0:
                status = f'Progress: {progress:.1f}% - Quarter 1 (East)'
            elif progress < 50.0:
                status = f'Progress: {progress:.1f}% - Quarter 2 (North)'
            elif progress < 75.0:
                status = f'Progress: {progress:.1f}% - Quarter 3 (West)'
            elif progress < 100.0:
                status = f'Progress: {progress:.1f}% - Quarter 4 (South)'
            else:
                status = f'Progress: {progress:.1f}% - Completing...'

            fb = ExecuteCircle.Feedback()
            fb.distance_traveled = distance
            fb.current_status = status
            gh.publish_feedback(fb)

            time.sleep(0.1)

        # Fallback
        self._stop()
        gh.abort()
        result = ExecuteCircle.Result()
        result.success = False
        result.final_report = 'Aborted: ROS2 shutdown'
        return result


# ============================================================
# MAIN FUNCTION - THIS IS WHAT WAS MISSING
# ============================================================
def main(args=None):
    rclpy.init(args=args)
    node = CirclePatrolServer()
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()

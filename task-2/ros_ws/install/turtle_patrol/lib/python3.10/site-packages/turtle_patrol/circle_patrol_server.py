#!/usr/bin/env python3

import rclpy
import math
import time
from rclpy.node import Node
from rclpy.action import ActionServer, CancelResponse, GoalResponse
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor

from geometry_msgs.msg import Twist          
from turtlesim.msg import Pose               

from turtle_patrol_interfaces.action import ExecuteCircle


class CirclePatrolServer(Node):

    def __init__(self):
        super().__init__('circle_patrol_server')
        
        self.LINEAR_VELOCITY = 1.5      
        self.WALL_MIN = 0.5             
        self.WALL_MAX = 10.5            
        self.COMPLETION_TOLERANCE = 0.2  
        self.FEEDBACK_RATE = 10.0       
        
        self.current_pose = None        
        self.is_first_pose = True       
        
        self.callback_group = ReentrantCallbackGroup()
        
        self.cmd_vel_publisher = self.create_publisher(
            Twist,
            '/turtle1/cmd_vel',
            10
        )
        
        self.pose_subscriber = self.create_subscription(
            Pose,
            '/turtle1/pose',
            self.pose_callback,            
            10,
            callback_group=self.callback_group
        )
        
        self.action_server = ActionServer(
            self,
            ExecuteCircle,                          
            'execute_circle',                       
            execute_callback=self.execute_callback, 
            goal_callback=self.goal_callback,       
            cancel_callback=self.cancel_callback,   
            callback_group=self.callback_group
        )
        
        self.get_logger().info('=' * 50)
        self.get_logger().info('  Circle Patrol Server is READY')
        self.get_logger().info('  Waiting for goals...')
        self.get_logger().info('=' * 50)

    def pose_callback(self, msg):
        self.current_pose = msg

    def goal_callback(self, goal_request):
        radius = goal_request.radius
        
        self.get_logger().info(f'New goal received: radius = {radius:.2f} m')
        
        if radius <= 0:
            self.get_logger().warn(f'REJECTED: Radius must be positive (got {radius})')
            return GoalResponse.REJECT
            
        if radius > 4.5:
            self.get_logger().warn(f'REJECTED: Radius {radius} too large for arena')
            return GoalResponse.REJECT
        
        self.get_logger().info(f'Goal ACCEPTED: Will patrol with radius {radius:.2f} m')
        return GoalResponse.ACCEPT

    def cancel_callback(self, goal_handle):
        self.get_logger().info('Cancel request received - accepting cancellation')
        return CancelResponse.ACCEPT

    def execute_callback(self, goal_handle):
        self.get_logger().info('=' * 50)
        self.get_logger().info('  Executing circular patrol mission')
        self.get_logger().info('=' * 50)
        
        radius = goal_handle.request.radius
        angular_velocity = self.LINEAR_VELOCITY / radius
        
        self.get_logger().info(f'Mission Parameters:')
        self.get_logger().info(f'  Radius:           {radius:.2f} m')
        self.get_logger().info(f'  Linear velocity:  {self.LINEAR_VELOCITY:.2f} m/s')
        self.get_logger().info(f'  Angular velocity: {angular_velocity:.4f} rad/s')
        
        circumference = 2 * math.pi * radius
        self.get_logger().info(f'  Expected distance: {circumference:.2f} m')
        
        self.get_logger().info('Waiting for pose data...')
        timeout = 0
        while self.current_pose is None and timeout < 50:
            time.sleep(0.1)
            timeout += 1
            
        if self.current_pose is None:
            self.get_logger().error('No pose data received! Is turtlesim running?')
            goal_handle.abort()
            result = ExecuteCircle.Result()
            result.success = False
            result.final_report = 'Mission Aborted: No turtle pose data available!'
            return result
        
        x_start = self.current_pose.x
        y_start = self.current_pose.y
        
        self.get_logger().info(f'Starting position: ({x_start:.2f}, {y_start:.2f})')
        
        distance_traveled = 0.0          
        loop_rate_seconds = 1.0 / self.FEEDBACK_RATE  
        first_iteration = True
        
        vel_cmd = Twist()
        vel_cmd.linear.x = self.LINEAR_VELOCITY
        vel_cmd.linear.y = 0.0
        vel_cmd.linear.z = 0.0
        vel_cmd.angular.x = 0.0
        vel_cmd.angular.y = 0.0
        vel_cmd.angular.z = angular_velocity  
        
        self.get_logger().info('Starting circular motion...')
        
        while rclpy.ok():
            
            if goal_handle.is_cancel_requested:
                self.get_logger().info('Goal cancelled by client')
                self._stop_turtle()
                goal_handle.canceled()
                result = ExecuteCircle.Result()
                result.success = False
                result.final_report = 'Mission Cancelled by client request'
                return result
            
            if self.current_pose is None:
                time.sleep(loop_rate_seconds)
                continue
                
            current_x = self.current_pose.x
            current_y = self.current_pose.y
            
            if (current_x < self.WALL_MIN or 
                current_x > self.WALL_MAX or
                current_y < self.WALL_MIN or 
                current_y > self.WALL_MAX):
                
                self.get_logger().error('=' * 50)
                self.get_logger().error('  WALL COLLISION DETECTED!')
                self.get_logger().error(f'  Position: ({current_x:.2f}, {current_y:.2f})')
                self.get_logger().error(f'  Boundaries: [{self.WALL_MIN}, {self.WALL_MAX}]')
                self.get_logger().error('=' * 50)
                
                self._stop_turtle()
                goal_handle.abort()
                
                result = ExecuteCircle.Result()
                result.success = False
                result.final_report = 'Mission Aborted: Boundary Collision Imminent!'
                return result
            
            distance_from_start = math.sqrt(
                (current_x - x_start) ** 2 + 
                (current_y - y_start) ** 2
            )
            
            if not first_iteration and distance_from_start < self.COMPLETION_TOLERANCE:
                self.get_logger().info('=' * 50)
                self.get_logger().info('  Circle COMPLETED successfully!')
                self.get_logger().info(f'  Total distance: {distance_traveled:.2f} m')
                self.get_logger().info(f'  Expected:       {circumference:.2f} m')
                self.get_logger().info('=' * 50)
                
                self._stop_turtle()
                goal_handle.succeed()
                
                result = ExecuteCircle.Result()
                result.success = True
                result.final_report = (
                    f'Mission Complete! Full circle executed. '
                    f'Total distance: {distance_traveled:.2f} m. '
                    f'Radius: {radius:.2f} m.'
                )
                return result
            
            if first_iteration:
                if distance_from_start > self.COMPLETION_TOLERANCE:
                    first_iteration = False
            
            self.cmd_vel_publisher.publish(vel_cmd)
            distance_traveled += self.LINEAR_VELOCITY * loop_rate_seconds
            
            if distance_from_start < 1.0 and not first_iteration:
                status = 'Approaching start position...'
            elif distance_traveled < circumference * 0.25:
                status = 'Phase 1/4: Starting circle...'
            elif distance_traveled < circumference * 0.5:
                status = 'Phase 2/4: Quarter way done...'
            elif distance_traveled < circumference * 0.75:
                status = 'Phase 3/4: Halfway through circle...'
            else:
                status = 'Phase 4/4: Completing circle...'
            
            feedback_msg = ExecuteCircle.Feedback()
            feedback_msg.distance_traveled = distance_traveled
            feedback_msg.current_status = status
            
            goal_handle.publish_feedback(feedback_msg)
            
            time.sleep(loop_rate_seconds)
        
        self._stop_turtle()
        goal_handle.abort()
        result = ExecuteCircle.Result()
        result.success = False
        result.final_report = 'Mission Aborted: ROS2 shutdown'
        return result

    def _stop_turtle(self):
        self.get_logger().info('Stopping turtle...')
        stop_cmd = Twist()  
        
        for _ in range(5):
            self.cmd_vel_publisher.publish(stop_cmd)
            time.sleep(0.05)  


def main(args=None):
    rclpy.init(args=args)
    server_node = CirclePatrolServer()
    
    executor = MultiThreadedExecutor(num_threads=4)
    executor.add_node(server_node)
    
    try:
        server_node.get_logger().info('Server spinning with MultiThreadedExecutor...')
        executor.spin()
    except KeyboardInterrupt:
        server_node.get_logger().info('Server shutting down...')
    finally:
        server_node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()

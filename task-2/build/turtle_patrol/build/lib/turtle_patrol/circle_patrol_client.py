#!/usr/bin/env python3

import rclpy
import sys
from rclpy.node import Node
from rclpy.action import ActionClient
from action_msgs.msg import GoalStatus

from turtle_patrol_interfaces.action import ExecuteCircle


class CirclePatrolClient(Node):

    def __init__(self):
        super().__init__('circle_patrol_client')
        
        self.action_client = ActionClient(
            self,
            ExecuteCircle,      
            'execute_circle'    
        )
        
        self.feedback_count = 0             
        self.last_distance_printed = -1.0  
        
        self.get_logger().info('Circle Patrol Client initialized')

    def send_goal(self, radius):
        self.get_logger().info('Waiting for action server...')
        
        server_ready = self.action_client.wait_for_server(timeout_sec=10.0)
        
        if not server_ready:
            self.get_logger().error('Action server not available after 10 seconds!')
            self.get_logger().error('Is circle_patrol_server running?')
            return
        
        self.get_logger().info('Action server found! Sending goal...')
        
        goal_msg = ExecuteCircle.Goal()
        goal_msg.radius = float(radius)
        
        self.get_logger().info('=' * 50)
        self.get_logger().info(f'  SENDING GOAL: radius = {radius:.2f} m')
        self.get_logger().info('=' * 50)
        
        send_goal_future = self.action_client.send_goal_async(
            goal_msg,
            feedback_callback=self.feedback_callback  
        )
        
        send_goal_future.add_done_callback(self.goal_response_callback)
        
        rclpy.spin(self)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        
        if not goal_handle.accepted:
            self.get_logger().error('=' * 50)
            self.get_logger().error('  GOAL REJECTED by server!')
            self.get_logger().error('  Check if radius is valid (0 < radius <= 4.5)')
            self.get_logger().error('=' * 50)
            rclpy.shutdown()
            return
        
        self.get_logger().info('Goal ACCEPTED by server!')
        self.get_logger().info('Waiting for turtle to complete the circle...')
        self.get_logger().info('-' * 50)
        
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self.result_callback)

    def feedback_callback(self, feedback_msg):
        self.feedback_count += 1
        
        distance = feedback_msg.feedback.distance_traveled
        status = feedback_msg.feedback.current_status
        
        if self.feedback_count % 5 == 0:  
            print(
                f'\r  [FEEDBACK] Distance: {distance:6.2f} m | {status}     ',
                end='',  
                flush=True  
            )
        
        milestones = [1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0]
        for milestone in milestones:
            if (self.last_distance_printed < milestone <= distance):
                print()  
                self.get_logger().info(
                    f'Milestone: {distance:.2f} m traveled | Status: {status}'
                )
                self.last_distance_printed = milestone
                break

    def result_callback(self, future):
        result_wrapper = future.result()
        
        status = result_wrapper.status
        success = result_wrapper.result.success
        final_report = result_wrapper.result.final_report
        
        print()  
        print()  
        
        self.get_logger().info('=' * 60)
        
        if status == GoalStatus.STATUS_SUCCEEDED:
            self.get_logger().info('  ACTION STATUS: SUCCEEDED ✓')
            self.get_logger().info(f'  Success Flag: {success}')
            self.get_logger().info(f'  Total Feedback Messages: {self.feedback_count}')
            self.get_logger().info('  FINAL REPORT:')
            self.get_logger().info(f'  "{final_report}"')
            
        elif status == GoalStatus.STATUS_ABORTED:
            self.get_logger().error('  ACTION STATUS: ABORTED ✗')
            self.get_logger().error(f'  Success Flag: {success}')
            self.get_logger().error('  FINAL REPORT:')
            self.get_logger().error(f'  "{final_report}"')
            
        elif status == GoalStatus.STATUS_CANCELED:
            self.get_logger().warn('  ACTION STATUS: CANCELED')
            self.get_logger().warn(f'  Success Flag: {success}')
            self.get_logger().warn(f'  FINAL REPORT: "{final_report}"')
            
        else:
            self.get_logger().warn(f'  Unknown action status: {status}')
            self.get_logger().warn(f'  FINAL REPORT: "{final_report}"')
        
        self.get_logger().info('=' * 60)
        self.get_logger().info('Client task complete. Shutting down.')
        
        rclpy.shutdown()


def main(args=None):
    rclpy.init(args=args)
    
    if len(sys.argv) > 1:
        try:
            radius = float(sys.argv[1])
            print(f'Using command-line radius: {radius}')
        except ValueError:
            print(f'Invalid radius "{sys.argv[1]}", using default 3.0')
            radius = 3.0
    else:
        radius = 3.0
        print(f'Using default radius: {radius}')
    
    client_node = CirclePatrolClient()
    
    try:
        client_node.send_goal(radius)
    except KeyboardInterrupt:
        client_node.get_logger().info('Client interrupted by user')
    finally:
        client_node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()

import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from rcl_interfaces.msg import ParameterDescriptor
from rcl_interfaces.msg import SetParametersResult
import math

class CollisionAvoidanceNode(Node):
    def __init__(self):
        super().__init__('collision_avoidance_node')
        
        descriptor = ParameterDescriptor(description="Minimum distance from walls")
        self.declare_parameter("safety_threshold", 1.5, descriptor)
        
        self.safety_threshold = self.get_parameter("safety_threshold").value
        self.get_logger().info(f"Safety Threshold set to: {self.safety_threshold}")
        
        self.subscriber = self.create_subscription(
            Pose,
            "/turtle1/pose",
            self.pose_callback,
            qos_profile_sensor_data,
        )
        self.get_logger().info("Subscribed to /turtle1/pose")
        
        self.publisher = self.create_publisher(
            Twist,
            '/turtle1/cmd_vel',
            10,
        )
        
        self.add_on_set_parameters_callback(self.parameter_callback)
        
    def pose_callback(self, msg):
        velocity = Twist()
        
        x = msg.x
        y = msg.y
        theta = msg.theta
        
        in_left_zone   = x < self.safety_threshold
        in_right_zone  = x > (11.0 - self.safety_threshold)
        in_bottom_zone = y < self.safety_threshold
        in_top_zone    = y > (11.0 - self.safety_threshold)
        
        facing_left   = (theta > math.pi / 2) or (theta < -math.pi / 2)
        facing_right  = (-math.pi / 2 < theta < math.pi / 2)
        facing_bottom = (theta < 0)
        facing_top    = (theta > 0)
        
        danger_left   = in_left_zone and facing_left
        danger_right  = in_right_zone and facing_right
        danger_bottom = in_bottom_zone and facing_bottom
        danger_top    = in_top_zone and facing_top
        
        if danger_left or danger_right or danger_top or danger_bottom:
            velocity.linear.x = 0.0
            velocity.angular.z = 1.5
            self.get_logger().info("Danger detected! Turning to safe heading...")
        else:
            velocity.linear.x = 2.0
            velocity.angular.z = 0.0
        
        self.publisher.publish(velocity)
        
    def parameter_callback(self, params):
        for param in params:
            if param.name == "safety_threshold":
                if param.value < 0.1 or param.value > 5.0:
                    self.get_logger().warn("Invalid Threshold for 11x11 window (must be between 0.1 and 5.0)")
                    return SetParametersResult(successful=False, reason="Threshold out of bounds")
                
                self.safety_threshold = param.value
                self.get_logger().info(f"Safety threshold dynamically set to {self.safety_threshold}")
                
        return SetParametersResult(successful=True)
        

def main(args=None):
    rclpy.init(args=args)
    node = CollisionAvoidanceNode()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()
    
if __name__ == "__main__":
    main()

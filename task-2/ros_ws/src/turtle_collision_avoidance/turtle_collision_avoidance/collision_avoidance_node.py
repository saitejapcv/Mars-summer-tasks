import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data

from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from std_msgs.msg import String

from rcl_interfaces.msg import ParameterDescriptor
from rcl_interfaces.msg import SetParametersResult

class CollisionAvoidanceNode(Node):
	def __init__(self):
		super().__init__('collision_avoidance_node')
		
		descriptor = ParameterDescriptor(
			description="Minimum distance from walls"
		)
		self.declare_parameter("safety_threshold", 1.5, descriptor) #Descriptor is not necessary. 
		
		self.safety_threshold = self.get_parameter("safety_threshold").value
		
		self.get_logger().info(f"Safety Threshold set to; {self.safety_threshold}")
		
		#Subscription
		self.subscriber = self.create_subscription(
			Pose,
			"/turtle1/pose",
			self.pose_callback,
			qos_profile_sensor_data,
		)
		
		self.get_logger().info("Subscribed to /turtle1/pose")
		
		#Publisher
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
		
		near_left = x < self.safety_threshold
		rear_right = x > (11.0 - self.safety_threshold)
		neer_top = y < self.safety_threshold
		near_bottom = y > (11.0 - self.safety_threshold)
		
		if near_left or near_right or near_top or near_bottom:
			velocity.linear.x = 0.0
			velocity.angular.z = 1.0
			self.get_logger().info(f"Near the wall x={x:.2f} y={y:.2f} so turning")
		else:
			velocity.linear.x = 2.0
			velocity.angular.z = 0.0
		
		self.publisher.publish(velocity)
		
	def parameter_callback(self, params):
		
		for param in params:
			if param.name == "safety_threshold":
				if param.value < 0.1 or param.value > 5.0:
					self.get_logger().info("Invalid Threshold for 11x11 window")
					return setParameterResult(successful=False)
				self.safety_threshold = param.value
				self.get_logger().info(f"Safty threshold set to {self.safety_threshold}")
				
		return setParameterResult(successful=True)
		

def main():
	rcply.init(args=args)
	node = CollisionAvoidanceNode()
	
	try:
		rcply.spin(node)
	except KeyboardInterrupt:
		pass
	
	node.destroy_node()
	rcply.shutdown()
	
if __name__ == "__main__":
	main()

		

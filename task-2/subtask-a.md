# Part-A

## Introduction:

- I have created 1 node called collision_avoidance_node in which i have a Telementary subscriber and a publisher which ensure safety.
- Telementary subscriber : It subscribes to /turtle1/pose topic to get the position and orientation of the turtle. 
- Safty logic publisher: If the turtle's X or Y coordinates come within the specified safety-threshold of any wall, My node will override the normal motion and publish angular velocity.
- Also I have used Standard service of type `rcl_interfaces/srv/SetParameters` to set_parameters. 
- I used a launch file named avoidance_launch.py which starts both turtlesim_node and collision_avoidance_node at the same time also can change the default threshold value of 1.5 during launch.
- Important note I have used python for this package.

## Creating package:

- I have created a directory named ros_ws and src directory in it. It is the place where we will create packages.
- Created package named turtle_collision_avoidance as mentioned in my first task files. 

## Creating and Writing nodes: 

- I explained how to create a node in the 1st task.

- I have created a node named collision_avoidance_node.

- First we have all the dependencies Needed for the node. 

- Some of them include `qos_profile_sensor_data`, `Twist`, `Pose`.

- `qos_profile_sensor_data` - It is a predefined QOS profile. Normally when a packet is missing the node will wait till the packet arrives. If we use this profile the missed packet will be dropped and the packet after that will be sent. Which means always newer msg will be given priority. 

- `Twist` - It is a class, Its objects are used to send data of velocity of the turtle here.

- `Pose` - It is also a class, the objects of pose are used to recieve data of the position of the turtle. 

- After importing dependencies there is CollisionAvoidanceNode class. 

- In its init function we have created safety threshold parameter, a subscription to the `/turtle1/pose` topic and a publisher to `/turtle1/pose` topic. 

- Then we have pose_callback function: It is the fuction which gets the data of the position and orientation from the subscription and publishes Twist velocity according to conditions.

- Lets see the safety conditions:
1. The node will see if the turtle is in any of the threshold zone.
2. Then which direction is it facing. 
3. If it is in the threshold zone and facing the wall of that zone then it assume that the turtle is in danger. 
4. If the turtle is in danger the normal motion is overrided by the angular rotation of 2 with z axis as its axis of rotation until it skips the danger.

- After this function we have a function called parameter callback. It is called when we change the parameter during the launch time or with terminal.

- This function will set the parameter `safety_threshold` with the given value if it is valid value.

- Then we have the main function. We will create an object using the CollisionAvoidanceNode class and spin the node. When we press Ctrl-C(keyboardInturrupt) in the terminal the node will destroy and shutdown.

## Add dependencies:

- We have to add dependencies to the package.xml and entry point to the setup.py as mentioned in the 1st task.

## Launch File:

- I have created a directory called launch in the package directory and create a launch file named `avoidance_launch.py`. 
- This files aim is to run both turtlesim_node and collision_avoidance_node at same time and set the custom safety threshold. 
- We have to import `LaunchDescription` and `Node`. 
- the basic structure of launch file is 
``` #Imports
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description(): # Function
	return LaunchDescription([
		Node(
			package="<package-name>",
			executable="<executable-node>",
			name="<custom-name>", # You will see this name in the list of active node
			output="screen" # This is where the log msg will be sent
			# we can also add parameters. 
		),
		
		# Write different nodes we want to launch
	])
```
- We have to add the below line in the data files of setup.py. This tells the python tools exactly where to copy this launch file when the package is built.

`('share/' + package_name + '/launch', ['launch/avoidance_launch.py']),`

## Build and run:

- Go to workspace directory and use colcon to build the package as mentioned in the 1st task.
- Open other termianl, source it using `source install/setup.bash`.
- Use this command to run `ros2 launch turtle_collision_avoidance avoidance_launch.py safety_threshold:=<value>`
- safety_threshold argument is optional. 
- This is the run command because we used launch file. 
- Now you can see the turtle.



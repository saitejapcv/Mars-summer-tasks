# Spawning My rover in Gazebo ignition. 

- We have created our robot with urdf now we have to spawn our robot to gazebo. 
- To Spawn our robot we use [ros_gz_sim](https://github.com/gazebosim/ros_gz/blob/humble/ros_gz_sim/README.md)

the command for spawning is `ros2 run ros_gz_sim create -name <name> -string <urdf_code>`

We use this in launch file as
```
spawn_robot = Node(
        package='ros_gz_sim',
        executable='create',
        arguments=[
            '-name', 'my_robot',
            '-string', robot_description,
            '-x', '0', '-y', '0', '-z', '1.0'
        ],
        output='screen'
)
```

## Bridge communication between ROS and Gazebo
- We should also setup a bridge between ROS2 and Gazebo using [ros_gz_bridge](https://github.com/gazebosim/ros_gz/tree/humble/ros_gz_bridge)
- ros_gz_bridge: This package provides a network bridge which enables the exchange of messages between ROS and Gazebo Transport.
- We use Twist objects for communication here for publishing velocity.
- The command for establishing bridge for this is
```ros2 run ros_gz_bridge parameter_bridge <msg_type> # general

ros2 run ros_gz_bridge parameter_bridge /cmd_vel@geometry_msgs/msg/Twist@ignition.msgs.Twist    # here
```
- We implement this in launch file using

```
bridge = Node(
     package='ros_gz_bridge',
     executable='parameter_bridge',
     arguments=[
         '/cmd_vel@geometry_msgs/msg/Twist@ignition.msgs.Twist',
     ],
     output='screen'
)
```

- We also create another bridge for joint_states. It has a another argument in launch file which is remapping: This line tells ROS 2: "Take that long Gazebo topic name and rename it to /joint_states inside the ROS network." This makes it instantly compatible with standard ROS 2 navigation and visualization tools.

## Launch File:

[gazebo.launch.py](../ros_ws/src/my_robot/launch/gazebo.launch.py)

## References:

[ROS + Gazebo Sim](https://github.com/gazebosim/ros_gz/blob/humble/ros_gz_sim/README.md)||[Bridge communication between ROS and Gazebo](https://github.com/gazebosim/ros_gz/tree/humble/ros_gz_bridge)

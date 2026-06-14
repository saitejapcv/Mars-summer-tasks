# Robot arm

- This arm will rotate with an axis of y.
- The arm has a camera in the front.

## Arm Structure

It is defined in [arm.xacro](../ros_ws/src/my_robot/urdf/arm.xacro)

### Arm base

- The arm base is a cylinder with radius 0.15 and length 0.08.
- It is fixed to the main chassis on the top.

### Arm link

- It is a cuboid with size 0.1 x 0.1 x 1. The joint of this arm is fixed to the arm base at the bottom.

- The joint between arm_link and arm_base is a revolute joint with axis of y. It can rotate between -90 and 90 degrees.

## Camera

It is defined in [camera.xacro](../ros_ws/src/my_robot/urdf/camera.xacro)

- For more about camera read [sensors.md](sensors.md)

## Arm controller

- The arm is controlled using the ros2_control and ros2_control_ign packages.

- We specifically use the following plugin

```
<plugin filename="libign_ros2_control-system.so" name="ign_ros2_control::IgnitionROS2ControlPlugin">
    <parameters>$(find my_robot)/config/controllers.yaml</parameters>
</plugin>
```

- We specify the minimum and maximum parameters for the `arm_joint` controller to prevent it from moving beyond the physical limits of the arm.

### controllers.yml

- We use controllers.yaml to define the controllers.

- It is a configuration file that tells the Controller Manager which controllers to load and how to configure them for our robot.

- We use `joint_state_broadcaster` to read the current joint positions, velocities and efforts of the robot. and `arm_controller` controllers for the arm.

## rqt

- We can control the arm using rqt.

- Use the following command

`ros2 run rqt_joint_trajectory_controller rqt_joint_trajectory_controller`

![image](images/rqt.png)

## Resources

[joint_state_broadcaster](https://control.ros.org/rolling/doc/ros2_controllers/joint_state_broadcaster/doc/userdoc.html#joint-state-broadcaster-userdoc) || [joint_trajectory_controller](https://control.ros.org/rolling/doc/ros2_controllers/joint_trajectory_controller/doc/userdoc.html#joint-trajectory-controller-userdoc) || [Example 1: RRBot](https://control.ros.org/rolling/doc/ros2_control_demos/example_1/doc/userdoc.html) || [rqt_joint_trajectory_controller](https://control.ros.org/master/doc/ros2_controllers/rqt_joint_trajectory_controller/doc/userdoc.html) || [joint_trajectory_controller parameters](https://control.ros.org/master/doc/ros2_controllers/joint_trajectory_controller/doc/parameters.html) || [ros2_control](https://sir.upc.edu/projects/ros2tutorials/7-control/index.html) || [ros2_control Concepts & Simulation](https://articulatedrobotics.xyz/tutorials/mobile-robot/applications/ros2_control-concepts)

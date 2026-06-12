# My Rover

## Creating a package.

- I have created a package first in my workspace. 
- The name of the package is my_robot.

## URDF

- This is a format of xml used to create the visualisation of our robot. 
- Our urdf file is in the location `~/Mars-summer-tasks/ros_ws/src/my_robot/urdf/my_robot.urdf`
- If you open it we see the first tag as
```
<?xml version="1.0"?>
```
- This tells that we are using xml and a version of 1.0
- Then comes the main tag which is `robot` tag. This is where we write all description of our robot. Also it contains an atribute `name`.
- Then we can see the `material` tag. It is used to define colours and textures. We should give an attribute `name` to that tag which is used when we want to use it later. Inside that we specify material properties. Here we specified color using `color` tag. We specify the color in rgba format using `rgba` parameter to the tag.


### link element

- Now comes the main tag. Which is `link` tag. It is where we create our parts. Initally we used it to create a dummy. The dummy is used because we cannot give inertia to the root link. If we don't use dummy the `base_link` will be chosen as root link. Then we cannot specify inertia to that. We talk about inertia in later sections

![link](https://wiki.ros.org/urdf/XML/link?action=AttachFile&do=get&target=inertial.png)

#### Attributes:

- name (required) : The name of the link itself.

- `<link>` tag has an attribute `name` which is used as reference when creating joints later. Inside `link` tag we have mainly `visual`, `collision` and `inertial` tags. `base_dummy` won't have these tags as it is a part of our rover. If you see the next `link` tag which is `base_link` you can see these tags.

#### Elements:

- `visual` tag: It is used to describe how the part should look like. It describes the geometry, origin and material and all using respective tags.
  - `geometry` : it has 4 shapes - `box`(attribute - size(side lengths)), `cylinder`(attributes - radius and length), `sphere`(attribute - radius) and `mesh` - It is a custom made geometry(recommended format for best texture and color support is Collada .dae files). 
  - We will also specify the material here or use already specified material by using name attribute as refference.
  - `origin` : It is used to specify origin of the object (or center of the object). We use xyz attribute to change the xyz coordinates of the origin(initially it will be at the exact center of the object.) and rpy represents the rotation around fixed axis: first roll around x, then pitch around y and finally yaw around z. All angles are specified in radians. 
- `collision` tag: It is used by physics engines and motion planners to calculate exactly how the robot interacts with its environment, preventing it from passing through itself or other physical objects. 
  - `geometry` tag : It is the same geometry tag as in visual tag. 
  - `origin` tag : it is also the same origin tag as in visual tag. 
- `inertial` tag : This defines the link’s mass, position of its center of mass, and its central inertia properties. It is used to calculate how the robot moves, accelerates, and responds to forces like gravity, collisions, and motor torques. It mainly consists of `origin`, `mass` and `inertia` tags.
  - `origin` tag : It has same properties as the origin in visual tag. But it is used to define the position and orientation of the center of mass frame C relative to link-frame L.
  - `mass` tag : The mass of the link is represented by the value attribute of this element.
  - `inertia` tag: This is link's moments of inertia ixx, iyy, izz and products of inertia ixy, ixz, iyz about Co (the link’s center of mass) for the unit vectors Ĉx, Ĉy, Ĉz fixed in the center-of-mass frame C. Note: the orientation of Ĉx, Ĉy, Ĉz relative to L̂x, L̂y, L̂z is specified by the rpy values in the <origin> tag. To caluculate the values of ixx, ixy, ixz, iyy, iyz, izz for some primitive shapes go [here](https://en.wikipedia.org/wiki/List_of_moments_of_inertia#List_of_3D_inertia_tensors).
  
### joint Element

The joint element describes the kinematics and dynamics of the joint and also specifies the safety limits of the joint.

![joint](https://wiki.ros.org/urdf/XML/joint?action=AttachFile&do=get&target=joint.png)

#### Attributes

- name (required) : Specifies a unique name of the joint

- type (required) : Specifies the type of joint, where type can be one of the following:
  - *fixed* — this is not really a joint because it cannot move. All degrees of freedom are locked.
  - *revolute* - a hinge joint that rotates along the axis and has a limited range specified by the upper and lower limits.
  - *continuous* - a continuous hinge joint that rotates around the axis and has no upper and lower limits.
  - *prismatic* - a sliding joint that slides along the axis, and has a limited range specified by the upper and lower limits.
  - *planar* — this joint allows motion in a plane perpendicular to the axis.
  - *floating* - this joint allows motion for all 6 degrees of freedom.

#### Elements

1. `<origin>`: This is the transform from the parent link to the child link. The joint is located at the origin of the child link, as shown in the figure above.
  - `xyz` - Represents the x, y, z offset. All positions are specified in metres.
  - `rpy` - Represents the rotation around fixed axis: first roll around x, then pitch around y and finally yaw around z. All angles are specified in radians.
  
2. `<parent>`: Parent link name with mandatory attribute:
  - `link` - The name of the link that is the parent of this link in the robot tree structure.
3. `<child>` : Child link name with mandatory attribute:
  - `link` - The name of the link that is the child of htis link in the robot tree structure.
4. `<axis>`: This is the axis of rotation for revolute joints, the axis of translation for prismatic joints, and the surface normal for planar joints.
  - `xyz` - Represents the (x, y, z) components of a vector. The vector should be normalized.
5. `<limit>`: This is the limit range of the joint. this element can contain the following attributes:
  - `lower` - It is the lower joint limit in radians.
  - `upper` - It is the upper joint limit in radians.
  - `effort` - An attribute for enforcing the maximum joint effort. [see safety limits here](https://wiki.ros.org/pr2_controller_manager/safety_limits)
  - `velocity ` - An attribute for enforcing the maximum joint velocity. [see safety limits here](https://wiki.ros.org/pr2_controller_manager/safety_limits)
- There are some other Elemets like `<calibration>`, `<dynamics>`, `<mimic>`, `<safety_controller>`, which we didn't use here. To know about those in detail go [here](https://wiki.ros.org/urdf/XML/joint)

### gazebo Element

- The gazebo element is an extension to the URDF robot description format, used for simulation purposes in the Gazebo simulator.
- We have used DiffDrive Plugin in this file. To know about this in detail go [here](https://gazebosim.org/api/gazebo/6/classignition_1_1gazebo_1_1systems_1_1DiffDrive.html#details)
- it is used to easily control and simulate robots with more than one independently driven wheels and a passive caster wheel.

#### System parameters of DiffDrive 
- `<left_joint>`: Name of a joint that controls a left wheel. This element can appear multiple times, and must appear at least once.
- `<right_joint>`: Name of a joint that controls a right wheel. This element can appear multiple times, and must appear at least once.
- `<wheel_separation>`: Distance between wheels, in meters. This element is optional, although it is recommended to be included with an appropriate value. The default value is 1.0m.
- `<wheel_radius>`: Wheel radius in meters. This element is optional, although it is recommended to be included with an appropriate value. The default value is 0.2m.
- `<topic>`: Custom topic that this system will subscribe to in order to receive command velocity messages. This element if optional, and the default value is /model/{name_of_model}/cmd_vel.

#### Friction

- We should use friction to create a realistic physics simulation. Without friction simulated models cannot grip the ground.
- How friction works: When two object collide, such as a ball rolling on a plane, a friction term is generated. In ODE this is composed of two parts, `mu1` and `mu2`, where:
  1. `mu1` is the primary friction coefficient (rolling direction).
  2. `mu2` is the secondary friction coefficient (sliding/lateral direction).

- We have used friction of 1 for the wheels as it will grip the ground perfectly and move.
- standard form to use in urdf file is:
```
<gazebo reference="{name_of_the_link}">
   	<mu1>{value}</mu1>
    	<mu2>{value}</mu2>
</gazebo>
```

Also we have used JointStatePublisher plugin.

### Our URDF File

- If you see my urdf file you will observe I have created 3 material properties with 3 different colours. 
- Then we have a dummy link and then base_link which is chasis. I have chosen the dimensions of it as 1.8x1.4x0.5. also assigned inertia as calculated and created collision with same dimensions
- Then we have 4 legs, which are fixed to the chasis. 
- Then we have 4 wheels joined to 4 legs which is a cylinder in the shape of a wheel and it is joined to the legs using continuous joint.
- Then we have gazebo tags which describes the friction and uses plugins like DiffDrive. 

## References

[Building a Visual Robot Model](https://docs.ros.org/en/humble/Tutorials/Intermediate/URDF/Building-a-Visual-Robot-Model-with-URDF-from-Scratch.html)||[Building a Movable Robot Model](https://docs.ros.org/en/humble/Tutorials/Intermediate/URDF/Building-a-Movable-Robot-Model-with-URDF.html)||[Adding Physical and Collision Properties](https://docs.ros.org/en/humble/Tutorials/Intermediate/URDF/Adding-Physical-and-Collision-Properties-to-a-URDF-Model.html)||[Describing robots with URDF](https://articulatedrobotics.xyz/tutorials/ready-for-ros/urdf/)||[URDF XML Specifications](https://wiki.ros.org/urdf/XML)

[DiffDrive](https://gazebosim.org/api/gazebo/6/classignition_1_1gazebo_1_1systems_1_1DiffDrive.html)||[Friction](https://classic.gazebosim.org/tutorials?tut=friction)||[SDF Friction](http://sdformat.org/spec?ver=1.8&elem=collision#surface_friction)||[JointStatePublisher](https://gazebosim.org/api/gazebo/6/classignition_1_1gazebo_1_1systems_1_1JointStatePublisher.html)[Moving Robot using gazebo](https://gazebosim.org/docs/fortress/moving_robot/)


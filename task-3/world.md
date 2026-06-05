# Rover World

We have build a simple world in `~Mars-summer-tasks/ros_ws/src/my_robot/worlds/my_robot_world.sdf`. 

## Defining world

- We start sdf world files with 
```
<?xml version="1.0" ?>
<sdf version="1.8">
    <world name="world_demo">
    ...
    ...
    </world>
</sdf>
```
- The first two tags define the version of the `XML` and the `SDF`. Then we have the `<world> </world>` tags between which everything goes.

## Physics

```
<physics name="1ms" type="ode">
	<max_step_size>0.001</max_step_size>
	<real_time_factor>1.0</real_time_factor>
	<real_time_update_rate>1000</real_time_update_rate>
</physics>
```
- The physics tag specifies the type and properties of the dynamic engine. We chose the `name` `1ms` as the step size is 1 millisecond. The `type` is the type of the dynamic engine (physics library). There are options like, Ode, Bullet, Simbody and Dart. We set it to `ignored`, as choosing the type of the physics engine is not done through this tag yet.

- `<max_step_size>` is the maximum time at which every system in simulation can interact with the states of the world. The smaller the value, the more accurate your calculations, but more computation power is needed. `<real_time_factor>` is the ratio of simulation time to real `<time.real_time_update_rate>` is the frequency at which the simulation time steps are advanced. 
[For more physics parameters](https://classic.gazebosim.org/tutorials?tut=physics_params)

## Plugins

- Plugins are a dynamically loaded chunk of code. For example:

```
<plugin filename="libignition-gazebo-physics-system.so"
	name="ignition::gazebo::systems::Physics"/>
```
The above one is `Physics` plugin which is very important for the dynamics of the world. [More about physics plugin](https://gazebosim.org/api/physics/5/physicsplugin.html)
```
<plugin filename="libignition-gazebo-user-commands-system.so"
	name="ignition::gazebo::systems::UserCommands"/>
```
This is `UserCommands` plugin which is responsible for creating models, moving models, deleting them and many other user commands.
```	
<plugin filename="libignition-gazebo-scene-broadcaster-system.so"
	name="ignition::gazebo::systems::SceneBroadcaster"/>
```
This is `SceneBroadcaster` Plugin which sshows our world scene.


## Light 

```
<light type="directional" name="sun">
	<cast_shadows>true</cast_shadows>
	<pose>0 0 10 0 0 0</pose>
	<diffuse>0.8 0.8 0.8 1</diffuse>
	<specular>0.2 0.2 0.2 1</specular>
	<direction>-0.5 0.1 -0.9</direction>
	<attenuation>
		<range>1000</range>
                <constant>0.9</constant>
                <linear>0.01</linear>
                <quadratic>0.001</quadratic>
	</attenuation>
	<direction>-0.5 0.1 -0.9</direction>
</light>
``` 

- `<light>` specifies the light source in the world. The `<type>` of the light can be `point`, `directional` or `spot`.
- `<pose>` is the position (x,y,z) and orientation (roll, pitch, yaw) of the light element with respect to the frame mentioned in the `relative_to attribute`; in our case (`relative_to` attribute is ignored) it is relative to the world.
- `<cast_shadows>` when true the light will cast shadows. `<diffuse>` and `<specular>` are the diffuse and specular light color.
- `<attenuation>` specifies the light attenuation properties, which are:
  - `<range>` is range of light.
  - `<constant>` is the constant attenuation factor, 1 never attenuate and 0 complete attenuation.
  - `<linear>` is the linear attenuation factor, 1 means attenuate evenly over the distance.
  - `<quadratic>` is the quadratic attenuation factor. It adds curvature to the attenuation.
  - `<direction>` is direction of the light, only applicable to spot and directional light.
  
## 

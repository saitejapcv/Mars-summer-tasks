# Part-B

## Introduction:

- This is a package which makes the turtle move in a circle with specified radius.
- I have created custom action in this part using CMake. 
- Also I have Action server which controls the velocity of the turtle, Goal Tracking, Feedback Loop, The Wall Crash Failure State.
- It has a Action Client which sends the target radius goal to the server, prints incoming feedback(Distance Travelled) and it prints the final result returned by the server.

## Creating Packages:

- as we already created a workspace for part-a I am continuing in it.

- We need 2 packages here because custom action cannot be built using ament_python because it cannot support                 rosidl_default_generators package. So I have created a package named `turtle_patrol_interfaces` for defining action and then `turtle_patrol` for action server and action clients.

- We have to create one package using `ament_cmake` and other with `ament_python`.

## Writing action file:

- In `turtle_patrol_interfaces` package I have created a directory named action and created a file named `ExecuteCircle.action`.

- Write the variables we use in the action. Structure of this file is 

``` # The goal
[data type] [variable name]

--- # this is the seperator

# The result
[data type] [variable name]

---

# The feedback
[data type] [variable name]
```

- We need to add the below lines of code in the `CMakeLists.txt` to include a dependency and generate action interface.
``` 
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "action/Fibonacci.action"
)
```

- Also we need to add the below lines in `package.xml` to add the dependencies.
```
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "action/Fibonacci.action"
)
```

- all set the action interface is ready. You can use it with any package either python or CMake.

## Writing Action server:

- As I am using python to create nodes I created a package named `turtle_patrol` using Python.

- In the package I have created an action server node named `circle_patrol_server.py`. 

- Lets examine this file.

- Initially we have installed some dependencies like `ActionServer`, `GoalResponse`, `CancelResponse`, `ReentrantCallbackGroup`, `MultiThreadedExecutor`.

- `ActionServer` : This is the main class used to instantiate an Action Server node.
- `GoalResponse` : This is an enum used inside your server's goal-validation callback function. When a client sends a new goal request, your server evaluates it and returns either GoalResponse.ACCEPT or GoalResponse.REJECT
- `CancelResponse` : Similar to GoalResponse, this is an enum used when a client tries to abort a running task mid-execution. Your server evaluates the request and returns either CancelResponse.ACCEPT or CancelResponse.REJECT.
- `ReentrantCallbackGroup` : By default, a ROS 2 node handles callbacks sequentially (one after the other). If your action is executing a long loop, it will block incoming position updates or cancel requests. By assigning your action and topics to a ReentrantCallbackGroup, you tell ROS 2: "It is completely safe to run these specific callbacks at the exact same time."
- `MultiThreadedExecutor` : This is the engine that actually makes parallelism happen. While the standard rclpy.spin(node) uses a single CPU thread to process everything in a single-file line, the MultiThreadedExecutor allocates a pool of multiple operating system threads.

- After importing dependencies there is CirclePatrolServer class.

- in the init function we have initiated the constants like the center coordinates, created a publisher for `/turtle1/cmd_vel`, subscription for `/turtle1/pose`, client for `/turtle1/teleport_absolute`, server for our custom action.

- For creating server for our custom action we have imported the ExecuteCircle action then, using ActionServer function and attributes, we have created the server. 

- After that we have some functions:
1. pose_cb: which is called when the packet arrives from the topic `/turtle1/pose`. It will update the current_pose.
2. goal_cb: it is called when the client gives a goal. It will check the valid conditions for the radius and if it is valid then accept the goal
3. teleport: This function is used to teleport the turtle to the starting position by setting the center of circle as the center of rotation.
4. stop: It is used to make the velocity(both linear and angular) zero. 
5. is_near_wall: It will check if the turtle is near the wall with a safety threshold of 1.5.
6. exec: This is where execution takes place. If the server accepts the goal this function is called. This will publish the velocity to `/turtle1/cmd_vel` and makes it move in a circle. We use standard linear velocity(v)=1.5 and angular velocity(w) = v/r where r is the radius. It will also constantly check if the turtle is near the wall, if it is near the wall then the turtle will stop and mission will abort. It will also constantly check the displacement between the final and initial point after some time so that it will stop if it comes to the initial point. also constant feedback will be given. 

- Then we have main fuction. We can see that this is different that other nodes. We have used an object of `MultiThreadedExecutor()` class, so that it will allocate a pool of multiple operating system threads.

## Writing an action client:

- In the same package as action server create a action client named `circle_patrol_client.py`.

- Lets examine the file.

- Initially we have imported some dependencies one of that includes `GoalStatus` it will check if the Goal is succeeded or aborted or cancelled.

- Then we have `CirclePatrolClient` Class.

- in the init file of it we have created some variables and a action client.

- Then we have some functions: 
1. `send_goal` : This will send the goal to the server with goal msg consisting of the radius.


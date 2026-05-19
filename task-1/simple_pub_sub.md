# Creating a simple publisher and subscriber using both C++ and Python

- Nodes are executable processes that communicate over the ROS graph. 
- In this tutorial, the nodes will pass information in the form of string messages to each other over a topic.
- The example used here is simple talker and listener. One node publishes data and the other node subscribes to the topic so it can recieve the data.

## Creating using C++

- Create a package first using 

`ros2 pkg create --build-type ament_cmake --license Apache-2.0 cpp_pubsub` 

in a workspace as mentioned in the [clietLibraries file](clientLibraries.md).

### Write the publisher node

Download the example talker code by entering the following command:

`wget -O publisher_member_function.cpp https://raw.githubusercontent.com/ros2/examples/humble/rclcpp/topics/minimal_publisher/member_function.cpp`

Now you will have a file named `publisher_member_function.cpp`. Open it using preffered Text Editor.

You will see the C++ Code here.

#### Examine the code

- Top of the code includes the standard C++ libraries.
- After that there is `rclcpp/rclcpp.hpp` include which allows you to use the most common pieces of the ROS 2 system.
- Last is `std_msgs/msg/string.hpp`, which includes the built-in message type you will use to publish data.


- These lines represent node dependencies. 
- The next line creates the node class `MinimalPublisher` by inheriting from `rclcpp::Node`. 
- Every `this` in the code is referring to the node.


- The public constructor names the node `minimal_publisher` and initializes `count_` to 0.
- Inside the constructor, the publisher is initialized with the `String` message type, the topic name `topic`, and the required queue size to limit messages in the event of a backup. 
- Next, `timer_` is initialized, which causes the `timer_callback` function to be executed twice a second.


- The `timer_callback` function is where the message data is set and the messages are actually published. 
- The RCLCPP_INFO macro ensures every published message is printed to the console.


- Last is the declaration of the timer, publisher, and counter fields.

- Following the `MinimalPublisher` class is `main`, where the node actually executes. 
- `rclcpp::init` initializes ROS 2, and `rclcpp::spin` starts processing data from the node, including callbacks from the timer.

#### Adding Dependencies

- As I mentioned earlier we need to add our dependencies in `package.xml`.
- In this file add dependencies after in a new line after the `ament_cmake` buildtool dependency.


- This declares the package needs `rclcpp` and `std_msgs` when its code is built and executed.

#### CMakeLists.txt

- We need to add the dependencies here too. 
- To add these open the `CMakeLists.txt` file. Below the existing dependency `find_package(ament_cmake REQUIRED)`, add the lines:

- After that, add the executable and name it `talker` so you can run your node using `ros2 run`:

- Finally, add the `install(TARGETS...)` section so `ros2 run` can find your executable:

- You can clean up your `CMakeLists.txt` by removing some unnecessary sections and comments, so it looks like this:



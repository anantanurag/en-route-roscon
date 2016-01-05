// The following has been taken from http://jbohren.com/articles/roscpp-hello-world/

// Include the ROS C++ APIs
#include <ros/ros.h>

// Standard C++ entry point
int main(int argc, char** argv) {
  // Announce this program to the ROS master as a "node" called "hello_world_node"
  ros::init(argc, argv, "hello_world_node");
  // Start the node resource managers (communication, time, etc)
  ros::start();
  // Broadcast a simple log message
  ROS_INFO_STREAM("Hello, world!");
  // Process ROS callbacks until receiving a SIGINT (ctrl-c)
  ros::spin();
  // Stop the node's resources
  ros::shutdown();
  // Exit tranquilly
  return 0;
}


/* 
  TO COMPILE
  g++ hello_world_node.cpp -o hello_world_node -I/opt/ros/indigo/include -L/opt/ros/indigo/lib -Wl,-rpath,/opt/ros/indigo/lib -lroscpp -lrosconsole -lrostime

  TO EXECUTE
  source /opt/ros/indigo/setup.sh
  roscore
  ./hello_world_node
*/

/* 
  
    hello_world_node.cpp The source file(s) to compile
    -o hello_world_node The name of the output file (the executable, in this case)
    -I/opt/ros/indigo/include An instruction to look for C++ header files in /opt/ros/indigo/include
    -L/opt/ros/indigo/lib An instruction to look for static libraries in /opt/ros/indigo/lib
    -Wl,-rpath,/opt/ros/indigo/lib An instruction to look for shared libraries in /opt/ros/indigo/lib
    -lroscpp Link against the library libroscpp.so (ROS C++ bindings)
    -lrosconsole Link against the library librosconsole.so (ROS distributed logging)
    -lrostime Link against the library librostime.so (ROS time measurement)
*/
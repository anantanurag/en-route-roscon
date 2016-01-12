Code in tutorial section has been taken from http://wiki.ros.org/
Compilation parameters have been taken from http://jbohren.com/articles/roscpp-hello-world/  and  http://answers.ros.org/

/* 
  TO COMPILE
  g++ hello_world_node.cpp -o hello_world_node -I/opt/ros/indigo/include -L/opt/ros/indigo/lib -Wl,-rpath,/opt/ros/indigo/lib -lroscpp -lrosconsole -lrostime -lroscpp_serialization

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



Tutorials

http://answers.ros.org/question/223599/how-to-subscribe-to-a-topic-while-publishing-to-another/

http://answers.ros.org/question/223579/not-able-to-spawn-basic-shapes-in-rviz/

https://github.com/ros/cheatsheet

http://wiki.ros.org/RecommendedRepositoryUsage/CommonGitHubOrganizations
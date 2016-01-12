/* 
  TO COMPILE
  g++ array_publisher.cpp -o array_publisher_node -I/opt/ros/indigo/include -L/opt/ros/indigo/lib -Wl,-rpath,/opt/ros/indigo/lib -lroscpp -lrosconsole -lrostime -lroscpp_serialization

  TO EXECUTE
  source /opt/ros/indigo/setup.sh
  roscore
  ./array_publisher_node
*/


#include <stdio.h>
#include <stdlib.h>

#include "ros/ros.h"

#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"

#include "std_msgs/Int32MultiArray.h"

int main(int argc, char **argv)
{
    

	ros::init(argc, argv, "arrayPublisher");

	ros::NodeHandle n;

	ros::Publisher pub = n.advertise<std_msgs::Int32MultiArray>("array", 100);
	std_msgs::Int32MultiArray array;
	array.data.clear();

	while (ros::ok())
	{
		
		//Clear array
		//for loop, pushing data in the size of the array
		// for (int i = 0; i < 90; i++)
		// {
		// 	//assign array a random number between 0 and 255.
		// 	array.data.push_back(rand() % 255);
		// }
		array.data.push_back(1);

		//Publish array
		pub.publish(array);
		//Let the world know
		ROS_INFO("I published something!");
		//Do this.
		ros::spinOnce();
		//Added a delay so not to spam
		sleep(0.1);
	}

}
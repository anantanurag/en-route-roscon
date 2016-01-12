/* 
  TO COMPILE
  g++ array_subscriber.cpp -o array_subscriber_node -I/opt/ros/indigo/include -L/opt/ros/indigo/lib -Wl,-rpath,/opt/ros/indigo/lib -lroscpp -lrosconsole -lrostime -lroscpp_serialization

  TO EXECUTE
  source /opt/ros/indigo/setup.sh
  roscore
  ./array_subscriber_node
*/



#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

#include "ros/ros.h"

#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"
#include "std_msgs/Int32MultiArray.h"

int Arr[90];
void arrayCallback(const std_msgs::Int32MultiArray::ConstPtr& array);

int main(int argc, char **argv)
{

	ros::init(argc, argv, "arraySubscriber");

	ros::NodeHandle n;	

	ros::Subscriber sub3 = n.subscribe("array", 100, arrayCallback);

	ros::spinOnce();

	for(int j = 1; j < 90; j++)
	{
		printf("%d, ", Arr[j]);
	}

	printf("\n");
	return 0;
}

void arrayCallback(const std_msgs::Int32MultiArray::ConstPtr& array)
{

	int i = 0;
	// print all the remaining numbers
	for(std::vector<int>::const_iterator it = array->data.begin(); it != array->data.end(); ++it)
	{
		Arr[i] = *it;
		i++;
	}

	return;
}
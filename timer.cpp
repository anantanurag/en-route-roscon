#include "ros/ros.h"
#include <ctime>

int main(int argc,char** argv)
{
	ros::init(argc, argv, "timer_node");

	ros::NodeHandle nh;

	ros::Rate loop_rate(1);
	time_t now = time(0);
	tm *ltm = localtime(&now);

	while(ros::ok())
	{
		now = time(0);
		ltm = localtime(&now);
		ROS_INFO_STREAM("Time: "<< 1 + ltm->tm_hour << ":" << 1 + ltm->tm_min << ":"<< 1 + ltm->tm_sec);
		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}
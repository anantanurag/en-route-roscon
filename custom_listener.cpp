#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/Num.h"

void chatterCallback(const beginner_tutorials::Num::ConstPtr &num)
{
	ROS_INFO("I heard: [%d]",  num->num);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "listener");

	ros::NodeHandle n;

	ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

	ros::spin();

	return 0;
}
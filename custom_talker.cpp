#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/Num.h"

#include <sstream>


int main(int argc, char **argv)
{
	ros::init(argc, argv, "talker");

	ros::NodeHandle n;

	ros::Publisher chatter_pub = n.advertise<beginner_tutorials::Num>("chatter", 1000);

	ros::Rate loop_rate(10);

	int count = 0;
	while(ros::ok())
	{
		beginner_tutorials::Num num;

		// std::stringstream ss;
		// ss <<"hello world" << count;
		num.num = 123456789;

		
		ROS_INFO("%d",num);

		chatter_pub.publish(num);

		ros::spinOnce();

		loop_rate.sleep();
		++count;
	}

	return 0;
}
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"

void poseCallback(const turtlesim::PoseConstPtr& msg)
{
	ROS_INFO("x: %.2f, y: %.2f", msg->x, msg->y);
}


int main(int argc, char** argv)
{

	const double FORWARD_SPEED_MPS = 0.5;
	
	ros::init(argc, argv, "move_turtle");
	ros::NodeHandle nh;

	ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);

	ros::Subscriber sub = nh.subscribe("turtle1/pose", 10, poseCallback);

	geometry_msgs::Twist msg;
	msg.linear.x = FORWARD_SPEED_MPS;
	
	ros::Rate rate(10);
	ROS_INFO("Starting to move forward");
	while(ros::ok())
	{
		pub.publish(msg);
		rate.sleep();
		ros::spinOnce();
	}
}

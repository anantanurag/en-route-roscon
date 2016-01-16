#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"

double x = 5.5;
bool flag = true;

void poseCallback(const turtlesim::PoseConstPtr& msg)
{
	ROS_INFO("x: %.2f, y: %.2f", msg->x, msg->y);
	if(msg->x - x > 1)
	{
		flag = false;
	}
}


int main(int argc, char** argv)
{

	const double FORWARD_SPEED_MPS = 1;
	const double ROTATE_SPEED_DEGPS = 1;
	
	ros::init(argc, argv, "move_turtle");
	ros::NodeHandle nh;

	ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);

	ros::Subscriber sub = nh.subscribe("turtle1/pose", 1, poseCallback);

	geometry_msgs::Twist msg;
	msg.linear.x = FORWARD_SPEED_MPS;
	msg.angular.z = 0;
	ros::Rate rate(0.5);
	ROS_INFO("Starting to move forward");
	// pub.publish(msg);
	// ros::spinOnce();
	// rate.sleep();

	// pub.publish(msg);
	// bool flag = false;
	while(ros::ok() && flag)
	{
		pub.publish(msg);
		rate.sleep();
		ros::spinOnce();
	}
	if(!flag)
	{
		msg.linear.x = 0;
		msg.angular.z = ROTATE_SPEED_DEGPS;
		pub.publish(msg);
	}
}

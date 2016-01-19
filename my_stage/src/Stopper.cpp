#include "Stopper.h"
#include "geometry_msgs/Twist.h"

Stopper::Stopper()
{
	keepMoving = true;

	commandPub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 10);

	laserSub = nh.subscribe("base_scan", 1, &Stopper::scanCallback, this);
}


void Stopper::moveForward()
{
	geometry_msgs::Twist msg;
	msg.linear.x = FORWARD_SPEED_MPS;
	commandPub.publish(msg);
};


void Stopper::scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan)
{
	int minIndex = ceil((MIN_SCAN_ANGLE_RAD));
	int maxIndex = floor((MAX_SCAN_ANGLE_RAD));
	int min_angle_Index = -1;
	float closestRange = scan->ranges[0];
	printf("%d and %d\n",minIndex, maxIndex );
	printf("%f\n", scan->angle_min);
	for(long long int currIndex = 1; currIndex <= maxIndex - minIndex; currIndex++)
	{
		// printf("%f\n", scan->ranges[currIndex]);
		if(scan->ranges[currIndex] < closestRange)
		{
			closestRange = scan->ranges[currIndex];
			min_angle_Index = currIndex;
		}
	}
	ROS_INFO_STREAM("Closest range: " << closestRange);
	printf("@ %d\n", min_angle_Index + min_angle_Index);

	if(closestRange < MIN_PROXIMITY_RANGE_M)
	{
		ROS_INFO("Stop!");
		keepMoving = false;
		geometry_msgs::Twist msg;
		msg.linear.x = 0;
		msg.angular.z = 100;
		commandPub.publish(msg);
		// ros::spinOnce();
		ros::Rate rate(2);
		rate.sleep();
		ros::spinOnce();
		keepMoving = true;

	}
}

void Stopper::startMoving()
{
	ros::Rate rate(10);
	ROS_INFO("Start moving");

	while(ros::ok() && keepMoving)
	{
		moveForward();
		ros::spinOnce();
		rate.sleep();
	}
}

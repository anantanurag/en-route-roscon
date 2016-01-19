#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"

class Stopper
{
public:
	// Tunable parameters
	const static double FORWARD_SPEED_MPS = 0.5;
	const static double MIN_SCAN_ANGLE_RAD = -10;
	const static double MAX_SCAN_ANGLE_RAD = +10;
	const static float MIN_PROXIMITY_RANGE_M = 5; // Should be smaller than sensor_msgs::LaserScan::range_max

	Stopper();
	void startMoving();

private:
	ros::NodeHandle nh;
	ros::Publisher commandPub;
	ros::Subscriber laserSub;
	bool keepMoving;

	void moveForward();
	void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan);
};

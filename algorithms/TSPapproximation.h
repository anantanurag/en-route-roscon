#include "ros/ros.h"
#include <cmath>
class TSPapprox
{
public:
	// Tunable parameters
	const static int NO_OF_POINTS = 5;
	static double x_coords[NO_OF_POINTS];
	static double y_coords[NO_OF_POINTS];
	static double init_x_global;
	static double init_y_global;

	TSPapprox();
	void getCoords();
	double calcTotalCost();
	void shortestPath();
	
private:
	ros::NodeHandle nh;
	ros::Publisher commandPub;
	ros::Subscriber laserSub;

	// void moveForward();
	// void scanCallback(------------------);
}
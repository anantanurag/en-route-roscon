#include "TSPapproximation.h"
#include "geometry_msgs/Twist"

TSPapprox::TSPapprox()
{
	commandPub = nh.advertise<eometry_msgs::Twist>("cmd_vel", 10);

	for(int i = 0; i < NO_OF_POINTS; i++)
	{
		x_coords[i] = y_coords[i] = 0;
	}

}

void TSPapprox::shortestPath(double* x_coords, double* y_coords)
{


// Very greedy algorithm

	double distance = 0, temp_distance;
	int index;
	// double sorted_x[NO_OF_POINTS];
	// double sorted_y[NO_OF_POINTS];

	double x_init = x_init_global, y_init = y_init_global;
	for(int j = 0; j < NO_OF_POINTS; j++)
	{
		distance = sqrt(pow(x_init - x_coords[j], 2) + pow(y_init - y_coords[j], 2));

		for(int i = 1 + j; i < NO_OF_POINTS; i++)
		{

			temp_distance = sqrt(pow(x_init - x_coords[i], 2) + pow(y_init - y_coords[i], 2));
			if(temp_distance < distance)
			{
				distance = temp_distance;
				index = i;
			}
		}

		x_init = x_coords[j];
		y_init = y_coords[j];

		x_coords[j] = x_coords[index];
		y_coords[j] = y_coords[index];

		x_coords[index] = x_init;
		y_coords[index] = y_init;


	}
}


double TSPapprox::calcTotalCost()
{
	double x_init = x_init_global, y_init = y_init_global;
	double totalDist = sqrt(pow(x_init - x_coords[0], 2) + pow(y_init - y_coords[0], 2));
	x_init = x_coords[0];
	y_init = y_coords[0];
	for(int i = 1; i < NO_OF_POINTS; i++)
	{
		totalDist += sqrt(pow(x_init - x_coords[i], 2) + pow(y_init - y_coords[i], 2));
	}

	return totalDist;
}
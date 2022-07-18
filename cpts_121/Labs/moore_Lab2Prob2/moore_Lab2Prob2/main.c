/*******************************************************************************************
Programmer: Devin Moore
Date:       2020/09/17
Class:      CptS121 Section 9 Andrew O'Fallon
Assignment: Lab 3 Problem 2

Description: Calculating the flight duration, and hight above ground of a projectile
			 when it reaches it's target.
*******************************************************************************************/


#include "calcLib.h"

int main(void)
{
	// Declaring Variables
	double velocity = 0.0,
		angle = 0.0,
		distance = 0.0,
		flight_duration = 0.0,
		landing_height = 0.0;

	// Printing greeting
	printf("Hello this program will calculate the duration, and landing height of some projectile\n\n");
	// 1. Prompting user for input and assigning it to the variables
	printf("please enter the projectiles Velocity as a real number: ");
	velocity = getDouble();
	printf("please Enter the distance the projectile traveled as a real number: ");
	distance = getDouble();
	printf("Please enter the projectiles launch angle in radians (1.571 = 90 degrees, 0 = 0 degrees): ");
	angle = getDouble();

	printf("Velocity: %lf\nDistance: %lf\nAngle: %lf\n", velocity, distance, angle);
	// 2. Calculating the flight duration
	flight_duration = flightDurationSeconds(velocity, angle, distance);

	// 3. Calculating the height of the projectile when it lands.
	landing_height = heightAfterLanding(velocity, angle, flight_duration);

    // 4. Printing flight duration to console.
	printf("Flight Duration: %.2lf\nHight of Projectile After Landing: %.2lf\n", flight_duration, landing_height);
	return (0);
}
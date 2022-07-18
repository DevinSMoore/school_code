/*******************************************************************************************
Programmer: Devin Moore
Date:       2020/09/17
Class:      CptS121 Section 9 Andrew O'Fallon
Assignment: Lab 3 Problem 2

Description: Calculating the flight duration, and hight above ground of a projectile
			 when it reaches it's target.
*******************************************************************************************/


#include "calcLib.h"

// This will take in a double from the user and return the value
double getDouble(void)
{
	double inputValue = 0.0;
	scanf("%lf", &inputValue);
	return inputValue;
}

// This will calculate the time to projectile landing and return the value
double flightDurationSeconds(double velocity, double angleInRadians, double distance)
{
	double time = 0.0;
	return time = ((distance) / (velocity * cos(angleInRadians)));
}

// This will calculate the height of your projectile when it lands and return the value
double heightAfterLanding(double velocity, double angleInRadians, double time)
{
	double height = 0.0;
	return height = (velocity * sin(angleInRadians) * time - ((G * pow(time, 2))));
}
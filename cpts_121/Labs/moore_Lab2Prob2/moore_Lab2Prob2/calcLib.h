/*******************************************************************************************
Programmer: Devin Moore
Date:       2020/09/17
Class:      CptS121 Section 9 Andrew O'Fallon
Assignment: Lab 3 Problem 2

Description: Calculating the flight duration, and hight above ground of a projectile 
			 when it reaches it's target.
*******************************************************************************************/

#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

#define G 32.17 // Gravitaional constant


// This will take in a double from the user and return the value
double getDouble(void);

// This will calculate the time to projectile landing and return the value
double flightDurationSeconds(double velocity, double angleInRadians, double distance);

// This will calculate the height of your projectile when it lands and return the value
double heightAfterLanding(double velocity, double angleInRadians, double time);

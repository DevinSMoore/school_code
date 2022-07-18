/////////////////////////////////////////////////////////////////////////////////
// Programmer: Devin Moore
// Assignment: Lab 2
// Class: CptS121 Section 9 Andrew O'Fallon
// 
// Description: Today we have three goals: 
//                  First is to create an algorithm 
//              that computes the slope-intercept form of the line bisecting
//              the line formed between two points given by the user. 
//                  Second is to compute the BMI when given a height (in feet),
//              and weight (in pounds) by the user. 
//                  Third is to compute the Bowl Championship Score of something
//				    I'll fix this later
/////////////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>


int main(void)
{
	// Initializing variables
	// Task 1
	double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0,
		slope = 0.0, y_mid = 0.0, x_mid = 0.0,
		perp_slope = 0.0, y_intercept = 0.0;
	// Task 2
	double weight = 0.0, bmi = 0.0, feet = 0.0, 
		height_in_inches = 0.0;
	// Task 3
	int harris_poll_score = 0, coaches_poll_score = 0;
	double computer_ranking = 0.0, harris_poll = 0.0,
		coaches_poll = 0.0, BCS_score = 0.0;

	// Task 1: Compute slope-intercept form of bisecting line.
	// 1. prompting and getting user input
	printf("Please input coordinates of two points: \n");
	printf("x1: ");
	scanf("%lf", &x1);
	printf("y1: ");
	scanf("%lf", &y1);
	printf("x2: ");
	scanf("%lf", &x2);
	printf("y2: ");
	scanf("%lf", &y2);

	// 2. Computing Slope of line
	slope = (y2 - y1) / (x2 - x1);

	// 3. Computing Midpoint of line
	y_mid = (y1 + y2) / 2;
	x_mid = (x1 + x2) / 2;

	// 4. Computing slope of line perpendicular to original line.
	perp_slope = (-1) * (1 / slope);

	// 5. Compute y-intercept of line perpendicular, and bisecting original line.
	y_intercept = y_mid - (perp_slope * x_mid);

	// 6. Outputing original coordinate pair, and slope-intercept of perpendicular line.
	printf("Original Coordinate pairs: \n1: (%.2lf, %.2lf)\n2: (%.2lf, %.2lf)\nEquation of line bisecting these points: y = %.2lf*x + %.2lf\n\n\n", x1, y1, x2, y2, perp_slope, y_intercept);

	// Task 2: Compute BMI
	// 1. Prompting and getting height in feet, and weight in pounds from user.
	printf("Please enter your height in feet, and your weight: \n");
	printf("Feet: ");
	scanf("%lf", &feet);
	printf("Weight: ");
	scanf("%lf", &weight);

	// 2. Convert height in feet to inches and find total height in inches.
	height_in_inches = (feet * 12);

	// 3. Compute BMI
	bmi = (weight / (pow(height_in_inches, 2))) * 703;

	// 4. Display value of BMI
	printf("Your BMI is : %lf\n\n\n", bmi);

	// Task 3: Computing Bowl Championship Series score
	// 1. Prompting user for harris, and coaches poll scores
	printf("Please enter a number between 1 and 2850 for the harris poll score: ");
	scanf("%d", &harris_poll_score);
	printf("Please enter a number between 1 and 1475 for the Coaches Poll Score: ");
	scanf("%d", &coaches_poll_score);
	
	// printf("Haris Score: %d\nCoaches Score: %d\n", harris_poll_score, coaches_poll_score); // for debugging

	// 2. Prompting for computer Ranking
	printf("Please enter the computers calculated ranking between 0 and 1: ");
	scanf("%lf", &computer_ranking);

	// 3. Calculating harris', and coaches poll ranking
	harris_poll = harris_poll_score / (double)2850;
	coaches_poll = coaches_poll_score / (double)1475;

	// printf("harris_poll value: %.2lf\ncoaches_poll value: %.2lf\n", harris_poll, coaches_poll); // For debugging

	// 4. Computing BCS score
	BCS_score = (harris_poll + coaches_poll + computer_ranking) / 3;

	// 5. Printing BCS score
	printf("Calculated Bowl Championship Series Score of your team: %.2lf\n", BCS_score);

	

	return 0;
}
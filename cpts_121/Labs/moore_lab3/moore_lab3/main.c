/*******************************************************************************************
Programmer: Devin Moore
Date:       2020/09/17
Class:      CptS121 Section 9 Andrew O'Fallon TA: Muthuu Svs
Assignment: Lab 3

Description: First Problem: Redoing our BMI calculation from last week with functions.
*******************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>	
#include <math.h>

int main(void)
{


	// Initializing Variables
	double weight = 0.0, bmi = 0.0, height_in_feet = 0.0,
		height_in_inches = 0.0;

	// Prototyping Functions
	// Gets height in feet from user as a real number then returns the value
	double get_height(void);
	// Gets weight in pounds from user as a real number then returns the value
	double get_weight(void);
	// Converts the provided height to inches then returns the value
	double convert_height_to_inches(double height_in_feet);
	// Calculates BMI and returns the value.
	double calculate_bmi(double weight_in_pounds, double height_in_feet);
	// Prints the BMI into console
	void display_bmi(double bmi);


	// 1. Prompting and getting height in feet, and weight in pounds from user.
	printf("Please enter your height in feet, and your weight: \n");
	printf("Feet: ");
	height_in_feet = get_height();
	printf("Weight: ");
	weight = get_weight();

	// 2. Compute BMI
	bmi = calculate_bmi(weight, height_in_feet);

	// 4. Display value of BMI
	display_bmi(bmi);

}

// Defining Functions

	// Prototyping Functions
// Gets height in feet from user as a real number then returns the value
double get_height(void)
{
	double feet = 0.0;
	return scanf("%lf", &feet);
}
// Gets weight in pounds from user as a real number then returns the value
double get_weight(void)
{
	double pounds = 0.0;
	return scanf("%lf", &pounds);
}

// Converts the provided height to inches then returns the value
double convert_height_to_inches(double height_in_feet)
{
	double height_in_inches = 0.0;
	return height_in_inches = (height_in_feet * 12);
}

// Calculates BMI and returns the value.
double calculate_bmi(double weight_in_pounds, double height_in_feet)
{
	double bmi = 0.0;
	return bmi = (weight_in_pounds / (pow(convert_height_to_inches(height_in_feet), 2))) * 703;
}

// Prints the BMI into console
void display_bmi(double bmi)
{
	printf("Your BMI is : %lf\n", bmi);
}
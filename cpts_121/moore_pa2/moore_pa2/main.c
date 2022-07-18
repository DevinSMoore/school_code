/*******************************************************************************************
Programmer: Devin Moore
Date:       2020/09/12
Class:      CptS121 Section 9 Andrew O'Fallon
Assignment: Program Assignment 2

Description: This program expands on the work we did in PA1. We will be moving the
calculations to functions, and employing a 3 file method of program orginization.
Everything is basically the same in main.c except the equations were replaced 
by the functions.
*******************************************************************************************/

#include "equations.h"

int main(void) {

	// Subtask 1: The following block of code will find the equivalent resistance of 3 resistors in series.
	// 1. Prompting user for resistance values
	printf("Please enter the values of your 3 resistors (as integers): \n");

	int R1 = 0, R2 = 0, R3 = 0;
	// 2. Getting the values for equivalent resistance.
	scanf("%d%d%d", &R1, &R2, &R3);

	double series_resistance = 0;
	// 3. calling series_resistance function to calculate
	series_resistance = calculate_series_resistance(R1, R2, R3);

	// 4. Printing the result of the calculation into the cosole.
	printf("Equivalent Series Resistance: R1 + R2 + R3 = (%d) + (%d) + (%d) = %.2lf\n", R1, R2, R3, series_resistance);


	// Subtask 2: The following block of code will find the sales tax for the price, and sales tax percent provided.
	// 1. Prompting user for price of item, and sales tax.
	printf("\n\nPlease enter the cost of your item, and then the percent sales tax: \n");


	double item_cost = 0, sales_tax_percent = 0, sales_tax_rate = 0, total_sales_tax = 0;
	// 2. Getting price of item, and sales tax in sequence. This is mostly just for style, and I do this for every prompt/get sequence except for the resistor values.
	printf("Cost of Item: ");
	scanf("%lf", &item_cost);
	printf("Sales tax Percent: ");
	scanf("%lf", &sales_tax_percent);

	// 3. Calculating sales tax.
	total_sales_tax = calculate_total_sales_tax(item_cost, computeSalesTaxRate(sales_tax_percent));

	// 4. Printing sales tax to console.
	printf("Sales tax for that item: (Cost of Item) X (Sales Tax Rate) = (%.2lf) X (%.2lf) = %.2lf\n\n", item_cost, sales_tax_rate, total_sales_tax);


	// Subtask 3: The following chunk of code will calculate the volume of a right rectangular pyramid.
	double length = 0, width = 0, height = 0;
	// 1. Prompting and getting the values for length, width, and height.
	printf("\nPlease enter the length, width, and height of your pyramid as real numbers: \n");
	printf("Length: ");
	scanf("%lf", &length);
	printf("width:  ");
	scanf("%lf", &width);
	printf("height: ");
	scanf("%lf", &height);

	double volume_pyramid = 0;
	// 2. Calculating the volume of the pyramid.
	volume_pyramid = computeVolumeOfPyramid(length, width, height);

	// 3. Printing value of volume to console.
	printf("Volume of pyramid: (Length) X (Width) X (Height) / 3 = (%.2lf) X (%.2lf) X (%.2lf) / 3 = %.2lf\n", length, width, height, volume_pyramid);

	// Subtask 4: The following calculation will find the equivalent resistance of 3 resistors in parallel.
	// 1. Prompting user for resistance values
	printf("\n\nPlease enter the values of your 3 resistors (as integers): \n");

	// 2. Getting the values for equivalent resistance.
	scanf("%d%d%d", &R1, &R2, &R3);

	double parallel_resistance = 0;
	// 3. calling the function computeParallelResistance to compute the value.
	parallel_resistance = computeParallelResistance(R1, R2, R3);

	// 4. Printing Value of parallel equivalent resistance.
	printf("Equivalent parallel resistance: (1 / ((1/R1) + (1/R2) + (1/R3)) = (1 / ((1/%d) + (1/%d) + (1/%d)) = %.2lf\n", R1, R2, R3, parallel_resistance);


	// Subtask 5: This chunk of code is about the relationship between the characters we see when we code
	// and the integer values that they are stored as.

	char plaintext_character = '\0', encoded_character = '\0'; // Initializing char values with [NULL]
	int shift_int = 0;
	// 1. Prompting and getting a character, and an integer
	printf("\n\nPlease enter a character upper, or lower case: ");
	scanf(" %c", &plaintext_character); // Space in front of here stop program from setting incorrect values 

	printf("Please enter an integer: ");
	scanf("%d", &shift_int);


	// printf("Value of \"plaintext_character\": %c\n\n", plaintext_character); // Used for debugging

	// 2. Evaluating the equations with the input values.
	encoded_character = computeEncodedCharacter(plaintext_character, shift_int);

	// 3. Printing encoded_character to console.
	printf("Encoded Character: ((Character Entered) - 'a') + ('A' - (Integer Entered)) = ((%c) - 'a') + ('A' - (%d)) = %c\n\n\n", plaintext_character, shift_int, encoded_character);

	// Subtask 6: This chunk of code finds the distance between two points.

	double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	// 1. Prompting and getting user for the two sets of coordinates.
	printf("Please enter the coordinates of your two points as real numbers:\n");
	printf("x1: ");
	scanf("%lf", &x1);
	printf("x2: ");
	scanf("%lf", &x2);
	printf("y1: ");
	scanf("%lf", &y1);
	printf("y2: ");
	scanf("%lf", &y2);

	double distance = 0;
	// 2. Calculating the distance between the points
	distance = computeDistanceBetweenPoints(x1, y1, x2, y2);

	// 3. Displaying result to user.
	printf("Distance between the two points: sqrt[(x1-x2)^2 + (y1-y2)^2] = sqrt[(%.2lf-%.2lf)^2 + (%.2lf-%.2lf)^2] = %.2lf\n\n", x1, x2, y1, y2, distance);

	// Subtask 7: finding the result of a general equation

	int a = 0;
	double x = 0, y = 0, z = 0;
	// 1. Prompting and getting values for a, x, y, and z.
	printf("\nPlease enter an integer value for a: \na = ");
	scanf("%d", &a);
	printf("Please enter real values for x, y, and z:\nx = ");
	scanf("%lf", &x);
	printf("y = ");
	scanf("%lf", &y);
	printf("z = ");
	scanf("%lf", &z);

	double temp_y = y; // this is so I can store the value of 'y' before it gets set to a new value below.
	// 2. Calculating the value of y
	y = computeValueForY(a, x, y, z);

	// 3. Printing the result to console.
	printf(" y = (y / (3/17)) - z + (x / (a %% 2)) + pi) = (%.2lf / (3/17)) - %.2lf + (%.2lf / (%d %% 2)) + pi) = %.2lf\n", temp_y, z, x, a, y); // double percent (%%) lets printf actually print a %.


	return(0); // Returning control to operating system.
}
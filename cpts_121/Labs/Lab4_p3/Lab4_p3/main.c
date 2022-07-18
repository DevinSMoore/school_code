////////////////////////////////////////////////////////
// Name: Devin Moore
// Class: CptS121 Section 9 Andrew O'Fallon
// TA: Muthuu Svs
// 
// Description: Will print the average, max, or min
//				values of a set depending on user input
////////////////////////////////////////////////////////

#include "Calculations.h"

int main(void)
{
	// 1. Declaring variables

	FILE* infile = fopen("InputFile.txt", "r");
	FILE* outfile = fopen("OutputFile.txt", "w");

	double num1 = 0.0, num2 = 0.0, num3 = 0.0, num4 = 0.0, num5 = 0.0,
		sum = 0.0, average = 0.0, max = 0.0, min = 0.0;

	// 2. Reading data from file
	num1 = read_double(infile);
	num2 = read_double(infile);
	num3 = read_double(infile);
	num4 = read_double(infile);
	num5 = read_double(infile);

	int userInput = 0;
	// 3. Prompting user for action
	printf("Please enter 1 to print average, 2 to print max value, 3 to print min value: ");
	scanf("%d", &userInput);

	switch(userInput) {
		case 1:
			average = calculate_mean(calculate_sum(num1, num2, num3, num4, num5), NUMBER_OF_ELEMENTS);
			printf("Average: %.2lf", average);
			break;
		case 2:
			max = find_max(num1, num2, num3, num4, num5);
			printf("Max value: %.2lf", max);
			break;
		case 3:
			min = find_min(num1, num2, num3, num4, num5);
			printf("Min value: %.2lf", min);
			break;
	}

	fclose(infile);
	fclose(outfile);

	return (0);
}
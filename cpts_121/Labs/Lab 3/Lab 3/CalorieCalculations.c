//////////////////////////////////////////////////
// Name: Devin Moore
// Class: CptS121 Section 9 Andrew O'Fallon
// TA: Muthuu Svs
// 
// Description: Creating a program that will take
// in information from the user and return 
// their daily caloric needs.
//////////////////////////////////////////////////


#include "CalorieCalc.h"

// Precondition: a double value has been passed which represents height in feet
// height in inches returned as a  double.
double convert_height_to_inches(double height_in_feet)
{
	double height_in_inches = 0.0;
	return height_in_inches = (height_in_feet * 12);
}

// Precondition: weight, height, gender, and age have been input, and passed as actual arguments
// Basal Metabolic Rate returned as a  double.
double calculate_bmr(double weight_in_pounds, double height_in_inches, char gender, double age)
{
	double bmr = 0.0;
	if (gender == 'f')
	{
		bmr = 655 + (4.35 * weight_in_pounds) + (4.7 * height_in_inches) - (4.7 * age);
	}
	else
	{
		bmr = 66 + (6.23 * weight_in_pounds) + (12.7 * height_in_inches) - (6.8 * age);
	}
	return bmr;
}

// Precondition: bmr has been calculated, and exercise level recieved from file/user
// Calories required returned as a double
double calculate_calories(double bmr, int exercise_level)
{
	double bmr_scalar = 0.0;

	switch(exercise_level)
	{
		case (0):
			bmr_scalar = 1.2;
			break;
		case (1):
			bmr_scalar = 1.375;
			break;
		case (2):
			bmr_scalar = 1.55;
			break;
		case (3):
			bmr_scalar = 1.725;
			break;
		case (4):
			bmr_scalar = 1.9;
			break;
	}

	return (bmr * bmr_scalar);

}

/*
* Function: print_double()
* Date Created: 2020/09/24
* Last Modified: 2020/09/24
* Description: Prints a double value to the file (to the hundreths place)
* Input Parameters:
* FILE *outfile
* double number
* Returns: VOID
* Precondition: outfile has be opened and passed as an argument along with number to be printed
* Postcondition: Value has been printed to the outfile to the hundreths place
*/
void file_print_double(FILE* outfile, double number)
{
	fprintf(outfile, "%.2lf\n", number);
}

/*
* Function: read_double()
* Date Created: 2020/09/24
* Last Modified: 2020/09/24
* Description: Reads a single double value from a file
* Input Parameters: FILE *infile
* Returns: Double value from file
* Precondition: Input file has been opened and passed as an argument.
* Postcondition: Double value will be returned
*/
double read_double(FILE* infile)
{
	double double_value = 0.0;
	fscanf(infile, "%lf", &double_value);
	return double_value;
}

/*
* Function: read_integer()
* Date Created: 2020/09/24
* Last Modified: 2020/09/24
* Description: Reads a single integer value from a file
* Input Parameters: FILE *infile
* Returns: Integer value
* Precondition: Input file is open and has been passed as an argument
* Postcondition: An integer value will be returned
*/
int read_int(FILE* infile)
{
	int int_value = 0;
	fscanf(infile, "%d", &int_value);
	return int_value;
}

/*
* Function: read_char()
* Date Created: 2020/09/24
* Last Modified: 2020/09/24
* Description: Reads a single integer value from a file
* Input Parameters: FILE *infile
* Returns: Integer value
* Precondition: Input file is open and has been passed as an argument
* Postcondition: An integer value will be returned
*/
char read_char(FILE* infile)
{
	char char_value = '\0';
	fscanf(infile, " %c", &char_value);
	return char_value;
}

/*
* Function: calculate_sum()
* Date Created: 2020/09/24
* Last Modified: 2020/09/24
* Description: Calculates the sum of a set of 5 numbers
* Input Parameters:
* double number1
* double number2
* double number3
* double number4
* double number5
* Returns: Double value
* Precondition: All double values have been read by the file and passed as arguments
* Postcondition: Sum of numbers passed
*/
double calculate_sum(double number1, double number2, double number3, double number4, double number5)
{
	return (number1 + number2 + number3 + number4 + number5);
}
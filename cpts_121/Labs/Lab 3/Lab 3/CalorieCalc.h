#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>


/*
* Function: read_double()
* Date Created: 2020/09/16
* Last Modified: 2020/09/16
* Description: Reads a single double value from a file
* Input Parameters: FILE *infile
* Returns: Double value from file
* Precondition: Input file has been opened and passed as an argument.
* Postcondition: Double value will be returned
*/
//////////////////////////////////////////////////
// Name: Devin Moore
// Class: CptS121 Section 9 Andrew O'Fallon
// TA: Muthuu Svs
// 
// Description: Creating a program that will take
// in information from the user and return 
// their daily caloric needs.
//////////////////////////////////////////////////


double read_double(FILE* infile);

/*
* Function: read_integer()
* Date Created: 2020/09/16
* Last Modified: 2020/09/16
* Description: Reads a single integer value from a file
* Input Parameters: FILE *infile
* Returns: Integer value
* Precondition: Input file is open and has been passed as an argument
* Postcondition: An integer value will be returned
*/
int read_int(FILE* infile);

/*
* Function: calculate_sum()
* Date Created: 2020/09/16
* Last Modified: 2020/09/22
* Description: Calculates the sum of a set of 5 numbers
* Input Parameters:
* double number1
* double number2
* double number3
* double number4
* double number5
* Returns: Double value
* Precondition: All double values have been read by the file and passed as arguments
* Postcondition: Sum of numbers returned
*/
double calculate_sum(double number1, double number2, double number3, double number4, double number5);

// Precondition: a double value has been passed which represents height in feet
// height in inches returned as a  double.
double convert_height_to_inches(double height_in_feet);

// Precondition: weight, height, gender, and age have been input, and passed as actual arguments
// Basal Metabolic Rate returned as a  double.
double calculate_bmr(double weight_in_pounds, double height_in_inches, char gender, double age);

// Precondition: bmr has been calculated, and exercise level recieved from file/user
// Calories required returned as a double
double calculate_calories(double bmr, int exercise_level);

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
char read_char(FILE* infile);

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
void file_print_double(FILE* outfile, double number);
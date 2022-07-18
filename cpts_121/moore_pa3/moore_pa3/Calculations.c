/*******************************************************************************************
Programmer: Devin Moore
Date:       2020/09/16
Class:      CptS121 Section 9 Andrew O'Fallon
Assignment: Program Assignment 3

Description: This program will read student data from a file, calculate the mean, and
             deviations of certain subesets of this data then print to an output file.
*******************************************************************************************/

#include "Calculations.h"

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
double read_double(FILE* infile)
{
    double double_value = 0.0;
    fscanf(infile, "%lf", &double_value);
    return double_value;
}

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
int read_int(FILE* infile)
{
    int int_value = 0;
    fscanf(infile, "%d", &int_value);
    return int_value;
}

/*
* Function: calculate_sum()
* Date Created: 2020/09/16
* Last Modified: 2020/09/16
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

/*
* Function: calculate_mean()
* Date Created: 2020/09/16
* Last Modified: 2020/09/16
* Description: Calculates the mean of a set of numbers (in this case 5 but it should be the size of your set)
*              and checks to see if the 'number' var is 0.
* Input Parameters:
* double sum
* int number
* Returns: double values
* Precondition: sum has been calulated and passed along with the number of elements in the set
* Postcondition: Calculated mean will be returned as a double. Or '-1.0' if 'number' actual argument is 0
*/
double calculate_mean(double sum, int number)
{
    if (number == 0)
    {
        return (-1.0);
    }
    return (sum / number);
}

/*
* Function: calculate_deviation()
* Date Created: 2020/09/16
* Last Modified: 2020/09/16
* Description: Calculates the deviation from the mean for the provided number
* Input Parameters:
* double mean
* doulbe number
* Returns: double value
* Precondition: Mean has be calculated and passed along with the number being compared to
* Postcondition: Deviation for that number has been returned
*/
double calculate_deviation(double mean, double number)
{
    return (number - mean);
}

/*
* Function: calculate_variance()
* Date Created: 2020/09/16
* Last Modified: 2020/09/22
* Description: Calculates the variance of the set of data by finding the mean of the squares of the deviations from the mean for each student
* Input Parameters:
* double number1
* double number2
* double number3
* double number4
* double number5
* int number
* Returns: double variance
* Precondition: deviation from mean calculated then passed along with the number of elements in your set
* Postcondition: Value of variance has been returned
*/
double calculate_variance(double number1, double number2, double number3, double number4, double number5, int number)
{

    return calculate_mean((pow(number1, 2) + pow(number2, 2) + pow(number3, 2) + pow(number4, 2) + pow(number5, 2)), number);
    // return ((pow(number1, 2) + pow(number2, 2) + pow(number3, 2) + pow(number4, 2) + pow(number5, 2)) / number);
}

/*
* Function: calculate_standard_deviation()
* Date Created: 2020/09/16
* Last Modified: 2020/09/16
* Description: will calculate the standard deviation of our data set
* Input Parameters:
* double variance
* Returns: double value of standard deviation
* Precondition: Variance has been calculated and passed as an argument
* Postcondition: value of Standard Deviation will be returned
*/
double calulate_standard_deviation(double variance)
{
    return sqrt(variance);
}

/*
* Function: find_max()
* Date Created: 2020/09/16
* Last Modified: 2020/09/16
* Description: determines the highest value number of the passed set of values
* Input Parameters:
* double number1
* double number2
* double number3
* double number4
* double number5
* Returns: double number
* Precondition: Numbers have been read from file and passed as arguments
* Postcondition: Highest value has been determined and returned.
*/
double find_max(double number1, double number2, double number3, double number4, double number5)
{
    double compare_value = number1;
    if (number2 >= compare_value)
    {
        compare_value = number2;
    }
    if (number3 >= compare_value)
    {
        compare_value = number3;
    }
    if (number4 >= compare_value)
    {
        compare_value = number4;
    }
    if (number5 >= compare_value)
    {
        compare_value = number5;
    }
    return compare_value;
}

/*
* Function: find_min()
* Date Created: 2020/09/16
* Last Modified: 2020/09/16
* Description: determines the lowest value number of the passed set of values
* Input Parameters:
* double number1
* double number2
* double number3
* double number4
* double number5
* Returns: double number
* Precondition: Numbers have been read from file and passed as arguments
* Postcondition: Lowest value has been determined and returned.
*/
double find_min(double number1, double number2, double number3, double number4, double number5)
{
    double compare_value = number1;
    if (number2 <= compare_value)
    {
        compare_value = number2;
    }
    if (number3 <= compare_value)
    {
        compare_value = number3;
    }
    if (number4 <= compare_value)
    {
        compare_value = number4;
    }
    if (number5 <= compare_value)
    {
        compare_value = number5;
    }
    return compare_value;
}

/*
* Function: print_double()
* Date Created: 2020/09/16
* Last Modified: 2020/09/16
* Description: Prints a double value to the file (to the hundreths place)
* Input Parameters:
* FILE *outfile
* double number
* Returns: VOID
* Precondition: outfile has be opened and passed as an argument along with number to be printed
* Postcondition: Value has been printed to the outfile to the hundreths place
*/
void print_double(FILE* outfile, double number)
{
    fprintf(outfile, "%.2lf\n", number);
}
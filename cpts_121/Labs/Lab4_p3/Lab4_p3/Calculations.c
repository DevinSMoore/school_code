//////////////////////////////////////////////////
// Name: Devin Moore
// Class: CptS121 Section 9 Andrew O'Fallon
// TA: Muthuu Svs
// 
// Description: Creating a program that will take
// in information from the user and return 
// their daily caloric needs.
//////////////////////////////////////////////////

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
* Function: print_double()
* Date Created: 2020/09/24
* Last Modified: 2020/09/24
* Description: Prints a double value to the console (to the hundreths place)
* Input Parameters:
* double number
* Returns: VOID
* Precondition: number has passed as an argument
* Postcondition: Value has been printed to the console to the hundreths place
*/
void print_double(double number)
{
    printf("%.2lf\n", number);
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
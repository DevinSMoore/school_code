#include "factorial.h"

// finds the factorial of the passed number.
// Precondition: value is read in from user and passed as argument.
// Postcondition: factorial of passed value has been returned to user as integer.
int findFactorial(int inputNumber)
{
	int factorial = 1;
	for (int i = inputNumber; i > 0 ; i--)
		factorial *= i;
	return(factorial);
}
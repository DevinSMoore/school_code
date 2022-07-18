#include "factorial.h"


int main(void) {
	int result = 0, userInputInt = 0, sentinel = 0; // Initializing variables
	// this just makes sure that the input to the scanf is a valid one.
	{
		printf("Please Enter the number: "); // prompting user and getting input
		sentinel = scanf("%d", &userInputInt); 
	} while (sentinel = 0);

	result = findFactorial(userInputInt); // computes the factorial
	printf("Factorial of %d is: %d\n", userInputInt, result); // prints result to user
	
	return 0;
}


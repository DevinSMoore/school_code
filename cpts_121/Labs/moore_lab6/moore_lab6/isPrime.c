///////////////////////////////////////////////////////////
// Name: Devin Moore
// Class: CptS121 Andrew O'Fallon
// TA: Muthuu Svs
// Date: 2020/10/08
//
// Description: Write a program that takes in an int from
//				a file and determines if the sum of the 
//				digits of the integer is a prime number.
///////////////////////////////////////////////////////////
#include "isPrime.h"


// this will check if the number is prime.
// precondition: positive integer has been passed
// postcondition: returns 1 if prime 0 if not.
int isPrime(int sum)
{
	for (int i = 2; i < sum; i++)
	{
		if ((sum % i) == 0) // This checks to see if any number less than the sum but greater than 1 is evenly divisible by the sum, if so returns 0
		{
			return 0;
		}
	}
	return 1;
}

// this will sum integers of a passed file
// precondition: File has been opened and passed
// postcondition: returns sum of integers in file
int sumIntegers(FILE* infile)
{
	int nextInteger = 0, sum = 0;
	while (!feof(infile))
	{

		fscanf(infile, "%d", &nextInteger);
		sum += nextInteger;
	}
	return sum;
}

// this will sum the digits of the passed number.
// precondition: positive integer has been passed.
// postcondition: returns sum of digits as an integer.
int sumDigits(int number)
{
	int sum = 0, num = 0;
	num = number;
	while (num != 0)
	{
		sum += (num % 10);
		num /= 10;
	}
	return sum;
}

//void displayIsPrime(int sumInteger, int sumDigits, int isPrime)
//{
//	printf("Sum of digits of %d is %d\n", sumInteger, sumDigits);
//	if (isPrime == 1) {
//		printf("%d is a prime number\n", sumDigits);
//	}
//	else {
//		printf("%d is not a prime number\n", sumDigits);
//	}
//}
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printBinary(int number)
{
	int binDig = 0;
	for (int i = 31; i >= 0; --i) { //starting at the most significant bit
		binDig = 0;
		if (((number) / pow(2, i)) >= 1) // if the remainder of num / 2^i is greater than 1 then the binary digit at that spot will print 1
		{
			binDig = 1;
			number -= (int)pow(2, i);
		}
		if (((i + 1) % 4) == 0 && i < 31) { printf(" "); } // adds a space after every nibble 

		printf("%d", binDig);
	}
	printf("\n");
}


int rightShiftFour(int number) {
	number = number >> 0b0100; // simple right shift by 0100 = 4
	return number;
}

int power2(int number, int exponent)
{
	number = number << exponent; // assigns to number the number shifted left by 'exponent' amount
	return number;
}

int packCharacters(const char array[], unsigned int storageInt)
{
	int i = 0;
	printf("\n");
	for (; i < 3; i++)
	{
		printf("before OR operation:\t");
		printBinary(storageInt);
		
		storageInt = storageInt | array[i];
		
		printf("After OR operation:\t");
		printBinary(storageInt);
		
		storageInt = storageInt << 8;
		
		printf("after shift:\t\t");
		printBinary(storageInt);
		printf("\n");
	}
	storageInt = storageInt | array[3];
	printf("After final OR operation:\t");
	printBinary(storageInt);
	printf("\n");
	return storageInt;
}

int main(void)
{
	srand((unsigned int)time(NULL));
	
	// part 1 of lab
	unsigned int numberToShift = 35;
	printf("Part 1 test Value before shift: %d\n", numberToShift);
	printf("Value before shift:\t");
	printBinary(numberToShift);
	numberToShift = rightShiftFour(numberToShift);
	printf("Value after shift:\t");
	printBinary(numberToShift);
	printf("Part 1 test Value after shift: %d\n", numberToShift);
	system("pause");
	
	// part 2 of lab
	system("cls");
	numberToShift = 35;
	int amountToShift = 2;
	printf("shifting by %d units to the left.\n", amountToShift);
	printf("Part 2 test Value before shift: %d\n", numberToShift);
	printf("Binary Value before shift:\t");
	printBinary(numberToShift);
	numberToShift = power2(numberToShift, amountToShift);
	printf("Binary Value after shift:\t");
	printBinary(numberToShift);
	printf("Part 2 test Value after shift: %d\n", numberToShift);
	system("pause");

	// part 3 of lab
	system("cls");
	char charArray[4] = { '\0', '\0', '\0', '\0' };
	int sentinalVal = 0;
	printf("please enter 4characters to shift into the unsigned integer\n");
	
	sentinalVal = scanf(" %c%c%c%c", &charArray[0], &charArray[1], &charArray[2], &charArray[3]);

	numberToShift = 0;
	printf("Part 3 unsigned int Value before shift: %d\n", numberToShift);
	printf("Binary Value before shift:\t");
	printBinary(numberToShift);
	for (int i = 0; i < 4; i++) {
		printf("char[%d]: %c\n", i, charArray[i]);
	printf("ASCII val of char[%d]: %d\n", i, charArray[i]);
	printf("Binary representation of char[%d] before fill:\t", i);
	printBinary(charArray[i]);
	}
	numberToShift = packCharacters(charArray, numberToShift);
	printf("Binary Value after fill:\t");
	printBinary(numberToShift);
	for (int i = 0; i < 4; i++) {
		printf("char[%d]: %c\n", i, charArray[i]);
		printf("ASCII val of char[%d]: %d\n", i, charArray[i]);
		printf("Binary representation of char[%d] after fill:\t", i);
		printBinary(charArray[i]);
	}
	printf("Part 3 unsigned int Value after fill: %d\n", numberToShift);
	system("pause");


	return 0;
}

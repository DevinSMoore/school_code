#include "lab8.h"


// Will take in an array and fill (overwrite) the items in the array with the list of ints in the file
// Postcondition: array is filled with every element in the file and size of array is returnd as an integer.
// MAX ARRAY SIZE = 100
int intakeArray(int intArray[], FILE* infile)
{
	int sentinal = 0, num = 0, counter = 0;
	do
	{
		printf("Begining of while loop\nValue of counter: %d\n", counter);
		sentinal = fscanf(infile, "%d", &num);
		intArray[counter] = num;
		printf("list[%d]: %d\n", counter, intArray[counter]);


		counter++;
		printf("counter: %d\n", counter);
		printf("sentinal: %d\n\n", sentinal);
	} while (sentinal != EOF);
	printf("counter: %d\n", counter);

	return (counter - 1); // this will return the size of the array which is the number of times it runs through  the loop -1
}

// Postcondition: Array order has been mirrored. i.e. { 1, 2, 3 } goes to { 3, 2, 1 }
// MAX ARRAY SIZE = 100
void arraySwapper(int intArray[], int size)
{
	int startIndex = 0, endIndex = size - 1, swapVar = 0;

	while (startIndex <= endIndex)
	{
		swapVar = intArray[startIndex];
		intArray[startIndex] = intArray[endIndex];
		intArray[endIndex] = swapVar;

		startIndex++;
		endIndex--;

	}


}

// will print array of data type integer to screen
void printIntArray(int intArray[], int size)
{
	printf("Begin list\n");
	for (int i = 0; i < size; i++)
	{
		printf("list[%d]: %d\n", i, intArray[i]);
	}
	printf("End list\n\n");
}

// Will fill an imported array with random integers between 1 and 100
void fillArrayRand(int intArray[])
{
	for (int index = 0; index < PROB_2_SIZE; index++)
	{
		intArray[index] = (rand() % 100) + 1;
	}
}

// Will fill a new array counting the number of times eache number 1-100 is in the imported array.
void numberCounter(int intArray[], int countingArray[])
{
	for (int index = 0; index < PROB_2_SIZE; index++)
	{
		countingArray[intArray[index]]++;
	}
}

// Will fill an imported array with a specified integer
void fillArrayChar(char charArray[], int size, int fillInt)
{
	for (int index = 0; index < size; index++)
	{
		charArray[index] = fillInt;
	}
}

// Will check if we've reached the win condition
// Will return 0 if we have not won, 1 if we have.
int winCheck(char wordArray[], char guessArray[], int arraySize)
{
	int victory = 0;
	for (int index = 0; index < arraySize; index++) {
		if (wordArray[index] != guessArray[index]) { // will check if any elements doen't match, if so it will break out of the loop and 0 will be returned
			break;
		}
		else {
			victory = 1;
			break;
		}
	}
	return victory;
}

// Will check to see if the guess is correct will incriment wrongGuessCounter if guess is incorrect.
// Will return 1 if guess is correct, 0 if incorrect
int guessCheck(char guess, char word[], char guessStorageArray[], int* guessCounter, int arraySize)
{
	int guessRight = 0;
	for (int index = 0; index < arraySize; index++)
	{
		if (guess == word[index]) // if the letter is in the word it will assign that same element of the array in the guess array to that letter
		{
			guessStorageArray[index] = guess;
			guessRight++;
			printf("guessRight: %d", guessRight);
		}
	}
	if (guessRight == 0) // Players guess was incorrect and guess
	{
		--* guessCounter;
		return 0;

	}
	else // Players guess was correct
	{
		return 1;
	}

}

// Will get guess from user
char userGuess()
{
	int check = 0;
	char guessChar = '\0';
	printf("Please enter a letter to guess the word: ");
	do
	{
		check = scanf(" %c", &guessChar);
	} while (check != 0);

	printf("guessChar: %c", guessChar);
	return guessChar;

}


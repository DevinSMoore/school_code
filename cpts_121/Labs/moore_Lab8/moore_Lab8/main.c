#include "lab8.h"

int main(void)
{
	// Declaring file, and array
	FILE* infile = NULL;
	int list[100] = { 0 }, trackingArray[101] = { 0 }, size = 0;
	
	// filling tracking array with -1 -> -1 denotes that the number was not in the array provided
	// fillArrayInt(trackingArray, PROB_2_SIZE + 1, -1);
	// printIntArray(trackingArray, PROB_2_SIZE + 1);

	srand((unsigned)time(NULL)); // Seeding rand() with time()

	// Opening file
	infile = fopen("newData.txt", "r");
	
	if (infile != NULL)
	{
		// Taking in array
		size = intakeArray(list, infile);
		printf("\nImported array:\n");
		printIntArray(list, size);
		// closing file
		fclose(infile);

		printf("\n"); // just printing a new line to seperate arrays a little
		// Mirroring imported array
		arraySwapper(list, size);
		printf("\nMirrored array: \n");
		printIntArray(list, size); // printing array to console
	}

	// begining of part 2
	system("pause");
	system("cls");


	// filling the array with random numbers
	
	fillArrayRand(list);
	printf("\nInteger Array:\n");
	printIntArray(list, PROB_2_SIZE);
	// printf("\nTracking Array:\n");
	// printIntArray(trackingArray, (PROB_2_SIZE + 1)); // tracking array is one larger than the filled array
	numberCounter(list, trackingArray);
	printf("\nPost count Tracking Array:\n");
	printIntArray(trackingArray, (PROB_2_SIZE + 1));


	// begining of part 3
	system("pause");
	system("cls");

	int wrongGuessCount = 0, * ptr_wrongGuessCount = &wrongGuessCount;
	char word[20] = { 'a','p','p','l','e' }, guessed[20] = { '\0' }, guess;	// hardcoded guess word: apple
	size = 5; // hardcoded word size

	guess = userGuess();
	guessCheck(guess, word, guessed, &guess, size);



	return 0;
}
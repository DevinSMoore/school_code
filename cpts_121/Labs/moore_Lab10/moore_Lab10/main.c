/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name: Devin Moore
//	Class: CptS121 Andrew O'Fallon
//	TA: Muthuu Svs
//
//	Assignment: Lab 10
//	Description: 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> // for printf()
#include <stdlib.h> // for srand() and rand9)
#include <time.h> // for time()
#include <string.h> // for strn commands

#define NUM_SENTENCES 20


// precondition: Sentence array has enough space for a new word.
void concatonateRandomWord(char sentenceArray[], char* wordArray[])
{
	strcat(sentenceArray, wordArray[rand() % 5]); // will chose a randow word from the array and concatinate it on the right to the input array
	strcat(sentenceArray, " "); // adding a space to the end of the previous word
}

int main(void) 
{
	srand((unsigned int)time(NULL)); // seeding random number generator

	// Initializing arrays with words
	char *article[5] = {"the", "a", "one", "some", "any"}; // Articles

	char *noun[5] = {"boy", "girl", "dog", "town", "car"}; // Nouns

	char *verb[5] = {"drove", "jumped", "ran", "walked", "skipped"}; // Verbs
	
	char *preposition[5] = {"to", "from", "over", "under", "on"}; // Prepositions

	// Initializing array that will be printed

	char sentenceArray[50];
	
	for (int i = 0; i < NUM_SENTENCES; i++)
	{
		memset(sentenceArray, 0, sizeof(sentenceArray)); // clearing out the sentenceArray so we can fill it with new words an print.
		concatonateRandomWord(sentenceArray, article);
		concatonateRandomWord(sentenceArray, noun);
		concatonateRandomWord(sentenceArray, verb);
		concatonateRandomWord(sentenceArray, preposition);
		concatonateRandomWord(sentenceArray, article);
		concatonateRandomWord(sentenceArray, noun);
		strcat(sentenceArray, "!"); // adding an exclamation mark to the end
		printf("%d: ", (i + 1));
		puts(sentenceArray);

	}
	
	sentenceArray[0] = toupper(sentenceArray[0]);
	system("pause");
	system("cls");

	return 0;
}



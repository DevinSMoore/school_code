#ifndef LAB8_H
#define LAB8_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // for IO functions FILE and user inputs
#include <stdlib.h> // for rand() and srand()
#include <time.h> // included for time() to seed srand()


#define PROB_2_SIZE 100
#define MAX_INCORRECT_GUESSES 6


// Will take in an array and fill (overwrite) the items in the array with the list of ints in the file
// Postcondition: array is filled with every element in the file and size of array is returnd as an integer.
// MAX ARRAY SIZE = 100
int intakeArray(int intArray[], FILE* infile);

// Postcondition: Array order has been mirrored. i.e. { 1, 2, 3 } goes to { 3, 2, 1 }
// MAX ARRAY SIZE = 100
void arraySwapper(int intArray[], int size);

// Will print array to console
void printIntArray(int intArray[], int size);

// Will fill an imported array with random integers between 1 and 100
void fillArrayRand(int intArray[]);

// Will fill an imported array with random integers between 1 and 100
void fillArrayInt(int intArray[], int size, int fillInt);

// Will fill a new array counting the number of times eache number 1-100 is in the imported array.
void numberCounter(int intArray[], int countingArray[]);

// Will check if we've reached the win condition
// Will return 0 if we have not won, 1 if we have.
int winCheck(char word[],char guess[], int arraySize);

// Will check to see if the guess is correct will incriment wrongGuessCounter if guess is incorrect.
// Will return 1 if guess is correct, 0 if incorrect
int guessCheck(char guess, char word[], char guessStorageArray[], int* guessCounter, int arraySize);

// Will get guess from user
char userGuess();

#endif LAB8_H
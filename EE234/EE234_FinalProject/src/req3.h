#ifndef REQ3_H
#define REQ3_H
#include "req1.h"
#include "req2.h"

// Reads in the twelve characters and spits them into an array
// Input Parameters:
//		char array: the Hex string that will contain our read in characters hex string
void readHexString(char hexString[]);

// THis will validate all of the characters we read in from the user and place them in a register
// Input Parameters:
//		char array: user input to verify
// Returns:
//		int: 1 = string verified; 0 = a character in the string was not a valid hex digit
int verifyHexString(char hexString[]);

// Will process the user input hex string and set the proper values in each register in a row
// Input Parameters:
//		char array: the verified hex string
void setDutyCycleFromHexString(char hexString[]);


#endif

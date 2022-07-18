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

#ifndef ISPRIME_H
#define ISPRIME_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// this will check if the number is prime.
// precondition: positive integer has been passed
// postcondition: returns 1 if prime 0 if not.
int isPrime(int sum);

// this will sum the digits of the passed number.
// precondition: positive integer has been passed.
// postcondition: returns sum of digits as an integer.
int sumDigits(int number);

// this will sum integers of a passed file
// precondition: File has been opened and passed
// postcondition: returns sum of integers in file
int sumIntegers(FILE *infile);

//void displayIsPrime(int sumInteger, int sumDigits, int isPrime);

#endif ISPRIME_H
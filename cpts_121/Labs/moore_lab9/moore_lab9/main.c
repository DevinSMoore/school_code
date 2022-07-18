////////////////////////////////////////////////////////////////////////////////////////////////////
//	Name: Devin Moore
//	Class: CptS121 Andrew O'Fallon
//	TA: Muthuu Svs
//	Assignment: Lab 9
//
//	Date: 2020/10/30
//	Description: Part1: a. reverse an array in place using a string array
//						b. do the same as a. but using only pointer notation and arithmetic
//				 Part2: Write a program that implements the following functions:
//							1) Copies all chars from source array to destination array
//							2) Concatenates 2 strings and gets rid of the null char on first
//							3) Compare dictionary order of s1 & s2. s2>s1 return -1 s1=s2 return 0
//							4) Returns the length of the input string. Doesn not include NULL char
////////////////////////////////////////////////////////////////////////////////////////////////////


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for tolower()

// function definitions

char *string_reverse(char string[]) // using arrays
{
	int index = 0, strLength = 0;
	// finding length of string
	while (string[strLength] != '\0')
	{
		strLength++;
	}
	int startIndex = 0, endIndex = strLength - 1;
	char tempChar = '\0';
	while (startIndex < endIndex)
	{
		tempChar = string[startIndex];
		string[startIndex] = string[endIndex];
		string[endIndex] = tempChar;
	
		startIndex++; endIndex--;
		//printf("startIndex: %d\nEndIndex: %d\n", startIndex, endIndex);
	}
	return string;
}

char *string_reverse_ptr(char *string_ptr, char *string2_ptr) // using arrays
{
	int index = -1;

	// strptr is pointed to the last position address
	while (*string_ptr)
	{
		string_ptr++;
		index++;
	}

	// string stored in str is copied to revstr
	while (index >= 0)

	{
		string_ptr--; // will be at the null character to start off with so we need to back up one
		*string2_ptr = *string_ptr;
		string2_ptr++;
		--index;
	}

	*string2_ptr = '\0';
	return string2_ptr;
}

char *my_strcpy(const char source[], char destination[]) // Copying strings using 2 arrays
{ 

	int i = 0;

	while (source[i] != '\0') {

		destination[i] = source[i];

		i++;

	}

	destination[i] = '\0';
	return destination;
}

char *my_strcat(const char source[], char destination[]) // source string getting slapped onto the end of destination
{
	int i = 0, j = 0;


	while (destination[i] != '\0')
	{ i++; } // will increment i up to the end of the string in source

	while (source[j] != '\0') // will start copying the jth element of source to the ith element of destination which is starting at the NULL char
	{
		destination[i] = source[j];
		i++; j++;
	}

	destination[i] = '\0';
	return destination;
}

int my_strcmp(const char str1[],const char str2[]) {

	int i = 0, flag = 0, charCompCheck = 0;
	char tempChar1 = '\0', tempChar2 = '\0';
	while (str1[i] != '\0' && str2[i] != '\0') {


		if (str1[i] != str2[i]) {

			flag = 1; // if any elements differ at the same index then flag will get set to 1

			break;

		}
		i++;
	}
	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0') {
		tempChar1 = tolower(str1[i]);
		tempChar2 = tolower(str2[i]);

		if (tempChar1 == tempChar2) { // if characters are euqal incriment counter
			i++;
			
		}
		else if (tempChar1 < tempChar2) { // if less than then this means the word is lower then break out of while loop
			break;
		}
		else {
			return -1; // if it's not equal or lower it must be greater therefore we return -1;
		}



	}

	if (flag == 0 && str1[i] == '\0' && str2[i] == '\0') // if all characters encountered are the same, and we're at the end of both strings then they are equal

		return 0;// if they're both the same retun 1

	else

		return 1;

}


int my_strln(const char string[]) // will loop until it hits the null character, and it counts each loop, will return this number
{
	int length = 0;
	while (string[length] != '\0') {
		length++;
	}
	return length;
}

int main(void)
{
	char string1[30] = "I love chocolate!", *string1_ptr = string1,
			string2[30], * string2_ptr = string2; // max length 30
	
	puts(string1);
	string_reverse(string1);
	puts(string1);
	// will reverse it

	system("pause");
	system("cls");

	// will return it to normal by reversing again
	puts(string1_ptr);
	string_reverse_ptr(string1_ptr, string2_ptr);
	puts(string2_ptr);

	system("pause");
	system("cls");
	// this is to copy one string to another
	char string3[20] = "F1 is cooool";
	char string4[20] = { '\0' };
	printf("--pre copy--\nString3: \n%s\nString4:\n%s\n", string3, string4);
	
	my_strcpy(string3, string4);

	printf("--post copy--\nString3: \n%s\nString4:\n%s\n", string3, string4);
	system("pause");
	system("cls");

	// This will concatenate one string onto another
	char string5[100] = "They look left, "; // destination
	char string6[100] = "and you go right."; // source
	
	printf("--pre concatenate--\nsource: \n%s\ndestination:\n%s\n", string6, string5);
	
	my_strcat(string6, string5);

	printf("--post concatenate--\nsource: \n%s\ndestination:\n%s\n", string6, string5);

	system("pause");
	system("cls");
	// This will check if one word is higher in the dictionary, equal or lower
	char string7[100] = "They look left, "; // destination
	char string8[100] = "and you go right."; // source
	int tempReg = my_strcmp(string7, string8);

	printf("returnvalue: %d\n", tempReg);

	system("pause");
	system("cls");
	// This will count the length of the string entered
	
	int length = my_strln(string7);

	printf("Length of string 7: %d\n\n", length);
	return 0;
}








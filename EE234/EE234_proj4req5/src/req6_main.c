/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/04/14
Class:      EE234 Clint Cole

Assignment: Project 4 Requirement 6

Description: For this requirement we are simply recreating all of the functionality from
			req1 - req4 in embedded c language

			Sequence of characters I used in video (both lines together each is 64 characters)
			0123456789012345678901234567890123456789012345678901234567890123
			0123456789012345678901234567890123456789012345678901234567890123
*******************************************************************************************/
#include <stdint.h> // for uint32_t
#include "req6.h"	// This contains all of the functions necessary to complete this requirement


int main(void)
{
	testSendChar();
	testReadChar();
	testSendString();
    testReadString(); // Enter any amount of characters or any amount up to 128 with a null char terminating it; only 128 characters (including nullchar) will print

    return 1;
}

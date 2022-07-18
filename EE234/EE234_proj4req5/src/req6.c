#include "req6.h"

// This function will test the send character functionality
// Input Parameters: NONE
// Returns: NONE
void testSendChar(void)
{
	char testChar = 'a';
	UART1_sendChar(testChar);
	testChar = '\n';
	UART1_sendChar(testChar);
	
}

// This function will test the recieve character functionality
// Input Parameters: NONE
// Returns: NONE
void testReadChar(void)
{
	char testChar = UART1_readChar();
	UART1_sendChar(testChar);
	testChar = '\n';
	UART1_sendChar(testChar);
}

// This function will test the send string functionality
// Input Parameters: NONE
// Returns: NONE
void testSendString(void)
{
	char testStr[128] = {"Apple Pie is alright"}; // 0-9 is 10 chars (10 * 13) -2 = 128; 9-2 = 7
	testStr[20] = '\0'; // adding the null char to just after the last character in the char array above
	UART1_sendString(testStr);
}

// This function will test the recieve string functionality
// Input Parameters: NONE
// Returns: NONE
void testReadString(void)
{
	char testStr[128] = { "" };
	UART1_recieveString(testStr);
	UART1_sendString(testStr); // Get da string, print da string =D
}

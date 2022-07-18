#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_LEN 128

extern void initUART1(void);

extern void sendCharacter(char data);
extern char receiveCharacter(void);

extern void sendString(char* stringArr);
extern void readString(char* stringArr, int maxStrLen);

extern void clearRx(void);
extern void echoLoop(char* stringArr);

// This function will test the send character subroutine in UARTmoduleAssembly.S
// the word "apple" will be print to the console each character to a new line
// Input Parameters: NONE
// Returns: NONE
void testSendCharacter(void);

// This function will test the receive character subroutine in UARTmoduleAssembly.S
// Input Parameters: NONE
// Returns: NONE
void testReceiveCharacter(void);

// This function will test the send string subroutine in stringModule.S
// Input Parameters: NONE
// Returns: NONE
void testSendString(void);

// This function will test the receive string subroutine in stringModule.S
// Input Parameters: NONE
// Returns: NONE
void testReadString(void);


int main(void)
{
	char testArr[MAX_STR_LEN] = {""};


	initUART1(); // 115200 BAUD rate; 8-bit data; 1 stop bit; no parity; normal operation

	readString(testArr, MAX_STR_LEN);
	//sendString(testArr);
	echoLoop(testArr);


	for(;;);


	return 1;
}


// This function will test the send character subroutine in UARTmoduleAssembly.S
// the word "apple" will be print to the console each character to a new line
// Input Parameters: NONE
// Returns: NONE
void testSendCharacter(void)
{
	char testChar = '\0';

	testChar = 'a';
	sendCharacter(testChar);
	testChar = '\n';
	sendCharacter(testChar);

	testChar = 'p';
	sendCharacter(testChar);
	testChar = '\n';
	sendCharacter(testChar);

	testChar = 'p';
	sendCharacter(testChar);
	testChar = '\n';
	sendCharacter(testChar);

	testChar = 'l';
	sendCharacter(testChar);
	testChar = '\n';
	sendCharacter(testChar);

	testChar = 'e';
	sendCharacter(testChar);
	testChar = '\n';
	sendCharacter(testChar);
}

// This function will test the receive character subroutine in UARTmoduleAssembly.S
// Input Parameters: NONE
// Returns: NONE
void testReceiveCharacter(void)
{
	char testChar = '\0';
	//for(;;)
	//{
		testChar = receiveCharacter();
		sendCharacter(testChar);
	//}
}

// This function will test the send string subroutine in stringModule.S
// Input Parameters: NONE
// Returns: NONE
void testSendString(void)
{
	// Just going to fill an array with a known number of characters and let 'er rip
	char testArr[MAX_STR_LEN] = "James likes to eat apples at applebees.\0\n";

	sendString(testArr);
}

// This function will test the receive string subroutine in stringModule.S
// Input Parameters: NONE
// Returns: NONE
void testReadString(void)
{
	char testArr[MAX_STR_LEN]; // Ok I had to declare this as a pointer to an array otherwise the code below was not behaving well

	readString(testArr, MAX_STR_LEN);
	sendString(testArr);
}


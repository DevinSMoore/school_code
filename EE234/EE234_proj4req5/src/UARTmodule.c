#include "UARTmodule.h"
// Function Declerations

// This function will reset the FIFO for the Rx and the Tx lines
// Input Parameters: NONE
// Returns: NONE
void resetRxTxFIFOs(void)
{
	UART1_CONTROL_REG |= RESET_FIFO_BITS; // Assert lower 2 bits to reset RX and TX lines and clear the FIFOs of data

	for (; (UART1_CONTROL_REG & RESET_FIFO_BITS) != 0;); // Mask upper bits and loop while lower 2 bits are not 0 meaning reset is still proceeding
}

// This function will set the mode register for UART1
// Input Parameters: NONE
// Returns: NONE
void UART1_setModeReg(void)
{
	UART1_MODE_REG = 0; // Clear reg
	UART1_MODE_REG |= PARITY_DISABLE; // set normal mode; 1 stop bit; no parity; 8-bit data; 100MHz master clock

}

// This function will be to enable Rx & Tx
// Input Parameters: NONE
// Returns: NONE
void UART1_enableRxTx(void)
{
	UART1_CONTROL_REG |= TX_RX_EN;	// Assert bit[4] (Tx EN) and bit[2] (Rx EN)
}

// This will set the baud rate to ~115200
// Input Parameters: NONE
// Returns: NONE
void UART1_setBaud115200(void) 
{
	UART1_BAUD_RATE = BAUDRATE_FOR_115200;
	UART1_BAUDGEN = BAUDGEN_VAL_FOR_115200;

}

// Read FIFO status register and return transmit FIFO full status
// Input Parameters: NONE
// Returns: Integer representing the full status: 1 = full; 0 = not full
int UART1_TxFullCheck(void) 
{

	return (UART1_STATUS_REG & TX_FULL_MASK) ? (1) : (0);
}


// Read FIFO status register to get receive FIFO empty status
// Input Parameters: NONE
// Returns: Integer: 1 = empty; 0 = not empty
int UART1_RxEmptyCheck(void)
{
	return (UART1_STATUS_REG & RX_EMPTY_MASK) ? (1) : (0);
}

// Send a character to the transmit FIFO
// Input Parameters: Character to be sent
// Returns: NONE
void UART1_sendChar(char charData)
{
	for (;(UART1_TxFullCheck() != 0);); // stay in this loop until FIFO check is 0 for not full

	UART1_FIFO_REG = charData; // Then send data

}

// Recieve a character from the PC to the blackboard over UART
// Input Parameters: NONE
// Returns: character recieved from the pc
char UART1_readChar(void)
{
	for (;(UART1_RxEmptyCheck() != 0);); // stay in this loop until Rx FIFO is not empty

	return UART1_FIFO_REG; // Then read in data and return
}

// Send a string to the blackboard max length is defined by the MAX_STR_LEN macro constant (128 for this proj)
// Input Parameters: Pointer to first element in array of chars
// Returns: NONE
void UART1_sendString(char* stringArr)
{
	for (int index = 0; index < MAX_STR_LEN; index++)
	{
		UART1_sendChar(stringArr[index]);
		if(stringArr[index] == '\0')
		{
			return;// if we encounter the null char break out of loop
		}
	}
}

// Read a string from the PC to the blackboard
// Input Parameters: Pointer to first element in char array to be filled
// Returns: NONE
void UART1_recieveString(char* fillString)
{
	int index = 0;
	for (;index <= MAX_STR_LEN; index++) // Read in chars until we reach the end-1
	{
		fillString[index] = UART1_readChar();
		if (fillString[index] == '\0')
		{
			return; // if we see the null char then we want to stop reading in characters and break out of function
		}
	}
	if (index == (MAX_STR_LEN - 1))
	{
		fillString[index] = '\0';
	}
}

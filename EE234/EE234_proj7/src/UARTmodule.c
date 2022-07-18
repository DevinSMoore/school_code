#include "UARTmodule.h"

// Function Declerations

// This will initialize the UART
void initUART1(void)
{
	resetRxTxFIFOs();
	UART1_setModeReg();
	UART1_setBaud115200();
	UART1_enableRxTx();
}


// This function will reset the FIFO for the Rx and the Tx lines
// Input Parameters: NONE
// Returns: NONE
void resetRxTxFIFOs(void)
{
	UART1_CONTROL |= RESET_FIFO_BITS; // Assert lower 2 bits to reset RX and TX lines and clear the FIFOs of data

	for (; (UART1_CONTROL & RESET_FIFO_BITS) != 0;); // Mask upper bits and loop while lower 2 bits are not 0 meaning reset is still proceeding
}

// This function will set the mode register for UART1
// Input Parameters: NONE
// Returns: NONE
void UART1_setModeReg(void)
{
	UART1_MODE = 0; // Clear reg
	UART1_MODE |= PARITY_DISABLE; // set normal mode; 1 stop bit; no parity; 8-bit data; 100MHz master clock

}

// This function will be to enable Rx & Tx
// Input Parameters: NONE
// Returns: NONE
void UART1_enableRxTx(void)
{
	UART1_CONTROL |= TX_RX_EN;	// Assert bit[4] (Tx EN) and bit[2] (Rx EN)
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
	return (UART1_STATUS & TX_FULL_MASK) ? (1) : (0);
}


// Read FIFO status register to get receive FIFO empty status
// Input Parameters: NONE
// Returns: Integer: 1 = empty; 0 = not empty
int UART1_RxEmptyCheck(void)
{
	return (UART1_STATUS & RX_EMPTY_MASK) ? (1) : (0);
}

// Send a character to the transmit FIFO
// Input Parameters: Character to be sent
// Returns: NONE
void UART1_sendChar(char charData)
{
	for (;(UART1_TxFullCheck() != 0);); // stay in this loop until FIFO check is 0 for not full
	UART1_FIFO = charData; // Then send data
}

// Recieve a character from the PC to the blackboard over UART
// Input Parameters: NONE
// Returns: character recieved from the pc
char UART1_readChar(void)
{
	for (;(UART1_RxEmptyCheck() == 1);); // stay in this loop until Rx FIFO is empty
	 // LED_REG |= 0b10000; // Turn on LED[4] if we hit this line; Used to debug
	return UART1_FIFO; // Then read in data and return
}

// Send a string to the blackboard max length is defined by the MAX_STR_LEN macro constant (128 for this proj)
// Input Parameters: Pointer to first element in array of chars
// Returns: NONE
void UART1_sendString(char* stringArr)
{
	for (int index = 0; index < MAX_STR_LEN; index++)
	{
		if(stringArr[index] == '\0')
		{
			return;// if we encounter the null char break out of loop
		}
		UART1_sendChar(stringArr[index]);
	}
}

// Read a string from the PC to the blackboard
// Input Parameters: Pointer to first element in char array to be filled
// Returns: NONE
void UART1_recieveString(char* fillString)
{
	int index = 0;
	for (;index < MAX_STR_LEN; index++) // Read in chars until we reach the end-1 
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

// Clears the interrupt flags that have been set
// Input Parameters: NONE
// Returns: NONE
void UART1_clearInterruptFlags(void)
{ 
	UART1_INTR_STATUS = BIT_MASK_32; // write 1 to all fields just to clear everyting
}

// Enable trigger level interrupt and configure UART1 for the interrupt
// Input Parameters: integer representing the level to trigger an interrupt; 6-bit val 1-64; 1 = one byte in FIFO; 64 = full
// Returns: NONE
void UART1_setRxLevelInterruptVal(uint32_t levelVal)
{
	UART1_RX_TRIG_VAL = (levelVal & BIT_MASK_6);
}

// Enables Rx FIFO level interrupt
void UART1_RxLevelInterrupt_Enable(void)
{
	UART1_EN_INTR = 0x1; // ORR bit[0] with 1: [0] is the receive trigger level interrupt enable
}

// Enables Rx FIFO level interrupt
void UART1_RxLevelInterrupt_Disable(void)
{
	UART1_DIS_INTR |= 0x1; // ORR bit[0] with 1: [0] is the receive trigger level interrupt disable
}

// Disables all interrupts
void UART1_disableAllInterrupts(void)
{
	UART1_DIS_INTR |= 0x1FFF; // Writes a 1 to all 12 interrupt disable bits
}

// Turns on the level interrupt for the RX and sets the level to 1
void UART1_Rx_singleByteInterrupt_Init(void)
{
	UART1_disableAllInterrupts(); 
	UART1_RxLevelInterrupt_Enable();
	UART1_setRxLevelInterruptVal(1); // pass one so we're interrupting when only a single byte is in the FIFO
}

// Interrupt Service Handler: This will read in all of the current contents of the Rx FIFO when it is not empty and push them to the Tx FIFO to send back to PC
// Input Parameters: NONE
// Returns: NONE
void UART1_intHandler_clearAndEchoRx(void)
{
	// LED_REG |= 0b0010; // Turn on LED[1] if we hit this function
	while (UART1_RxEmptyCheck() == 0) // while Recieve FIFO is not empty
	{
		// LED_REG |= 0b0100; // Turn on LED[2] if we hit this condition in this function; Used to debug

		UART1_sendChar(UART1_readChar()); // read char send char, beep boop
	}

	UART1_clearInterruptFlags(); // Clear the interrupt flags before we return
}

 //	This will print a 32 bit register out in line
 //	HAVENT TESTED YET -----
void UART1_printRegister(uint32_t data)
{
	uint32_t i = 0x80000000, j = 0; // 0x80000000 is bit[32] then we right shift it by 1 each time checking the AND of it and the data; if it's 1 we print 1 else we print 0
	uint32_t tempData = (data & i);

	for (; j < 32; j++)
	{
		if(j > 0 && (j % 4 == 0))
		{
			UART1_sendChar(' '); // add a space every fourth print
		}
		tempData = (data & i);
		if (tempData > 0)
		{
			UART1_sendChar(ASCII_1);
		}
		else
		{
			UART1_sendChar(ASCII_0);
		}

		i = i>>1;
	}
	UART1_sendChar('\n');
}

// Send Integer: take in an integer 0-9 and send the ascii version to the UART
// Input Parameters:
//		int: between 0 and 9
void UART1_printDigit(int digit)
{
	switch (digit)
	{
		case 0:
			UART1_sendChar(ASCII_0);
			break;
		case 1:
			UART1_sendChar(ASCII_1);
			break;
		case 2:
			UART1_sendChar(ASCII_2);
			break;
		case 3:
			UART1_sendChar(ASCII_3);
			break;
		case 4:
			UART1_sendChar(ASCII_4);
			break;
		case 5:
			UART1_sendChar(ASCII_5);
			break;
		case 6:
			UART1_sendChar(ASCII_6);
			break;
		case 7:
			UART1_sendChar(ASCII_7);
			break;
		case 8:
			UART1_sendChar(ASCII_8);
			break;
		case 9:
			UART1_sendChar(ASCII_9);
			break;
		default:
			UART1_sendString("\nHit default case in UART1_printDigit....\n");
			break;
	}
}

// Take an integer and print it to the screen
void UART1_printInt(int printInt)
{

	int index = 0, intArr[10] = { 0 }, tempCount = printInt;// set tempCount to the current count value so we can chop it up

	if(printInt == -1)
	{
		UART1_sendChar('-');
		UART1_printDigit(1);
		return;
	}
	else if (printInt == 0)
	{
		UART1_printDigit(0);
	}

	for (; tempCount > 0; index++)
	{// it would be easier to find a way to push this to the stack the print the value that gets poped from the stack as we pop them
		intArr[index] = (tempCount % 10);
		tempCount /= 10; // get the least significant digit then divide by ten to get the next higest val
	}
	while (--index >= 0) // Fill in reverse order then print in reverse-reverse order 
	{
		UART1_printDigit(intArr[index]);
	}
}

// This will take in a 32-bit int then convert it (if applicable) to the integer representation 0-9
// Input Parameters:
//		uint32_t: data to convert
// Returns:
//		int: If the input was 0-9 then it will be converted; else it will set the value to -1
void UART1_getInt(const uint32_t data, int* pInt)
{
	switch (data)
	{
	case ASCII_0:
		*pInt = 0;
		return;
	case ASCII_1:
		*pInt = 1;
		return;
	case ASCII_2:
		*pInt = 2;
		return;
	case ASCII_3:
		*pInt = 3;
		return;
	case ASCII_4:
		*pInt = 4;
		return;
	case ASCII_5:
		*pInt = 5;
		return;
	case ASCII_6:
		*pInt = 6;
		return;
	case ASCII_7:
		*pInt = 7;
		return;
	case ASCII_8:
		*pInt = 8;
		return;
	case ASCII_9:
		*pInt = 9;
		return;
	default:
		// UART1_sendString("\nCannot convert passed value to integer....\n");
		*pInt = -1;
		return;
	}
}

// This will empty out the receive FIFO
void UART1_clearRxFIFO(void)
{
	//UART1_sendString("Entered clear RX....\n");

	while (UART1_RxEmptyCheck() == 0)
	{
		//UART1_sendString("Char read in: ");
		UART1_readChar();
	}

}

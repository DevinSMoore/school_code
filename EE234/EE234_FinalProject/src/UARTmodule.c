#include "UARTmodule.h"

// Function Declerations

// This will initialize the UART to 115200 baud rate
void initUART1(void)
{
	resetRxTxFIFOs();
	UART1_setModeReg();
	UART1_setBaud115200();
	UART1_enableRxTx();
}


// This function will reset the FIFO for the Rx and the Tx lines
void resetRxTxFIFOs(void)
{
	UART1_CONTROL |= RESET_FIFO_BITS; // Assert lower 2 bits to reset RX and TX lines and clear the FIFOs of data

	for (; (UART1_CONTROL & RESET_FIFO_BITS) != 0;); // Mask upper bits and loop while lower 2 bits are not 0 meaning reset is still proceeding
}

// This function will set the mode register for UART1
void UART1_setModeReg(void)
{
	UART1_MODE = 0; // Clear reg
	UART1_MODE |= PARITY_DISABLE; // set normal mode; 1 stop bit; no parity; 8-bit data; 100MHz master clock

}

// This function will be to enable Rx & Tx
void UART1_enableRxTx(void)
{
	UART1_CONTROL |= TX_RX_EN;	// Assert bit[4] (Tx EN) and bit[2] (Rx EN)
}

// This will set the baud rate to ~115200
void UART1_setBaud115200(void)
{
	UART1_BAUD_RATE = BAUDRATE_FOR_115200;
	UART1_BAUDGEN = BAUDGEN_VAL_FOR_115200;

}

// Read FIFO status register and return transmit FIFO full status
// Returns:
//		Integer representing the full status: 1 = full; 0 = not full
int UART1_TxFullCheck(void)
{
	return (UART1_STATUS & TX_FULL_MASK) ? (1) : (0);
}


// Read FIFO status register to get receive FIFO empty status
// Returns:
//		Integer: 1 = empty; 0 = not empty
int UART1_RxEmptyCheck(void)
{
	return (UART1_STATUS & RX_EMPTY_MASK) ? (1) : (0);
}

// Send a character to the transmit FIFO
// Input Parameters:
//		Character to be sent
void UART1_sendChar(char charData)
{
	for (;(UART1_TxFullCheck() != 0);); // stay in this loop until FIFO check is 0 for not full
	UART1_FIFO = charData; // Then send data
}

// Receive a character from the PC to the blackboard over UART
// Returns:
//		char: character received from the pc
char UART1_readChar(void)
{
	for (;(UART1_RxEmptyCheck() == 1);); // stay in this loop until Rx FIFO is empty
	return UART1_FIFO; // Then read in data and return
}

// Send a string to the blackboard max length is defined by the MAX_STR_LEN macro constant
// Input Parameters:
//		Pointer to first element in array of chars
void UART1_sendString(const char* stringArr)
{
	for (int index = 0; index < MAX_STR_LEN; index++)
	{
		if(stringArr[index] == '\0')
		{
			return;// if we encounter the null char return
		}
		UART1_sendChar(stringArr[index]);
	}
}

// Clears the interrupt flags that have been set
void UART1_clearInterruptFlags(void)
{ 
	UART1_INTR_STATUS = BIT_MASK_32; // write 1 to all fields just to clear everything
}

// Enable trigger level interrupt and configure UART1 for the interrupt level being passed
// Input Parameters:
//		uint32_t: Level to trigger an interrupt; 6-bit val 1-64; 1 = one byte in FIFO; 64 = full
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

 //	This will print a 32 bit register out in line
// Input Parameters:
//		uint32_t: register to be print
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
}

// This will empty out the receive FIFO
void UART1_clearRxFIFO(void)
{
	while (UART1_RxEmptyCheck() == 0)
	{
		UART1_readChar(); // Rx = 0 means data is in FIFO -> read in next byte
	}

}

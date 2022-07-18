#ifndef UARTMODULE_H
#define UARTMODULE_H

#include <stdint.h>

volatile int UART_RX_NOT_EMPTY_FLAG;

// Ascii value definitions
#define ASCII_0 0x30
#define ASCII_1 0x31
#define ASCII_2 0x32
#define ASCII_3 0x33
#define ASCII_4 0x34
#define ASCII_5 0x35
#define ASCII_6 0x36
#define ASCII_7 0x37
#define ASCII_8 0x38
#define ASCII_9 0x39
#define ASCII_NULLCHAR 0x00

#define BIT_MASK_6 0x3f // 0011 1111
#define BIT_MASK_32 0xFFFFFFFF // 32 1s
#define MAX_STR_LEN 128 // Most characters allowed - terminating char = 127

#define LED_REG 			*((volatile uint32_t *)0x41210000)

// reg address'; casting each as a pointer to a 32-bit unsigned int then dereferencing it so the ceonstant refers to the actual register
#define UART1_CONTROL		*((volatile uint32_t *)0xE0001000) 		// Configuration register for UART1
#define UART1_MODE	 		*((volatile uint32_t *)0xE0001004) 		// Mode register

// Interrupt Registers
#define UART1_EN_INTR 		*((volatile uint32_t *)0xE0001008)			// Enable Interrupts
#define UART1_DIS_INTR 		*((volatile uint32_t *)0xE000100C)			// Disable interrupts
#define UART1_INTR_MASK		*((volatile uint32_t *)0xE0001010)		// Interrupt mask; read; 1 = interrupt is enabled, 0 = intr disabled
#define UART1_INTR_STATUS   *((volatile uint32_t *)0xE0001014)		// Interrupt status reg, bits set to 1 indicate event occured; write 1 to clear flags

#define UART1_RX_TRIG_VAL 	*((volatile uint32_t *)0xE0001020)			// This is the offset to set the value for the rx FIFO fill level interrupt or status bit; 6 bit value

// Going to set this to 0x7C for 115200 target BAUD rate
#define UART1_BAUDGEN		*((volatile uint32_t *)0xE00010018) 	// This is the divisor for the Rx line polling rate, MasterClk/BAUDGEN = Rx polling rate
#define BAUDGEN_VAL_FOR_115200 0x7C

#define UART1_STATUS	  	*((volatile uint32_t *)0xE000102C)			// Status register for UART1 FIFO
#define UART1_FIFO		  	*((volatile uint32_t *)0xE0001030)			// This holds the FIFO data in the least significant byte; read the recieve FIFO, and write to the transmit FIFO using this same offset;

#define UART1_BAUD_RATE		*((volatile uint32_t *)0xE0001034)		// This will set the actual baud rate based on the Rx polling rate: BAUD_RATE = RxPollRate / BAUD_RATE_REG; we pass the baud rate val into this register
#define BAUDRATE_FOR_115200 0x06							// To get that magical 115200, well close enough anyways

#define RESET_FIFO_BITS 0x03

#define PARITY_DISABLE 0x20	//  0000100000 for normal operation in the MODE register

#define TX_RX_EN 0x14				// Combined TX and RX enable mask b/c I have a lot of constants already; 10100
#define TX_FULL_MASK 0x10			// bit[4] is TX full check
#define RX_EMPTY_MASK 0x02			// bit[1] is the Rx FIFO empty status bit


// Function Declerations

// This will initialize the UART
void initUART1(void);

// This function will reset the FIFO for the Rx and the Tx lines
// Input Parameters: NONE
// Returns: NONE
void resetRxTxFIFOs(void);

// This function will set the mode register for UART1
// Input Parameters: NONE
// Returns: NONE
void UART1_setModeReg(void);

// This function will be to enable Rx & Tx
// Input Parameters: NONE
// Returns: NONE
void UART1_enableRxTx(void);

// This will set the baud rate to ~115200
// Input Parameters: NONE
// Returns: NONE
void UART1_setBaud115200(void);

// Read FIFO status register and return transmit FIFO full status
// Input Parameters: NONE
// Returns: Integer representing the full status: 1 = full; 0 = not full
int UART1_TxFullCheck(void);


// Read FIFO status register to get receive FIFO empty status
// Input Parameters: NONE
// Returns: Integer: 1 = empty; 0 = not empty
int UART1_RxEmptyCheck(void);

// Send a character to the transmit FIFO
// Input Parameters: Character to be sent
// Returns: NONE
void UART1_sendChar(char charData);

// Recieve a character from the PC to the blackboard over UART
// Input Parameters: NONE
// Returns: character recieved from the pc
char UART1_readChar(void);

// Send a string to the blackboard max length is defined by the MAX_STR_LEN macro constant (128 for this proj)
// Input Parameters: Pointer to first element in array of chars
// Returns: NONE
void UART1_sendString(const char* stringArr);

// Clears the interrupt flags that have been set
// Input Parameters: NONE
// Returns: NONE
void UART1_clearInterruptFlags(void);

// Enable trigger level interrupt and configure UART1 for the interrupt
// Input Parameters: integer representing the level to trigger an interrupt; 6-bit val 1-64; 1 = one byte in FIFO; 64 = full
// Returns: NONE
void UART1_setRxLevelInterruptVal(const uint32_t levelVal);

// Enables Rx FIFO level interrupt
void UART1_RxLevelInterrupt_Enable(void);

// Enables Rx FIFO level interrupt
void UART1_RxLevelInterrupt_Disable(void);

// Disables all interrupts
void UART1_disableAllInterrupts(void);

// This will print a 32 bit register out in line
void UART1_printRegister(uint32_t data);

// This will empty out the receive FIFO
void UART1_clearRxFIFO(void);


#endif

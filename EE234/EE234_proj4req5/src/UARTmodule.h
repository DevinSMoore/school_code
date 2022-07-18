/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/04/14
Class:      EE234 Clint Cole
Assignment: Project 4 Requirement 6

Description: This will contain the function declerations for the UART setup module.
			Includes:
				readCharacter
				writeCharacter
				readString
				writeString
*******************************************************************************************/
#include <stdint.h>


#define MAX_STR_LEN 128 // Most characters - terminating char = 127

// reg address'; casting each as a pointer to a 32-bit unsigned int then dereferencing it so the ceonstant refers to the actual register
#define UART1_CONTROL_REG	 *((uint32_t *)0xE0001000) 		// bit[5] = Tx Disable; bit[4] = Tx EN; bit[3] = Rx Dis; bit[2] = Rx En; bit[1]=Tx reset (1=RS); [0]:Rx reset (1=reset)
#define UART1_MODE_REG	 	 *((uint32_t *)0xE0001004) 			// bit[9:8]: ChannMode(00 for normal); [7:6] #StopBits (00 for 1); [5:3] parity (1XX for no parity); [2:1] dataLen(0X:8bits); [0] MasterClk (0 for 100MHz);
#define UART1_EN_INT_REG  	 *((uint32_t *)0xE0001008)		// 1=En; [10]:Tx Near Full; [4]:TxFIFOfull; [3]:TxFIFOempty; [2]:RxFIFOfull; [1]:RxFIFOempty; [0]:Rx Trigg Int
#define UART1_DIS_INT_REG 	 *((uint32_t *)0xE000100C)		// Same mapping as above; write 1 to disable
#define UART1_INT_MASK_REG   *((uint32_t *)0xE0001010)		// Same mapping but read to check if INT is EN; 1=EN,0=NOT EN
#define UART1_INT_STATUS_REG *((uint32_t *)0xE0001014)	// Same mapping, any enable interrupts will set the values in this reg when their conditions are met

#define UART1_RX_TRIG_VAL_REG *((uint32_t *)0xE0001020)			// This is the offset to set the value for the rx FIFO fill level interrupt or status bit; 6 bit value
#define UART1_TX_TRIG_VAL_REG *((uint32_t *)0xE0001044)			// Same as above but for the transmit FIFO

// Going to set this to 0x7C for 115200 target BAUD rate
#define UART1_BAUDGEN *((uint32_t *)0xE00010018) 		// This is the divisor for the Rx line polling rate, MasterClk/BAUDGEN = Rx polling rate
#define BAUDGEN_VAL_FOR_115200 0x7C


#define UART1_STATUS_REG *((uint32_t *)0xE000102C)		// [11]: Tx State Mch. Active (1=Actv); [10]:RX State Mch; [4]:TxFull; [3]:TxEmpty; [2]:RxFull; [1]:RxEmpty; [0]:Rx level trigger bit; if FIFO is above level set this will be set
#define UART1_FIFO_REG   *((uint32_t *)0xE0001030)		// This holds the FIFO data in the least significant bit; read the recieve FIFO, and write to the transmit FIFO using this same offset; 1 byte only please and thank you; also use LDRB to make sure we nab the correct info

#define UART1_BAUD_RATE *((uint32_t *)0xE0001034)		// This will set the actual baud rate based on the Rx polling rate: BAUD_RATE = RxPollRate / BAUD_RATE_REG; we pass the baud rate val into this register
#define BAUDRATE_FOR_115200 0x06	// To get that magical 115200, well close enough anyways

#define RESET_FIFO_BITS 0x03

#define PARITY_DISABLE 0x20	// this is the only bit in the mode reg we want to set: 0000100000 for our operation

#define TX_RX_EN 0x14				// Combined TX and RX enable mask b/c I have a lot of constants already; 10100
#define TX_FULL_MASK 0x10			// bit[4] is TX full check
#define RX_EMPTY_MASK 0x02			// bit[1] is the Rx FIFO empty status bit


// Function Declerations

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
void UART1_sendString(char* stringArr);

// Read a string from the PC to the blackboard
// Input Parameters: Pointer to first element in char array to be filled
// Returns: NONE
void UART1_recieveString(char* fillString);

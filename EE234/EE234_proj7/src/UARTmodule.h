/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/04/14
Class:      EE234 Clint Cole
Assignment: Project 5 Requirement 4

Description: This will
*******************************************************************************************/
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
#define MAX_STR_LEN 128 // Most characters - terminating char = 127

#define LED_REG *((uint32_t *)0x41210000)

// reg address'; casting each as a pointer to a 32-bit unsigned int then dereferencing it so the ceonstant refers to the actual register
#define UART1_CONTROL	  *((uint32_t *)0xE0001000) 		// bit[5] = Tx Disable; bit[4] = Tx EN; bit[3] = Rx Dis; bit[2] = Rx En; bit[1]=Tx reset (1=RS); [0]:Rx reset (1=reset)
#define UART1_MODE	 	  *((uint32_t *)0xE0001004) 			// bit[9:8]: ChannMode(00 for normal); [7:6] #StopBits (00 for 1); [5:3] parity (1XX for no parity); [2:1] dataLen(0X:8bits); [0] MasterClk (0 for 100MHz);

// Interrupt Registers
#define UART1_EN_INTR 	  *((uint32_t *)0xE0001008)		// 1=En; [10]:Tx Near Full; [4]:TxFIFOfull; [3]:TxFIFOempty; [2]:RxFIFOfull; [1]:RxFIFOempty; [0]:Rx Trigg Int
#define UART1_DIS_INTR 	  *((uint32_t *)0xE000100C)		// Same mapping as above; write 1 to disable
#define UART1_INTR_MASK    *((uint32_t *)0xE0001010)		// Same mapping but read to check if INT is EN; 1=EN,0=NOT EN
#define UART1_INTR_STATUS  *((uint32_t *)0xE0001014)		// Same mapping, any enable interrupts will set the values in this reg when their conditions are met; Write a 1 to a field to clear

#define UART1_RX_TRIG_VAL *((uint32_t *)0xE0001020)			// This is the offset to set the value for the rx FIFO fill level interrupt or status bit; 6 bit value
#define UART1_TX_TRIG_VAL *((uint32_t *)0xE0001044)			// Same as above but for the transmit FIFO

// Going to set this to 0x7C for 115200 target BAUD rate
#define UART1_BAUDGEN		  *((uint32_t *)0xE00010018) 		// This is the divisor for the Rx line polling rate, MasterClk/BAUDGEN = Rx polling rate
#define BAUDGEN_VAL_FOR_115200 0x7C


#define UART1_STATUS	  *((uint32_t *)0xE000102C)		// [11]: Tx State Mch. Active (1=Actv); [10]:RX State Mch; [4]:TxFull; [3]:TxEmpty; [2]:RxFull; [1]:RxEmpty; [0]:Rx level trigger bit; if FIFO is above level set this will be set
#define UART1_FIFO		  *((uint32_t *)0xE0001030)		// This holds the FIFO data in the least significant bit; read the recieve FIFO, and write to the transmit FIFO using this same offset; 1 byte only please and thank you; also use LDRB to make sure we nab the correct info

#define UART1_BAUD_RATE		  *((uint32_t *)0xE0001034)		// This will set the actual baud rate based on the Rx polling rate: BAUD_RATE = RxPollRate / BAUD_RATE_REG; we pass the baud rate val into this register
#define BAUDRATE_FOR_115200 0x06	// To get that magical 115200, well close enough anyways

#define RESET_FIFO_BITS 0x03

#define PARITY_DISABLE 0x20	// this is the only bit in the mode reg we want to set: 0000100000 for our operation

#define TX_RX_EN 0x14				// Combined TX and RX enable mask b/c I have a lot of constants already; 10100
#define TX_FULL_MASK 0x10			// bit[4] is TX full check
#define RX_EMPTY_MASK 0x02			// bit[1] is the Rx FIFO empty status bit

#define TEST_STR_STS_REG "Interrupt Status register contents : "
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
void UART1_sendString(char* stringArr);

// Read a string from the PC to the blackboard
// Input Parameters: Pointer to first element in char array to be filled
// Returns: NONE
void UART1_recieveString(char* fillString);

// Clears the interrupt flags that have been set
// Input Parameters: NONE
// Returns: NONE
void UART1_clearInterruptFlags(void);

// Enable trigger level interrupt and configure UART1 for the interrupt
// Input Parameters: integer representing the level to trigger an interrupt; 6-bit val 1-64; 1 = one byte in FIFO; 64 = full
// Returns: NONE
void UART1_setRxLevelInterruptVal(uint32_t levelVal);

// Enables Rx FIFO level interrupt
void UART1_RxLevelInterrupt_Enable(void);

// Enables Rx FIFO level interrupt
void UART1_RxLevelInterrupt_Disable(void);

// Disables all interrupts
void UART1_disableAllInterrupts(void);

// Turns on the level interrupt for the RX and sets the level to 1
void UART1_Rx_singleByteInterrupt_Init(void);

// Interrupt Service Handler: This will read in all of the current contents of the Rx FIFO when it is not empty and push them to the Tx FIFO to send back to PC
// Input Parameters: NONE
// Returns: NONE
void UART1_intHandler_clearAndEchoRx(void);

// This will print a 32 bit register out in line
void UART1_printRegister(uint32_t data);

// Send Integer: take in an integer 0-9 and send the ascii version to the UART
// Input Parameters:
//		int: between 0 and 9
void UART1_printDigit(int digit);

// Integer must be less than 10 characters long
void UART1_printInt(int printInt);

// This will take in a 32-bit int then convert it (if applicable) to the integer representation 0-9
// Input Parameters:
//		uint32_t: data to convert
// Returns:
//		int: If the input was 0-9 then it will be converted; else 
void UART1_getInt(const uint32_t data, int* pInt);

// This will empty out the receive FIFO
void UART1_clearRxFIFO(void);
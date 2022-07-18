/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/04/13
Class:      EE234 Clint Cole
Assignment: Project 4 Requirement 6

Description: This file contains the function declarations for the UART modules (just 1 for
			now). Module 1 is connected to the PC, Module 2 is connected to the ESP32s weefee
			module (or blootoof I'll look it up in a bit)
*******************************************************************************************/
#include <stdint.h>


// reg address'
#define UART1_CONTROL_REG 		*((unit32_t *)0xE0001000) 		// bit[5] = Tx Disable; bit[4] = Tx EN; bit[3] = Rx Dis; bit[2] = Rx En; bit[1]=Tx reset (1=RS); [0]:Rx reset (1=reset)
#define UART1_MODE_REG	 		*((unit32_t *)0xE0001004)		// bit[9:8]: ChannMode(00 for normal); [7:6] #StopBits (00 for 1); [5:3] parity (1XX for no parity); [2:1] dataLen(0X:8bits); [0] MasterClk (0 for 100MHz);
#define UART1_EN_INTRPT_REG		*((unit32_t *)0xE0001008)		// 1=En; [10]:Tx Near Full; [4]:TxFIFOfull; [3]:TxFIFOempty; [2]:RxFIFOfull; [1]:RxFIFOempty; [0]:Rx Trigg Int
#define UART1_DIS_INTRPT_REG 	*((unit32_t *)0xE000100C) 		// Same mapping as above; write 1 to disable
#define UART1_INT_MASK_REG		*((unit32_t *)0xE0001010)		// Same mapping but read to check if INT is EN; 1=EN,0=NOT EN
#define UART1_INT_STATUS_REG	*((unit32_t *)0xE0001014) 		// Same mapping, any enable interrupts will set the values in this reg when their conditions are met

#define UART1_RX_TRIG_VAL_REG	*((unit32_t *)0xE0001020)	// address to set the value for the rx FIFO fill level interrupt or status bit; 6 bit value
#define UART1_TX_TRIG_VAL_REG	*((unit32_t *)0x4E000104)	// Same as above but for the transmit FIFO

// Going to set this to 0x7C for 115200 target BAUD rate
#define UART1_BAUDGEN			*((unit32_t *)0xE0001018) 		// This is the divisor for the Rx line polling rate, MasterClk/BAUDGEN = Rx polling rate
#define BAUDGEN_115200 0x7C				// Value that will give us a near 115200 bit/s rate


#define UART1_STATUS_REG *((unit32_t *)0xE000102C)		// [11]: Tx State Mch. Active (1=Actv); [10]:RX State Mch; [4]:TxFull; [3]:TxEmpty; [2]:RxFull; [1]:RxEmpty; [0]:Rx level trigger bit; if FIFO is above level set this will be set
#define UART1_FIFO_REG *((unit32_t *)0xE0001030)		// This holds the FIFO data in the least significant bit; read the recieve FIFO, and write to the transmit FIFO using this same offset; 1 byte only please and thank you; also use LDRB to make sure we nab the correct info

#define UART1_BAUD_RATE *((unit32_t *)0xE0001034)		// This will set the actual baud rate based on the Rx polling rate: BAUD_RATE = RxPollRate / BAUD_RATE_REG; we pass the baud rate val into this register
#define BAUDRATE_115200 0x06			// To get that magical 115200, well close enough anyways

#define RESET_BIT_MASK, 0x03

#define PARITY_DISABLE_MASK, 0x20		// This is the only bit in the mode reg we want to set: 0000100000 for our operation

#define TX_RX_EN, 0x14					// Combined TX and RX enable mask b/c I have a lot of constants already; 10100

#define TX_FULL_MASK, 0x10				// Bit[4] is TX full check
#define RX_EMPTY_MASK,0x02				// Bit[1] is the Rx FIFO empty status bit



// could do the fancy shamncy *(((unit32_t *)0xE0001000) + n) but I want the names to clearly communicate the info they contain

/*
* Description: This will initialize the UART1 module to ~115200 BAUD, 8-bit data, 1 stop bit, and no parity
* Input Parameters: NONE
* Returns: NONE
*/
void initUART_1(void);

/*
* Description: Reset Rx and Tx FIFOs
* Input Parameters: NONE
* Returns: NONE
*/
void resetFIFOs(void);


/*
* Description: Set the mode register: Normal Operation; 1 stop bit; no parity; 8-bit data; 100MHz master clock
* Input Parameters: NONE
* Returns: NONE
*/
void setUart1ModeReg(void);


/*
* Description: This enables the Tx and Rx FIFOs
* Input Parameters: NONE
* Returns: NONE
*/
void enableTransmitRecieve(void);



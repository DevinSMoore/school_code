/*
	Programmer:	Devin moore

	Description: This module containts the necessary code to communicate with the IIC controlers on the ZYNQ chip.
*/

#ifndef I2C_H
#define I2C_H



#include <stdint.h>
#include "UARTmodule.h"

#define I const volatile	// RO
#define O volatile			// WrO
#define IO volatile			// R/Wr


//Registers for the IIC controller
typedef struct
{
	IO uint16_t XIICPS_CR;				// 16-bit; Control Register; 0x00
	short int zFiller0;
	I  uint16_t XIICPS_SR;				// 16-bit; Status Register; 0x04
	short int zFiller1;
	IO uint16_t XIICPS_ADDR;				// 16-bit; IIC address; 0x08
	short int zFiller2;
	IO  uint16_t XIICPS_DATA;			// 16-bit; IIC data; 0x0C
	short int zFiller3;
	IO  uint16_t XIICPS_ISR;				// 16-bit; IIC interrupt status; 0x10
	short int zFiller4;
	IO  uint8_t XIICPS_TRANS_SIZE;		// 8-bit;  IIC transfer size; 0x14
	char zFiller5[3];
	IO  uint8_t XIICPS_SLV_PAUSE;		// 8-bit;  Slave monitor pause; 0x18
	char zFiller6[3];
	IO  uint8_t XIICPS_TIME_OUT;			// 8-bit;  Time out; 0x1C
	char zFiller7[3];
	I  uint8_t XIICPS_IMR;				// 8-bit;  Interrupt mask; 0x20
	char zFiller8[3];
	IO  uint8_t XIICPS_IER;				// 8-bit;  Interrupt enable; 0x24
	char zFiller9[3];
	IO  uint8_t XIICPS_IDR;				// 8-bit;  Interrupt disable; 0x28

} I2C_REGISTERS;

/* 
	Bits for the control register
	
	Bit[7] is reserved and reads 0
	bit[8:13] = DIVB value for clock divider
	bit[14:15] = DIVA val for clock
	CLK frequency = (CPU_CLK)/[(DIVA + 1)*(DIVB + 1)]
*/
enum controlReg
{
	RD = 1 << 0,			// R/W; Direction of transfer; 1 = master reciever; 0 = master transmitter
	MS = 1 << 1,			// R/W; Overall Interface Mode; 1 = master; 0 = slave
	NEA = 1 << 2,			// R/W; Addressing Mode(MASTER ONLY); 1 = normal (7-bit) address; 0 = reserved
	ACKEN = 1 << 3,			// R/W; Acknowledge Enable; NEEDS TO BE SET TO 1
	HOLD = 1 << 4,			// R/W; hold_bus; 1 = When no more data to transfer, or no more data tcan be received then hold SCLK line low until serviced; 0 = allow transfer to terminate as soon as all data transfered
	SLVMON = 1 << 5,		// R/W; Slave monitor mode; 1 = monitor mode; 0 = normal operation;
	CLR_FIFO = 1 << 6,		// R/W; 1 = Initializes FIFO to all zeros and clears the transfer size reg except in master receive mode. 
} CRM;

/*
	Status Register

	Bit[2:0] reserved; reads zero
	Bit[4] reserved; reads zero
	Bit[15:9] reserved; reads zero
*/
enum statusReg
{
	RXRW = 1 << 3,			// RO; Mode of the transmision received by the master
	RXDV = 1 << 5,			// RO; Receiver data valid; 1 = data to be read is valid
	TXDV = 1 << 6,			// RO; Transmit data valid; 1 = a uint8_t still needs to be transmitted by interface
	RXOVF = 1 << 7,			// RO, Rx overflow; 1 = FIFO is full and a new uint8_t in shift reg. New uint8_t is NACKed and FIFO is unchanged
	BA = 1 << 8				// RO; Bus active; 1 = Ongoing transfer on I2C bus
} SRM;

/*
	Interrupt Status Register bits

	--Write to clear flags--

	The Interrupt Mask, Enable, and Disable Registers all share the same bitfields
	In the mask register a bit being set coorisponds the same bit being ignored in the ISR.
	Thus 0 = interrupt enabled 1 = interrupt disabled.

	To set bit, you must disable the particular interrupt by writing 1 to the IDR.
	Writing a 1 to the IER enable the register clearing the bit in the IMR.

	Bit[8] is reserved
	Bits[15:10] are reserved
*/
typedef enum InterruptStatusReg
{
	IXR_COMP		= 1 << 0,		// 1 = Transfer complete; 
	IXR_DATA		= 1 << 1,		// 1 = Data is being set or received
	IXR_NACK		= 1 << 2,		// 1 = slave responded with NACK or master terminated communication early
	IXR_TO			= 1 << 3,		// 1 = I2C SCK line is held low for too long; Transfer time out
	IXR_SLV_RDY		= 1 << 4,		// 1 = Slave returned ACK
	IXR_RX_OVR		= 1 << 5,		// 1 = FIFO full and new uint8_t received
	IXR_TX_OVR		= 1 << 6,		// 1 = Host attempts to write to FIFO more times the the depth of the FIFO
	IXR_RX_UNF		= 1 << 7,		// 1 = host attamps to read (value of transfer size + 1) causeing and underflow
	IXR_ARB_LOST	= 1 << 9		// 1 = Master loses bus ownership during transfer due to ongoing arbitration
}IRM;

/*
	These are just typical high speed I2C values to get the particular bus speed
*/
typedef enum clkSpd
{
	DIVA_400KHz = 0x00 << 14,
	DIVA_100KHz = 0x02 << 14,
	DIVA_BITMASK = 0xFF << 14,
	DIVB_400KHz = 0x0C << 8,
	DIVB_100KHz = 0x10 << 8,
	DIVB_BITMASK = 0xFF << 8

} CLK_SPEED;

#define I2C0_BASE 0xE0004000
#define I2C1_BASE 0xE0005000

#define I2C0 ((I2C_REGISTERS*)I2C0_BASE)
#define I2C1 ((I2C_REGISTERS*)I2C1_BASE)

// Base address: 0xF8000000; I2C_RST_CTRL_OFFSET: 0x0224
#define SLCR_I2C_RST_CTRL *((volatile uint32_t *)0xF8000224) // Bit[0] = I2C0; Bit[1] = I2C1; : AMBA clock of I2CX reset if bit asserted; Bit[31:2] reserved
#define I2C0_RST 1
#define I2C1_RST 2

// Init function will set up I2C 0 or 1 for master out
void initMaster0(void);
void initMaster1(void);

/*	
	Write a single uint8_t to IIC0 to given address
	Input Parameters:
			7-bit address (assuming normal mode)
			uint8_t that contains the data to send;l
*/
void writeuint8_tIIC0(const uint8_t address, const uint8_t data);

/*
	Write a single uint8_t to IIC1 to given address
	Input Parameters:
			7-bit address (assuming normal mode)
			uint8_t that contains the data to send;l
*/
void writeuint8_tIIC1(const uint8_t address, const uint8_t data);

/*
	Read a bit from the interrupt register for IIC0
	Input Parameters:
			bitmask for the bit you want to peek
*/
const uint8_t peekInt0RegBit(const int bitMask);

/*
	Read a bit from the interrupt register for IIC0
	Input Parameters:
			7-bit address (assuming normal mode)
			uint8_t that contains the data to send;l
*/
const uint8_t peekInt1RegBit(const int bitMask);

/*
	Enable an interrupt based on passed InterruptStatus value
	Input Parameters:
			Bit mask for intterupt to set
	Returns:
			0 for interrupt set
			1 for not set
*/
uint8_t setInterruptIIC0(const IRM bitMask);

void setI2C0Clock(const DIVA_400KHz, const DIVB_400KHz);
void setI2C1Clock(const DIVA_400KHz, const DIVB_400KHz);


#endif // !I2C_H

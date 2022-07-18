#include "I2C.h"


void initMaster0(void)
{
	SLCR_I2C_RST_CTRL = (I2C0_RST );
	while (SLCR_I2C_RST_CTRL); // Stay in here while the reset is happenening
	UART1_sendString("IIC reset....\n");

	I2C0->XIICPS_CR |= (MS | NEA | ACKEN | CLR_FIFO); // Interface to master, normal address mode, ACK enable, Clear transfer size reg and transfer FIFO contents
	I2C0->XIICPS_CR &= ~SLVMON; // slave monitor normal mode
	UART1_sendString("IIC master mode set up....\n");

	setI2C0Clock400KHz(DIVA_400KHz, DIVB_400KHz);

	UART1_sendString("I2C0 set up....\n");
}

void initMaster1(void)
{
	SLCR_I2C_RST_CTRL = (I2C1_RST);
	while (SLCR_I2C_RST_CTRL);
	UART1_sendString("IIC reset....\n");

	I2C1->XIICPS_CR |= (MS | NEA | ACKEN | CLR_FIFO);
	I2C1->XIICPS_CR &= ~SLVMON;
	UART1_sendString("IIC master mode set up....\n");

	I2C1->XIICPS_IER |= IXR_COMP;
	(readInt1RegBit(IXR_COMP)) ? (UART1_sendString("Transfer Complete Interrupt enabled....\n")) : (UART1_sendString("Interrupt not enabled....\n"));
		
	setI2C1Clock400KHz(DIVA_400KHz, DIVB_400KHz);

	UART1_sendString("I2C1 set up....\n");
}

void writeuint8_tIIC0(const uint8_t address, const uint8_t data)
{
	I2C0->XIICPS_CR &= ~RD; // Clear direction bit to enable transfer mode

	I2C0->XIICPS_DATA = data;
	I2C0->XIICPS_ADDR = address;	
}

/*
	Write a single uint8_t to IIC1 to given address
	Input Parameters:
			7-bit address (assuming normal mode)
			uint8_t that contains the data to send;
*/
void writeuint8_tIIC1(const uint8_t address, const uint8_t data)
{
	I2C1->XIICPS_CR &= ~RD; // Clear direction bit to enable transfer mode

	I2C1->XIICPS_DATA = data;
	I2C1->XIICPS_ADDR = address;
}

/*
	Read a bit from the interrupt register for IIC0
	Input Parameters:
			bitmask for the bit you want to peek
*/
const uint8_t peekInt0RegBit(const int bitMask)
{
	return I2C0->XIICPS_IMR & bitMask;
}

/*
	Read a bit from the interrupt register for IIC0
	Input Parameters:
			7-bit address (assuming normal mode)
			uint8_t that contains the data to send
*/
const uint8_t peekInt1RegBit(const int bitMask)
{
	return I2C1->XIICPS_IMR & bitMask;
}

/*
	Enable an interrupt based on passed InterruptStatus value
	Input Parameters:
			Bit mask for intterupt to set
	Returns:
			0 for interrupt set
			1 for not set
*/
uint8_t setInterruptIIC0(const IRM bitMask)
{
	I2C0->XIICPS_IER |= bitMask;
	
	if(I2C0->XIICPS_IMR & bitMask)
		return 0; 
	//else 
	return 1;
}

void setI2C0Clock(const CLK_SPEED DIVA_val, const CLK_SPEED DIVB_val)
{
	
}

void setI2C1Clock(const CLK_SPEED DIVA_val, const CLK_SPEED DIVB_val)
{

}

#include "GPIOmodule.h"
// To set up GPIO interrupt
// 1. Create int handler function for the GPIO interrupt specifically
// 2. Pass in GPIO interrupt ID, priority, and sensitivity to GIC ID interrupt initializer function
// 3. Disable interrupts
// 4. Set interrupt's sensitivity (edge/level) and polarity(active_high/_low)
// 5. Enable interrupt


// Basically the exact same as the modular fucntions on the site
// Set RGB out
// Input Parameters:
//			Int representing the GPIO bank you want to access
//			32-bit int representing the mask of the GPIO you want to enable value for
void GPIO_set_output(int bankNum, uint32_t mask)
{
	GPIO_DIRM(bankNum) |= mask;
}

// Set RGB in; just does the same as above but with the NOT of the mask preserving the other bits, and clearing the mask bits
void GPIO_set_input(int bankNum, uint32_t mask)
{
	GPIO_DIRM(bankNum) &= ~mask;
}

// Read in GPIO value
int GPIO_readInput(int bankNum, uint32_t mask)
{
	return (GPIO_DATA_RO(bankNum) & mask);
}

// This function will accept an int reg bank, uint32 GPIO mask, and an int write value (1 or 0) to write to a particular output
void GPIO_setDataOut(int bankNum, uint32_t mask, int writeValue)
{
	if (writeValue == 0)
	{
		GPIO_DATA(bankNum) &= ~mask; // Clear bit = 0
	}
	else if (writeValue == 1)
	{
		GPIO_DATA(bankNum) |= mask; // Write a 1
	}
}

// Enables the output for a given GPIO; To assert the output signal we must set the output for the GPIO, then enable it (or visa-versa) with this funciton
void GPIO_enable_output(int regNum, uint32_t mask)
{
	GPIO_OEN(regNum) |= mask;
}

// This will disable GPIO output
void GPIO_disable_output(int regNum, uint32_t mask)
{
	GPIO_OEN(regNum) &= ~mask;
}

// Turns on RGB LEDs in the IP block
void GPIO_RGB_on(void)
{
	GPIO_DATA(RGB_BANK) |= RGB_MASK; // Write a 1
	// GPIO_setDataOut(RGB_BANK, RGB_MASK, 1); // turn on all leds by ANDing the NOT the entire RGB mask
}

// Turns off RGB LEDs in the IP block
void GPIO_RGB_off(void)
{
	GPIO_DATA(RGB_BANK) &= ~RGB_MASK; // Clear bit = 0
	//GPIO_setDataOut(RGB_BANK, RGB_MASK, 0); // turn off all leds by ANDing the NOT the entire RGB mask
}

// This will enable the interrupt; 1 to enable
// Input Parameters:
//		Integer for the bank register that holds the interrupt you want to enable
//		32-bit uInt mask to OR with register
void GPIO_Interrupt_enable(int bankReg, uint32_t mask)
{
	GPIO_INT_EN(bankReg) = mask; // Writes a one to both GPIO buttons outputs; bit[18] and bit[19] in bank 1
}
//
//// This will enable the interrupt; 1 to enable
//// Input Parameters:
////		Integer for the bank register that holds the interrupt you want to enable
////		32-bit uInt mask to OR with register
//void GPIO_BTN_Interrupt_enable(void)
//{
//	GPIO_INT_EN(BTN_BANK) = mask; // Writes a one to both GPIO buttons outputs; bit[18] and bit[19] in bank 1
//}

// Disable interrupt; write 1 to desiable 
// Input Parameters:
//		Integer for the bank register that holds the interrupt you want to disable
//		32-bit uInt mask to OR with register
void GPIO_Interrupt_disable(int bankReg, uint32_t mask)
{
	GPIO_INT_DIS(bankReg) = mask; // Writes 0 to bit 18 & 19 and keeps the other values
}

// Disable all interrupts in banks 0 and 1
void GPIO_disableAllGPIOInterrupts(void) // updated name b/c I spent an hour debuging why the buttons weren't working and though this was clearing the flags, but was actually turning them off lol
{
	GPIO_INT_DIS(0) = BIT_MASK_32;
	GPIO_INT_DIS(1) = BIT_MASK_32;
	GPIO_INT_DIS(2) = BIT_MASK_32;
	GPIO_INT_DIS(3) = BIT_MASK_32; // read 1 into the entire register
}

// This will check if the BTN4 & BTN5 interrupts are enabled
void checkBTNinterruptEnable(void)
{
	uint32_t maskReg = (GPIO_INT_MASK(BTN_BANK) & (BTN4_MASK | BTN5_MASK));
	if (maskReg > 0)
	{
		UART1_sendString("Interrupt not enabled....\n"); // 1 = mask enabled -> interrupt not enabled
	}
	else {
		UART1_sendString("Interrupt enabled....\n");
	}
}

// Clears interrupt flags in the bank being passed as an argument
// Input Parameters: 
//		Integer representing the bank register you want to clear
void GPIO_clearInterruptFlags(int bankReg)
{
	GPIO_INT_STAT(bankReg) = GPIO_INT_STAT(bankReg);// any set bits will be cleared when writing 1 to reg
}

// Will clear all fo the interrupt flags
void GPIO_clearAllInterruptFlags(void)
{
		GPIO_clearInterruptFlags(0);
		GPIO_clearInterruptFlags(1);
		GPIO_clearInterruptFlags(2);
		GPIO_clearInterruptFlags(3); // Clear all banks' interrupt flags
}

void GPIO_checkInterruptDisabledBank(int bankReg)
{
	uint32_t tempReg = GPIO_INT_MASK(bankReg);
	tempReg &= BIT_MASK_32;
	UART1_printRegister(tempReg);

}	

// Sets the sensitivity type for the interrupts
// Input Parameters: 
//		Integer for the bank register that holds the interrupt you want to disable
//		32-bit uInt mask to OR with register
//		Integer for the sensitivity level desired; 0 = level-sens; 1 = edge-sens
void GPIO_setSensitivity(int bankReg, uint32_t mask, int sensitivity)
{
	if (sensitivity)
	{
		GPIO_INT_TYPE(bankReg) |= mask; // set bit
	}
	else
	{
		GPIO_INT_TYPE(bankReg) &= ~mask; // clear bit
	}
}

// Sets polarity for interrupt
// Input Parameters:
//		Integer for the bank register that holds the interrupt you want to disable
//		32-bit uInt mask to OR with register
//		Integer for the polarity; 0 = active low; 1 = active high
void GPIO_setPolarity(int bankReg, uint32_t mask, int polarity)
{
	if (polarity)
	{
		GPIO_INT_POL(bankReg) |= mask; // set bit
	}
	else
	{
		GPIO_INT_POL(bankReg) &= ~mask; // clear bit
	}
}

// This function will disable the any edge trigger for the GPIO interrupt
// Input Parameters:
//		Integer for the bank register that holds the interrupt you want to disable
//		32-bit uInt mask to OR with register
void GPIO_disableAnyEdge(int bankReg, uint32_t mask)
{
	GPIO_INT_ANY(bankReg) &= ~mask; // Clear bit => disable any_edge trigger condition
}

// Reads the interrupt status register for a passed interrupt and returns it; We want to return a masked reg so we can check which button was pressed
// Input Parameters:
//		Integer for the bank register that holds the interrupt you want to disable
//		32-bit uInt mask to OR with register
// Returns: 
//		uint32_t: Copy of the masked bank register 
uint32_t GPIO_readInterupptStatus(int bankReg, uint32_t mask)
{
	//UART1_sendString("Hit read Int Status....\nMask Reg: ");
	//UART1_printRegister(mask);
	//UART1_sendChar('\n');
	uint32_t intStatusReg = (GPIO_INT_STAT(bankReg) & mask);
	//UART1_sendString("Status Reg: ");
	//UART1_printRegister(intStatusReg);
	//UART1_sendChar('\n');
	
	return (intStatusReg);
}

// This function will read which button caused the interrupt then either enable the RGBs or disable them
// BTN4 Enables RGB LEDs; BTN5 Disables them
void GPIO_BTNinterruptHandler(void)
{
	uint32_t statusReg = GPIO_readInterupptStatus(BTN_BANK, BIT_MASK_32);
	// LED_REG |= LED4; // LED0 if we hit handler

	statusReg &= (BTN4_MASK | BTN5_MASK);
	switch (statusReg)
	{
		case BTN4_MASK:
			// UART1_sendString("Hit BTN4 mask\n");
			GPIO_RGB_on();
			UART1_sendString("RGB on....\n");
			break;
		case BTN5_MASK:
			// UART1_sendString("Hit BTN5 mask\n");
			GPIO_RGB_off();
			UART1_sendString("RGB off....\n");
			break;
		case (BTN4_MASK | BTN5_MASK): // It's hitting this one each time
			// Do nothing
			//LED_REG |= LED8; // just for testing
			UART1_sendString("Both buttons pressed....\nReturning from handler function....\n");
			break;
		default:
			UART1_sendString("Hit GPIO_BTNinterruptHandler default case....");
			break;
	}

	GPIO_clearInterruptFlags(BTN_BANK); // Clear the flags in the buttons bank register

	//delay(COUNT_VAL);
	// LED_REG |= LED5;

}

// Configure MIO pins for the Blackboard's PS-connected buttons and LEDs
void configure_PS_MIO(void)
{
	SLCR_UNLOCK = UNLOCK_KEY;	//unlock SLCRs
	MIO_50 = 0x0600; // BTN4 is LVCMOS33
	MIO_51 = 0x0600; // BTN5 is LVCMOS33
	MIO_16 = 0x1600; // RGB_LED_B is LVCMOS33 with disabled input buffer
	MIO_17 = 0x1600; // RGB_LED_R is LVCMOS33 with disabled input buffer
	MIO_18 = 0x1600; // RGB_LED_G is LVCMOS33 with disabled input buffer
	SLCR_LOCK = LOCK_KEY;	//relock SLCRs
}

// This will just pause for a moment
void delay(int delayLen)
{
	while (delayLen-- > 0) {} // While it's greater than zero It'll keep going
}

// This will return the masked register of the button 4 & 5 status register
uint32_t GPIO_returnButtonInterruptStatusBank(void)
{
	return GPIO_readInterupptStatus(BTN_BANK, BIT_MASK_32);// (BTN4_MASK | BTN5_MASK));
}

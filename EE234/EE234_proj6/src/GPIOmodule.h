#include <stdint.h>
#include "UARTmodule.h"
// MIO banks 0 and 1 are for processing system GPIO
// Bank0: MIO 0-31; Bank1: MIO 32-53; 32 = 0 => 50-32 = pin[18]
// BTN[4] = MIO50 = bit[18] in bank1; BTN[5] = MIO51 = bit[19] in bank1
// RGB LEDS: Blue = MIO16 = bit[16] in bank0; Red = MIO17 = bit[17] in bank0; Green = MIO18 = bit[18] in bank0

volatile int GPIO_BTN4_BTN5_FLAG;

// Register definitions; grabbed these from the site

// Output data register; Drive the coresponding output
#define GPIO_DATA(n)		*(((uint32_t*) 0xE000A040)+n)

// Input data register; Always show current value on the pin
#define GPIO_DATA_RO(n) 	*(((uint32_t*) 0xE000A060)+n)

// Direction register; 1 = out; 0 = in
#define GPIO_DIRM(n) 		*(((uint32_t*) 0xE000A204) + 16*n) // multiply by 16 becuase these are seperated by 0x40 which is 4*16; 0x0204 -> 0x0244 -> 0x0284 -> 0x02C4

// Output enable register
#define GPIO_OEN(n) 		*(((uint32_t*) 0xE000A208) + 16*n) // Same as above

//interrupt mask readonly reg
#define GPIO_INT_MASK(n)	*(((uint32_t *) 0xE000A20C) + 16*(n))

//interrupt enable
#define GPIO_INT_EN(n)		*(((uint32_t *) 0xE000A210) + 16*(n))

//interrupt disable
#define GPIO_INT_DIS(n)		*(((uint32_t *) 0xE000A214) + 16*(n))

//interrupt status register
#define GPIO_INT_STAT(n)	*(((uint32_t *) 0xE000A218) + 16*(n))

//interrupt edge/level sensitivity register
#define GPIO_INT_TYPE(n)	*(((uint32_t *) 0xE000A21C) + 16*(n))

//interrupt polarity register
#define GPIO_INT_POL(n)		*(((uint32_t *) 0xE000A220) + 16*(n))

//interrupt any edge register
#define GPIO_INT_ANY(n)		*(((uint32_t *) 0xE000A224) + 16*(n))

// System Level Control Register Definitions
#define SLCR_LOCK	*((uint32_t *) 0xF8000004)
#define SLCR_UNLOCK	*((uint32_t *) 0xF8000008)
#define UNLOCK_KEY	0xDF0D
#define LOCK_KEY	0x767B

//  MIO pins register definitions
#define MIO_16 *((uint32_t *)0xF8000740)
#define MIO_17 *((uint32_t *)0xF8000744)
#define MIO_18 *((uint32_t *)0xF8000748)
#define MIO_50 *((uint32_t *)0xF80007C8)
#define MIO_51 *((uint32_t *)0xF80007CC)

// RGB LED channels are bits 16-18, in bank 0
#define RGB_MASK 0x70000 // 0111 0000 0000 0000 0000
#define RGB_BANK 0

// BTN 4 & 5 are on bits 18 and 19 in bank 1
//#define BTN_MASK 0xC0000
#define BTN4_MASK 0x40000 // gets to bit[18]
#define BTN5_MASK 0x80000 // bit[19]
#define BTN_BANK 1

#define test_MASK2 0x2
#define test_MASK4 0x4
#define test_MASK8 0x8
#define test_MASK16 0x10
#define test_MASK20000 0x20000
// Just used as input variables I named them so that the code made more sense even though I comment like crazy
#define LEVEL_SENS 0
#define EDGE_SENS 1
#define ACTIVE_HIGH 1
#define ACTIVE_LOW 0

// Used the leds for debugging; just enabled a particular LED when I hit a certain point in the program
#define LED_REG *((uint32_t *)0x41210000)

#define LED0 0x01
#define LED1 0x02
#define LED2 0x04
#define LED3 0x08
#define LED4 0x10
#define LED5 0x20
#define LED6 0x40
#define LED7 0x80
#define LED8 0x100
#define LED9 0x200

#define COUNT_VAL 0x6FFFFFF
#define TEST_STR_INTR_STS "Status register returned 0....\n"
#define BIT_MASK_32 0xFFFFFFFF	 // 32 ones


// Basically the exact same as the modular functions on the site
// Set RGB out
// Input Parameters:
//			int: bank number you want access to
//			uint32_t: Mask of output bit(s) to set
void GPIO_set_output(int regNum, uint32_t mask);

// Set RGB in
void GPIO_set_input(int regNum, uint32_t mask);

// Read in GPIO value
int GPIO_readInput(int regNum, uint32_t mask);

// This function will accept an int reg bank, uint32 GPIO mask, and a uint32 write value (1 or 0) to write to a particular output
// Input Parameters:
//			int: bank number you want access to
//			uint32_t: Mask of output bit(s) to set
//			int: Value to drive bit to
void GPIO_setDataOut(int bankNum, uint32_t mask, int writeValue);

// Enables the output for a given GPIO; To assert the output signal we must set the output for the GPIO, then enable it (or visa-versa) with this funciton
// Input Parameters:
//			int: bank number you want access to
//			uint32_t: Mask of output bit(s) to set
void GPIO_enable_output(int regNum, uint32_t mask);

// This will disable GPIO output
void GPIO_disable_output(int regNum, uint32_t mask);

// Turns off RGB LEDs in the IP block
void GPIO_RGB_on(void);

// Turns off RGB LEDs in the IP block
void GPIO_RGB_off(void);

// This will enable the interrupt
// Input Parameters:
//		Integer for the bank register that holds the interrupt you want to enable
//		32-bit uInt mask to OR with register
void GPIO_Interrupt_enable(int bankReg, uint32_t mask);

// Disable interrupt
// Input Parameters:
//		Integer for the bank register that holds the interrupt you want to disable
//		32-bit uInt mask to OR with register
void GPIO_Interrupt_disable(int bankReg, uint32_t mask);

// This will check if the BTN4 & BTN5 interrupts are enabled
void checkBTNinterruptEnable(void);

// Disable all interrupts in banks 0 and 1
void GPIO_disableAllGPIOInterrupts(void);

// Clears interrupt flags in the button bank
void GPIO_clearInterruptFlags(int bankReg);

// Will clear all fo the interrupt flags
void GPIO_clearAllInterruptFlags(void);

// Sets the sensitivity type for the interrupts
// Input Parameters:
//			int: bank number you want access to
//			uint32_t: Mask of output bit(s) to set
//			int: Sensitivity you would like to set your interrupt to
void GPIO_setSensitivity(int bankReg, uint32_t mask, int sensitivity);

// Sets polarity for interrupt
// Input Parameters:
//		Integer for the bank register that holds the interrupt you want to disable
//		32-bit uInt mask to OR with register
//		Integer for the polarity; 0 = active low; 1 = active high
void GPIO_setPolarity(int bankReg, uint32_t mask, int sensitivity);

// This function will disable the any edge trigger for the GPIO interrupt
// Input Parameters:
//		Integer for the bank register that holds the interrupt you want to disable
//		32-bit uInt mask to OR with register
void GPIO_disableAnyEdge(int bankReg, uint32_t mask);

// Reads the interrupt status register for a passed interrupt and returns it; We want to return the whole reg so we can check which button was checked outside of this function
// Input Parameters:
//		Integer for the bank register that holds the interrupt you want to disable
//		32-bit uInt mask to OR with register
// Returns: 
//		uint32_t: Copy of the bank register if the interrupt happened
uint32_t GPIO_readInterupptStatus(int bankReg, uint32_t mask);


// This funciton will read which button caused the interrupt then either enable the RGBs or disable them
// BTN4 Enables RGB LEDs; BTN5 Disables them
void GPIO_BTNinterruptHandler(void);

// Configure MIO pins for the Blackboard's PS-connected buttons and LEDs
void configure_PS_MIO(void);


// This will just pause for a moment
void delay(int delayLen);

// This will return the register masked register of the button register
uint32_t GPIO_returnButtonInterruptStatusBank(void);
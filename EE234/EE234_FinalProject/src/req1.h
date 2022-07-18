#ifndef REQ1_H
#define REQ1_H
#include "interruptModule.h"
#include "UARTmodule.h"
#include <stdint.h>

// Defining registers 

//casting the integers as a pointer to an unsigned 32-bit then derefrencing it to get direct access to the registers' contents
#define FPGA_BTN_DATA	*((volatile uint32_t *)0x41200000)	// read only; bit[3] -> bit[0] represent BTN[3] -> BTN[0]
#define LED_DATA		*((volatile uint32_t *)0x41210000)	// write; 1 = on, 0 = off; [9] -> [0] = LED[9] -> LED[0]
#define SW_DATA			*((volatile uint32_t *)0x41220000)	// read; bit[11]->[0] = SW[11]->SW[0]
#define SSD_CTRL		*((volatile uint32_t *)0x43C10000)
#define SSD_DATA		*((volatile uint32_t *)0x43C10004)

#define SSD_DIG0 0xFF
#define SSD_DIG1 0xFF00
#define SSD_DIG2 0xFF0000
#define SSD_DIG3 0xFF000000
#define DP3_EN	 0x808080 // Will turn off all DP bits except the most significant DP

#define SW0		0x00
#define SW1		0x01
#define SW2		0x02


#define MODE_SEL_SW_MASK 0xC00	// Mask for the upper 2 switches
#define RGB_SEL_SW_MASK 0x7		// Mask lower 3 switches which will be for selecting which of the LEDs to change

#define BTN0 0x1 // Increment
#define BTN1 0x2 // Decrement
#define BTN2 0x4 // Nufin
#define BTN3 0x8 // Reset brightness

// 0-6; Multiplying (n) by 4 because the offsets shift by 16 not 4; i.e. 0x00 -> 0x10 -> 0x20 -> 0x30 -> 0x40 -> 0x50
#define RGB_PWM_EN(n)			*(((volatile uint32_t *)0x43C00000) + 4*(n)) // write only; bit[0] is enable bit 1 = on
#define RGB_PWM_WINDOW_VAL(n)	*(((volatile uint32_t *)0x43C00004) + 4*(n))	// Divides down a 100MHz clock to determine pulse window period -> RGB_PWM_WINDOW_VAL / 100MHz = window period
#define RGB_PWM_PULSE_WIDTH(n)	*(((volatile uint32_t *)0x43C00008) + 4*(n))	// Divides the window period to define the pulse width

#define WINDOW_VAL_255 (uint32_t)255

#define ONES_PLACE_MASK		0xF00
#define TENS_PLACE_MASK		0xF000
#define HUNDREDS_PLACE_MASK 0xF0000


// Delay program by waiting for GTC flag; will pause for ~0.156 ms
void delay(void);

// This will enable all of the RGB PWM circuits and set the Window period
void intitializeAllRgbLed(void);

// This will initialize the SSD to BCD/Hex mode and enable it
void initSsd(void);

// This will increment at a rate of 25% a second
// Input Parameters:
//		int: user choice for RGB to decrement; val btwn 1 & 6
void incrementBrightness(int rgbIndex);

// This will decrement at a rate of 25% a second
// Input Parameters:
//		int: user choice for RGB to decrement; val btwn 1 & 6
void decrementBrightness(int rgbIndex);

// Reset the brightness of all 6 of the RGB LEDs
void resetAllRgbBrightness(void);

// Uses the Double-Dabble Binary to BCD conversion algorithm
// Input Parameters:
//		int: index of RGB to convert
//		uint32_t: int to hold the hundreds place
//		uint32_t: int for tens place	
//		uint32_t: int for ones place
// Precondition: rgbIndex between 0-5
void binary_to_BCD(int rgbIndex, uint32_t* hundredsPlace, uint32_t* tensPlace, uint32_t* onesPlace);

// Will update the SSD by forming a new register then setting the SSD reg to that newly formed one
// Input Parameters:
//		int: Index of RGB user wants to display; 1 - 6
void updateSevSegDisplay(int rgbIndex);

#endif // !REQ1_H




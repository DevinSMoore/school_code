#ifndef REQ2_H
#define REQ2_H



// Information: https://www.realdigital.org/doc/e9e203ee8948f149613078755d6ece41
#include "req1.h"

#define XADC_CTRL0 *((uint32_t *)0x43C50300) // Control register; Write which component we wnat to read data from into bits [4:0]; 0x0 = TEMP; 0x3 for Vp which is the potential difference btwn Vp and Vn, Vn is gnd -> Vp-0 = Vp -> Unipolar = Bipolar in our case 
#define VP_SEL 0x3

#define XADC_VP_DATA *((uint32_t *)0x43C5020C) // Data comes in on bits[15:4]; from site V = data/4096; 12 bits gives us 2^12 resolution -> 4096

// Enable poteniometer input int ADC by writing 0x3 (VP_SEL) into control reg 0
void potentiometerReadEnable(void);

// Read in and scale shifted data up to 255 to get our brightness; 255 / 4096; if we do 256/4096 we get 1/16 which is just a right shift of 4 after the initial shift; The values right shifted 4 are off by +0.39% (theoretical = 255/4096) which I'm ok with
// Returns:
//		uint32_t: scaled potentiometer data between 0 and 255
uint32_t readAndScalePotentiometerData(void);

// Will set the selected RGB's brightness to the passed value
// Input Parameters:
//		int: Which rgb are you adjusting the brightness of; values between 1-6 bitte
//		uint32_t: Value between 0-255 representing the brightness level to set
void ADC_setBrightness(int rgbSel, uint32_t data);

#endif // !REQ2_H
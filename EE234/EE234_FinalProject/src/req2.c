#include "req2.h"

// Enable poteniometer input int ADC by writing 0x3 (VP_SEL) into control reg 0
void potentiometerReadEnable(void)
{
	XADC_CTRL0 &= ~VP_SEL; 
	XADC_CTRL0 |= VP_SEL;	// clear any previous entry then set new value
}

// Read in and scale shifted data up to 255 to get our brightness; 255 / 4096; if we do 256/4096 we get 1/16 which is just a right shift of 4 after the initial shift; The values right shifted 4 are off by +0.39% (theoretical = 255/4096) which I'm ok with
// Returns:
//		uint32_t: scaled potentiometer data between 0 and 255
uint32_t readAndScalePotentiometerData(void)
{
	// preserve only the 12 bits of concern then shift by 8 (initial 4 shift then 4 more)
	return (XADC_VP_DATA & 0xFFF0) >> 8; // The data I read in from the potentiometer never got above 254 so (I tried a lot of different math with different data types to try to get it to go to 255 cap but I couldn't I'm a dummy)
}

// Will set the selected RGB's brightness to the passed value
// Input Parameters:
//		int: Which rgb are you adjusting the brightness of; values between 1-6 bitte
//		uint32_t: Value between 0-255 representing the brightness level to set
void ADC_setBrightness(int rgbSel, uint32_t data)
{
	RGB_PWM_PULSE_WIDTH(--rgbSel) = data; // pre decrement rgbSel to match real indicies then set that particular RGB to the data value which is between 0-255
}

#include "req1.h"

// Delay program by waiting for GTC flag; will pause for ~0.156 ms
void delay(void)
{
	int counter = 0;
	while (counter < 10)
	{
		if (GLOBAL_GTC_FLAG == 1) // ok so 10/64th of a second is ~.156 ms I tuned this for debouncing, and to just pause while waiting for users finger to lift off the button after pressing
		{
			GLOBAL_GTC_FLAG = 0;
			counter++;
		}
	}
}


// This will enable all of the RGB PWM circuits and set the Window period
void intitializeAllRgbLed(void)
{
	for (int i = 0; i < 6; i++)
	{
		RGB_PWM_WINDOW_VAL(i) = WINDOW_VAL_255; // Sets each window period value to 255
		RGB_PWM_EN(i) = 1; // Will loop through setting all enable bits to 1
	}
}

// This will initialize the SSD to BCD/Hex mode and enable it
void initSsd(void)
{
	SSD_CTRL = 0x01;	// enable default mode (bit[1] = 0); Enable SSD (bit[0] = 1)
	SSD_DATA = DP3_EN;	// will set everythint to zero except the lower 3 decimal places to disable them 
}

// This will increment at a rate of 25% a second
// Input Parameters:
//		int: user choice for RGB to decrement; val btwn 1 & 6
void incrementBrightness(int rgbIndex)
{
	// rgbIndex - 1 to offset it so we're looking at the real RGB indicies
		if (RGB_PWM_PULSE_WIDTH(rgbIndex - 1) < WINDOW_VAL_255) // enforce boundary conditions
		{
			(RGB_PWM_PULSE_WIDTH(rgbIndex - 1))++; // Increment
		}
}

// This will decrement at a rate of 25% a second
// Input Parameters:
//		int: user choice for RGB to decrement; val btwn 1 & 6
void decrementBrightness(int rgbIndex)
{
	// rgbIndex-- to look at the real RGB indicies
		if (RGB_PWM_PULSE_WIDTH(--rgbIndex) > 0) // enforce boundary conditions
		{
			(RGB_PWM_PULSE_WIDTH(rgbIndex))--;
		}
}

// Reset the brightness of all 6 of the RGB LEDs
void resetAllRgbBrightness(void)
{
	for (int i = 0; i < 6; i++)
	{
		(RGB_PWM_PULSE_WIDTH(i)) = 0; // Loop through and set each RGBs pulse width to 0
	}
}

// Uses the Double-Dabble Binary to BCD conversion algorithm
// Input Parameters:
//		int: index of RGB to convert
//		uint32_t: int to hold the hundreds place
//		uint32_t: int for tens place	
//		uint32_t: int for ones place
// Precondition: rgbIndex between 0-5
void binary_to_BCD(int rgbIndex, uint32_t* hundredsPlace, uint32_t* tensPlace, uint32_t* onesPlace)
{
	uint32_t binaryToBcdReg = (RGB_PWM_PULSE_WIDTH(rgbIndex) & 0xFF), // Anding with 0xFF to clear any possible upper bits in the reg we're going to manipulate
		tempReg = 0;

	//UART1_printRegister(binaryToBcdReg);

	// our data length is 8, and the pulse width registers will all have values between 0 and 255 in the least significant byte
	for (int i = 0; i < 8; i++)
	{
		tempReg = (binaryToBcdReg & ONES_PLACE_MASK) >> 8; // Shift right by 8 to place the ones place digit into the LS nibble
		
		if (tempReg >= 5) // if the binary value in this place is greater than or equal to 5 then we want to add 3 to that binary number
		{
			tempReg += 3; // add 3
			tempReg <<= 8; // Shift back into ones place
			binaryToBcdReg &= ~ONES_PLACE_MASK; // clear current value
			binaryToBcdReg |= (tempReg & ONES_PLACE_MASK); // set ones place
		}

		tempReg = (binaryToBcdReg & TENS_PLACE_MASK) >> 12; // Shift right by 12 to place tens in the LS nibble
		
		if (tempReg >= 5)
		{
			tempReg += 3; // add 3
			tempReg <<= 12; // Shift back into tens place
			binaryToBcdReg &= ~TENS_PLACE_MASK; // clear current value
			binaryToBcdReg |= (tempReg & TENS_PLACE_MASK); // set tens place
		}

		tempReg = (binaryToBcdReg & HUNDREDS_PLACE_MASK) >> 16; // Shift right by 16 to place hundreds in the LS nibble

		if (tempReg >= 5)
		{
			tempReg += 3; // add 3
			tempReg <<= 16; // Shift back into hundreds place
			binaryToBcdReg &= ~HUNDREDS_PLACE_MASK; // clear current value
			binaryToBcdReg |= (tempReg & HUNDREDS_PLACE_MASK); // set hundreds place
		}

		// Shift left by 1
		binaryToBcdReg <<= 1;

		// If we haven't shifted 8 times then loop again
	}

	// should have a nice converted register here
	//UART1_printRegister(binaryToBcdReg);

	binaryToBcdReg >>= 8; // shift right 8 to get the ones place in the lower nibble
	*onesPlace = binaryToBcdReg & 0xF;

	binaryToBcdReg >>= 4; // shift right 4 to get the tens place in the lower nibble
	*tensPlace = binaryToBcdReg & 0xF;

	binaryToBcdReg >>= 4; // shift 4 again for the hundreds
	*hundredsPlace = binaryToBcdReg & 0xF;
}

// Will update the SSD by forming a new register then setting the SSD reg to that newly formed one
// Input Parameters:
//		int: Index of RGB user wants to display; 1 - 6
void updateSevSegDisplay(int rgbIndex)
{
	uint32_t hundreds = 0, tens = 0, ones = 0, tempReg = 0;
	binary_to_BCD((rgbIndex - 1), &hundreds, &tens, &ones);

	// So we're going to build the register from left to right starting at the right then shifting it all left chunk by chunk
	// [RGB we're incrementing/decrementing] : [Hundreds Dig] : [Tens Dig] : [Ones Dig]

	// Set dig3
	tempReg |= (rgbIndex);

	tempReg <<= 8; // Shift left by 8 to get at digit2

	tempReg |= (hundreds & 0xFF); // Set dig2

	tempReg <<= 8; // Shift left by 8 to get at digit1

	tempReg |= (tens & 0xFF); // Set dig1

	tempReg <<= 8; // Shift left by 8 to get at digit0

	tempReg |= (ones & 0xFF); // Set dig0

	tempReg |= DP3_EN;

	SSD_DATA = tempReg;
}

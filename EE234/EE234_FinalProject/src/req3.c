#include "req3.h"

// Reads in the twelve characters and spits them into an array
// Input Parameters:
//		char array: the Hex string that will contain our read in characters hex string
void readHexString(char hexString[])
{
	for (int i = 0; i < 12; i++) // iterate 12 times
	{
		(hexString[i]) = UART1_readChar(); // Place in the characters starting from index[11] -> index[0] b/c we get MSB first from the PC
	}

	delay();
	UART1_clearRxFIFO(); // Clear out Rx FIFO
}

// THis will validate all of the characters we read in from the user
// Input Parameters:
//		char array: user input to verify
// Returns:
//		int: 1 = string verified; 0 = a character in the string was not a valid hex digit
int verifyHexString(char hexString[])
{	
	int success = 1; // Set initially to 1. We'll flip it if one of the chars is not a valid HEX digit and handle it outside this function
	char tempChar = '\0';

	for (int i = 0; i < 12; i++)
	{
		tempChar = hexString[i];

		if ((tempChar <= '9' && tempChar >= '0'))
		{

		}
		else if (tempChar <= 'F' && tempChar >= 'A') // if tempChar is a valid HEX digit A-F
		{

		}
		else if (tempChar <= 'f' && tempChar <= 'a') // valid HEX digit a-f
		{

		}
		else
		{
			// A valid HEX digit was not read in -> set success to 0
			success = 0;
		}
	}

	return success;
}

// Will process the user input hex string and set the proper values in each register in a row
// Input Parameters:
//		char array: the verified hex string
void setDutyCycleFromHexString(char hexString[])
{
	char tempChar = '\0';
	uint32_t tempInt = 0;
	SSD_DATA = DP3_EN;
	for (int i = 0; i < 12; i += 2)
	// basically the pattern will go (left term = i; right = j): 0 + 0 = 0 -> 0 + 1 = 1 -> 2 + 0 = 2 -> 2 + 1 = 3 -> ... -> 10 + 0 = 10 -> 10 + 1 = 11; [11] is the last index
	{
		// -- FROM VIDEO -- fixed the order that data gets set to registers by setting rgbIndex to 5 - i/2 which will go 5 -> 4 -> 3 -> 2 -> 1 -> 0; meaning that the order you type in hex digits in will be reflected on the RGBs and the SSD
		int rgbIndex = 5 - (i / 2); // Dividing i by 2 will give us the indicies each step of the way
		RGB_PWM_PULSE_WIDTH(rgbIndex) = 0; // Clear current register value

		for (int j = 0; j < 2; j++)
		{
			tempChar = hexString[i + j];

			if ((tempChar <= '9' && tempChar >= '0'))
			{
				tempInt = ((tempChar - ASCII_0) & 0xF);

				RGB_PWM_PULSE_WIDTH(rgbIndex) |= tempInt;

				if(j == 0) // This will check if we're loading in the Most significant hex digit; If we are we will shift left by a nibble
				{
					RGB_PWM_PULSE_WIDTH(rgbIndex) <<= 4;
				}
			}
			else if (tempChar <= 'F' && tempChar >= 'A') // if tempChar is a valid HEX digit A-F
			{
				tempInt = ((tempChar - 0x37) & 0xF);
				// {ASCII_F,ASCII_A} = {0x46,0x41} -> to get to F from 0x46 we take away 0x37: 0x46 - 0x37 = 0x0F
				RGB_PWM_PULSE_WIDTH(rgbIndex) |= tempInt;
				
				if(j == 0)
				{
					RGB_PWM_PULSE_WIDTH(rgbIndex) <<= 4;
				}
			}
			else if (tempChar <= 'f' && tempChar <= 'a') // valid HEX digit a-f
			{
				tempInt = ((tempChar - 0x57) & 0xF);
				// same logic as F-A but take away an additional 0x20 -> 'f' = 0x66 - 0x57 = 0x0F
				RGB_PWM_PULSE_WIDTH(rgbIndex) |= (tempChar - 0x57);

				if(j == 0) // This will check if we're loading in the Most significant hex digit; If we are we will shift left by a nibble
				{
					RGB_PWM_PULSE_WIDTH(rgbIndex) <<= 4;
				}
			}
			else
			{
				// We shouldn't hit this condition if we verified the string before passing into here
			}
		} // end of inner loop
	}// end outer loop

}

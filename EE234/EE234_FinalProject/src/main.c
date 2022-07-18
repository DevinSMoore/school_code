//	Programmer: Devin Moore
//	Class : EE234 Clint Cole
//
//	Assignment: Final Exam Project
//
//	Description: For this final project we are adjusting the brightness of the RGB LEDs on the blackboard
//				in different modes and Switch 11 and 10 control the mode you're in:
//						Mode 1: (00) Push button 0 will increment, and BTN[1] will decrement the brightness 
//								of a selected RGB LED at ~25% a second. BTN[3] will reset the brightness.
//								Brightness level will be displayed to SSD digits [2]-[0], SSD[3] will show
//								which RGBs brightness is being adjusted.
//
//						Mode 2: (01) The potentiometer (XADC POT) on the blackboard will control the LED brightness.
//								BTN 3 will reset the brightness
//
//						Mode 3: (10) Pass in 12 HEX digits from PC (through UART) and set RGB brightness with values.
//								BTN 3 will again reset, and current RGB SW selection will show it's value on the SSD

#include "req1.h"
#include "req2.h"
#include "req3.h"
#include "UARTmodule.h"

#define BTN_MODE		0x000
#define ADC_MODE		0x400 // SW[10] alone
#define UART_INPUT_MODE 0x800 // SW[11] alone


int main(void)
{
	initUART1();
	initSsd();
	enableInterrupts();
	intitializeAllRgbLed();
	potentiometerReadEnable();

	int pulseWidthSum = 0, tempInt = 0, setBrightnessFlag = 0;
	uint32_t dataReg = 0;
	char hexString[12]; // not actually a c string b/c not terminating in null char


	while (1) // stay in here forrreeeevvvvverrrrrr
	{
		uint32_t modeSelect = (SW_DATA & MODE_SEL_SW_MASK);
		uint32_t rgbSelect = (SW_DATA & RGB_SEL_SW_MASK); // set users selections for RGB and mode

		switch(modeSelect)
		{
			case BTN_MODE:
				UART1_sendString("\nEntering button mode....\n");

				while(modeSelect == BTN_MODE) // Loop while in this mode
				{
					if(GLOBAL_GTC_FLAG) // 1/64th of a second has passed if the flag is set
					{
						GLOBAL_GTC_FLAG = 0;

							switch (FPGA_BTN_DATA) // Check which button user is pressing
							{
								case BTN0:
									if (rgbSelect <= 6 && rgbSelect >= 1)
									{
										incrementBrightness(rgbSelect); // Increment the brightness of the selection by 1/255th of the total brightness
										updateSevSegDisplay(rgbSelect); // Update incremented RGB
									}
									else// switches outside bounds
									{
										UART1_sendString("Please select an RGB value between 1 and 6....\n");
										delay();
									}

									break;
								case BTN1:
									if (rgbSelect <= 6 && rgbSelect >= 1)
									{
										decrementBrightness(rgbSelect); // Decrement by 1
										updateSevSegDisplay(rgbSelect); // Set new duty cycle
									}
									else
									{
										UART1_sendString("Please select an RGB value between 1 and 6....\n");
										delay();
									}
									break;
								case BTN2:
									UART1_sendString("No function available for BTN2....\n");
									delay();
									break;
								case BTN3:
									// sum all of the pulse width REGs if any are not zeroed out then we reset the values
									pulseWidthSum = RGB_PWM_PULSE_WIDTH(0) + RGB_PWM_PULSE_WIDTH(1) + RGB_PWM_PULSE_WIDTH(2) + RGB_PWM_PULSE_WIDTH(3) + RGB_PWM_PULSE_WIDTH(4) + RGB_PWM_PULSE_WIDTH(5); 

									if(pulseWidthSum != 0)
									{
										resetAllRgbBrightness();
										SSD_DATA = DP3_EN; // Reset SSD to all zeros and most sig. DP EN
										UART1_sendString("Brightness reset....\n");
									}
									else
									{
										UART1_sendString("Brightness already at zero....\n");
									}
									delay();
									break;
								default :
									// Default for button select -> do nothing
									break;
							}

							rgbSelect = (SW_DATA & RGB_SEL_SW_MASK);
							modeSelect = (SW_DATA & MODE_SEL_SW_MASK); // re-check SW reg for mode and rgb
						} // Loop back to check GTC flag

					}// end button mode while loop

				break;

			case ADC_MODE:
				UART1_sendString("Entered ADC Mode!....\n");

				while (modeSelect == ADC_MODE) // Continue until user switches modes
				{
					if (rgbSelect <= 6 && rgbSelect >= 1)
					{
						dataReg = readAndScalePotentiometerData(); 	// value between 0-255 is returned

						ADC_setBrightness(rgbSelect, dataReg);		// pass in user selection and ADC data

						updateSevSegDisplay(rgbSelect);
					}
					if (FPGA_BTN_DATA == BTN3)
					{
						pulseWidthSum = RGB_PWM_PULSE_WIDTH(0) + RGB_PWM_PULSE_WIDTH(1) + RGB_PWM_PULSE_WIDTH(2) + RGB_PWM_PULSE_WIDTH(3) + RGB_PWM_PULSE_WIDTH(4) + RGB_PWM_PULSE_WIDTH(5);

						if(pulseWidthSum != 0)
						{
							resetAllRgbBrightness();
							SSD_DATA = DP3_EN; // Reset SSD to all zeros and most sig. DP EN
							UART1_sendString("Brightness reset....\n");
						}
						else
						{
							UART1_sendString("Brightness already at zero....\n");
						}
						delay();
					}
					else if (FPGA_BTN_DATA != 0) // if we've pressed a button but not button 3
					{
						UART1_sendString("Enter button mode to increment using the buttons....\n");
						delay();
					}
					modeSelect = (SW_DATA & MODE_SEL_SW_MASK);
					rgbSelect = (SW_DATA & RGB_SEL_SW_MASK);	 	// re-check SW reg and rgbSel

				} // End ADC mode loop
				break;

			case UART_INPUT_MODE:
				UART1_sendString("Entered UART input Mode!....\n");
				setBrightnessFlag = 1; // first time entering we want to set flag
				while (modeSelect == UART_INPUT_MODE)
				{
					if(setBrightnessFlag == 1) // If we have yet to set a value, or we have just set a value then print this message
					{
						UART1_sendString("Please enter a 12 digit HEX number setting the brightness for each RGB LED...\n");
						setBrightnessFlag = 0;
					}

					if (FPGA_BTN_DATA == BTN3) // There is a smarter way to do this button checking stuff and I may or may not get to it
					{
						pulseWidthSum = RGB_PWM_PULSE_WIDTH(0) + RGB_PWM_PULSE_WIDTH(1) + RGB_PWM_PULSE_WIDTH(2) + RGB_PWM_PULSE_WIDTH(3) + RGB_PWM_PULSE_WIDTH(4) + RGB_PWM_PULSE_WIDTH(5);

						if (pulseWidthSum != 0)
						{
							resetAllRgbBrightness();
							SSD_DATA = DP3_EN; // Reset SSD to all zeros and most sig. DP EN
							UART1_sendString("Brightness reset....\n");
						}
						else
						{
							UART1_sendString("Brightness already at zero....\n");
						}
						delay();
					}
					else if (FPGA_BTN_DATA != 0) // if we've pressed a button but not button 3
					{
						UART1_sendString("Enter button mode to increment using the buttons....\n");
						delay();
					}
					


					if (GLOBAL_UART1_FLAG) // 12+ bytes waiting in Rx FIFO
					{
						GLOBAL_UART1_FLAG = 0;
						readHexString(hexString);
						tempInt = verifyHexString(hexString);

						if(tempInt == 1) // string verified
						{
							setDutyCycleFromHexString(hexString); // Set all pulse windows
							UART1_sendString("Brightness Set!\n");
							setBrightnessFlag = 1; // Set the flag so we print message again for user
							delay();
							UART1_clearRxFIFO(); // Clear out Rx FIFO

						}
					}

					modeSelect = (SW_DATA & MODE_SEL_SW_MASK);
					rgbSelect = (SW_DATA & RGB_SEL_SW_MASK);

					if (rgbSelect <= 6 && rgbSelect >= 1)
					{
						updateSevSegDisplay(rgbSelect); // re-check user selection of rgb and mode, then update SSDs
					}

				} // End UART mode loop
				break;

			default:

				break;
		}
	}
	return 1;
}

#include "req5.h"

// Blink the led the passed number of times btwn 1 and 9
// Input Parameters:
//		int: Number between 1 and 9 representing the number of times the LED will toggle
void ledBlinkNtimes(const int blinkCycles);

void delaySome(uint32_t delayCycles);

#define A_LOT 0xCFFFFF

// Defining states for ledBlink funciton
#define OFF 0
#define ON 1
#define START (uint32_t)0x40000 // this is the mask to button 4
#define RESTART (uint32_t)0x80000 // BTN 5 mask


int main(void)
{
	int convertedInput = 0;

	initUART1();
	proj5_initGPIO();
	enableInterrupts();
	while (1)
	{
		if (UART_RX_NOT_EMPTY_FLAG) // There are characters waiting in the FIFO
		{
			//UART1_sendString("Entering UART interrupt set check....\n");
			req5_UART1_interruptHandler(&convertedInput);
			delaySome(A_LOT);
			UART1_clearRxFIFO();

		//	UART1_printInt(convertedInput);
			//UART1_sendChar('\n');
			if (convertedInput > 0) // Blink N times if valid input
			{
				ledBlinkNtimes(convertedInput); // blink 1-9 times
			}
			else if (convertedInput == 0)
			{
				UART1_sendString("Please enter an Integer between 1 and 9....\n");
			}
			else if (convertedInput < 0)
			{
				UART1_sendString("Please enter an Integer....\n");
			}
			UART1_clearRxFIFO();
		}

	}
	return 1;
}




// Blink the led the passed number of times btwn 1 and 9; ok this does more than Blink N times but I'm not changing it...
// Input Parameters:
//		int: Number between 1 and 9 representing the number of times the LED will toggle
void ledBlinkNtimes(const int blinkCycles)
{
	int blinkCount = 0, countState = OFF;
	uint32_t buttonReg = 0;

	UART1_sendString("Count limit: ");
	UART1_printInt(blinkCycles);
	UART1_sendChar('\n');
	UART1_sendString("Press button 4 to begin the count....\n");
	UART1_sendString("While the counting, Button 5 will reset the count then resume....\n");

	while (blinkCount < blinkCycles * 2) // Scale blink cycles by 2 to accomidate the fact that we're doing 2 cycles of this loop a second which will be 1 LED cycle
	{
		if (GPIO_BTN4_BTN5_FLAG) // button pressed enter swtich statement
		{
			buttonReg = req5_GPIO_interruptHandler();
			//UART1_sendString("Button was pressed....\n");


			//UART1_printRegister(buttonReg);
			switch (buttonReg)
			{
				case START: // => begin count; set state to ON if current count state is off
					if (countState == OFF)
					{
						UART1_sendString("Count beginning....\n");
						GTC_globalTimer_enable();
						countState = ON;
					}
					else // print this then return to loop
					{
						UART1_sendString("Count already in progress....\n");
					}
					break;
				case RESTART: // => pause count; set state to PUASED; return to loop
					if (countState == ON)
					{
						GTC_globalTimer_disable();
						// GTC_clearGlobalTimer(); // reset global timer
						blinkCount = 0; // Reset local timer
						UART1_sendString("Count reset and resuming....\n");
						GTC_globalTimer_enable();
					}
					else // print this then return to loop
					{
						UART1_sendString("Count has not begun yet....\n");
					}
					break;
				default:
					//UART1_sendString("Hit default case....\n");
					return; // go back to main
			}

		}
		else if (countState == ON && !GPIO_BTN4_BTN5_FLAG) // If we're not pressing the button and we're in the counting state
		{
			if (GTC_flag) // Counter flag is set -> increment value
			{
				//UART1_sendString("Hit increment....");
				GTC_interruptIncrementer(&blinkCount); // blinkCount++ and reset GTC interrupt flags
				
				if ((blinkCount % 2) == 1) // if it's odd turn it on
				{
					GPIO_RGB_on();
					//UART1_sendString("RGB should be on....\n");
				}
				else if ((blinkCount % 2) == 0) // even turn it off
				{
					UART1_sendString("Count: ");
					UART1_printInt(blinkCount / 2);
					UART1_sendChar('\n');
					GPIO_RGB_off();
					//UART1_sendString("RGB should be off....\n");
				}
			}

		}
	}

	UART1_sendString("Count ending....\nPlease enter another count value....\n");
	
	GTC_globalTimer_disable(); // Stop count
	GTC_resetTimerAndComparitor(); // reset global timer
	UART1_clearRxFIFO(); // Clear input before returning to main
}

void delaySome(uint32_t delayCycles)
{
	if(delayCycles > 0)
	{
		delay(--delayCycles);
	}
}

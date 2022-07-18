#include "req4.h"

int main(void)
{
	initUART1();
	enableInterrupts();
	
	int GTC_count = 0;
	while (1)
	{
	
		// UART1_sendString("Start of loop....\n");
		if (GTC_flag)
		{
			GTC_flag = 0;
			GTC_secondCounterInterruptHandler(&GTC_count);
		}
		else if (UART_RX_NOT_EMPTY_FLAG)
		{
			UART_RX_NOT_EMPTY_FLAG = 0;
			// UART1_sendString("Hit UART_RX_NOT_EMPTY_FLAG true....\n");
			while (UART1_RxEmptyCheck() == 0) // while Recieve FIFO is not empty
			{
				// LED_REG |= 0b0100; // Turn on LED[2] if we hit this condition in this function; Used to debug
				// UART1_sendString("Hit UART_RX_NOT_EMPTY_FLAG true....\n");
				UART1_sendChar(UART1_readChar()); // read char send char, beep boop
			}

			UART1_clearInterruptFlags();
		}
	}

	return 1;
}

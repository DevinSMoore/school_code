#include "req1.h"

int main(void)
{
	initUART1();
	// LED_REG |= 0b1000; // Turn on led[3] if we hit this line
	enableInterrupts();

	for (;;);

	return 1;
}

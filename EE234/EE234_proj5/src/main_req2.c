#include "req2.h"

int main(void)
{
	initUART1();
	proj5_init(); // Enables and configures button and RGBs
	enableInterrupts();

	for (;;);

	return 1;
}

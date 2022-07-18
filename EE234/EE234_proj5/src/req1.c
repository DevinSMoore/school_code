#include "req1.h"

// void Xil_exceptionRegisterHandler(u32 Exception_id, Xil_ExceptionHandler Handler, void *Data)

// Enable trigger level interrupt and register interrupt handler
// Input Parameters: NONE
// Returns: NONE
void enableInterrupts(void)
{
	disable_arm_interrupts();

	Xil_ExceptionRegisterHandler(5, IRQ_handler, NULL); // Register our handler

	// I
	initGIC_ID(UART1_INTR_ID, 10, HIGH_LEVEL); // 10 priority is just arbitrary; basically 1 priority b/c it's in the upper 5 bits which are priority the bits

	UART1_Rx_singleByteInterrupt_Init(); // Initialize UART1 Rx line trigger level interrupt to 1 Byte in FIFO
	enable_arm_interrupts();

}


// Will check the ICCIAR register which holds the interrupt ID being passed by the GIC and service any interrupts
void IRQ_handler(void* data)
{
	uint32_t ID = ICCIAR;

	switch (ID) // This register will hold the ID of the interrupt that was triggered
	{
	case UART1_INTR_ID:
		LED_REG |= 0x1; // Turn on LED0 if we hit this function; Used for debugging
		UART1_intHandler_clearAndEchoRx(); // Will read in all data from Rx FIFO and echo it to the Tx FIFO
		break;

	default:
		// boop
		break;
	}

	ICCEOIR = ID; // Write the interrupt ID that was acknowledged to tell GIC that we handeled interrupt
}

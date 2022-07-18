#include "interruptModule.h"
#include "UARTmodule.h"


// Disables the ARM IRQ EN bit in the CPSR by setting the I bit
void disable_arm_interrupts(void)
{
	uint32_t cpsr_val = 0;
	asm("mrs %0, cpsr\n" : "=r" (cpsr_val));	//get current cpsr
	cpsr_val |= 0x80;				//set the I bit (bit7)
	asm("msr cpsr, %0\n" : : "r" (cpsr_val));	//writeback modified value
	return;

}

// Enables the ARM IRQ EN bit in the CPSR; Clearing the I bit in the CPSR enables IRQ interrupts
void enable_arm_interrupts(void)
{
	uint32_t cpsr_val = 0;
	asm("mrs %0, cpsr\n" : "=r" (cpsr_val));	//get current cpsr
	cpsr_val &= 0xFFFFFF7F;						//clear the I bit (bit7)
	asm("msr cpsr, %0\n" : : "r" (cpsr_val));	//writeback modified value
	return;
}

// Enable trigger level interrupt and global timer comparitor interrupt with auto-increment
// Input Parameters: NONE
// Returns: NONE
void enableInterrupts(void)
{
	disable_arm_interrupts();

	ICDDCR_gicDistributor_enableDisable(DISABLE);

	Xil_ExceptionRegisterHandler(5, IRQ_handler, NULL); // Register our handler

	ICCICR_IRQ_passthroughDisable();
	ICCPMR_setCpuPriorityBound(255); // Handle all interrupts

	// In my projects I had much more generalized GIC functions (did chal1 for proj5) but I overdid the specificity here a bit; w/e it works
	// Disabling interrupt IDs and clearing CPU targets (only the one cpu really)
	GTC_disable_tarCpu();
	GTC_disable_intrID();

	UART1_disable_tarCpu();
	UART1_disable_intrID();

	// Setting sensitivity and priority for UART1 and GTC
	GTC_setPriority();
	GTC_setSensitivity();

	UART1_setPriority();
	UART1_setSensitivity();

	// Configure GTC and UART1 interrupts
	enableGtcInterrupt(); // set to auto-increment mode at ~64Hz
	enableUart1Interrupt(); // Set to 12 byte Rx trigger val for the FIFO for req 3 UART input mode 

	// Re-enable interrupt IDs and set target CPU
	GTC_enable_intrID();
	GTC_enable_tarCpu();

	UART1_enable_intrID();
	UART1_enable_tarCpu();



	ICDDCR_gicDistributor_enableDisable(ENABLE);

	enable_arm_interrupts();

}


// Clear Interrupt status bit
void GTC_clearEventFlag(void)
{
	GTC_INTR_STS = 0x1; // Write a one to clear bit[0]
}

// Sets compare value
// Input Parameters:
//		uint32_t: compare value UPPER register value
//		uint32_t: compare value LOWER register value
void GTC_setCompareValue(uint32_t upperVal, uint32_t lowerVal)
{
	GTC_CMPVAL_UPPER = upperVal;
	GTC_CMPVAL_LOWER = lowerVal;
}

// Sets auto-increment value
// Input Parameters:
//		uint32_t: Value to increment compare reg by
void GTC_setAutoIncrementVal(uint32_t incrementVal)
{
	GTC_AUTO_INCRM_VAL = incrementVal;
}

// Clear global timer value
void GTC_resetTimerAndComparitor(void)
{
	GTC_DATA_LOWER = 0;
	GTC_DATA_UPPER = 0; // set upper and lower to zero
	GTC_setCompareValue(0, 0); // set Comparitor upper and lower reg values
}

// Shuts off the passthrough of the IRQ signal so that the CPU can handle them
void ICCICR_IRQ_passthroughDisable(void)
{
	ICCICR |= 0x3; // Or with 3 to enable lower 2 bits to allow interrupts
}

// Set control reg for interrupts; auto increment enabled; comparitor enable; global timer signal enable

void enableGtcInterrupt(void)
{
	GTC_CONTROL_REG = ~(INCRM_EN | INTERRUPT_EN | CMPR_EN | GTC_EN); // Turns off GTC settings, does not touch the prescaler

	GTC_resetTimerAndComparitor();
	GTC_setAutoIncrementVal(INCRM_VAL_64HZ);
	GTC_setCompareValue(0, INCRM_VAL_64HZ);// set upper bit to 0 lower to 0x4F78D9

	GTC_CONTROL_REG = (INCRM_EN | INTERRUPT_EN | CMPR_EN | GTC_EN); // Turn on the counter with comparator EN, auto-increment EN, and interrupt EN

}

// This function will set the UART level interrupt to 1 byte and enable it
void enableUart1Interrupt(void)
{
	UART1_disableAllInterrupts();
	UART1_setRxLevelInterruptVal(12); // interrupt when we hit 12 bytes in the Rx FIFO
	UART1_RxLevelInterrupt_Enable();
}

// Will check the ICCIAR register which holds the interrupt ID being passed by the GIC and service any interrupts
void IRQ_handler(void* data)
{
	uint32_t ID = ICCIAR;
	switch (ID) // This register will hold the ID of the interrupt that was triggered
	{
	case UART1_INTR_ID:
		//UART1_sendString("Hit UART interrupt....\n");
		GLOBAL_UART1_FLAG = 1;
		UART1_clearInterruptFlags();
		break;
	case GLOBAL_TIMER_INTR_ID:
		//UART1_sendString("Hit GTC interrupt....\n");
		GLOBAL_GTC_FLAG = 1;
		GTC_clearEventFlag();
		break;
	default:
		//UART1_sendString("Hit default case in IRQ_handler....\n");
		break;
	}
	ICCEOIR = ID; // Write the interrupt ID that was acknowledged to tell GIC that we handeled interrupt
}

// This will enable or disable the GIC distributor; 
// Input Parameters: 
//			32-bit Int representing state you want GIC distributor in; 0 = disable; 1 = enable
void ICDDCR_gicDistributor_enableDisable(uint32_t input)
{
	ICDDCR = (input & 0x1); // 0 = disabled; 1 = enabled; AND with 1 to keep it to 1 bit which is not actually necessary (I don't think I didn't test)
}

// Conifgure priority mask, this will set the lower bound (inclusive) of the priority of the interrupts that the CPU will address
// Input Parameters: 
//			uint32_t representing the lower bound of priority; 0 = highest priority only; 255 = all interrupts will be handled by the CPU
void ICCPMR_setCpuPriorityBound(uint32_t lowerBound)
{
	ICCPMR = (lowerBound & 0xFF); // Hide upper 24 bits
}


// GTC interrupt GIC config
// Will disable the target processor for the GTC by clearing bit; Interrupt ID = 27
void GTC_disable_tarCpu(void)
{
	ICDIPTR(6) &= ~(0x3000000); // 27 / 4 = 6 => reg bank for GTC int; 27 % 4 = 3 * 8 = 24 => left shift 3 by 24 to put in proper bit location for GTC intr
}

// Enable target processor for the GTC
void GTC_enable_tarCpu(void)
{
	ICDIPTR(6) |= (0x1000000); // ORR in 01 to bit[25]:bit[24] setting target CPU to, well the only one we have
}

// Will disable the ID for the GTC interrupt in the GIC by setting proper bit in ICDICER (interrupt clear enable reg)
void GTC_disable_intrID(void)
{
	// ID / 32 gets us the bank reg; (ID % 32) gets us the data bit of concern

	ICDICER(0) |= 0x8000000;// 27 / 32 = 0; 27 % 32 = 27; set bit[27] to 1 clearing interrupt enable = 0x 0800 0000
}

// Enable ID for GTC interrupt in the GIC by setting proper bit in proper ICDISER (interrupt set enable) register
void GTC_enable_intrID(void)
{
	ICDISER(0) |= 0x8000000;// 27 / 32 = 0; 27 % 32 = 27; set bit[27] to 1 enable interrupt
}

// Set the priority to 8 for the GTC interrupt in the GIC
void GTC_setPriority(void)
{
	// ID / 4 gets regNum; (id % 4) gets us the data chunk (8-bit; only upper 5 bits used) that we care about;
	ICDIPR(6) &= ~(0xF8000000); // clear upper chunk then set priority to 8

	ICDIPR(6) |= (0x08000000); // 0x08 shifted left by 24 into the upper 8 bits
}

// Set sensitivity to high level for the GTC
void GTC_setSensitivity(void)
{
	// ID / 16 gets sensitivity register; ID % 16 gets (2-bit) data chunk of concern (then to get the amount to shift we multiply the (ID % 16) by 2 because our total bit width is 32
	ICDICFR(1) &= ~(0xC00000); // Clears bits [24] & [23]
	ICDICFR(1) |= (HIGH_LEVEL << 22);
}


// UART 1 to the PC GIC interrupt setup functions
// Disable the target processor for UART1; Interrupt ID = 82
void UART1_disable_tarCpu(void)
{
	ICDIPTR(20) &= ~(0x30000); // 82 / 4 = 20; 82 % 4 = 2 * 8 = 16
}

// Enable the target processor for UART1
void UART1_enable_tarCpu(void)
{
	ICDIPTR(20) |= (0x10000); // ORR in 01 to to bits [17] and [16] setting target to our CPU
}

// Disable ID for UART1 interrupt in the GIC
void UART1_disable_intrID(void)
{
	ICDICER(2) |= 0x40000;// 82 / 32 = 2; 82 % 32 = 18; set bit[18] to 1 = 0x 0004 0000
}

// Enable ID for UART1 interrupt in the GIC
void UART1_enable_intrID(void)
{
	ICDISER(2) |= 0x40000;// 82 / 32 = 2; 82 % 32 = 18; set bit[18] to 1 = 0x 0004 0000
}

// Set the priority to 8 for UART1 interrupt
void UART1_setPriority(void)
{
	ICDIPR(20) &= ~(0xF80000); // clearing old value

	ICDIPR(20) |= (0x80000); // 0x08 shifted left by 16 set into priority reg
}

// Set high level sensitivity for UART1
void UART1_setSensitivity(void)
{
	ICDICFR(5) &= ~(0x30); // clear bits [5] & [4]

	ICDICFR(5) |= (HIGH_LEVEL << 4); // 82 % 16 = 2 * 2 = 4; 
}

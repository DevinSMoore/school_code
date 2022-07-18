#include "GICmodule.h"
#include <stdint.h>


// This and enable arm interrupts are the only functions I grabbed from the site
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
	cpsr_val &= 0xFFFFFF7F;				//clear the I bit (bit7)
	asm("msr cpsr, %0\n" : : "r" (cpsr_val));	//writeback modified value
	return;
}



// Disable the CPU interrupt proccessor target bit for a particular ID
// Input Parameters: 32-bit int that is the ID of the interrupt of concern
// Returns: NONE
void ICDIPTR_cpuTargetReg_Disable(uint32_t ID)
{
	ICDIPTR(ID / 4) &= ~(BIT_MASK_2 << ((ID % 4) * 8)); // Clearing the bits by ANDing with the not of the mask
}

// Enable the target CPU
// Input Parameters: ID of interrupt CPU to disable
// Returns: NONE
void ICDIPTR_cpuTargetReg_Enable(uint32_t ID)
{
	ICDIPTR(ID / 4) |= 0x01 << ((ID % 4) * 8); // Setting the bits by orring with the mask
}

// Disable the interrupt by setting the bit in the proper field in the Inerrupt Clear Enable register
// Input Parameters: 32-bit int ID for the interrupt target CPU enable
// Returns: NONE
void ICDICER_interruptID_Disable(uint32_t ID)
{
	ICDICER(ID / 32) |= (1 << (ID % 32)); // Set bit at the proper register bit; for example ID#52: shiftAmnt = 52 % 32 = 20; registerNumber = ID / 32 = 3; both are correct for ID#52
}

// Enable the interrupt by setting the bit in Interrupt Set Enables register (there are 3 of these)
// Input Parameters: 32-bit int ID
// Returns: NONE
void ICDISER_interruptID_Enable(uint32_t ID)
{
	ICDISER(ID / 32) |= 1 << (ID % 32); // Same as above except the enable register
}

// This will enable or disable the GIC distributor; 
// Input Parameters: 32-bit Int representing state  you want GIC distributor in; 0 = disable; 1 = enable
// Returns: NONE
void ICDDCR_gicDistributor_enableDisable(uint32_t input)
{
	ICDDCR = (input & 0x1); // 0 = disabled; 1 = enabled; AND with 1 to keep us proper
}

// This will set the priority of a prticular interrupt ID
// Input Parameters:
//		ID for interrupt
//		MAX 5-bit value for priority level; lower = higher priority
// Returns: NONE
void ICDIPR_setInterruptPriorityValue(uint32_t ID, uint32_t priority)
{
	priority = (priority & 0x1F) << 3; // AND priority with 0x1F to enforce the 5-bit max; left shift by three to put it into the upper 5 bits
	int shiftAmt = (ID % 4) * 8; // the product of the mod val and the outer value (4 and 8 in this case) must be the size of the register (32)
	int regNum = ID / 4;

	ICDIPR(regNum) &= ~(BIT_MASK_8 << shiftAmt); // Clear previous value by shifting 0xFF to the same reg/bits then AND it with the not of 0xFF

	ICDIPR(regNum) |= (priority << shiftAmt); 
}

// This will set the priority of a prticular interrupt ID
// Input Parameters:
//		32-bit val representing ID for interrupt
//		MAX 2-bit value for sensitivity level; l1 == rising edge; 01 == high level
// Returns: NONE
void ICDICFR_setInterruptSensitivity(uint32_t ID, uint32_t sensitivity)
{
	int shiftAmt = (ID % 16) * 2; // data chunks are 8-bits still but the only 2 that matter are the lower 2
	int regNum = ID / 16;

	ICDICFR(regNum) &= ~(BIT_MASK_2 << shiftAmt); // clear

	ICDICFR(regNum) |= ((sensitivity & BIT_MASK_2) << shiftAmt); // AND with 3 to enforce 2 bit max val then Set


}

// Conifgure priority mask, this will set the lower bound (inclusive) of the priority of the interrupts that the CPU will address
// Input Parameters: 
//			uint32_t representing the lower bound of priority; 0 = highest priority only; 255 = all interrupts will be handled by the CPU
// Returns: NONE
void ICCPMR_setCpuPriorityBound(uint32_t lowerBound)
{
	ICCPMR = (lowerBound & BIT_MASK_8); // Hide upper 24 bits
}

// Disable the IRQ signal passthrough to allow CPU to receive input
// Input Parameters: NONE
// Returns: NONE
void ICCICR_IRQ_passthroughDisable(void)
{
	ICCICR |= BIT_MASK_2; // Or with 3 to enable lower 2 bits to allow interrupts
}

// This will settup the GIC for a particular ID
// Input Parameters:
//		32-bit int represetning the Interrupt ID
//		32-bit int for the priority	This must be a 5 bit value
//		32-bit int for sensitivity 3-bit value
// Returns: NONEi
void initGIC_ID(uint32_t ID, uint32_t priority, uint32_t sensitivity)
{
	ICDDCR_gicDistributor_enableDisable(DISABLE);
	
	ICCICR_IRQ_passthroughDisable(); // Allows IRQ interrupts to be handled by CPU

	ICCPMR_setCpuPriorityBound(255); // All interrupts

	ICDIPTR_cpuTargetReg_Disable(ID);
	ICDICER_interruptID_Disable(ID);

	ICDIPR_setInterruptPriorityValue(ID, priority);
	ICDICFR_setInterruptSensitivity(ID, sensitivity);

	ICDIPTR_cpuTargetReg_Enable(ID);
	ICDISER_interruptID_Enable(ID);

	ICDDCR_gicDistributor_enableDisable(ENABLE);
} // boop



#include <stdint.h>


// Defining macro constants
#define HIGH_LEVEL 0b01 
#define RISING_EDGE 0b11		 // These are used to set the sensitivity value
#define BIT_MASK_32 0xFFFFFFFF	 // 32 ones
#define BIT_MASK_8 0xFF			 // 1111 1111
#define BIT_MASK_2 0x03			 //      0011
#define ENABLE 0x01
#define DISABLE 0x00

// Interrupt ID definitions
#define GLOBAL_TIMER_INTR_ID (uint32_t)27
#define UART1_INTR_ID (uint32_t)82
#define GPIO_INTR_ID (uint32_t)52

// Copied this list from the site
// Register definitions => casting as uint32_5 pointers then dereferencing them so we get direct access to the values of the registers
//definitions for GIC configuration registers
#define ICCPMR		*((uint32_t *) 0xF8F00104)			//Priority mask reg
#define ICCICR		*((uint32_t *) 0xF8F00100)			//CPU interface control reg
#define ICDDCR		*((uint32_t *) 0xF8F01000)			//Distributor Control reg
#define ICDISER(n)	*(((uint32_t *) 0xF8F01100) + n )	//Int. set enable reg
#define ICDICER(n)	*(((uint32_t *) 0xF8F01180) + n )	//Int. Clear Enable reg
#define ICDIPR(n)	*(((uint32_t *) 0xF8F01400) + n )	//Int. Priority reg
#define ICDIPTR(n)	*(((uint32_t *) 0xF8F01800) + n )	//Int. Processor Targets reg
#define ICDICFR(n)	*(((uint32_t *) 0xF8F01C00) + n )	//Int. Configuration reg

#define ICCIAR 		*((uint32_t *)0xF8F0010C)			// Interrupt Acknowledge Register
#define ICCEOIR		*((uint32_t *)0xF8F00110)			// End of Interrupt register

// Function prototypes

// This and enable_arm are the only functions I grabbed from the site
// Enables the ARM IRQ EN bit in the CPSR
void disable_arm_interrupts(void);

// Disables the ARM IRQ EN bit in the CPSR
void enable_arm_interrupts(void);

// Disable the CPU interrupt proccessor target bit for a particular ID
// Input Parameters: 32-bit int that is the ID of the interrupt of concern
// Returns: NONE
void ICDIPTR_cpuTargetReg_Disable(uint32_t ID);

// Enable the target CPU
// Input Parameters: 32-bit in that is the ID
// Returns: NONE
void ICDIPTR_cpuTargetReg_Enable(uint32_t ID);

// Disable the passthrough of the interrupt by clearing the bit in the proper field
// Input Parameters: 32-bit int ID
// Returns: NONE
void ICDICER_interruptID_Disable(uint32_t ID);

// Disable the passthrough of the interrupt by clearing the bit in the proper field
// Input Parameters: 32-bit int ID
// Returns: NONE
void ICDISER_interruptID_Enable(uint32_t ID);

// Enable or disable the GIC distributor; pass a 0 to disable 1 to enable
// Input Parameters: Int representing state  you want GIC distributor in
// Returns: NONE
void ICDDCR_gicDistributor_enableDisable(uint32_t input);

// Set the priority of a prticular interrupt ID
// Input Parameters:
//		32-bit val representing ID for interrupt
//		MAX 5-bit value for priority level; lower = higher priority
// Returns: NONE
void ICDIPR_setInterruptPriorityValue(uint32_t ID, uint32_t priority);

// Set the priority of a prticular interrupt ID
// Input Parameters:
//		32-bit val representing ID for interrupt
//		MAX 2-bit value for sensitivity level; l1 == rising edge; 01 == high level
// Returns: NONE
void ICDICFR_setInterruptSensitivity(uint32_t ID, uint32_t sensitivity);

// Conifgure priority mask, this will set the lower bound (inclusive) of the priority of the interrupts that the CPU will address
// Input Parameters: 
//			uint8_t representing the lower bound of priority; 0 = highest priority only; 255 = all interrupts will be handled by the CPU
// Returns: NONE
void ICCPMR_setCpuPriorityBound(uint32_t lowerBound);

// Disable the IRQ signal passthrough to allow CPU to receive input
// Input Parameters: NONE
// Returns: NONE
void ICCICR_IRQ_passthroughDisable(void);

// Setup the GIC for a particular ID
// Input Parameters:
//		32-bit int representing the Interrupt ID
//		32-bit int for the priority	This must be a 5 bit value
//		32-bit int for sensitivity 3-bit value
// Returns: NONEi
void initGIC_ID(uint32_t ID, uint32_t priority, uint32_t sensitivity);


#ifndef INTERRUPTMODULE_H
#define INTERRUPTMODULE_H
#include <stdint.h>
#include "xil_exception.h"

// Global interrupt flags 
volatile int GLOBAL_GTC_FLAG;
volatile int GLOBAL_UART1_FLAG;

// Register definitions => casting as uint32_5 pointers then dereferencing them so we get direct access to the values of the registers
//definitions for GIC configuration registers
#define ICCPMR		*((uint32_t *) 0xF8F00104)			//Priority mask reg
#define ICCICR		*((uint32_t *) 0xF8F00100)			//CPU interface control reg
#define ICDDCR		*((uint32_t *) 0xF8F01000)			//Distributor Control reg
#define ICDISER(n)	*(((uint32_t *) 0xF8F01100) + (n))	//Int. set enable reg
#define ICDICER(n)	*(((uint32_t *) 0xF8F01180) + (n))	//Int. Clear Enable reg
#define ICDIPR(n)	*(((uint32_t *) 0xF8F01400) + (n))	//Int. Priority reg
#define ICDIPTR(n)	*(((uint32_t *) 0xF8F01800) + (n))	//Int. Processor Targets reg
#define ICDICFR(n)	*(((uint32_t *) 0xF8F01C00) + (n))	//Int. Configuration reg

#define ICCIAR 		*((uint32_t *)0xF8F0010C)			// Interrupt Acknowledge Register
#define ICCEOIR		*((uint32_t *)0xF8F00110)			// End of Interrupt register

// Global Timer Counter registers
#define GTC_CONTROL_REG		*((uint32_t *)0xF8F00208) // bit[0] = EN; [1] = Comparitor output EN; [2] = Interrupt EN; [3] = Auto-INCR EN;
#define GTC_INTR_STS		*((uint32_t *)0xF8F0020C) // Read/Write; interrupt status register; bit[0] holds interrupt status; Write 1 to clear

#define GTC_DATA_LOWER		*((uint32_t *)0xF8F00200)
#define GTC_DATA_UPPER		*((uint32_t *)0xF8F00204) // Global counter value

#define GTC_CMPVAL_LOWER	*((uint32_t *)0xF8F00210)
#define GTC_CMPVAL_UPPER	*((uint32_t *)0xF8F00214) // Comparitor value Lower and Upper registers

#define GTC_AUTO_INCRM_VAL	*((uint32_t *)0xF8F00218)
#define INCRM_VAL_64HZ 0x4F78D9 // Will give us an interrupt rate of ~64Hz

// General macro constant definitions
#define GTC_EN 0x01
#define CMPR_EN 0x02
#define INTERRUPT_EN 0x04
#define INCRM_EN 0x08 // Just masks to set the configuration for the GTC and it's interrupt

#define ENABLE 0x01
#define DISABLE 0x00 //

#define HIGH_LEVEL 0b01 
#define RISING_EDGE 0b11		 // These are used to set the sensitivity value for interrupts in the GIC


// Interrupt ID definitions
#define GLOBAL_TIMER_INTR_ID (uint32_t)27
#define UART1_INTR_ID (uint32_t)82



void disable_arm_interrupts(void);
void enable_arm_interrupts(void);

// Enable trigger level interrupt and global timer comparitor interrupt with auto-increment
// Input Parameters: NONE
// Returns: NONE
void enableInterrupts(void);

// Clear Interrupt status bit for the global timer counter
void GTC_clearEventFlag(void);

// Sets compare value for GTC
// Input Parameters:
//		uint32_t: compare value upper register value
//		uint32_t: compare value lower register value
void GTC_setCompareValue(uint32_t upperVal, uint32_t lowerVal);

// Sets auto-increment value for GTC interrupt
// Input Parameters:
//		uint32_t: Value to increment compare reg by
void GTC_setAutoIncrementVal(uint32_t upperVal);

// Clear global timer value
void GTC_resetTimerAndComparitor(void);

// Disable the IRQ signal passthrough to allow CPU to receive input
void ICCICR_IRQ_passthroughDisable(void);

// This will enable or disable the GIC distributor; 
// Input Parameters: 32-bit Int representing state  you want GIC distributor in; 0 = disable; 1 = enable
// Returns: NONE
void ICDDCR_gicDistributor_enableDisable(uint32_t input);

// Will check the ICCIAR register which holds the interrupt ID being passed by the GIC and service any interrupts
void IRQ_handler(void* data);



// Conifgure priority mask, this will set the lower bound (inclusive) of the priority of the interrupts that the CPU will address
// Input Parameters: 
//			uint32_t representing the lower bound of priority; 0 = highest priority only; 255 = all interrupts will be handled by the CPU
// Returns: NONE
void ICCPMR_setCpuPriorityBound(uint32_t lowerBound);

// GTC interrupt GIC config
// Will disable the target processor for the GTC
void GTC_disable_tarCpu(void);

// Enable target processor for the GTC
void GTC_enable_tarCpu(void);

// Will disable the ID for the GTC interrupt in the GIC
void GTC_disable_intrID(void);

// Enable ID for GTC interrupt in the GIC
void GTC_enable_intrID(void);

// Set the priority to 8 for the GTC interrupt in the GIC
void GTC_setPriority(void);

// Set sensitivity to high level for the GTC
void GTC_setSensitivity(void);

// This function will configure GTC to enable interrupts with comparitor enabled, and aut-increment enabled
void enableGtcInterrupt(void);

// UART 1 to the PC GIC interrupt setup functions
// Disable the target processor for UART1
void UART1_disable_tarCpu(void);

// Enable the target processor for UART1
void UART1_enable_tarCpu(void);

// Disable ID for UART1 interrupt in the GIC
void UART1_disable_intrID(void);

// Enable ID for UART1 interrupt in the GIC
void UART1_enable_intrID(void);

// Set the priority to 8 for UART1 interrupt
void UART1_setPriority(void);

// Set high level sensitivity for UART1
void UART1_setSensitivity(void);

// Configure UART1 hardware interrupts
void enableUart1Interrupt(void);

#endif // !INTERRUPTMODULE_H

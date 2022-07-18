

#include "UARTmodule.h"
#include <stdint.h>

volatile int GTC_flag;
volatile int req3_counter;



#define INCREMENTER_VAL_1Hz 0x13DE4355 // Will be used as initial comparison value, and also the autoincrement valuei; 333,333,333 / (666MHz / 2) = 666,666,666 / 666MHz ~= 1.001001 seconds => every thousand secends we're off by one which is not too shaby; we could actually account for this mathmatically, as well as the additional second every one-million seconds
#define INCREMENTER_VAL_2Hz 0x09EF21AA // Half of the above amount


#define GTC_DATA_LOWER		*((volatile uint32_t *)0xF8F00200)
#define GTC_DATA_UPPER		*((volatile uint32_t *)0xF8F00204)

#define GTC_CONTROL_REG		*((volatile uint32_t *)0xF8F00208)

#define GTC_INTR_STS		*((volatile uint32_t *)0xF8F0020C)

#define GTC_CMPVAL_LOWER	*((volatile uint32_t *)0xF8F00210)
#define GTC_CMPVAL_UPPER	*((volatile uint32_t *)0xF8F00214)

#define GTC_AUTO_INCRM_VAL	*((volatile uint32_t *)0xF8F00218)

#define GTC_EN 0x01
#define INCRM_EN 0x08
#define CMPR_EN 0x02
#define INTERRUPT_EN 0x04

// Clear global timer value
void GTC_resetTimerAndComparitor(void);

// Clear Interrupt status bit
void GTC_clearEventFlag(void);

// Disable Global Timer
void GTC_globalTimer_disable(void);

// Enable Global Timer
void GTC_globalTimer_enable(void);

// Sets compare value
// Input Parameters:
//		uint32_t: compare value upper register value
//		uint32_t: compare value lower register value
void GTC_setCompareValue(uint32_t upperVal, uint32_t lowerVal);

// Sets auto-increment value
// Input Parameters:
//		uint32_t: Value to increment compare reg by
void GTC_setAutoIncrementVal(uint32_t upperVal);

// Will send current count value to the PC then increment the count
void GTC_secondCounterInterruptHandler(int* count);

// Will increment the passed integer and clear the event flags
// Input Parameters:
//		int pointer: pointer to the value being incremented
void GTC_interruptIncrementer(int* pCount);

#include "timerModule.h"

// Clear global timer value
void GTC_resetTimerAndComparitor(void)
{

	GTC_DATA_LOWER = 0;
	GTC_DATA_UPPER = 0; // set 
	GTC_setCompareValue(0, 0);
}

// Clear Interrupt status bit
void GTC_clearEventFlag(void)
{
	GTC_INTR_STS = 0x1; // Write a one to clear bit[0]
}

// Disable Global Timer
void GTC_globalTimer_disable(void)
{
	GTC_CONTROL_REG &= ~GTC_EN; // Clear timer enable bit
}

// Enable Global Timer
void GTC_globalTimer_enable(void)
{
	GTC_CONTROL_REG |= GTC_EN; // Set timer enable
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

// Will send current count value to the PC then increment the count
// Input Paramters:
//		int pointer: pointer to value to print then increment
void GTC_secondCounterInterruptHandler(int* pCount)
{
	//UART1_sendString("Current count value: ");
	
	UART1_sendString("Count: ");
	UART1_printInt(*pCount); // print current count in line
	UART1_sendChar('\n');

	GTC_clearEventFlag();

	 ++(*pCount); // increment count val
}

// Will increment the passed integer and clear the event flags
// Input Parameters:
//		int pointer: pointer to the value being incremented
void GTC_interruptIncrementer(int* pCount)
{
	GTC_flag = 0; // interrupt acknowledged
	++(*pCount); // increment count val
}

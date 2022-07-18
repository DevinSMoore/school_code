#include "xil_exception.h"

#include "GICmodule.h"
#include "UARTmodule.h"
#include "GPIOmodule.h"
#include "timerModule.h"

#define TEST_STR "\nChar: "
#define DEFAULT_TEST_STR "Hit default case in IRQ handler...."

// Enable trigger level interrupt
// Input Parameters: NONE
// Returns: NONE
void enableInterrupts(void);

// Will check the ICCIAR register which holds the interrupt ID being passed by the GIC and service any interrupts
void IRQ_handler(void* data);

// Initializes the RGB and BTN GPIO
void proj5_init(void);

// Configure BTN4 and BTN5 interrupts to be rising edge sensitive
void cofigBtnInterrupt(void);

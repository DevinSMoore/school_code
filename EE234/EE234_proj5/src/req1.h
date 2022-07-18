#include "xil_exception.h"

#include "GICmodule.h"
#include "UARTmodule.h"
#include "GPIOmodule.h"
#include "timerModule.h"

// Enable trigger level interrupt
// Input Parameters: NONE
// Returns: NONE
void enableInterrupts(void);

// Will check the ICCIAR register which holds the interrupt ID being passed by the GIC and service any interrupts
void IRQ_handler(void* data);

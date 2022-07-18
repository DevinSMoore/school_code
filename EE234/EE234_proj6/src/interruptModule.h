#include "xil_exception.h"

#include "GICmodule.h"
#include "UARTmodule.h"
#include "GPIOmodule.h"
#include "timerModule.h"

#define TEST_STR "\nChar: "
#define DEFAULT_TEST_STR "Hit default case in IRQ handler...."

// This will just be a generic function that will enable all of the interrupts
// Input Parameters: NONE
// Returns: NONE
void enableInterrupts(void);

// Will check the ICCIAR register which holds the interrupt ID being passed by the GIC and service any interrupts
void IRQ_handler(void* data);

// Initializes the RGB and BTN GPIO
void GPIO_button4and5InterruptEnable(void);

// Configure BTN4 and BTN5 interrupts to be rising edge sensitive
void cofigBtnInterrupt(void);

// Set control reg for interrupts; auto increment enabled; comparitor enable; global timer signal enable
void GTC_configGlobalTimerInterrupt(void);

// This will take care of the button interrupt for req 5
// Returns:
//	uint32_t: masked register with BTN4 & BTN5 unmasked
uint32_t req5_GPIO_interruptHandler(void);

// UART1 interrupt handler for req5
void req5_UART1_interruptHandler(int* input);

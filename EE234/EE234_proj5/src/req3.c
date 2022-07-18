#include "req3.h"

// void Xil_exceptionRegisterHandler(u32 Exception_id, Xil_ExceptionHandler Handler, void *Data)

// Enable trigger level interrupt and register interrupt handler
// Input Parameters: NONE
// Returns: NONE
void enableInterrupts(void)
{
	disable_arm_interrupts();

	Xil_ExceptionRegisterHandler(5, IRQ_handler, NULL); // Register our handler

	initGIC_ID(GLOBAL_TIMER_INTR_ID, 8, HIGH_LEVEL);
	initGIC_ID(UART1_INTR_ID, 9, HIGH_LEVEL); // 10 priority is just arbitrary
	initGIC_ID(GPIO_INTR_ID, 10, RISING_EDGE); // 9 so we look at the button interrupt before we look for the UART


	GTC_configGlobalTimerInterrupt();
	UART1_Rx_singleByteInterrupt_Init(); // Initialize UART1 Rx line trigger level interrupt to 1 Byte in FIFO
	cofigBtnInterrupt(); // Config interrupts for BTN4 & BTN5 on blackboard

	// checkBTNinterruptEnable();

	enable_arm_interrupts();

}


// Will check the ICCIAR register which holds the interrupt ID being passed by the GIC and service any interrupts
void IRQ_handler(void* data)
{
	int tempInt = 0;
	// checkBTNinterruptEnable();
	uint32_t ID = ICCIAR;
	// UART1_sendString("Entering IRQ handler\n");
	switch (ID) // This register will hold the ID of the interrupt that was triggered
	{
		case UART1_INTR_ID:
			// UART1_sendString("Hit UART interrupt\nChar: ");
			UART1_intHandler_clearAndEchoRx(); // Will read in all data from Rx FIFO and echo it to the Tx FIFO
			UART1_sendChar('\n');
			break;
		case GPIO_INTR_ID:
			// UART1_sendString("Hit BTN interrupt\n");
			//GPIO_BTNinterruptHandler();
			//UART1_sendChar('\n');
			break;
		case GLOBAL_TIMER_INTR_ID:
			// UART1_sendString("Hit GTC interrupt\n");
			tempInt = req3_counter;
			GTC_secondCounterInterruptHandler(&tempInt);
			req3_counter = tempInt;
			break;
		default:
			// boop
			UART1_sendString(DEFAULT_TEST_STR);
			break;
	}
	//UART1_sendString("Exiting IRQ handler\n\n");
	ICCEOIR = ID; // Write the interrupt ID that was acknowledged to tell GIC that we handeled interrupt
}

// Initializes the RGB and BTN GPIO
void proj5_init(void)
{
	configure_PS_MIO();

	GPIO_disable_output(BTN_BANK, (BTN4_MASK | BTN5_MASK));
	GPIO_disable_output(RGB_BANK, RGB_MASK);

	GPIO_set_input(BTN_BANK, (BTN4_MASK | BTN5_MASK));
	GPIO_set_output(RGB_BANK, RGB_MASK);

	GPIO_enable_output(RGB_BANK, RGB_MASK);

	GPIO_RGB_on();
	GPIO_RGB_off(); // Turn the off to start with
}

// Configure BTN4 and BTN5 interrupts to be rising edge sensitive
void cofigBtnInterrupt(void)
{
	GPIO_disableAllGPIOInterrupts();
	GPIO_clearAllInterruptFlags();
	// GPIO_Interrupt_disable(BTN_BANK, (BTN4_MASK | BTN5_MASK));

	GPIO_setSensitivity(BTN_BANK, (BTN4_MASK | BTN5_MASK), EDGE_SENS);
	GPIO_setPolarity(BTN_BANK, (BTN4_MASK | BTN5_MASK), ACTIVE_HIGH); // set buttons to enable interupt bit on rising edge

	GPIO_disableAnyEdge(BTN_BANK, (BTN4_MASK | BTN5_MASK));

	GPIO_Interrupt_enable(BTN_BANK, (BTN4_MASK | BTN5_MASK));
}

// Set control reg for interrupts; auto increment enabled; comparitor enable; global timer signal enable
void GTC_configGlobalTimerInterrupt(void)
{
	GTC_CONTROL_REG = ~(INCRM_EN | INTERRUPT_EN | CMPR_EN | GTC_EN);
	
	GTC_resetTimerAndComparitor();
	GTC_CONTROL_REG = (INCRM_EN | INTERRUPT_EN | CMPR_EN | GTC_EN); // Sets interrupt, auto-increment, comparitor, and enables the GTC to start counting
	
	GTC_setAutoIncrementVal(INCREMENTER_VAL_1Hz);
	GTC_setCompareValue(0, INCREMENTER_VAL_1Hz);// set upper bit to 0 lower to 333,333,333




	
}

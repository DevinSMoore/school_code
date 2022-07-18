@	Name: Devin Moore
@	Assignment: Project 2 Requirement 4
@	Description: For this requirement we are going to be building subroutines to control an LED by
@				 using the PWM circuit. Using SW11-SW9 to select which led to turn on. SW7-SW0
@				 control the pulse width.
@
@				 101 = RGBLD11_BLU - 000 = RGBLD10_RED; So as it turns out this is not correct unless there is something wrong with my code somewhere.
@														Becuase 000 turns on blue 10 (right side led), and 101 will turn on red 11. So I'm not sure what's
@														going on becuase I referenced the addresses on the GPIO page on real digital. (I also let Clint know
@														so if I'm not wrong it may have been changed since then.)
@
@														GPIO reference: https://www.realdigital.org/doc/25bc9b4ca6fbcb20e44a0ae17631943a


.text
.global main

@ These three constants represent the "base" address'. I'm going to use offsets from these addresses to get to the particular LEDs we care about
.equ BASE_EN_ADDR, 0x43C00000		@ Address to set enable (1 = on; 0 = off)
.set BASE_WINDOW_ADDR, 0x43C00004	@ Address to set the RGBL_10 Red period value (32-bit value)
.equ BASE_DUTYCCL_ADDR, 0x43C00008	@ Address to set RGB LED 10 Red duty cycle (or pulse width) (32-bit value)

.equ SW_ADDR, 0x41220000

.set WINDOW_LENGTH, 255				@ Window period = (WINDOW_LENGTH / PWMfrequency) = ( 255 / 100MHz) = 2.55uS
									@ I chose 255 because it's the highest value our switches can go so we get a linear 1:1 rampup
main:

	MOV R3,#0						@ Initializing our counter for initWindow subroutine

	BL initWindow
	B loop

@ Initialize all LEDs with the window length constant
initWindow:							@ This subroutine will simply loop through and set the period of the PWM circuits to some set value.
	PUSH {R4, R5, LR}
	LDR R0,=BASE_WINDOW_ADDR
	ORR R2,R3,R0					@ OR the base address with our count value R3 to get the address offset for the next item to set the window length for
	LDR R1,=WINDOW_LENGTH			@ We could add logic to change window length but we would have to add more stuff so that we could change window length and duty cycle at different times. like useing a btn to latch a value, and looking at a free switch to check whether we would be changing window or dutyCycle
	STR R1,[R2]						@ *R4 = R5; PWM window reg gets set to our window length
	ADD R3,R3,#0x10					@ Increment by 0x10 and this increment value will become our offset value for the next address
	CMP R3,#0x50					@ Comparing against our max value to select
	POP {R4, R5, LR}				@ I realize pushing and poping the stack like this is resource intensive but I aint smart enough to figure this one (do this loop while preserving the register values w/o PUSH/POP)
	BLE initWindow					@ Branch to initWindow while our counter is less than or equal to 0x50
	BX LR


loop:
	LDR R3,=SW_ADDR					@ Loading switch address
	LDRB R1,[R3]					@ Loading LSByte into R1 (duty cycle value); SW7:SW0
	LDR R0,[R3, {LSR #9}]						@ load switch values into R0
	@LSR R0, R0,#9					@ If we shift the switch values to the right by 9, SW9 becomes the least significant bit going up to SW11 for the select values
	LSL R0, R0,#4					@ left shift to get our particular LED offset; this is just a way to multiply by 16 or 0x10

	@ At this point R0 contains our shifted select values and R1 contains our Duty cycle value

	CMP R0,#0x50
	BGT loop						@ If a value greater than 0x50 is selected then we will just loop again, and maintain the last selected LED
	BL pwmEnable					@ B to turn on selected input
	BL dutyValue					@ Set duty Value
	MOV R2,#0						@ Initializing a counting variable for the disable loop
	BL pwmDisableLoop				@ Disable all other channels
B loop							@ Do it all again yo

pwmEnable:
	LDR R2,=BASE_EN_ADDR
	ORR R2,R2,R0					@ OR R2 with R0 (store into R2) to get the offset address to the LED selected
	MOV R3,#1						@ R3 = 1
	STR R3,[R2]						@ *R2 = R3; set enable bit
BX LR

dutyValue:
	LDR R2,=BASE_DUTYCCL_ADDR
	ORR R2,R2,R0					@ ORing shifted address with the Duty Cycle address
	STR R1,[R2]						@ *R2 = R1; R1 = dutyValue
BX LR

@This subroutine will go through and check if a particular select value matches the selected switch from the user. If it does it will
pwmDisableLoop:
	PUSH {R5, LR}
	CMP R0, R2						@ Check the select value (R0) against counter value (R2)
	BLNE pwmDisable					@ For every value not selected it will go and disable that channel (there's definately a smarter way of doing this)
	ADD R2,#0x10					@ R2 = R2 + 0x10
	cmp R2,#0x50					@ Check against max offset.
	POP {R5, LR}
	BLE pwmDisableLoop				@ If R2 (counter) is less than or equal to max offset, then continue loop
BX LR


pwmDisable:
	PUSH {R4}
	LDR R3,=BASE_EN_ADDR
	ORR R3,R3,R2					@ OR R3 with R2 (our counter value) to get the address to the LED to disable
	MOV R4,#0						@ R4 = 0;
	STR R4,[R3]						@ *R3 = R4 = 0; Set EN bit to 0
	POP {R4}
BX LR

.end

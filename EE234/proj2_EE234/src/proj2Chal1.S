@	Name: Devin Moore
@	Assignment: Project 1 Requirement 1
@	Description: For this requirement we are going to be building subroutines to control an LED by
@				 using the PWM circuit. Using SW11-SW9 to select which led to turn on. SW7-SW0
@				 control the pulse width.
@
@				 101 = RGBLD11_BLU - 000 = RGBLD10_RED; So as it turns out this is not correct unless there is something wrong with my code somewhere.
@														Becuase 000 turns on blue 10 (right side led), and 101 will turn on red 11. So I'm not sure what's
@														going on becuase I referenced the addresses on the GPIO page on real digital.
@
@														GPIO reference: https://www.realdigital.org/doc/25bc9b4ca6fbcb20e44a0ae17631943a


.text
.global main

@ These three constants represent the "base" address'. I'm going to use offsets from these addresses to get to the particular LEDs we care about
.equ BASE_EN_ADDR, 0x43C00000		@ Address to set enable (1 = on; 0 = off)
.set BASE_WINDOW_ADDR, 0x43C00004	@ Address to set the RGBL_10 Red period value (32-bit value)
.equ BASE_DUTYCCL_ADDR, 0x43C00008	@ Address to set RGB LED 10 Red duty cycle (or pulse width) (32-bit value)

.equ SW_ADDR, 0x41220000

.set WINDOW_LENGTH, 10000			@ 100uS window period
									@ Window period = (WINDOW_LENGTH / PWMfrequency); PWMf = 100MHz

main:

	MOV R0,#0						@ Initializing our counter for initializeChannel subroutine
	LDR R1,=BASE_WINDOW_ADDR
	LDR R2,=WINDOW_LENGTH			@ Passing the window length address, and value we're going to set it as to initializeChannel
	BL initializeChannel

	MOV R0,#0						@ Resetting counter
	LDR R1,=BASE_EN_ADDR
	MOV R2,#1						@ Passing in base EN address and 1 to enable them all because we're just going to vary the duty cycle
	BL initializeChannel

	MOV R7,#0						@ These will be our counters for each LED. R7 = BLUE LED 10
	MOV R8,#0
	MOV R9,#0
	MOV R10,#0
	MOV R11,#0
	MOV R12,#0						@ Setting our counters to zero

	B loop


initializeChannel:					@ This subroutine will simply loop through and set the period of the PWM to some set value and enable all of the LEDs
	PUSH {R4, LR}
	AND R4,#0						@ Clearing R4
	ORR R4,R1,R0					@ OR the base address with our count value R3 to get the address we're going to set the window length for
	STR R2,[R4]						@ *R4 = R2; Set value at R4 to passed value R2
	ADD R0,R0,#0x10					@ Increment our offset value
	CMP R0,#0x50					@ Comparing against our max value to select
	POP {R4, LR}					@ I realize pushing and poping the stack like this is resource intensive but I aint smart enough to figure this one.
	BLE initializeChannel			@ Branch to initializeChannel while less than 0x60
	BX LR

loop:

	LDR R2,=0x4BE0CE5				@ The delay function was messed around with untill I got a nice and smooth build up of the lights while also stepping throught the brightness levels somewhat quickly
	BL delay						@ I used this to tune the ramp up time of all of them outside affecting the increment amounts or window length

@ So I think the way I'm going to do this is to just update them in order with different functions. All of these will increment in R0 step amounts, up to
@ All of the increment step values are somewhat arbitrary. a good spread means that each light will reach it's peak brightness at different points.

incR7:								@ Blue 10

	LDR R0,=500						@ this has about a 3 second period
	ADD R7,R0						@ Increment by R0
	MOV R0,#0x00					@ Address offset for dutyValue subroutine
	MOV R1,R7						@ Set R1 as the counter value to be passed to the dutyValue subroutine
	BL dutyValue	 				@ Set pulse width for this LED
	LDR R0,=WINDOW_LENGTH
	cmp R7,R0
	BLT incR8						@ If our increment val is less than window length continue down the line incrementing
	MOV R7,#0						@ Else set current counter to 0 then move on

incR8:								@ Green 10
	LDR R0,=200
	ADD R8,R0						@ Incrementing R8
	MOV R0,#0x10
	MOV R1,R8
	BL dutyValue					@ Setting duty value
	LDR R0,=WINDOW_LENGTH
	cmp R8,R0
	BLT incR9						@ Reset if greater than windown length
	MOV R8,#0

incR9:								@ Red 10
	LDR R0,=100
	ADD R9,R0						@ Increment R9
	MOV R0,#0x20
	MOV R1,R9
	BL dutyValue					@ Pass R1 as the address offset;Set Duty val of a passed offset value
	LDR R0,=WINDOW_LENGTH
	cmp R9,R0
	BLT incR10
	MOV R9,#0						@ If our increment val is less than window length continue down the line incrementing

incR10:								@ Blue 11
	LDR R0,=10
	ADD R10,R0
	MOV R0,#0x30
	MOV R1,R10						@ Set Dut value
	BL dutyValue					@ Pass R1 as the address offset;Set Duty val of a passed offset value
	LDR R0,=WINDOW_LENGTH
	cmp R10,R0
	BLT incR11
	MOV R10,#0

incR11:								@ Green 11
	LDR R0,=500
	ADD R11,R0						
	MOV R0,#0x40
	MOV R1,R11
	BL dutyValue					@ Pass R1 as the address offset;Set Duty val of a passed offset value
	LDR R0,=WINDOW_LENGTH
	cmp R11,R0
	BLT incR12
	MOV R11,#0

incR12:								@ Red 11
	LDR R0,=190
	ADDS R12,R0
	MOV R0,#0x50
	MOV R1,R12
	BL dutyValue					@ Pass R0 as the address offset;Set Duty val of a passed offset value
	LDR R0,=WINDOW_LENGTH
	cmp R12,R0
	BLT loop
	MOV R12,#0						@ If we reache the window value we reset then go back to the start
	B loop

dutyValue:							@ R1 is going to be set as Duty cycle value
	PUSH {R4, R5}
	AND R4,#0
	LDR R5,=BASE_DUTYCCL_ADDR
	ORR R4,R5,R0					@ ORing the offeset passed as R0 with the Duty Cycle address R5, store in R4
	STR R1,[R4]						@ Store duty cycle val into the register R4 points to
	POP {R4, R5}
	BX LR




delay:								@ If I figured it correctly the delay for this particular function is = (num cycles * period) = (4 * (r1 - 1) + 8) * (~1.49925nS); 667MHz clock frequency for blackboard
	SUBS r2, r2, #1					@ Will decrement passed value by 1
	BNE delay						@ Until r1 = 1 we will branch to start of subroutine
	BX LR							@ Back to blinkLoop

.end

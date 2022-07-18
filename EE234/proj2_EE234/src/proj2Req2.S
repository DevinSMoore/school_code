@	Name: Devin Moore
@	Assignment: Project 1 Requirement 2
@	Description: For this requirement we are going to be building subroutines to control
@				 an LED. We're also going to be adding a delay to toggle the led on and
@				 off at a level we can see as humans.

.text
.global main

@ Defining constants
.set LED_ADDR, 0x41210000
.equ SW_ADDR,  0x41220000

@ Body
main:
	blinkLoop:
		bl led1_toggle
		ldr r0,=SW_ADDR
		ldrb r1,[r0]		@ Loading in just the least significant byte of the switches into r1
		lsl r1,r1,#24		@ Left shifting the byte by 3 bytes (24 bits)
		add r1,#1
		bl delay			@ Calling Delay and passing in our shifted switch value
		b blinkLoop

@ Subroutines
led1_toggle:
	ldr r0,=LED_ADDR
	ldr r1,[r0]				@ Load LED address [r0] then load into r1
	eor r1,r1,#2			@ toggling LED by XORing with 1 which will invert the bit.
	str r1,[r0]				@ Store result of XOR into led reg
	bx lr					@ Exit subroutine to LR address

delay:						@ If I read it correctly the delay for this particular function is = (num cycles * period) = (4 * (r0 - 1) + 5) * (~1.49925nS); 667MHz clock frequency for blackboard
	subs r1, r1, #1			@ Will decrement passed value by 1
	bne delay				@ Until r1 = 1 we will branch to start of subroutine
	bx lr					@ Back to blinkLoop

.end

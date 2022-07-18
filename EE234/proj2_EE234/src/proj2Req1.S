@	Name: Devin Moore
@	Assignment: Project 2 Requirement 1
@	Description: For this requirement we are going to be building subroutines to control
@				 an LEDs brightness and which RGB LED is enabled.

.text
.global main

@ Defining constants
.set LED_ADDR, 0x41210000

@ Body
main:
	bl led1_on 			@ Branching to led1_on and copying the adress of the line below this one to the link reg
	bl led1_off			@ Turning LED1 off
	bl led1_toggle		@ Toggling LED twice
	bl led1_toggle
	b main

@ Subroutines
led1_on:
	ldr r0,=LED_ADDR
	ldr r1,[r0]			@ Load LED address [r0] then load into r1
	orr r1,r1,#2		@ ORing led reg with 2 to ensure that LED gets turned on
	str r1,[r0]			@ Store 1 into led reg
	bx lr				@ Exit subroutine by setting program counter to the link address then continue program

led1_off:
	ldr r0,=LED_ADDR
	ldr r1,[r0]			@ Load LED address [r0] then load into r1
	and r1,r1,#0		@ clearing r1 by ANDing with 0 then latching that into r1
	str r1,[r0]			@ Store 0 into led reg
	bx lr				@ Exit subroutine to LR address

led1_toggle:
	ldr r0,=LED_ADDR
	ldr r1,[r0]			@ Load LED address [r0] then load into r1
	eor r1,r1,#2		@ toggling LED by XORing with 1 which will invert the bit.
	str r1,[r0]			@ Store result of XOR into led reg
	bx lr				@ Exit subroutine to LR address



.end

@	Name: Devin Moore
@	Assignment: Project 1 Requirement 3
@	Description: For this requirement we are going to be building subroutines to control
@				 an LEDs brightness with Pulse Width Modulation. We're also going to be
@				 adding a delay to toggle the led on and off at a level we can't see as
@				 humans, but we can use that to dim the lights. by creating a cycle
@				 where part of the cycle has the light on, and for the other part it is
@				 off. Changing the length of the on/off period without changing the overall
@				 cycle time.


.text
.global main

@ Defining constants
.set LED_ADDR, 0x41210000
.equ SW_ADDR,  0x41220000

@ Body
main:
	ldr r3,=SW_ADDR
	ldr r0,=0x28B5E 		@ This gives us a number of cycles that will make our PWM period ~= 1ms (this is correct if we only take into accoutn the delay subroutine it's going to be off due to, well, all of other subroutines and instructions).
							@ r0 is used to define our window using the delay subroutine
loop:
	bl pwmLED
	b loop

@ Subroutines
led1_on:
	push {r5, r6}			@ Pushing r5, and r6 to stack
	ldr r6,=LED_ADDR
	ldr r5,[r6]				@ r5 = *r6; getting value of LEDs
	orr r5,r5,#2			@ ORing LED reg with 2 to ensure that LED1 gets turned on
	str r5,[r6]				@ *r6 = r5; Turn on LED1
	pop {r5, r6}			@ Returning r5, and r6 values from stack
	bx lr					@ Exit subroutine by setting program counter to the link address then continue program

led1_off:
	push {r5, r6}			@ Pushing r5, and r6 to stack
	ldr r6,=LED_ADDR
	ldr r5,[r6]				@ Load LED address [r6] then loading value into r1
	and r5,r5,#0			@ clearing r1 by ANDing with 0 then latching that into r1
	str r5,[r6]				@ r5 = *r6; Turn off all LEDs
	pop {r5, r6}
	bx lr					@ Exit subroutine to LR address

pwmLED:
	push {r4, r5, lr}		@ Pushing r5, r4 and link reg to stack
	ldrb r4,[r3]			@ Loading in just the least significant byte of the switches into r1 to set our delay value
	lsl r1,r4,#5			@ Left shifting by 5 will push our range up to 130,560 max which is ~78% duty cycle
	cmp r1,#0
	blgt led1_on			@ branch led1_on if any switches are greater than 0
	blgt delay				@ delaying by the amount passed via switches if any are on
	bl led1_off				@ LED off
	sub r1, r0, r1			@ Subtracting the pulse width from the pulse window and then delay by the remainder
	bl delay
	pop {r4, r5, lr}		@ Pulling r5, r4 and link reg from stack
	bx lr					@ Returning from whence we came (well the next instruction down)

delay:						@ If I figured it correctly the delay for this particular function is = (num cycles * periode) = (4 * (r1 - 1) + 8) * (~1.49925nS); 667MHz clock frequency for blackboard
	subs r1, r1, #1			@ r1--;
	bne delay				@ Until r1 = 1 we will branch to start of subroutine
	bx lr					@ Back to where we came from

.end

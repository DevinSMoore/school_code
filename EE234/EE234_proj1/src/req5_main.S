.text
.global main

@define constants, these can be used as symbols in your code
.equ LED_CTL, 0x41210000
.set SW_DATA, 0x41220000

@the set and equ directives are equivalent and can be used interchangably

main:
	ldr r1,=SW_DATA 	@Load switch address from constant
	ldr r2,=LED_CTL	 	@Load LED address from constant

loop:
	ldrb r0,[r1]		@Load switch value *r1 -> r0
	and r0,r0,#0xF		@AND with 0xF wich will let us ignore the upper bits and just communicate the 4 LSB

	cmp r0, #12
	bge led3			@If switch value is greater than or equal to 12 branch to led3

	cmp r0, #8
	bge led2			@If sw val >= 8 branch to led2

	cmp r0, #4
	bge led1			@If sw val >= 4 branch to led1

	cmp r0, #0
	bge led0			@If sw val >= 0 branch to led0


led0:
	mov r4,#1
	str r4,[r2]			@Turning on LED0 if we hit this condition
	b loop

led1:
	mov r4,#2
	str r4,[r2]			@Turning on LED1
	b loop

led2:
	mov r4,#4
	str r4,[r2]			@Turning on LED2
	b loop

led3:
	mov r4,#8
	str r4,[r2]			@Turning on LED3
	b loop

.end

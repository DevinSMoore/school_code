.text
.global main

@define constants, these can be used as symbols in your code
.equ LED_CTL,  0x41210000
.equ BTN_DATA, 0x41200000

@the set and equ directives are equivalent and can be used interchangably

main:
	ldr r1,=BTN_DATA @Load button address from constant
	ldr r2,=LED_CTL @Load LED address from constant

loop:
	ldr r0,[r1]		@Load button value *r1 -> r0
	str r0,[r2] 	@Store value to led reg *r2 <- r0
	b loop 			@go back to "loop"

.end

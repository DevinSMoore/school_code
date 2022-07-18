.text
.global main

@define constants, these can be used as symbols in your code
.equ LED_CTL, 0x41210000
.set SW_DATA, 0x41220000

@the set and equ directives are equivalent and can be used interchangably

main:
	ldr r1,=SW_DATA 	@Load switch address from constant
	ldr r2,=LED_CTL 	@Load LED address from constant
	ldr r3,=0x3FF		@Loading r3 with 0011 1111 1111 to XOR with the 10 switches

bloop:
	ldr r0,[r1]			@Load switch value *r1 -> r0
	eor r0, r0,r3  		@invert r0 then place that in r0
	str r0,[r2] 		@Store value to led reg *r2 <- r0
	b bloop 			@go back to "loop"

.end

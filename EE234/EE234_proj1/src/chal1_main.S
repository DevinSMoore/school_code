.text
.global main

@define constants, these can be used as symbols in your code
.equ LED_CTL,  0x41210000
.set SW_DATA,  0x41220000
.equ BTN_DATA, 0x41200000

@the set and equ directives are equivalent and can be used interchangably

main:
	ldr r0,=BTN_DATA	@Loading the button address
	ldr r1,=SW_DATA 	@Load switch address from constant
	ldr r2,=LED_CTL 	@Load LED address from constant


loop:
	ldr r3,[r0]		@Loading Button values
	ldr r4,[r1]		@Loading the switch values
	eor r5,r3,r4	@XORing the switches and buttons
	and r5,r5,#0xF	@AND with 0xF which will let us ignore the upper bits and just communicate the 4 LSB
	str r5,[r2] 	@Store value to led reg *r2 <- r5
	b loop 			@go back to "loop"

.end

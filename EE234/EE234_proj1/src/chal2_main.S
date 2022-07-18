.text
.global main

@Defining LED, switch, and button address'
.equ LED_CTL, 0x41210000
.set SW_DATA, 0x41220000
.equ BTN_DATA, 0x41200000

@the set and equ directives are equivalent and can be used interchangably

main:
	ldr r0,=BTN_DATA	@Loading button address
	ldr r1,=SW_DATA 	@Load switch address
	ldr r2,=LED_CTL		@Load LED address

loop:
	ldrb r3,[r1]		@Loading first byte of the switches into r3
	ldr  r4,[r0]		@Loading buttons into r4
	cmp r4,#1
	beq ledLatch		@If BTN0 is 1 then latch switches into LED reg

	cmp r4,#8		@If BTN3 is 1 then clear LEDs
	beq ledClear

	b loop 				@go back to "loop"

ledLatch:
	str r3,[r2]
	b loop

ledClear:
	mov r3, #0			@reg 3 is going to be reset to the swtich values when we go back to loop so it should be fine to reuse it
	str r3,[r2]
	b loop

.end

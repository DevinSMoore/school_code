.text
.global main

@Defining LED, and button address'
.equ LED_CTL, 0x41210000
.equ BTN_DATA, 0x41200000

@the set and equ directives are equivalent and can be used interchangably

main:
	ldr r0,=BTN_DATA	@Loading button address
	ldr r1,=LED_CTL		@Load LED address
	mov r4, #0
	mov r5, #1

loop:
	ldr r2,[r0]		@Loading button values

	cmp r2,#1		@if BTN0 is pressed branch to ledToggle
	beq ledToggle

	b loop 			@go back to "loop"

ledToggle:
	ldr r3,[r1]		@loading r3 with the led value
	cmp r3,#0		@if led is off branch to toggle on, if it's greater than 0 branch to toggle off
	beq toggleOn
	bgt toggleOff

toggleOff:
	str r4,[r1]		@Store 0 onto the LED reg
	ldr r2,[r0]
	cmp r2,#1		@if our button is still pressed down it will go back to toggleOff otherwise it will return to loop branch
	beq toggleOff
	b loop

toggleOn:
	str r5,[r1]		@storing value 1 into LED reg which will turn on the first led only
	ldr r2,[r0]
	cmp r2,#1		@Again if button is held down we'll stay in this branch
	beq toggleOn
	b loop

.end

.text
.global main

.equ LED_CTL, 0x41210000
.equ SW_DATA, 0x41220000

main:
	ldr r1,=SW_DATA
	ldr r2,=LED_CTL
loop:
	ldr r0,[r1]		@load switch value, (*r1) ->r0
	cmp r0,#31		@compare switch value with 31
	blt led_light	@branch to 'led_light' if sw val is less than 31
led_dim:
	mov r0,#0
	str r0,[r2]
	b loop			@go back to start of loop
led_light:
	mov r0,#1
	str r0,[r2]
	b loop

.end

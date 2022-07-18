@	Programmer: Devin Moore
@	Class: EE234 Clint Cole
@
@	Description: This contains subroutines that will take in data from peripherals and return them

.text
.global readButtons
.global readSwitches
.global readLEDs
.global toggleLED

@ Setting up constants for peripheral addresses

.equ BTN_ADR, 0x41200000
.set SW_ADR, 0x41220000
.equ LED_ADDRESS, 0x41210000 @ [9:0] for LED[9]:LED[0]; 1 to enable, 0 to disable


@ Setting up some constants for convinence
.equ BTN_MASK, 0x0000000F	@ This will mask all but the least significant nibble
.equ SW_MASK, 0x00000FFF	@ All but the lower 12 bits will be masked
.equ LED_MASK, 0x1FF		@ [9:0]

@ Reads in button data
@ Return: R0 = Value of button register
readButtons:
	PUSH {R1, R2, LR}
	LDR R1,=BTN_ADR
	LDR R2,=BTN_MASK
	LDR R0,[R1]
	AND R0,R0,R2			@ R0 now contains only the buttons values
	POP {R1, R2, LR}
BX LR @ Exiting

@ Reads in button data
@ Return: R0 = Value of switch register
readSwitches:
	PUSH {R1, R2, LR}
	LDR R1,=SW_ADR
	LDR R2,=SW_MASK
	LDR R0,[R1]
	AND R0,R0,R2 			@ R0 = switch vals
	POP {R1, R2, LR}
BX LR @ Exiting

@ Read in value of LED regs
@ Returns: LED reg in R0
readLEDs:
	PUSH {LR}
	LDR R1,=LED_ADDRESS
	LDR R2,=LED_MASK
	LDR R3,[R1]			@ R3 = *R1
	AND R0,R2,R3		@ R0 = R2&R3; return R0 to main
	POP {LR}
BX LR

@ Will check led value at specified LED and change it to the opposite state
@ Passed parameters: R0 will be the index of the LED of concern
@ Returns: NONE
toggleLED:
	PUSH {R4, R5, LR}

	CMP R0,#9
	POPGT {R4, LR}
BXGT LR					@ if an int greater than 9 is passed in we branch outa here
	MOV R4,R0
	LDR R5,=LED_ADDRESS

	BL readLEDs			@ R0 = LED reg

	MOV R1,#1
	LSL R1,R1,R4 		@ left shift by an amount equal to the LED index

	AND R3,R0,R1		@ R3 = R0 & R1; R1 = LED mask, R0 = LED reg value
	CMP R3,#0			@ if it's zero turn it on, else if it's greater than turn it off

	ORREQ R0,R1			@ R0 = R0 || R1; just set that bit with R1
	BICGT R0,R1			@ R0 = R0&(~R1); clear the bit that R1 has been shifted to (if at all)

	STR R0,[R5]			@ Set new LED value

	POP {R4, R5, LR}
BX LR

@	Programmer: Devin Moore
@	Class: EE234 Clint Cole
@
@	Description: This contains subroutines that will take in data from peripherals (right now just buttons and switches) and return them

.text
.global readButtons
.global readSwitches

@ Setting up constants for peripheral addresses

.equ BTN_ADR, 0x41200000
.set SW_ADR, 0x41220000

@ Setting up some constants for convinence
.equ BTN_MASK, 0x0000000F	@ This will mask all but the least significant nibble
.equ SW_MASK, 0x00000FFF	@ All but the lower 12 bits will be masked

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

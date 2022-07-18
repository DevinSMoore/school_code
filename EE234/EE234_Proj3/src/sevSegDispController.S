@	Programmer: Devin Moore
@	Class: EE234 Clint Cole
@
@	Description: This contains subroutines that will push passed data onto the seven segment display


.text
.global enableDisplay
.global setDisplayReg
.global enableCustomMode
.global display32BitReg
.global disableAllDP


@ Setting our addresses and offset values for the Seven Segment Display
.equ CONFIG_REG, 0x43C10000 // bit[0] = EN : 1 = enabled; 0(defualt) = disabled --- bit[1] = Mode: 1(default) = Custom/Individual Segment Data; 0 = default (BCD/Hex data); all other bits ignored
.equ DATA_REG, 0x43C10004 // 32 Bits total eache 8 bit chunk represents a digit => least significant byte = least sig digit
.equ DP_DISABLE_MASK, 0x80808080
.equ SEG_DISABLE, 0xFFFFFFFF
.set CLEAR_DIG_MASK, 0xFF	// We're going to shift this to the proper digit to clear the previous data


.equ DIG_1, 0b11001111
.equ DIG_2, 0b10010010
.equ DIG_3, 0b10000110
.equ DIG_4, 0b11001100
.equ DIG_5, 0b10100100
.equ DIG_6, 0b10100000
.equ DIG_7, 0b10001111
.equ DIG_8, 0b10000000
.equ DIG_9, 0b10000100
.equ DIG_A, 0b10001000
.equ DIG_b, 0b11100000
.equ DIG_C, 0b10110001
.equ DIG_d, 0b11000010
.equ DIG_E, 0b10110000
.equ DIG_F, 0b10111000

// Enable the SSD
enableDisplay:
	PUSH {R0, R1, LR}
	LDR R1,=CONFIG_REG
	MOV R0,#1
	STR R0,[R1]				@ Shift 1 into the config reg enables the Display
	POP {R0, R1, LR}
BX LR

@ WIll enable the custom decoding mode. Asserting 1 to a bit will turn that particular segment off. 0 is on
@ Each byte of the 32 bit data reg correlates to a segment going from DP->A->...->G
enableCustomMode:
	PUSH {R0, R1, LR}
	LDR R1,=CONFIG_REG
	MOV R0,#2
	STR R0,[R1]				@ Shift 2 into the config reg sets BCD Mode; bit[1] is asserted
	POP {R0, R1, LR}
BX LR


@ This subroutine sets a particular SSD digit in the display register to a particular value to then be displayed by the SSD
@ R0 = Digit to display data to; 1-4 (LSdigit -> MSdigit); this range will be verified before data is displayed
@ R1 = Data to display to provided digit
@ R3 = Display Register; Will also be the return value
setDisplayReg:
	PUSH {R0, R1, R4, LR}
	LDR R4,=CLEAR_DIG_MASK

	CMP R0,#0
BXLE LR
    CMP R0,#5
BXGE LR						@ Button val is within acceptable range if we don't branch out of the subroutine in either of the previous comparisons
	SUB R0,R0,#1			@ Take away one so we're indexing from 0
	LSL R0,R0,#3			@ Multiply digit shown by 8 (shift left by 3) to put it in the proper location in the digits byte
	LSL R1,R1,R0			@ Shift by the scaled digit amount so data is in correct location in register

	LSL R4,R4,R0			@ Shift the dig clear mask by same amount
	MVN R4,R4				@ Not the mask to set the values to 0 at the particular digits byte
	AND R3,R3,R4			@ Preserving the other digits info

	ORR R3,R3,R1			@ OR it into R3
	POP {R0, R1, R4, LR}
BX LR @ Exit back to program



@ R3 passed as register to display
@ Will set the SSD data register with our passed display register
display32BitReg:
	PUSH {R2, LR}
	LDR R2,=DATA_REG
	STR R3,[R2]				@ Store data to SSD Digit Data Register
	POP {R2, LR}
BX LR

@ Will simply OR the display reg with the DP_Display mask and returning the OR'd register
@ R3: Display register, will return register with Decimal places turned off
disableAllDP:
	PUSH {R0, LR}
	LDR R0,=DP_DISABLE_MASK
	ORR R3,R3,R0				@ the DP disable mask contains 1000 0000 1000 0000 1000 0000 1000 0000; which will set each dp bit position to '1' which will disable the segment
	POP {R0, LR}
BX LR




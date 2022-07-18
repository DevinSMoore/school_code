@	Programmer: Devin Moore
@	Class: EE234 Clint Cole
@
@	Assignment: Project 3 Requirement 1
@
@	Description: For this requirement we are reading a 12-bit number from the switches (0-11),
@				and using four of the buttons for a 4-bit number. We are then going to display
@				The switch value (in hex) onto the three least significant digits, and the
@				button number on the most significant digit. Four switches will represent each
@				individual digit where the least significant group of 4 controlling the least
@				significant digit, the upper digits are represented by their cooresponding switches.

.text
.global main

@ Defining constants
.equ SW_MASK, 0x0000000F	@ All but the lower nibble will be masked; Will be set to R11 for this program
.equ DP_DISABLE_MASK, 0x80808080 // targets each decimal point in the regist will set them to 1 to turn them off

main:
	LDR R8,=DP_DISABLE_MASK
	LDR R11,=SW_MASK
	BL enableDisplay	@ Turn on the SSD


	B loop

loop:

	MOV R3,#0			@ R3 will hold our data to diplay to the SSD; Resetting on start of loop
	BL disableAllDP

	BL readSwitches
	MOV R10,R0			@ R10 = R0; Doing this to store the read in switch value for later processing
	AND R1,R10,R11		@ R1 =  LS 4 bits of SW vals after applying mask
	MOV R0,#1			@ R0 = 1; Display first digit
	BL setDisplayReg	@ R3 will be returned with the proper value in the display register (R3)

	LSR R10,R10,#4
	AND R1,R10,R11		@ Shift switch vals right by 4 and mask bits [31:4]
	MOV R0,#2			@ Increment the digit we're goint to display
	BL setDisplayReg	@ Display to digit R0 (2)

	LSR R10,R10,#4
	AND R1,R10,R11		@ Shift right by 4 and mask bits [31:4]; I don't think the mask is strictly necessary here because we masked anything above sw11 and shifting right fills with 0
	MOV R0,#3			@ Increment the digit we're goint to display
	BL setDisplayReg	@ Display to digit R0 (3)

	BL readButtons		@ R0 = BTN vals
	MOV R1,R0			@ R1 = R0
	AND R1,R1,R11
	MOV R0,#4			@ Increment the digit we're goint to display
	BL setDisplayReg		@ R0 is the digit on which to display data, R1 is Data to display




	BL display32BitReg
	B loop 				@ Do a loopty-loop




oDelay:
	MOV R0,#0xFFF
	iDelay:
		SUBS R0,R0,#1
		BNE iDelay
BX LR

.end





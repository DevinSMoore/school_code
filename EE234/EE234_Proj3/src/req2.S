@	Programmer: Devin Moore
@	Class: EE234 Clint Cole
@
@	Assignment: Project 3 Requirement 2
@
@	Description: For this requirement we are creatin a BCD counter with a reset button (BTN[0]) and an increment buttion (BTN[1]).
@				 We also want to select which digit we're going to increment using SW[3]-SW[0], if none are selected then we'll
@				 increment the most significant digit
@					Theres a lot of repeated code, if I wasn't behind this would be much more clean

.text
.global main

@ Setting Constants
.equ COUNT_VAL, 0x5FFFFFF @ Used for a delay countdown

main:
	MOV FP,SP			@ FP = SP
	SUB SP,SP, #0x10	@ Moving SP down by 4*4 Bytes
	MOV R1, #0
	MOV R2, #0			@ R2 is going to hold the previous state of the switches (well really just BTN[1] our increment sw)
	MOV R0, #0
	MOV R3, #0			@ R3 will hold our display register

	@ Setting each of our local variables to 0
	STR R0,[FP,#-4]		@ DIG0
	STR R0,[FP,#-8]		@ DIG1
	STR R0,[FP,#-12]	@ DIG2
	STR R0,[FP,#-16]	@ DIG3

	BL enableDisplay


	B loop


loop:
	BL disableAllDP		@ sets all DP bits to 1 in R3 (display reg)
	BL display32BitReg	@ Display current register value

	BL readButtons

	CMP R2,#0					@ Check if previous state it's greater than 0
	CMPGT R0,#0					@ if it is check if we're not pressing button
	BICEQ R2,R2					@ If both conditions are true we reset previous state; It's ok if we set R2 to 0 if it's zero

	CMP R0,R2					@ This will compare current state (R0) with previous state (R2)
	BEQ loop					@ If the state hasn't changed (or we reset it) then branch to control loop
	BLNE latchButtonPress		@ and if we change state then we want to set that value of buttons into R0 and add a delay

	CMP R2,#0			@ Check if previous state was zero again
	CMPEQ R0,#3
	MOVEQ R2,R0			@ Set prevState=currState
	BEQ loop 			@ If both buttons are pressed branch to loop

	CMP R2,#0
	CMPEQ R0,#1
	MOVEQ R2,R0			@ Set prevState=currState
	BEQ reset			@ Branch to reset count if BTN[0] is pressed.

	CMP R2,#0
	CMPEQ R0,#2
	BEQ increment		@ If prev state was 0 and curr state is 2 then branch to increment


	B loop				@ Loop back around after doing our checks


increment: @ This chain of subroutines will control which digit gets incremented if we hit an increment condition
	MOV R2, #2			@ Set previous state to 2 if  previous state was 0 and we are pressing the button
	PUSH {R0, R2, R4, R9, LR}
	BIC R2,R2

	BL readSwitches
	AND R0,R0,#0xF		@ Masking the upper bits keeping the lower nibble
	MOV R4,R0			@ Preserving the value of the switches in R4
	CMP R0, #0			@ if no switches are active then increment most significant digit
	BLEQ incrementDig3
	CMP R0, #1
	BLEQ incrementDigit	@ If Sw[0] is active branch
	CMP R0, #2
	BLEQ incrementDigit	@ else if s[1] is set branch to incrementDigit
	CMP R0,#4
	MOVEQ R0,#3			@ Set R0 to 3 if sw[2] is pressed to scale offset properly
	BLEQ incrementDigit	@ we want to specifically only branch if one of the proper switch values is set, so we don't branch if 2 swtiches are set or 0
	CMP R0,#8
	LSREQ R0,#1			@ Divide by 2 if it's 8 to pass 4
	BLEQ incrementDigit
	@ So I'm not really protecting against a situation where 2 switches are fliped in the same loop seeing as you would have to be pretty fast to do that

	CMP R2, #1			@ if incrementDigit set R2 to 1 then we hit a condition in which we want to increment the following digits
	POPNE {R0, R2, R4, R9, LR}
	BNE loop 			@ Pop stack and branch back to loop if we don't need to increment the proceeding digits

	CMP R4,#1	@ checks if R0 was 1 meaning increment digit 0 was incremented now we want to increment dig1 and check if we need to follow up
	BEQ incrementDig1
	CMP R4,#2		@ Checks if R0 was 2 so increment dig2
	BEQ incrementDig2
	CMP R4,#4
	BEQ incrementDig3	@ Only need to check for 3-1 for incrementing when there is a carry

	STR R9,[FP,#-4]		@ Storing incremented value back to it's variable

	POP {R0, R2, R4, R9, LR}
B loop

incrementDig1:
	PUSH {R9, LR}
	MOV R2,#0 			@ Resetting R2

	LDR R9,[FP,#-8]		@ Load dig1
	ADD R9,R9,#1		@ R9++ incrementing DIG1

	CMP R9,#9
	MOVGT R9,#0			@ If R9 > 9 then R9 = 0
	MOVGT R2,#1


	MOV R1,R9			@ Loading the current digit value to the R1 to be displayed to the SSD
	MOV R0,#2			@ setting R0 to 2 to pass DIG1 information to setDisplayReg
	BL setDisplayReg

	STR R9,[FP,#-8]		@ Storing value (incremented or 0) back to it's variable on stack
	POP {R9, LR}

    CMP R2, #1
	BEQ incrementDig2	@ If DIG1 is greater than 9 then branch to inc2

B loop


incrementDig2:
	PUSH {R9, LR}
	MOV R2,#0 			@ Resetting R2

	LDR R9,[FP,#-12]	@ R9 = Dig2
	ADD R9,R9,#1		@ R9++ incrementing DIG2

	CMP R9,#9
	MOVGT R9,#0
	MOVGT R2,#1

	MOV R1,R9			@ Loading the current digit value to the R1 to be displayed to the SSD
	MOV R0,#3			@ setting R0 to 3 to pass DIG2 information to setDisplayReg
	BL setDisplayReg

	STR R9,[FP,#-12]	@ Storing value to stack variable
	POP {R9, LR}

    CMP R2, #1
	BEQ incrementDig3	@ If DIG0 is greater than 9 then branch to inc1
	MOV R2,#0
B loop

incrementDig3:
	PUSH {R0, R1, R9, LR}
	MOV R2,#0 			@ Resetting R2

	LDR R9,[FP,#-16]
	ADD R9,R9,#1		@ Dig3++

	CMP R9,#9
	MOVGT R9,#0
	MOVGT R2,#1

	MOV R1,R9			@ Loading the current digit value to the R1 to be displayed to the SSD
	MOV R0,#4			@ setting R0 to 4 to pass DIG3 information to setDisplayReg
	BL setDisplayReg

	STR R9,[FP,#-16]
	POP {R0, R1, R9, LR}
	CMP R0,#0	@ Ok this is a little hacky mayby but the only time that we should have R0 be 0 is when no switches are active
	BXEQ LR 	@ so in that case we need to branch with link then branch back hence these 2 instructions

    CMP R2, #1
	BEQ reset			@ If the most significant digit is above 9 then reset the whole counter
B loop

reset:
	PUSH {R0, LR}
	BIC R3,R3			@ Resetting the display reg
	BL display32BitReg
	MOV R0,#0
	STR R0,[FP,#-4]		@ Setting each of our local variables to 0 to reset the counter
	STR R0,[FP,#-8]
	STR R0,[FP,#-12]
	STR R0,[FP,#-16]
	POP {R0, LR}
	BL disableAllDP
B loop					@ Branch back to the begining of the loop.


@ R0 being passed as the digit to increment, it will scale the offset for our LDR and STR
@ R2 is a return value representing whether to increment the following digit or not
incrementDigit:
	PUSH {R1, R9, LR}
	MOV R1,#4
	MUL R1,R1,R0 			@ Scale the base offset (4) by R0
	SUB R1,FP,R1			@ R1 = FP - (scaled offset)

	LDR R9, [R1]		@ Load digit R0 into val at R1
	ADD R9,R9,#1			@ R9++
	CMP R9, #9
	MOVGT R9,#0
	MOVGT R2,#1 			@ If the digit is above 9 then we reset it (R9 = 0) and return 1 in R2
	STR R9, [R1]


	MOV R1,R9
	BL setDisplayReg


	POP {R1, R9, LR}
BX LR


@ this will just mask the buttons to the lower 2 btns and then set into a register then call a delay function to wait out the mechanical bounce
latchButtonPress:

	PUSH {R1, R2, LR}
	LDR R1,=COUNT_VAL
	BL debounceDelay
	POP {R1, R2, LR}

	AND R0,#0b0011 			@ Deleting upper 2 buttons' info

BX LR

@ R1 is delay count value
debounceDelay:
	SUBS R1,#1
	BNE debounceDelay
BX LR



.end





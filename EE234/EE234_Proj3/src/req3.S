@	Programmer: Devin Moore
@	Class: EE234 Clint Cole
@
@	Assignment: Project 3 Requirement 3
@
@	Description: Change previous requirement to allow for stopwatch behavior
@					Button 3 will stop and start counter, normal increment
@					and reset work but only when continuous increment isn't
@					happening.
@				Program is basically the exact same, but made slight adjustments to the increment fucntion to resolve register conflicts
@					and added continuous count, and adjusted debounceDelay to be a genaric delay subroutine

.text
.global main

@ Setting Constants
.equ COUNT_VAL, 0x6FFFFFF
.equ CONTINUOUS_DELAY, 0xA2700@0xC49BA @ attempt to get 1ms increment at the LSdigit 0xA2700 is pretty dang close

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
	BL disableAllDP
	BL display32BitReg

	CMP R2,#4
	BEQ continuousCount

	BL readButtons

	CMP R2,#0
	CMPGT R0,#0
	BICEQ R2,R2

	CMP R0,R2					@ This will compare current state (R0) with previous state (R2)
	BEQ loop					@ If the state hasn't changed (or we reset it) then branch to control loop
	BLNE latchButtonPress		@ and if we change state then we want to set that value of buttons into R0 and add a delay

	CMP R2,#0					@ Check if previous state was zero again
	BNE loop					@

	CMP R0,#3
	MOVEQ R2,R0					@ Set prevState=currState
	BEQ loop 					@ If both buttons are pressed branch to loop

	CMP R0,#4
	MOVEQ R2,R0
	BEQ continuousCount			@ If BTN[3] is pressed start continuous count

	CMP R0,#2
	BEQ increment				@ If prev state was 0 and curr state is 2 then branch to increment

	CMP R0,#1
	MOVEQ R2,R0					@ Set prevState=currState
	BEQ reset					@ Branch to reset count if BTN[0] is pressed.



	B loop						@ Loop back around after doing our checks


increment:

	MOV R2, #2
	PUSH {R0, R2, R4, R9, LR}
	BIC R2,R2

	BL readSwitches
	AND R0,R0,#0xF
	MOV R4,R0

	CMP R0, #0
	BEQ loop					@ No switches = no increment; Changed this from previous requirement

	CMP R0, #1
	BLEQ incrementDigit
	CMP R0, #2
	BLEQ incrementDigit
	CMP R0,#4
	MOVEQ R0,#3
	BLEQ incrementDigit
	CMP R0,#8
	LSREQ R0,#1
	BLEQ incrementDigit


	CMP R2, #1
	POPNE {R0, R2, R4, R9, LR}
	BNE loop

	CMP R4,#1
	BEQ incrementDig1
	CMP R4,#2
	BEQ incrementDig2
	CMP R4,#4
	BEQ incrementDig3

	STR R9,[FP,#-4]

	POP {R0, R2, R4, R9, LR}
B loop

incrementDig1:
	PUSH {R5, R9, LR}
	MOV R5,#0 					@ Resetting R2

	LDR R9,[FP,#-8]				@ Load dig1
	ADD R9,R9,#1				@ R9++ incrementing DIG1

	CMP R9,#9
	MOVGT R9,#0					@ If R9 > 9 then R9 = 0
	MOVGT R5,#1


	MOV R1,R9					@ Loading the current digit value to the R1 to be displayed to the SSD
	MOV R0,#2					@ setting R0 to 2 to pass DIG1 information to setDisplayReg
	BL setDisplayReg

	STR R9,[FP,#-8]				@ Storing value (incremented or 0) back to it's variable on stack


    CMP R5, #1
    POP {R5, R9, LR}
	BEQ incrementDig2			@ If DIG1 is greater than 9 then branch to inc2

B loop


incrementDig2:
	PUSH {R5, R9, LR}
	MOV R5,#0 					@ Resetting R2

	LDR R9,[FP,#-12]			@ R9 = Dig2
	ADD R9,R9,#1				@ R9++ incrementing DIG2

	CMP R9,#9
	MOVGT R9,#0
	MOVGT R5,#1

	MOV R1,R9					@ Loading the current digit value to the R1 to be displayed to the SSD
	MOV R0,#3					@ setting R0 to 3 to pass DIG2 information to setDisplayReg
	BL setDisplayReg

	STR R9,[FP,#-12]			@ Storing value to stack variable


    CMP R5, #1
    POP {R5, R9, LR}
	BEQ incrementDig3			@ If DIG0 is greater than 9 then branch to inc1

B loop

incrementDig3:
	PUSH {R1, R5, R9, LR}
	MOV R5,#0 					@ Resetting R2

	LDR R9,[FP,#-16]
	ADD R9,R9,#1				@ Dig3++

	CMP R9,#9
	MOVGT R9,#0
	MOVGT R5,#1

	MOV R1,R9					@ Loading the current digit value to the R1 to be displayed to the SSD
	MOV R0,#4					@ setting R0 to 4 to pass DIG3 information to setDisplayReg
	BL setDisplayReg

	STR R9,[FP,#-16]

	CMP R5, #1
	POP {R1, R5, R9, LR}
	BEQ reset
B loop

reset:
	PUSH {R0, LR}
	BIC R3,R3
	BL display32BitReg
	MOV R0,#0
	STR R0,[FP,#-4]
	STR R0,[FP,#-8]
	STR R0,[FP,#-12]
	STR R0,[FP,#-16]
	POP {R0, LR}
	BL disableAllDP
B loop


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
	BL delay
	POP {R1, R2, LR}

	AND R0,#0b0111 			@ Deleting upper buttons info

BX LR

@ R1 is delay count value
delay:
	SUBS R1,#1
	BNE delay
BX LR


continuousCount:
	PUSH {R2, LR}
	BL readButtons
	CMP R0,#4
	LDREQ R1,=COUNT_VAL
	BLEQ delay
	POPEQ {R2, LR}
	MOVEQ R2,#0				@ basically reset the state so we don't jump bck in here if we hit BTN[2]
	BEQ loop				@ If we reach the subroutine and we read BTN[2] being pressed branch back to loop

	LDR R1,=CONTINUOUS_DELAY
	BL delay


  	MOV R0,#1				@ Set digit to increment to 1 for DIG[0]
	BL incrementDigit
	BL disableAllDP
	BL display32BitReg
	CMP R2,#1
	POP {R2, LR}
	BEQ incrementDig1
	B continuousCount
.end





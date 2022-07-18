@	Programmer: Devin Moore
@	Class: EE234 Clint Cole
@
@	Descripltion: This file will contain subroutines to handle string inputs

.global sendString
.global readString
.equ ASCII_CAR_RTN, 0x0D
.equ COUNT_VAL, 0x6FFFFFF

@ This function will send a string of unknown length to the PC
@ Passed Parameters: R0 which will hold the starting address of the string to be sent,
@		- must contain the null char at the end
@ Returns: NONE
sendString:
	PUSH {R4, R5, LR}
	MOV R4,R0 @ Load R4 with the start address

	send_loop:
		LDRB R0,[R4],#1 		@ R0_LSB = R4_LSB; Load single byte into R0 from R4 then increment addr by 1 byte
		AND R0,R0,#0xFF			@ clearing the upper bits
		MOV R5,R0				@ passing into R5 for comparison after sendChar
		CMP R5,#0x00	@ if the character we sent wasn't the null char continue to loop
		BLNE sendCharacter
		CMP R5,#0x00	@ so the cpsr gets set to a different value during sendChar so I'm going to recompare for this check
		BNE send_loop

	POP {R4, R5, LR}
BX LR


@ This subroutine will read in a string of max length 128 characters.
@ if the number of characters read in reaches 127 we will stop read in and place null char at final memory location
@ Passed Parameters:
@			R0: starting address of memory location we're going to store the string at
@			R1: Max length of char array (128) ** Changed this slightly from requirement 4
@
readString:
	PUSH {R4, R5, LR}
	MOV R4,R0				@ Set our address into R4
	MOV R5,R1				@ Set our max len into R5
	SUB R5,#1				@ sub 1 from R5 to reduce max size by one to fit null char ** added for req 5
	readLoop:
		BL receiveCharacter

		CMP R0,#ASCII_CAR_RTN @ if we read in the car_rtn before we're done reading in the string then jump back to read in another char we don't want this
		BEQ readLoop

		STRB R0,[R4],#1				@ Set char into *R4 then increment R4 by 1 byte (well just by one but it translates into moving by a byte in memory)
		SUB R5,#1					@ decrement R5 by 1 if we don't see the null char

		CMP R0,#0x00				@ check if return value is the null char
		BEQ exitStrLoop				@ If we see the null char branch back out of here

		CMP R5,#0
		BNE readLoop
		BL o_delay
		MOV R0,#0x00		@ If we reach 0 with R5 it means we need to slap a NULL char on the end and get the heck out of dodge
		STRB R0,[R4]	@ R4 should be at the final memory location in our array at this point b/c it's increment after which means it'll be sitting on an 'empty' memory location
exitStrLoop:
	POP {R4, R5, LR}
BX LR @ Head back to main

o_delay:
	PUSH {R0, R1, LR}
	LDR R1,=COUNT_VAL
	i_delay:
		SUBS R1,#1
		BNE i_delay
	POP {R0, R1, LR}
BX LR

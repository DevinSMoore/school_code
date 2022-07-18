@	Programmer: Devin Moore
@	Class: EE234 Clint Cole
@
@	Assignment: Project 4 Requirement 4
@
@	Description: For this requirement we are receiving a string from the PC

.equ ASCII_CAR_RTN, 0x0D			@ Check for this to see if we send over the enter key; CAR_RTN = carriage return
.equ MAX_STR_LEN, 0x7F				@ 127 so we have space for the null char at the end if we read in a long sequence of chars w/o null char
@.equ MAX_STR_LEN, 0x05		@ for testingu b/c testing with 128 characters a bad idea for my sanity


.global main

.data

.comm input_string_arr, 128			@ 128-bytes as per the requirement

.text

main:
	BL initUART1	@ Initialize UART1 to the PC

	LDR R0,=input_string_arr
	LDR R1,=MAX_STR_LEN
	BL readString

	BL clearRx		@ Clear out Rx so we don't read in the CAR_RTN char before we want to check if user hit enter
	LDR R0,=input_string_arr
	BL echoLoop
	B HERE

HERE: B HERE


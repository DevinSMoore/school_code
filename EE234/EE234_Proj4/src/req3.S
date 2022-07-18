@	Programmer: Devin Moore
@	Class: EE234 Clint Cole
@
@	Assignment: Project 4 Requirement 3
@
@	Description: For this requirement we are sending a null terminated string which is
@				a sequence of bytes representing characters, the final byte being full
@				of zeros representing the null character therby terminating the string.
.global main

.data

@ Character array representing my name "Devin" : 0x44,0x65,0x76,0x69,0x6E; 5 chars long
devin_start:
.byte 0x44,0x65,0x76,0x69,0x6E,0x00 // 0x00 being the null char at the end for the string; 6 chars long


@ Main program below
.text


main:
	BL initUART1	@ Initialize UART1

	B loop

loop:
	LDR R0,=name_start
	BL sendString

HERE: B HERE






.end

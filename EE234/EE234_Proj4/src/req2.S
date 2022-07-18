@	Programmer: Devin Moore
@	Class: EE234 Clint Cole
@
@	Assignment: Project 4 Requirement 2
@
@	Description: Using UART to recieve characters do some stuff with LEDs then send characters back

.equ CHAR_LWR_A, 0x61 @ a
.equ CHAR_LWR_B, 0x62 @ b
.equ CHAR_LWR_C, 0x63 @ c
.equ CHAR_LWR_D, 0x64 @ d

.equ ASCII_0, 0x30
.equ ASCII_1, 0x31
.equ ASCII_2, 0x32
.equ ASCII_3, 0x33

.equ ASCII_NEWLINE, 0x0A

.text
.global main


main:
	BL initUART1	@ Initialize UART1

	B loop

loop:
	BL receiveCharacter

	CMP R0,#CHAR_LWR_A
	BLT loop					@ if it's below the lower bound go back to loop
	BEQ led0
	CMP R0,#CHAR_LWR_B
	BEQ led1
	CMP R0,#CHAR_LWR_C
	BEQ led2
	CMP R0,#CHAR_LWR_D
	BEQ led3
	BGT loop					@ if it's above the upper bound go back to loop


@ The following subroutines will simply pass the necessary values to the subroutines in gpio.S and UARTmodule.S to do the work
led0:
	MOV R0,#0
	BL toggleLED
	MOV R0,#ASCII_0
	BL sendCharacter
	MOV R0,#ASCII_NEWLINE
	BL sendCharacter
B loop

led1:
	MOV R0,#1
	BL toggleLED
	MOV R0,#ASCII_1
	BL sendCharacter
	MOV R0,#ASCII_NEWLINE
	BL sendCharacter
B loop

led2:
	MOV R0,#2
	BL toggleLED
	MOV R0,#ASCII_2
	BL sendCharacter
	MOV R0,#ASCII_NEWLINE
	BL sendCharacter
B loop

led3:

	MOV R0,#3
	BL toggleLED
	MOV R0,#ASCII_3
	BL sendCharacter
	MOV R0,#ASCII_NEWLINE
	BL sendCharacter
B loop


.end

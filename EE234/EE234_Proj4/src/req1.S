@	Programmer: Devin Moore
@	Class: EE234 Clint Cole
@
@	Assignment: Project 4 Requirement 1
@
@	Description: For this project we are setting up UART module 1 which is connected to our PC and then sending some info back and forth
@				This first requirement is just sending a character to the PC

.text

.global main

main:
	BL initUART1	// Initialize UART1

	MOV R0,#0x44	// put char 'D' into R1 then call sendCharacter then cross your fingers
	BL sendCharacter

HERE: B HERE // YAAAAY

.end



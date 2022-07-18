@	Programmer: Devin Moore
@	Class: EE234 Clint Cole
@
@	Assignment: Project 4 UART module
@
@	Description: Contains subroutines necessary to set up the UART for our specific use case
@				 It likely won't be very generalized


.global initUART1
.global sendCharacter
.global receiveCharacter
.global clearRx
.global echoLoop

@ Declaring Address' and offsets
.equ UART1_BASE_ADDRESS, 0xE000100C

@ reg address'
.equ UART1_CONTROL_REG, 0xE0001000 	@ bit[5] = Tx Disable; bit[4] = Tx EN; bit[3] = Rx Dis; bit[2] = Rx En; bit[1]=Tx reset (1=RS); [0]:Rx reset (1=reset)
.equ UART1_MODE_REG, 0xE0001004 		@ bit[9:8]: ChannMode(00 for normal); [7:6] #StopBits (00 for 1); [5:3] parity (1XX for no parity); [2:1] dataLen(0X:8bits); [0] MasterClk (0 for 100MHz);
.equ UART1_EN_INT_REG, 0xE0001008	@ 1=En; [10]:Tx Near Full; [4]:TxFIFOfull; [3]:TxFIFOempty; [2]:RxFIFOfull; [1]:RxFIFOempty; [0]:Rx Trigg Int
.equ UART1_DIS_INT_REG, 0xE000100C 	@ Same mapping as above; write 1 to disable
.equ UART1_INT_MASK_REG, 0xE0001010	@ Same mapping but read to check if INT is EN; 1=EN,0=NOT EN
.equ UART1_INT_STATUS_REG, 0xE0001014 @ Same mapping, any enable interrupts will set the values in this reg when their conditions are met

.equ UART1_RX_TRIG_VAL_REG, 0x20	@ This is the offset to set the value for the rx FIFO fill level interrupt or status bit; 6 bit value
.equ UART1_TX_TRIG_VAL_REG, 0x44	@ Same as above but for the transmit FIFO

// Going to set this to 0x7C for 115200 target BAUD rate
.equ UART1_BAUDGEN, 0xE0001018 		@ This is the divisor for the Rx line polling rate, MasterClk/BAUDGEN = Rx polling rate
.equ BAUDGEN_VAL_FOR_115200, 0x7C


.equ UART1_STATUS_REG, 0xE000102C		@ [11]: Tx State Mch. Active (1=Actv); [10]:RX State Mch; [4]:TxFull; [3]:TxEmpty; [2]:RxFull; [1]:RxEmpty; [0]:Rx level trigger bit; if FIFO is above level set this will be set
.equ UART1_FIFO_REG, 0xE0001030		@ This holds the FIFO data in the least significant bit; read the recieve FIFO, and write to the transmit FIFO using this same offset; 1 byte only please and thank you; also use LDRB to make sure we nab the correct info

.equ UART1_BAUD_RATE, 0xE0001034		@ This will set the actual baud rate based on the Rx polling rate: BAUD_RATE = RxPollRate / BAUD_RATE_REG; we pass the baud rate val into this register
.equ BAUDRATE_FOR_115200, 0x06	@ To get that magical 115200, well close enough anyways

.equ RESET_BIT_MASK, 0x03

.equ PARITY_DISABLE_MASK, 0x20	@ this is the only bit in the mode reg we want to set: 0000100000 for our operation

.equ TX_RX_EN, 0x14				@ Combined TX and RX enable mask b/c I have a lot of constants already; 10100
.equ TX_FULL_MASK, 0x10			@ bit[4] is TX full check
.equ RX_EMPTY_MASK,0x02			@ bit[1] is the Rx FIFO empty status bit

.equ ASCII_CAR_RTN, 0x0D			@ Check for this to see if we send over the enter key; CAR_RTN = carriage return


@ Order of operations for setting up our UART communiction with the PC:
@ 1. Reset Tx and Rx using SRT&SRR bits ([1]&[0]) in control reg (write 1 then wait for both to return 0 to continue with program)
@ 2. Set channel mode 00 for normal, stop bits 00 for 1,, parity 100 for no parity, 00 to dataLen for 8 bits, 0 to master clock for 100MHz
@ 3. Enable Tx & Rx with control reg: bit[4]:Tx EN; bit[2]:Rx EN
@ 4. Set Rx poll rate divisor to 0x7C, and baud rate divisor to 0x06


@ This subroutine will be the outward facing one that we call to set up the UART
initUART1:
	PUSH {LR}
	BL resetFIFO
	BL setUartModeReg
	BL enableTransmitRecieve
	BL setBaud115200
	POP {LR}
BX LR

@ This subroutine will reset Tx and Rx FIFOs
resetFIFO:
	PUSH {R4, LR}
	LDR R0,=UART1_CONTROL_REG
	LDR R4,=RESET_BIT_MASK

	LDR R1,[R0]					@ Load contents of control reg
	ORR R1,R4,R1				@ OR control reg with reset masks to set value

	STR R1,[R0]					@ Store values back into R0

	@ this will loop until reset is done; I don't know if this is necessary
	resetWaitLoop:
			LDR R1,[R0] 	@ Load current control reg
			AND R1,R4,R1	@ AND w/ reset mask to hide upper bits
			CMP R1,#0
			BNE resetWaitLoop @ If either of the lower two bits are set it will be greater than zero -> we continue to wait

	POP {R4, LR} @ If reset is complete return to main
BX LR

@ This subroutine will set our mode register how we want it. I'm going to clear the reg then set it to the new value
@ Normal Operation; 1 stop bit; no parity; 8-bit data; 100MHz master clock
setUartModeReg:
	PUSH {LR}
	LDR R0,=UART1_MODE_REG

	LDR R1,[R0]
	BIC R1,R1					@ Load then clear the mode register; this is because we want all zeros except for the parity disable bit

	LDR R2,=PARITY_DISABLE_MASK

	ORR R1,R2,R1
	STR R1,[R0]					@ ORR with parity disable mask then set mode reg

	POP {LR}
BX LR @ Jump back to main

@ This subroutine will enable the transmit and recieve lines
enableTransmitRecieve:
	PUSH {LR}
	LDR R0,=UART1_CONTROL_REG

	LDR R1,[R0]					@ Load control register value
	BIC R1,R1					@ Clear register
	LDR R2,=TX_RX_EN

	ORR R1,R2,R1				@ OR R1 with TX and RX enable mask
	STR R1,[R0]					@ Store R1 into config reg
	POP {LR}
BX LR

@ This subroutine will set the baud rate to 115200
setBaud115200:
	PUSH {LR}
	LDR R0,=UART1_BAUDGEN
	LDR R1,=BAUDGEN_VAL_FOR_115200
	STR R1,[R0]					@ Store desired baud gen val into baudgen register

	LDR R0,=UART1_BAUD_RATE
	LDR R1,=BAUDRATE_FOR_115200
	STR R1,[R0]					@ Store baud rate value int othe baud rate register

	POP {LR}
BX LR @ Return to main

@ This subroutine will check the value of the Tx FIFO full bit to see if there is room in the FIFO for transmit
@ R0: returns (0) for NOT full; (1) for full;
transmitFullCheck:
	PUSH {LR}
	MOV R0,#0
	LDR R1,=UART1_STATUS_REG

	LDR R2,[R1]  @ R2= contents of status reg
	LDR R1,=TX_FULL_MASK

	AND R1,R2,R1 @ AND R1 w/R2 and enable status bits to check if this results in zero which means that our
	CMP R1,#0
	MOVNE R0,#1	 @ If the reg doesn't equal zero set R0 to 1 to return full status, else return R0 with the 0 set in it to indiciate not full
	POP {LR}
BX LR

@ This subroutine will check the value of the Rx FIFO empty bit to see if there is anything in there to be read
@ Passed parameters: NONE
@ Returns: R0 returns (0) for NOT empty; (1) for empty;
recieveEmptyCheck:
	PUSH {LR}
	MOV R0,#0
	LDR R1,=UART1_STATUS_REG

	LDR R2,[R1]  @ R2 has contents of status reg
	LDR R1,=RX_EMPTY_MASK

	AND R1,R2,R1 @ AND R1 w/R2 and enable status bits to check if this results in zero which means that our Rx FIFO is not empty
	CMP R1,#0
	MOVNE R0,#1	 @ If the reg doesn't equal zero set R0 to 1 to return empty status, else return R0 with the 0 set to indiciate not empty
	POP {LR}
BX LR

@ This function will take in a character and check for an empty transmit FIFO then send the char when it is empty
@ Passed parameters: R0 will be the character that is print to the screen
@ Returns: NONE
sendCharacter:
	PUSH {R4, R5, LR}
	LDR R5,=UART1_FIFO_REG
	AND R4,R0,#0xFF			// Set our char val into the lower byte and clear upper byte of R4

	sendCharCheck:
		BL transmitFullCheck	@ Sit in this loop until the FIFO is not full (0)
		CMP R0,#0
		BNE sendCharCheck

	STRB R4,[R5]				@ once it's not full push next data into queue then we're done here

	POP {R4, R5, LR}
BX LR

@ This subroutine will read in a character from UART then passes it back to main
@ Passed parameters: NONE
@ Returns: R0 will contain the character recieved from UART FIFO
receiveCharacter:
	PUSH {LR}
	RxFifoEmptyCheck:
		BL recieveEmptyCheck
		CMP R0,#0
		BNE RxFifoEmptyCheck @ If returns 0 (not empty) break out of loop and read in next char

	LDR R1,=UART1_FIFO_REG
	LDRB R0,[R1]			 @ LSByte of R0 contains the read in char

	POP {LR}
BX LR @return to main

@ This subroutine will simply reset the Rx
clearRx:
	PUSH {R4, LR}
	LDR R4,=UART1_FIFO_REG

	BL recieveEmptyCheck
	CMP R0,#1			@ if it's empty just drop out of the subroutine
	BEQ exit_clrRx
	readLoop:
		LDR R3,[R4]		@ else jump into this loop where we load R3 with byte from front of queue then check if it's empty and loop again if it's not
		BL recieveEmptyCheck
		CMP R0,#1
		BNE readLoop @ If either of the lower two bits are set it will be greater than zero -> we continue to wait

exit_clrRx:
	POP {R4, LR}
BX LR

@ if we see the carriage return character then enter has been 'pressed' therefore we echo the string we read in from PC back to the PC
@ Input Parameters: input string to be echod
@ Returns: NONE
echoLoop:
	PUSH {R5, LR}
	MOV R5,R0 				@ Store string to echo in R5
	BL clearRx				@ have to clear it every time we go through
	BL receiveCharacter
	@BL o_delay
	CMP R0,#ASCII_CAR_RTN
	BNE echoLoop
	MOVEQ R0,R5
	BLEQ sendString
	POP {R5, LR}
BX LR

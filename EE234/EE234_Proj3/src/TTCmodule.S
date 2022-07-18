@	Programmer: Devin Moore
@	Class: EE234 Clint Cole
@
@	Description: This will contain the functions necessary to get the TT counters working
.text

.global setClock
.global setIntervalMode
.global setOneMsInterval
.global setIntervalOccured
.global readIntervalOccured
.global readCountValue



@ Constants to set up our counter
.equ ONE_MS_INTERVAL, 0xD8CC 				@ 55500 interval in decimal for a 55.5MHz clock gets 1ms
.equ ONE_MS_PRESCALE, 0x0	 				@ Just want to divide 111MHz clock by 2 => we want the prescale value to be 0

.equ TTC0_BASE_ADDRESS, 0xF8001000			@ First TTC module

.equ TTC0_1_CONFIG_OFFSET, 0x00	 			@ First timer in TTC0 module is what we're going to be setting up here; bit[1] is interval mode set bit: 1 to enable
.equ TTC0_1_111_CLK_ENABLE, 0x00			@ Bit[5] is CLK source: 1 for external; 0 for 111MHz
.equ TTC0_1_PRESCALE_ENABLE, 0x1			@ Bit[0] = prescale enable: 1 to enable

.equ TTC0_1_MODE_CONFIG_OFFSET, 0X0C
.equ INTERVAL_MODE_ENABLE, 0x2				@ Bit[1] = interval mode; 1 to enable

.equ TTC0_1_INTERRUPT_ENABLE_OFFSET, 0x60 	@ bit[0] = interval occured interrupt enable bit: 1 to enable
.set TTC0_1_INTERVAL_OCCURED_ENABLE, 0x1

.equ TTC0_1_INTERVAL_VAL_OFFSET, 0x24   	@ 16-bit int

.equ TTC0_1_INTERRUPT_STATUS_OFFSET, 0x54 	@ We're concerned with bit[0] which is the Interval Occured bit; read only, clear on read
.equ TTC0_1_INTERVAL_OCCURED_MASK, 0x1		@ We'll use this to just look at the LSbit

.equ TTC0_1_COUNT_VAL_OFFSET, 0x18

@ Subroutines

@ R0 will return the baseAddr || configOffset
getClockConfigAddress:
	PUSH {R4, R5, LR}
	BIC R0,R0
	LDR R4,=TTC0_BASE_ADDRESS
	LDR R5,=TTC0_1_CONFIG_OFFSET
	ORR R0,R4,R5		@ ORR R4 and R5 and set result into R0 then exit subroutine
	POP {R4, R5, LR}
BX LR

@ This will enable interval mode in TT0 timer 1
setClock:
	PUSH {R0, R4, R5, LR}
	BL getClockConfigAddress
	LDR R4,[R0]				@ Load R4 with current config register
	LDR R5,=TTC0_1_111_CLK_ENABLE
	ORR R4,R4,R5			@ ORR in 111clcok
	LDR R5,=TTC0_1_PRESCALE_ENABLE
	ORR R4,R4,R5			@ ORR in prescale enable

	LDR R5,=ONE_MS_PRESCALE
	LSL R5,#1				@ Shift prescale value left by 1 to get  it into the correct position
	ORR R4,R4,R5

	STR R4,[R0]				@ Set config reg
	POP {R0, R4, R5, LR}
BX LR

getModeConfigAddress:
	PUSH {R4, R5, LR}
	BIC R0,R0
	LDR R4,=TTC0_BASE_ADDRESS
	LDR R5,=TTC0_1_MODE_CONFIG_OFFSET
	ORR R0,R4,R5		@ ORR R4 and R5 and set result into R0 then exit subroutine
	POP {R4, R5, LR}
BX LR

setIntervalMode:
	PUSH {R0, R4, R5, LR}
	BL getModeConfigAddress
	LDR R4,[R0]						@ Bring in current config reg
	LDR R5,=INTERVAL_MODE_ENABLE
	ORR R4,R4,R5					@ Or with interval enable
	BIC R4,#1						@ clear bit[0] to unfreeze count
	STR R4,[R0]						@ Set config reg
	POP {R0, R4, R5, LR}
BX LR

getIntervalConfigAddress:
	PUSH {R4, R5, LR}
	BIC R0,R0
	LDR R4,=TTC0_BASE_ADDRESS
	LDR R5,=TTC0_1_INTERVAL_VAL_OFFSET
	ORR R0,R4,R5		@ ORR R4 and R5 and set result into R0 then exit subroutine
	POP {R4, R5, LR}
BX LR

setOneMsInterval:
	PUSH {R0, R4, R5, LR}
	BL getIntervalConfigAddress
	LDR R4,[R0]					@ bring in current value
	LDR R5,=ONE_MS_INTERVAL		@ bring in value we're going to set it to
	MOV R4,R5
	STR R4,[R0]					@ current val = new val
	POP {R0, R4, R5, LR}
BX LR

getInterruptEnableAddress:
	PUSH {R4, R5, LR}
	BIC R0,R0
	LDR R4,=TTC0_BASE_ADDRESS
	LDR R5,=TTC0_1_INTERRUPT_ENABLE_OFFSET
	ORR R0,R4,R5		@ ORR R4 and R5 and set result into R0 then exit subroutine
	POP {R4, R5, LR}
BX LR

setIntervalOccured:
	PUSH {R0, R4, R5, LR}
	BL getInterruptEnableAddress
	LDR R4,[R0]
	LDR R5,=TTC0_1_INTERVAL_OCCURED_ENABLE
	ORR R4,R4,R5
	STR R4,[R0]
	POP {R0, R4, R5, LR}
BX LR

getInterruptStatusAddress:
	PUSH {R4, R5, LR}
	BIC R0,R0
	LDR R4,=TTC0_BASE_ADDRESS
	LDR R5,=TTC0_1_INTERRUPT_STATUS_OFFSET
	ORR R0,R4,R5		@ ORR R4 and R5 and set result into R0 then exit subroutine
	POP {R4, R5, LR}
BX LR

@ Will return the value of the interrupt statos bit[0] register
@ Status register is cleared on read
readIntervalOccured:
	PUSH {R4, LR}
	BIC R0,R0
	BL getInterruptStatusAddress
	LDR R0,[R0]	@ load reg into R0
	LDR R4,=TTC0_1_INTERVAL_OCCURED_MASK
	AND R0,R0,R4	@ And with mask to get the LSbit
	POP {R4, LR}
BX LR @ return from subroutine with R0 as the read value



getCountValueAddress:
	PUSH {R4, R5, LR}
	BIC R0,R0
	LDR R4,=TTC0_BASE_ADDRESS
	LDR R5,=TTC0_1_COUNT_VAL_OFFSET
	ORR R0,R4,R5		@ ORR R4 and R5 and set result into R0 then exit subroutine
	POP {R4, R5, LR}
BX LR

readCountValue:
	PUSH {R4, R5, LR}
	BL getCountValueAddress
	LDR R1,[R0]
	MOV R0,R1
	POP {R4, R5, LR}
BX LR


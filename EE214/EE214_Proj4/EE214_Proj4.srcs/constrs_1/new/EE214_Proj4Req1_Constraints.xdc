# Constraints file for Project 4 Reqruirement 1

# Switches for sel0 - sel2
set_property -dict { PACKAGE_PIN R17   IOSTANDARD LVCMOS33 } [get_ports { sel[0] }]; #IO_L19N_T3_VREF_34 Schematic=SW0
set_property -dict { PACKAGE_PIN U20   IOSTANDARD LVCMOS33 } [get_ports { sel[1] }]; #IO_L15N_T2_DQS_34 Schematic=SW1

## Switches for I0-I3 -- I0
#set_property -dict { PACKAGE_PIN T10   IOSTANDARD LVCMOS33 } [get_ports { I0[0] }]; #IO_L10P_T1_34 Sch=VGA_R4_CON
#set_property -dict { PACKAGE_PIN T12   IOSTANDARD LVCMOS33 } [get_ports { I0[1] }]; #IO_L10N_T1_34 Sch=VGA_R5_CON
#set_property -dict { PACKAGE_PIN T11   IOSTANDARD LVCMOS33 } [get_ports { I0[2] }]; #IO_L18P_T2_34 Sch=VGA_R6_CON
#set_property -dict { PACKAGE_PIN T14   IOSTANDARD LVCMOS33 } [get_ports { I0[3] }]; #IO_L18N_T2_AD13N_35 Sch=VGA_R7_CON

# Push Buttons for I4-I7
set_property -dict { PACKAGE_PIN W14   IOSTANDARD LVCMOS33 } [get_ports { I0[4] }]; #IO_L8P_T1_34 Schematic=BTN0
set_property -dict { PACKAGE_PIN W13   IOSTANDARD LVCMOS33 } [get_ports { I0[5] }]; #IO_L4N_T0_34 Schematic=BTN1
set_property -dict { PACKAGE_PIN P15   IOSTANDARD LVCMOS33 } [get_ports { I0[6] }]; #IO_L24P_T3_34 Schematic=BTN2
set_property -dict { PACKAGE_PIN M14   IOSTANDARD LVCMOS33 } [get_ports { I0[7] }]; #IO_L23P_T3_35 Schematic=BTN3

# Individual LEDS
set_property -dict { PACKAGE_PIN N20   IOSTANDARD LVCMOS33 } [get_ports { led }]; #IO_L14P_T2_SRCC_34 Schematic=LD0
#set_property -dict { PACKAGE_PIN P20   IOSTANDARD LVCMOS33 } [get_ports { led[1] }]; #IO_L14N_T2_SRCC_34 Schematic=LD1
#set_property -dict { PACKAGE_PIN R19   IOSTANDARD LVCMOS33 } [get_ports { led[2] }]; #IO_0_34 Schematic=LD2
#set_property -dict { PACKAGE_PIN T20   IOSTANDARD LVCMOS33 } [get_ports { led[3] }]; #IO_L15P_T2_DQS_34 Schematic=LD3
#set_property -dict { PACKAGE_PIN T19   IOSTANDARD LVCMOS33 } [get_ports { led[4] }]; #IO_L3P_T0_DWS_PUDC_B_34 Schematic=LD4
#set_property -dict { PACKAGE_PIN U13   IOSTANDARD LVCMOS33 } [get_ports { led[5] }]; #IO_25_34 Schematic=LD5
#set_property -dict { PACKAGE_PIN V20   IOSTANDARD LVCMOS33 } [get_ports { led[6] }]; #IO_L16N_T2_34 Schematic=LD6
#set_property -dict { PACKAGE_PIN W20   IOSTANDARD LVCMOS33 } [get_ports { led[7] }]; #IO_L17N_T2_34  Schematic=LD7
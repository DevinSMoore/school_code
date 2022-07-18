#RGB_LEDS
set_property -dict { PACKAGE_PIN W18   IOSTANDARD LVCMOS33 } [get_ports { rgb_red }]; #IO_L22P_T3_34  Schematic=LD10_R


set_property -dict { PACKAGE_PIN Y14   IOSTANDARD LVCMOS33 } [get_ports { rgb_yellow[0] }]; #IO_L8N_T1_34 Schematic=LD11_R
set_property -dict { PACKAGE_PIN Y16   IOSTANDARD LVCMOS33 } [get_ports { rgb_yellow[1] }]; #IO_L7P_T1_34 Schematic=LD11_G
# set_property -dict { PACKAGE_PIN Y17   IOSTANDARD LVCMOS33 } [get_ports { rgb_yellow }]; #IO_L7N_T1_34 Schematic=LD11_B

#Switches
set_property -dict { PACKAGE_PIN R17   IOSTANDARD LVCMOS33 } [get_ports { sw[0] }]; #IO_L19N_T3_VREF_34 Schematic=SW0
set_property -dict { PACKAGE_PIN U20   IOSTANDARD LVCMOS33 } [get_ports { sw[1] }]; #IO_L15N_T2_DQS_34 Schematic=SW1
set_property -dict { PACKAGE_PIN R16   IOSTANDARD LVCMOS33 } [get_ports { sw[2] }]; #IO_L19P_T3_34 Schematic=SW2
set_property -dict { PACKAGE_PIN N16   IOSTANDARD LVCMOS33 } [get_ports { sw[3] }]; #IO_L21N_T3_DQS_AD14N_35 Schematic=SW3
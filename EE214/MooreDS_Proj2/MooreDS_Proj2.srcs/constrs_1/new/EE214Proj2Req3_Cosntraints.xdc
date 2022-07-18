# Switches 3 - 6 mapped to sw0 - sw3
set_property -dict { PACKAGE_PIN N16   IOSTANDARD LVCMOS33 } [get_ports { sw[0] }]; #IO_L21N_T3_DQS_AD14N_35 Schematic=SW3
set_property -dict { PACKAGE_PIN R14   IOSTANDARD LVCMOS33 } [get_ports { sw[1] }]; #IO_L6N_T0_VREF_34 Schematic=SW4
set_property -dict { PACKAGE_PIN P14   IOSTANDARD LVCMOS33 } [get_ports { sw[2] }]; #IO_L6P_T0_34 Schematic=SW5
set_property -dict { PACKAGE_PIN L15   IOSTANDARD LVCMOS33 } [get_ports { sw[3] }]; #IO_L22N_T3_AD7N_35 Schematic=SW6

#led[3] pammed to led
set_property -dict { PACKAGE_PIN T20   IOSTANDARD LVCMOS33 } [get_ports { led }]; #IO_L15P_T2_DQS_34 Schematic=LD3
# Individual LEDS
set_property -dict { PACKAGE_PIN N20   IOSTANDARD LVCMOS33 } [get_ports { led[0] }]; #IO_L14P_T2_SRCC_34 Schematic=LD0
set_property -dict { PACKAGE_PIN P20   IOSTANDARD LVCMOS33 } [get_ports { led[1] }]; #IO_L14N_T2_SRCC_34 Schematic=LD1

# RGB_LEDS
set_property -dict { PACKAGE_PIN W16   IOSTANDARD LVCMOS33 } [get_ports { RGB_led_G_10 }]; #IO_L18N_T2_34 Schematic=LD10_G
set_property -dict { PACKAGE_PIN Y14   IOSTANDARD LVCMOS33 } [get_ports { RGB_led_R_11 }]; #IO_L8N_T1_34 Schematic=LD11_R


# Switches
set_property -dict { PACKAGE_PIN R17   IOSTANDARD LVCMOS33 } [get_ports { sw }]; #IO_L19N_T3_VREF_34 Schematic=SW0

# Push Buttons
set_property -dict { PACKAGE_PIN W14   IOSTANDARD LVCMOS33 } [get_ports { btn[0] }]; #IO_L8P_T1_34 Schematic=BTN0
set_property -dict { PACKAGE_PIN W13   IOSTANDARD LVCMOS33 } [get_ports { btn[1] }]; #IO_L4N_T0_34 Schematic=BTN1
set_property -dict { PACKAGE_PIN P15   IOSTANDARD LVCMOS33 } [get_ports { btn[2] }]; #IO_L24P_T3_34 Schematic=BTN2
set_property -dict { PACKAGE_PIN M14   IOSTANDARD LVCMOS33 } [get_ports { btn[3] }]; #IO_L23P_T3_35 Schematic=BTN3
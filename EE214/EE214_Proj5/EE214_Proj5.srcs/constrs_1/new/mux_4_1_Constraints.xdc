# Clock
# set_property -dict { PACKAGE_PIN H16   IOSTANDARD LVCMOS33 } [get_ports { clk }]; #IO_L13P_T2_MRCC_35 Schematic=SYSCLK
# create_clock -add -name sys_clk_pin -period 10.00 -waveform {0 4} [get_ports { clk }];

# Individual LEDS
set_property -dict { PACKAGE_PIN N20   IOSTANDARD LVCMOS33 } [get_ports { led }]; #IO_L14P_T2_SRCC_34 Schematic=LD0
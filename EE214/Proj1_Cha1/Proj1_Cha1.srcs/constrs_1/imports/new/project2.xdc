# Buttons and sinble switch (0)
set_property -dict { PACKAGE_PIN W14   IOSTANDARD LVCMOS33 } [get_ports { btn[0] }];
set_property -dict { PACKAGE_PIN W13   IOSTANDARD LVCMOS33 } [get_ports { btn[1] }];
set_property -dict { PACKAGE_PIN P15   IOSTANDARD LVCMOS33 } [get_ports { btn[2] }];

set_property -dict { PACKAGE_PIN R17   IOSTANDARD LVCMOS33 } [get_ports { sw }];

#RGB LED 10
set_property -dict { PACKAGE_PIN W18   IOSTANDARD LVCMOS33 } [get_ports { RGB_led_A[0] }];
set_property -dict { PACKAGE_PIN W16   IOSTANDARD LVCMOS33 } [get_ports { RGB_led_A[1] }];
set_property -dict { PACKAGE_PIN Y18   IOSTANDARD LVCMOS33 } [get_ports { RGB_led_A[2] }];


////////////////////////////////////////////////////////////////////////////////// 
// Name: Devin Moore
// Class: EE214 Clint Cole
// Assignment: Project 4 Requirement 3
// TA: Logan Dihel
//
// Date Created: 2020/10/02
// Date Modified: 2020/10/09
// Module Name: EE214_Proj4Req3_test_fixture
//
// Description: This implements a priority Encoder
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns/1ps


module EE214_Proj4Req3_test_fixture;

// Declaring inputs
reg [3:0] btn;
reg sw;

// Declaring outputs
wire RGB_led_G_10;
wire RGB_led_R_11;
wire [1:0] led;

// Instantiating the CUT
EE214_Proj4Req3 cut(
    .btn(btn), // data in
    .sw(sw), // Enable 
    .RGB_led_G_10(RGB_led_G_10),
    .RGB_led_R_11(RGB_led_R_11),
    .led(led)
);
integer i;
initial
begin 
    sw = 0; // Asserting Ein low
    btn = 0;
    
    for (i = 0; i < 16; i = i + 1)
        #20 btn = i;
        
    #20 btn <=0; // 
    
    #20 sw = 1; // Asserting Ein high

    for (i = 0; i < 16; i = i + 1)
        #20 btn = i;
    #20 $finish;
end

endmodule

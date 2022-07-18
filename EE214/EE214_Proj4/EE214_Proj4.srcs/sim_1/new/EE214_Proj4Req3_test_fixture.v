////////////////////////////////////////////////////////////////////////////////// 
// Name: Devin Moore
// Class EE214 Clint Cole Section
// Assignment Project 3 Challenge 1
// 
// Create Date: 2020/09/22
// Last Modified: 2020/09/22
// Module Name: EE214_Proj3Chal1
//
// Description: This is an odd and even number detector.
//              If and odd number of switches are on led[0] will go high
//              If and even number of switches are on led[1] will go high
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

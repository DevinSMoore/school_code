////////////////////////////////////////////////////////////////////////////////// 
// Name: Devin Moore
// Class: EE214 Clint Cole
// Assignment: Project 4 Requirement 3
// TA: Logan Dihel 
// 
// Date Created: 2020/10/02
// Date Modified: 2020/10/09
// Module Name: EE214_Proj4Req3
//
// Description: This implements a priority Encoder
//////////////////////////////////////////////////////////////////////////////////
`timescale 1 ns / 1 ps


module EE214_Proj4Req3(
    input [3:0] btn, // 4 inputs
    input sw, // Ein
    output [1:0] led, // 2 bit output
    output RGB_led_G_10, // GS
    output RGB_led_R_11 // Eout
    );

reg [1:0] led;
reg RGB_led_G_10;
reg RGB_led_R_11;

always @ (btn, sw)
begin
    if (sw == 1) // if Ein is 1 then the outputs go into a priority system I3 gets priority over I2> I1 > I0
        led = (btn[3] == 1) ? 2'd3 : (
              (btn[2] == 1) ? 2'd2 : (
              (btn[1] == 1) ? 2'd1 : 2'd0)
             );
     else // this takes care of the condition where Ein = 0 then all outputs are 0
        led = 2'd0;
end

always @ (btn, sw)
begin
    if (sw == 1 && btn == 0) // if Ein is asserted high, and ALL inputs are off then Eout will be asserted high
        RGB_led_R_11 = 1'b1;
    else
        RGB_led_R_11 = 1'b0; // Eout will be asserted low if Ein and ANY output are high.
end
 
always @ (btn, sw)
begin
    if (sw == 1 && btn != 0) // if Ein and ANY inputs are on then Eout will be asserted high
        RGB_led_G_10 = 1'b1;
    else
        RGB_led_G_10 = 1'b0; // GS is asserted low if Ein is high and ALL outputs are low.
end

endmodule

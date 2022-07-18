`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/30/2020 03:09:19 AM
// Design Name: 
// Module Name: EE214_Proj7Req6
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module EE214_Proj7Req6(
    input i_serialData, // sw[0]
    input i_clk, i_rst, // i_rst = btn[1], i_clk = btn[0]
    output [7:0] o_led
);

wire o_clock;

// Instantiating the 8-bit SIPO shifter
shiftReg_8bit_SIPO shiftReg (
    .i_SD(i_serialData),
    .i_clk(i_clk),
    .i_rst(i_rst),

    .o_Q(o_led)
    
);

endmodule

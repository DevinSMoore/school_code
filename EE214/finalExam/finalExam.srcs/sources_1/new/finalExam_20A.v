`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/14/2020 12:25:55 PM
// Design Name: 
// Module Name: finalExam_20A
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


module finalExam_20A
(
    input i_clk, i_rst, i_A,
    [7:0] i_D,
    output o_X, o_Y
);
    
reg [15:0] r_counter;
assign o_X = (r_counter < i_D) ? (1'b1) : (1'b0);
assign o_Y = (r_counter > i_D) ? (1'b1) : (1'b0);
always @ (posedge i_clk)
begin assign r_counter = (i_A) ? (r_counter + 1) : (r_counter); end
endmodule


`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/14/2020 12:25:55 PM
// Design Name: 
// Module Name: finalExam_20B
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


module finalExam_20B(
    input [3:0] i_A, i_B,
    [1:0] i_sel,
    output o_Z,
    [3:0] o_F
    );

assign o_F = (i_sel == 2'b00) ? (i_A + i_B) :
             (i_sel == 2'b01) ? ({1'b0, i_A[3:1]}) :
             (i_sel == 2'b10) ? (i_A & i_B) : (i_A ^ i_B);
assign o_Z = (o_F) ? (1'b0) : (1'b1);
    
endmodule

`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/14/2020 12:37:51 PM
// Design Name: 
// Module Name: finalExam_20A_TB
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


module finalExam_20A_TB;

reg [7:0] i_A, i_B, i_D;
reg [1:0] i_sel;
wire o_Z;
wire [7:0] o_F;

assign o_F = (i_sel == 2'b00) ? (i_A + i_B) :
             (i_sel == 2'b01) ? ({1'b0, i_A[7:1]}) :
             (i_sel == 2'b10) ? (i_A & i_B) : (i_A ^ i_B);
assign o_Z = (o_F) ? (1'b0) : (1'b1);


initial begin
#20;
i_clk = 0;
i_A = 0;
i_D = 8'd0;






    
#20 $finish;
end
endmodule

//////////////////////////////////////////////////////////////////////////////////
//  Name: Devin Moore
//  Class: EE214 Clint Cole
//  TA: Logan Dihel
// 
//  Date Created: 2020/10/19
//  Date Modified: 2020/10/19
//  Module Name: EE214_Proj6Req1
//
//  Description: This requirement is implementing a circuit then hard coding
//               circuit delays into the simulation then simulating it.
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps

module Glitch_Testbench;
reg A, B, C;

wire X;

wire N1, N2, N3;

// AND gate with 1ns delay
assign #2 N1 = A & B;
// Not Gate with 1ns delay
assign #2 N2 = ~B;
// And Gate with 1ns delay
assign #2 N3 = N2 & C;
// Or Gate with 1ns delay
assign #2 X = N1 | N3;

initial begin
A = 0;
B = 0;
C = 0;

#1 A = 1'b1;
#1 C = 1'b1;

#1 B = 1'b1;
#10 B = 1'b0;


#10 B = 1'b1;
#10 B = 1'b0;


#20 $finish;
end
endmodule

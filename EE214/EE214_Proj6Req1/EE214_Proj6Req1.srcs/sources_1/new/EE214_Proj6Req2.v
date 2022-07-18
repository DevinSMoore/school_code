//////////////////////////////////////////////////////////////////////////////////
//  Name: Devin Moore
//  Class: EE214 Clint Cole
//  TA: Logan Dihel
// 
//  Assignment: Project 6 Delays and Glitches
//  Date Created: 2020/10/19
//  Date Modified: 2020/10/23
//  Module Name: EE214_Proj6Req2
//
//  Description: This requirement is implementing a circuit then hard coding
//               circuit delays into the simulation then simulating it.
//                 For this requirement we increased the delay to 2ns
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps

module EE214_Proj6Req2(
    input A, B, C,
    output X
);

wire N1, N2, N3;

// AND gate with 1ns delay
assign #1 N1 = A & B;
// Not Gate with 1ns delay
assign #1 N2 = ~B;
// And Gate with 1ns delay
assign #1 N3 = N2 & C;
// Or Gate with 2ns delay
assign #2 X = (N1 | N3); // increased the delay to 2ns

endmodule

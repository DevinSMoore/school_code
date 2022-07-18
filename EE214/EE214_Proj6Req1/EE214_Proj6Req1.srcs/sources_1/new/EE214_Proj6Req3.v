//////////////////////////////////////////////////////////////////////////////////
//  Name: Devin Moore
//  Class: EE214 Clint Cole
//  TA: Logan Dihel
// 
//  Assignment: Project 6 Delays and Glitches
//  Date Created: 2020/10/19
//  Date Modified: 2020/10/23
//  Module Name: EE214_Proj6Req3
//
//  Description: This requirement is basically identical to Req1 but everything
//               takes 5 times longer to happen. so the glitch takes 10ns to
//               reach the output then it lasts for 5ns which is the INV delay
//               which checks out.
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps

module EE214_Proj6Req3(
    input A, B, C,
    output X
);

wire N1, N2, N3;

// AND gate with 1ns delay
assign #5 N1 = A & B;
// Not Gate with 1ns delay
assign #5 N2 = ~B;
// And Gate with 1ns delay
assign #5 N3 = N2 & C;
// Or Gate with 1ns delay
assign #5 X = N1 | N3;

endmodule

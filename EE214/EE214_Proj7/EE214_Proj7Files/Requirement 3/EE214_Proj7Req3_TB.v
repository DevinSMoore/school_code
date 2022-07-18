//////////////////////////////////////////////////////////////////////////////////
//  Name: Devin Moore
//  Class: EE214 Clint Cole
//  TA: Logan Dihel
// 
//  Assignment: Project 7 Latches and Flip-Flops
//  Date Created: 2020/10/26
//  Date Modified: 2020/10/28
//  Module Name: EE214_Proj7Req3_TB
//
//  Description: This impliments a D-Latch with delays to be simulated 
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps

module EE214_Proj7Req3_TB;
reg D, G;
wire Q, Qn; 
wire ND, NDn, NQ, NQn, NInv;

EE214_Proj7Req3 cut(
    .D(D),
    .G(G),
    .Q(Q),
    .Qn(Qn)
);
assign #1 ND = ~(D & G);
assign #1 NInv = ~D;
assign #1 NDn = ~(NInv & G);
assign #1 NQ = ~(ND & NQn);
assign #1 NQn = ~(NDn & NQ);
assign Q = NQ;
assign Qn = NQn;

initial begin


   // Initialize Inputs
D = 0;
G = 0;

#20 G = 1;
#20 D = 1;
#1  G = 0;
    D = 0;



#20 $finish;
end

endmodule
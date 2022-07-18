//////////////////////////////////////////////////////////////////////////////////
//  Name: Devin Moore
//  Class: EE214 Clint Cole
//  TA: Logan Dihel
// 
//  Assignment: Project 7 Latches and Flip-Flops
//  Date Created: 2020/10/26
//  Date Modified: 2020/10/28
//  Module Name: EE214_Proj7Req3
//
//  Description: This impliments a D-Latch with delays to be simulated 
//                  metastable state happens when D is low, and G is high.
//                  D gets asserted high then 1 nanosecond later G (and/or D)
//                  goes low. Waiting 1ns for the signal from D going to 0 to
//                  propegate through the inverter.
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps

module EE214_Proj7Req3(
    input D, G,
    output Q, Qn 
);

wire ND, NDn, NQ, NQn, NInv;

assign #1 ND = ~(D & G);
assign #1 NInv = ~D;
assign #1 NDn = ~(NInv & G);
assign #1 NQ = ~(ND & NQn);
assign #1 NQn = ~(NDn & NQ);
assign Q = NQ;
assign Qn = NQn;

endmodule
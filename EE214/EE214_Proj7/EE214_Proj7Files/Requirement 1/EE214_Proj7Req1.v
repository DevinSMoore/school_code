//////////////////////////////////////////////////////////////////////////////////
//  Name: Devin Moore
//  Class: EE214 Clint Cole
//  TA: Logan Dihel
// 
//  Assignment: Project 7 Latches and Flip-Flops
//  Date Created: 2020/10/26
//  Date Modified: 2020/10/28
//  Module Name: EE214_Proj7Req1
//
//  Description: This impliments a NAND SRlatch with delays to be simulated 
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps

module EE214_Proj7Req1(
    input R, S,
    output Q, Qn
    );
    
wire NQ, NQn; // Node for Q, and Node for Qn

assign #1 NQ = ~(S & NQn);
assign #1 NQn = ~(R & NQ);
assign Q = NQ;
assign Qn = NQn;
    
    
endmodule

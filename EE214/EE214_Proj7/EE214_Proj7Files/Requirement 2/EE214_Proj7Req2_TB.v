//////////////////////////////////////////////////////////////////////////////////
//  Name: Devin Moore
//  Class: EE214 Clint Cole
//  TA: Logan Dihel
// 
//  Assignment: Project 7 Latches and Flip-Flops
//  Date Created: 2020/10/26
//  Date Modified: 2020/10/28
//  Module Name: EE214_Proj7Req2_TB
//
//  Description: This impliments a NOR SRlatch with delays to be simulated 
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps

module EE214_Proj7Req2_TB;
reg R, S;
wire Q, Qn;

    
wire NQ, NQn; // Node for Q, and Node for Qn

assign #1 NQ = ~(S & NQn);
assign #1 NQn = ~(R & NQ);
assign Q = NQ;
assign Qn = NQn;
    

// instantiating CUT
EE214_Proj7Req1 cut(
    .R(R),
    .S(S),
    .Q(Q),
    .Qn(Qn)
);


initial begin
   #20;
   // Initializing Inputs
    S = 1;
    R = 1;
    
    #20 S = 1;
    #20 S = 0;
    #20 R = 1;
    #20 R = 0;
    
    #20 S = 1;
        R = 1;
        
    #100;
    
    


    
    #20 $finish;
end



endmodule
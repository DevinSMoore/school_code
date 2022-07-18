`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////
// Name: Devin Moore
// Class EE214 Clint Cole
// Assignment Project 3 Requirement 3
// 
// Create Date: 09/22/2020
// Last Modified: 09/22/2020
// Module Name: EE214_Proj3Req3
//
// Description: 
//////////////////////////////////////////////////////////////

module EE214_Proj3Req3(
    input [7:0] sw,
    output led
    );

assign led = ((sw[7] & ~sw[6] & sw[5]) 
            & ((~sw[4]) | (sw[4] & (~sw[3] | (~sw[2] & ~sw[1])))));
            
//assign led = ((sw[7] & ~sw[6] & sw[5]) &
//              ((~sw[4] & ~sw[3] & ~sw[2] & ~sw[1] & ~sw[0])
//            | (~sw[4] & ~sw[3] & ~sw[2] & ~sw[1] & sw[0])
//            | (~sw[4] & ~sw[3] & ~sw[2] & sw[1] & ~sw[0])
//            | (~sw[4] & ~sw[3] & ~sw[2] & sw[1] & sw[0])
//            | (~sw[4] & ~sw[3] & sw[2] & ~sw[1] & ~sw[0])
//            | (~sw[4] & ~sw[3] & sw[2] & ~sw[1] & sw[0])
//            | (~sw[4] & ~sw[3] & sw[2] & sw[1] & ~sw[0])
//            | (~sw[4] & ~sw[3] & sw[2] & sw[1] & sw[0])
//            | (~sw[4] & sw[3] & ~sw[2] & ~sw[1] & ~sw[0])
//            | (~sw[4] & sw[3] & ~sw[2] & ~sw[1] & sw[0])
//            | (~sw[4] & sw[3] & ~sw[2] & sw[1] & ~sw[0])
//            | (~sw[4] & sw[3] & ~sw[2] & sw[1] & sw[0])
//            | (~sw[4] & sw[3] & sw[2] & ~sw[1] & ~sw[0])
//            | (~sw[4] & sw[3] & sw[2] & ~sw[1] & sw[0])
//            | (~sw[4] & sw[3] & sw[2] & sw[1] & ~sw[0])
//            | (~sw[4] & sw[3] & sw[2] & sw[1] & sw[0])
//            | (sw[4] & ~sw[3] & ~sw[2] & ~sw[1] & ~sw[0])
//            | (sw[4] & ~sw[3] & ~sw[2] & ~sw[1] & sw[0])
//            | (sw[4] & ~sw[3] & ~sw[2] & sw[1] & ~sw[0])
//            | (sw[4] & ~sw[3] & ~sw[2] & sw[1] & sw[0])
//            | (sw[4] & ~sw[3] & sw[2] & ~sw[1] & ~sw[0])
//            | (sw[4] & ~sw[3] & sw[2] & ~sw[1] & sw[0])
//            | (sw[4] & ~sw[3] & sw[2] & sw[1] & ~sw[0])
//            | (sw[4] & ~sw[3] & sw[2] & sw[1] & sw[0])
//            | (sw[4] & sw[3] & ~sw[2] & ~sw[1] & ~sw[0])
//            | (sw[4] & sw[3] & ~sw[2] & ~sw[1] & sw[0])));
endmodule

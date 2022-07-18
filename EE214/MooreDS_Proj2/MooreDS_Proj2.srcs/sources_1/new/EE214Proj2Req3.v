`timescale 1ns / 1ps
////////////////////////////////////////////////////////////////////////////////// 
// Name: Devin Moore
// Class EE214 Clint Cole Section whatever
// Assignment Project 2 Requirement 3
// 
// Create Date: 09/15/2020
// Module Name: EE214Proj2Req3
// 
//////////////////////////////////////////////////////////////////////////////////


module EE214Proj2Req3(
    input [3:0] sw,
    output led

);

assign led = (~sw[3] & ~sw[2] & ~sw[1] & sw[0])
           + (~sw[3] & ~sw[2] & sw[1] & sw[0])
           + (~sw[3] & sw[2] & ~sw[1] & ~sw[0])
           + (~sw[3] & sw[2] & sw[1] & ~sw[0])
           + (sw[3] & ~sw[2] & ~sw[1] & sw[0])
           + (sw[3] & ~sw[2] & sw[1] & sw[0])
           + (sw[3] & sw[2] & ~sw[1] & ~sw[0])
           + (sw[3] & sw[2] & sw[1] & ~sw[0]);

endmodule

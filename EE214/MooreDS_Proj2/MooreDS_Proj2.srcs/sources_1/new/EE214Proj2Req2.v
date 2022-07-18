`timescale 1ns / 1ps
////////////////////////////////////////////////////////////////////////////////// 
// Name: Devin Moore
// Class EE214 Clint Cole Section whatever
// Assignment Project 2 Requirement 2
// 
// Create Date: 09/15/2020
// Module Name: EE214Proj2Req2
// 
//////////////////////////////////////////////////////////////////////////////////

module EE214Proj2Req2(
    input [7:0] sw,
    output [2:0] led
);

// POS code
assign led[0] = (sw[1] | sw[0]) & (~sw[1] | ~sw[0]);

assign led[1] = (sw[3] | sw[2] | ~sw[1]) & (sw[3] | ~sw[2] | sw[1]) & (~sw[3] | sw[2] | sw[1]) &
(~sw[3] | ~sw[2] | sw[1]) & (~sw[3] | ~sw[2] | ~sw[1]);

assign led[2] = (sw[7] | sw[6] | sw[5] | sw[4]) & (sw[7] | sw[6] | ~sw[5] | sw[4]) &
                (sw[7] | ~sw[6] | sw[5] | ~sw[4]) & (sw[7] | ~sw[6] | ~sw[5] | sw[4]) &
                (sw[7] | ~sw[6] | ~sw[5] | ~sw[4]) & (~sw[7] | sw[6] | sw[5] | sw[4]) &
                (~sw[7] | sw[6] | sw[5] | ~sw[4]) & (~sw[7] | sw[6] | ~sw[5] | sw[4]) &
                (~sw[7] | sw[6] | ~sw[5] | ~sw[4]) & (~sw[7] | ~sw[6] | sw[5] | sw[4]) &
                (~sw[7] | ~sw[6] | sw[5] | ~sw[4]) & (~sw[7] | ~sw[6] | ~sw[5] | sw[4]);
                
endmodule
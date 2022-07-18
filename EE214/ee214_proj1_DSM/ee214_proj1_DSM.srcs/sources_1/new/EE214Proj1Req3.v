///////////////////////////////////////////////////////////////////////////////////////
// Devin Moore  
// EE214 Clint Cole Fall 2020
// 
// Create Date: 08/31/2020
// Design Name: Project 1 Requirement 3
//
// Description: Turn on each led sequentially use switches to individually turn them on
///////////////////////////////////////////////////////////////////////////////////////

`timescale 1ns / 1ps


module EE214Proj1Req3(
    
    output [11:0] led,
    input [11:0] sw

);


assign led = sw;

endmodule

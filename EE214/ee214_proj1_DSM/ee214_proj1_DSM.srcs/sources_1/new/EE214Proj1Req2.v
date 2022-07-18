////////////////////////////////////////////////////////////////////////////////////
// Devin Moore  
// EE214 Clint Cole Fall 2020
// 
// Create Date: 08/31/2020
// Design Name: Project 1 Requirement 2
//
// Description: For this requirement we turned on a single led, with a single switch
////////////////////////////////////////////////////////////////////////////////////

`timescale 1ns / 1ps


module EE214Proj1Req2(
   
   output led,
    input sw
);


assign led = sw;

endmodule



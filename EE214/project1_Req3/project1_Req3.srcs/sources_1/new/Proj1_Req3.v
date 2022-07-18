`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Devin Moore  
// EE214 Clint Cole Fall 2020
// 
// Create Date: 08/31/2020
// Design Name: Project 1 Requirement 3
//////////////////////////////////////////////////////////////////////////////////


module Proj1_Req3(
    
    // Statements for assignment 3
    output [11:0] led,
    input [11:0] sw

);


// statments for requirement 3
assign led = sw;

endmodule

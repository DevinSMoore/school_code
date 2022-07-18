//////////////////////////////////////////////////////////////////////////////////
// Devin Moore  
// EE214 Clint Cole Fall 2020
// 
// Create Date: 08/31/2020
// Design Name: Project 1 Requirement 4
//
// Description: Turn on each led in reverse order. I did this by reversing the 
//              mapping of the chips led pins such that when I turn on sw[0] the
//              variable led[0] goes high, but pin Y16 will go high on the board.
//////////////////////////////////////////////////////////////////////////////////

`timescale 1ns / 1ps


module EE214Proj1Req4(

    output [11:0] led,
    input [11:0] sw
);


assign led [11:0] = sw [11:0];

endmodule



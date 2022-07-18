`timescale 1ns / 1ps
/////////////////////////////////////////////////////////////////////////////////////////
// Devin Moore  
// EE214 Clint Cole Fall 2020
// 
// Create Date: 08/31/2020
// Design Name: Project 1 Requirement 4
//
// Description: The compliment of the switches drives the cathode of each segment low,
//              so that I can set the switches high to turn on a particular segment.
//              The four buttons drive the PFET on the anode of each SSD, which allows
//              to flow to the segments which turns (whichever ones that are enabled) on.
/////////////////////////////////////////////////////////////////////////////////////////

module EE214Proj1Reg5(
    output [3:0] seg_an,
    output [7:0] seg_cat,
    input [7:0] sw,
    input [3:0] btn

);

assign seg_cat[7:0] = ~sw[7:0];

assign seg_an[3:0] = ~btn[3:0];

endmodule



//////////////////////////////////////////////////////////////////////////////////
//  Name: Devin More
//  Class: EE214 Clint Cole
//  TA: Logan Dihel
//  Assignment: Exam 1 Makeup
//
//  Date Created: 2020/11/02
//  Description: Define a 4:1 mux that outputs the minterm equation:
//                  y<=m(3,5,6,7,10,12,14)
//              No dont cares, max size assumed 16 bits
// 
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps

module ExamMux_TB;
// Declaring I/O
reg C, D;
reg [1:0] sel;
wire Y;

// Instantiating the Circuit Under Test
ExamMux cut (
    .sel(sel),
    .C(C),
    .D(D),
    .Y(Y)
);

// initializeing loop variable
integer index;

initial begin // Input stumulus
#10;
// Initializing inputs
sel = 2'b00;
C = 0;
D = 0;

for (index = 0; index < 4; index = index + 1)
begin
    #20 sel = index; // should loop through every possible combination
end
C = 1;
D = 0;
for (; index < 4; index = index + 1)
begin
    #20 sel = index; // should loop through every possible combination
end

C = 0;
D = 1;
for (; index < 4; index = index + 1)
begin
    #20 sel = index; // should loop through every possible combination
end

C = 1;
D = 1;
for (; index < 4; index = index + 1)
begin
    #20 sel = index; // should loop through every possible combination
end


#20 $finish; // end simulation
end 
endmodule

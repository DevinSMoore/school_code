////////////////////////////////////////////////////////////////////////////////// 
// Name: Devin Moore
// Class: EE214 Clint Cole
// Assignment: Project 5 Challenge 1
// TA: Logan Dihel
//
// Date Created: 2020/10/14
// Date Modified: 2020/10/15
// Modlule Name: EE214_Proj5Chal1_test_fixture
//
// Description: Using a clock signal, a mux, and a decimal decoder to output
//              digits on two seven segment displays
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps

module EE214_Proj5Chal1_test_fixture;
// Inputs
reg [3:0] I0; // switches 3-0 control the value of the rightmost
reg [3:0] I1; // switches 7-4 controls second from right value
reg clk;

// Outputs
wire [7:0] Y; // SSD cathodes
wire [3:0] digit; // SSD anodes

// Instantiating the CUT
EE214_Proj5Chal1 cut(
    .I0(I0),
    .I1(I1),
    .clk(clk),
    .Y(Y),
    .digit(digit)
);

integer i; // Initializing loop variable
always #5 clk = ~clk;
// Input stimulus
initial
begin
#20; // just a delay at the begining to account for transiants.
I0 = 0;
I1 = 0;
clk = 0;
 


// Segment 0 going through the digits
for (i = 0; i < 16; i = i + 1)
begin 
    #20 I0 = i;
end
#20 I0 = 4'd15; // reseting sw register to 0
#20 I0 = 0;

// Segment 1 displaying from 0-f in hex
for (i = 0; i < 16; i = i + 1)
begin 
    #20 I1 = i;
end

#20 I1 = 4'd15;
#20 $finish;
end
endmodule

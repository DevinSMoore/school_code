////////////////////////////////////////////////////////////////////////////////// 
// Name: Devin Moore
// Class: EE214 Clint Cole
// Assignment: Project 5 Requirement 2
// TA: Logan Dihel
//
// Date Created: 2020/10/12
// Date Modified: 2020/10/15
// Modlule Name: EE214_Proj5Req2_test_fixture
//
// Description: Create a mux to demux transmission system
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps


module EE214_Proj5Req2_test_fixture;
// inputs
reg [3:0] sw;
wire [7:0] seg;
wire [3:0] seg_an;

// instantiating the CUT
EE214_Proj5Req2 cut(
    .sw(sw),
    .seg(seg),
    .seg_an(seg_an)
);

integer i; // initializing the counting variable

initial
begin
sw <= 0;

for (i = 0; i < 16; i = i + 1)
begin 
    #20 sw <= i; // will test all combinations of inputs from 0 through 15
end

#20 $finish;
end
endmodule

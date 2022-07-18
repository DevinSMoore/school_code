`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
//  Name: Devin Moore
//  Date: 2020/10/14
//
//  Description: This is the test fixture for Req3
//////////////////////////////////////////////////////////////////////////////////


module EE214_Proj5Req3_test_fixture;
// Inputs
reg [7:0] sw;
reg sel; // btn[0]

// Outputs
wire [7:0] seg_cat; // SSD cathodes
wire [3:0] seg_an; // SSD anodes

// Instantiating the CUT
EE214_Proj5Req3 cut(
    .sw(sw),
    .sel(sel),
    .seg_cat(seg_cat),
    .seg_an(seg_an)
);

integer i; // Initializing loop variable

// Input stimulus
initial
begin
sel = 0;
sw = 0;

// should be segment 0 going through the digits
for (i = 0; i < 16; i = i + 1)
begin 
    #20 sw = i;
end
#20 sw = 8'd15;
sw = 0; // reseting sw register to 0
sel = 1; // selecting segment 1 to display
// should be segment 1 going through the digits
for (i = 16; i < 256; i = i + 1)
begin 
    #20 sw = i;
end
#20 $finish;
end
endmodule

//////////////////////////////////////////////////////////////////////////////////
//  Name: Devin Moore
//  Class: EE214 Clint Cole
//  TA: Logan Dihel
// 
//  Assignment: Project 6 Delays and Glitches
//  Date Created: 2020/10/19
//  Date Modified: 2020/10/23
//  Module Name: EE214_Proj6Chal1_test_fixture
//
//  Description: This requirement is to impliment a 4:16 decoder then assign 
//               the 4 select signals to sw0-sw4 and the 16 outputs to ld0-ld16
//               then we find out what the exact delay is between setting sw0 to 1
//               and led0 getting asserted as a response.
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps


module EE214_Proj6Chal1_test_fixture;

// Inputs
reg [3:0] sw;

// Outputs
wire [15:0] led;

// Instantiating the CUT
EE214_Proj6Chal1 cut(
    .sw(sw),
    .led(led)
);

// Loop variable decliration
integer i = 0;

// Input stimulus
initial begin
#20;

sw = 0;

for (i = 0; i < 16; i = i + 1)
begin 
    #20 sw <= i;
end

#20 $finish;
end
endmodule

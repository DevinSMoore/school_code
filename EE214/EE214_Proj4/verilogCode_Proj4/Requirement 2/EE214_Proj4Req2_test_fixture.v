/////////////////////////////////////////////////////////////////////////////////////
// Name: Devin Moore
// Class: EE214 Clint Cole
// Assignment: Project 4 Requirement 1
// TA: Logan Dihel
// 
// Date Created: 2020/10/02
// Date Modified: 2020/10/09
// Module Name: EE214_Proj4Req2_test_fixture
//
// Description: Implements a decoder that will set led high, when certain 
//              combinations of sw[0] - sw[2] and btn[0] - btn[3] are set high
////////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps

module EE214_Proj4Req2_test_fixture;
// Input declarations
reg [1:0] sw;
reg [3:0] btn;

// Outputs
wire [3:0] led;

// Instantiate CUT
EE214_Proj4Req2 cut(
    .sw(sw),
    .btn(btn),
    .led(led)
);

integer i, j = 0;

// Applying the inputs 
initial 
begin


sw = 0;
btn = 0;
    // For loop will run through every combination of switches and buttons
    for (i = 0; i < 4; i = i + 1)
        begin
        #20 sw = i;
        for (j = 0; j < 16; j = j + 1)
            begin
            #20 btn = j;
            end
        end  #20 $finish;
end 
endmodule

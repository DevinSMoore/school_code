////////////////////////////////////////////////////////////////////////////////////
// Name: Devin Moore
// Class EE214 Clint Cole
// Assignment Project 4 Requirement 2
// 
// Create Date: 2020/10/02
// Last Modified: 2020/10/05
// Module Name: EE214_Proj4Req2_test_fixture
//
// Description:  Implements a decoder that will assert led high, when certain 
//              combinations of sw[0] - sw[2] and btn[0] - btn[3] are asserted high
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

integer i = 0, j = 0;

// Applying the inputs 
initial 
begin


    sw = 0;
    btn = 0;
    // For loops will run through every combination of switches and buttons
    for (i = 0; i < 4; i = i + 1)
        begin
        sw = i;
        for (j = 0; j < 16; j = j + 1)
            begin
            btn = j;
            #20;
            end
        end  #20 $finish;
end 
endmodule

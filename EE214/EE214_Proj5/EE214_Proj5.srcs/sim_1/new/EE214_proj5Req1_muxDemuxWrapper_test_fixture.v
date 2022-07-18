////////////////////////////////////////////////////////////////////////////////// 
// Name: Devin Moore
// Class: EE214 Clint Cole
// Assignment: Project 5 Requirement 1
// TA: Logan Dihel
//
// Date Created: 2020/10/12
// Date Modified: 2020/10/15
// Modlule Name: EE214_proj4Req1_muxDemuxWrapper_test_fixture
//
// Description: Create a mux to demux transmission system
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps


module EE214_proj4Req1_muxDemuxWrapper_test_fixture;
// Inputs 
reg [7:0] I; // Switches 0-7 for our mux data in
reg clk = 0;
// Outputs
wire [7:0] Y; // LED 0-7 is our demux output
wire red_led; // RED LED indicating the state of Y/EN wire (i.e. led is 1 when Y/EN is 1;

// Instantiating the CUT
EE214_proj5Req1_muxDemuxWrapper cut(
    .I(I),
    .clk(clk),
    .Y(Y),
    .red_led(red_led)
);


always #5 clk = ~clk; // implementing clock
integer i; // initializing loop variable

// Input stimulus
initial
begin
#20;
    I <= 8'd0;
    
    for (i = 0; i < 256; i = i + 1)
    begin
        #15 I = i;
    end


#20 $finish;
end


endmodule

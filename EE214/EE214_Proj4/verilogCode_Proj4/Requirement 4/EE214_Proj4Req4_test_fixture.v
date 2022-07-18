////////////////////////////////////////////////////////////////////////////////// 
// Name: Devin Moore
// Class EE214 Clint Cole Section
// Assignment Project 4 Requirement 4
// 
// Create Date: 2020/10/02
// Last Modified: 2020/10/09
// Module Name: EE214_Proj4Req4_test_fixture
//
// Description: This ipmliments a shifter onto our board
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps


module EE214_Proj4Req4_test_fixture;

// Inputs
reg [7:0] sw;
reg D; // Direction 0 for left 1 for right, sw[8]
reg R; // Rotate, 0 for no 1 for yes, sw[9]
reg F; // Fill bit value, btn[0]
reg EN; // Enable bit, btn[3]
reg [1:0] amt; // shift by what amount, sw[10] and sw[11]

// Output
wire [7:0] led; // leds 0-7 representing result of our shift operations.


// Instantiating the CUT
EE214_Proj4Req4 cut(
    .sw(sw),
    .D(D),
    .R(R),
    .F(F),
    .EN(EN),
    .led(led)
);
integer i = 0; // Declaring loop variable

// Input stimulus
initial
begin
    sw = 8'b11000110;  // setting some value then I'm going to go through the various settings
    D = 0; // Direction: left = 0; right = 1
    R = 0; // Rotate: Off = 0; On = 1
    F = 0; // Fill Bit: well 1 for 1, and 0 for 0.
    EN = 0; // Enable: 0 = Shifting Off and sw is passed straight throught to LED; 1 = Shifting enabled
    amt = 0; // Amount: 2 bit wide BUS that acts as the amount we want to shift. 0 for no shift; 1 for single bit shift; 2 for 2 bits; 3 for 3 bits


#5 EN = 0; // doing a run through with enable low
for (i = 0; i < 4; i = i + 1)
    begin
    #20 amt = i;
    end


#5 EN = 1; // Shifting left with fill bit low and EN high
for (i = 0; i < 4; i = i + 1)
    begin
    #20 amt = i;
    end

#5 D = 1; // Shift right, fill bit low
for (i = 0; i < 4; i = i + 1)
    begin
    #20 amt = i;
    end

#5 D = 0;
#5 R = 1; // Roatating left
for (i = 0; i < 4; i = i + 1)
    begin
    #20 amt = i;
    end


#5 D = 1; // Rotating right
for (i = 0; i < 4; i = i + 1)
    begin
    #20 amt = i;
    end

#5 D = 0;
#5 F = 1; // Shfiting left with fill bit enabled
for (i = 0; i < 4; i = i + 1)
    begin
    #20 amt = i;
    end


#5 D = 1; // Shfiting right with fill bit enabled
for (i = 0; i < 4; i = i + 1)
    begin
    #20 amt = i;
    end



#20 $finish; 
end
endmodule

////////////////////////////////////////////////////////////////////////////////// 
// Name: Devin Moore
// Class EE214 Clint Cole
// Assignment Project 4 Requirement 4
// 
// Create Date: 2020/10/02
// Last Modified: 2020/10/09
// Module Name: EE214_Proj4Req4
//
// Description: This ipmliments a shifter onto our board
//				Direction = sw[8]; 0 = left, 1 = right
//				Rotate = sw[9]; 0 = disabled, 1 = enabled
//				Fill = btn[0]; value of button is value of fill bit
//				Enable = btn[3]; 0 = value of input bus is passed to output
//								 1 = shifter is enabled.
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps

module EE214_Proj4Req4(
    input [7:0] sw,
    input D, // Direction 0 for left 1 for right, >>> sw[8]
    input R, // Rotate, 0 for no 1 for yes, >>> sw[9]
    input F, // Fill bit value, btn[0]
    input EN, // Enable bit, btn[3]
    input [1:0] amt, // shift by what amount, sw[10] and sw[11]
    output [7:0] led // leds 0-7 representing result of our shift operations.
);

reg [7:0] led;

always @ (sw, EN)
begin
    if (EN == 0) led = sw;
    else
        case (amt)
            2'd0:
                led = sw; // doesn't shift the values
            2'd1:
                if (R == 0) // Shifts/Rotates by 1 bit
                    led = (D == 0) ? {sw[6:0], F} : {F, sw[7:1]}; // Shifts and fills with value of F by concatinating the fill bit on the side that is being shifted.
                else
                    led = (D == 0) ? {sw[6:0], sw[7]} : {sw[0], sw[7:1]}; // Rotates don't care about fill bits here obviously
            2'd2:
                if (R == 0) // Shifts/Rotates by 2
                    led = (D == 0) ? {sw[5:0], F, F} : {F, F, sw[7:2]};
                else
                    led = (D == 0) ? {sw[5:0], sw[7], sw[6]} : {sw[1], sw[0], sw[7:2]}; 
            2'd3:
                if (R == 0) // Shifts/Rotates by 3
                    led = (D == 0) ? {sw[4:0], F, F, F} : {F, F, F, sw[7:3]};
                else
                    led = (D == 0) ? {sw[4:0], sw[7], sw[6], sw[5]} : {sw[2], sw[1], sw[0], sw[7:3]};
        endcase;
end

endmodule

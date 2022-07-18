////////////////////////////////////////////////////////////////////////////////// 
// Name: Devin Moore
// Class EE214 Clint Cole
// Assignment Project 4 Requirement 4
// 
// Create Date: 2020/10/02
// Last Modified: 2020/10/19
// Module Name: EE214_Proj4Req4
//
// Description: This ipmliments a shifter onto our board
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

reg [7:0] tempReg;

always @ (*) // previous sesitivity list did not include every input, this is now fixed
begin
    if (EN == 0) tempReg = sw;
    else
        case (amt)
            2'b00:
                tempReg = sw; // doesn't shift the values
            2'b01:
                if (R == 0) // Shifts/Rotates by 1 bit
                    tempReg = (D == 0) ? {sw[6:0], F} : {F, sw[7:1]}; // Shifts and fills with value of F
                else
                    tempReg = (D == 0) ? {sw[6:0], sw[7]} : {sw[0], sw[7:1]}; // Rotates
            2'b10:
                if (R == 0) // Shifts/Rotates by 2
                    tempReg = (D == 0) ? {sw[5:0], F, F} : {F, F, sw[7:2]};
                else
                    tempReg = (D == 0) ? {sw[5:0], sw[7], sw[6]} : {sw[1], sw[0], sw[7:2]}; 
            2'b11:
                if (R == 0) // Shifts/Rotates by 3
                    tempReg = (D == 0) ? {sw[4:0], F, F, F} : {F, F, F, sw[7:3]};
                else
                    tempReg = (D == 0) ? {sw[4:0], sw[7], sw[6], sw[5]} : {sw[2], sw[1], sw[0], sw[7:3]};
            default:
                tempReg = 8'b11000000;
        endcase;
end

assign led = tempReg;

endmodule

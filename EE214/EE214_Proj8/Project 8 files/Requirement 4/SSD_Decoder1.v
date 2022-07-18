////////////////////////////////////////////////////////////////////////////////// 
// Name: Devin Moore
// Class: EE214 Clint Cole
// Assignment: Project 5 Requirement 2
// TA: Logan Dihel
//
// Date Created: 2020/10/12
// Date Modified: 2020/10/12
// Modlule Name: EE214_Proj5Req2
//
// Description: creating a seven segment decoder using switchs to control which
//              digits to display.
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps


module SSD_Decoder1(
    input [3:0] i_data,
    output reg [7:0] o_seg // I did this so I could represent a particular digit as an 8 bit string of binary numbers goes from A-DP 0-7
    );
    
localparam zero = 8'b11111100; // gives us a 0 on an SSD
wire [7:0] one = 8'b01100000; // 1
wire [7:0] two = 8'b11011010; // 2
wire [7:0] three = 8'b11110010; // 3
wire [7:0] four = 8'b01100110; // 4
wire [7:0] five = 8'b10110110; // 5
wire [7:0] six = 8'b10111110; // 6
wire [7:0] seven = 8'b11100000; // 7
wire [7:0] eight = 8'b11111110; // 8
wire [7:0] nine = 8'b11100110; // 9
wire [7:0] A = 8'b11101110; // A
wire [7:0] b = 8'b00111110; // b
wire [7:0] C = 8'b10011100; // C
wire [7:0] d = 8'b01111010; // d
wire [7:0] E = 8'b10011110; // E
wire [7:0] F = 8'b10001110; // F

always @ (i_data)
begin
    case(i_data)    // I took the bitwise compliment because the letters encoded above work for a common cathode (segments are anodes).
        4'b0000:
            o_seg = ~zero;
        4'b0001:
            o_seg = ~one;
        4'b0010:
            o_seg = ~two;
        4'b0011:
            o_seg = ~three;
        4'b0100:
            o_seg = ~four;
        4'b0101:
            o_seg = ~five;
        4'b0110:
            o_seg = ~six;
        4'b0111:
            o_seg = ~seven;
        4'b1000:
            o_seg = ~eight;
        4'b1001:
            o_seg = ~nine;
        4'b1010:
            o_seg = ~A;
        4'b1011:
            o_seg = ~b;
        4'b1100:
            o_seg = ~C;
        4'b1101:
            o_seg = ~d;
        4'b1110:
            o_seg = ~E;
        4'b1111:
            o_seg = ~F;
        default:
            o_seg = 0;
    endcase
end

    
endmodule

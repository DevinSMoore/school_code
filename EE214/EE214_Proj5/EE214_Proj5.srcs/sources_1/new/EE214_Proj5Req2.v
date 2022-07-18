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


module EE214_Proj5Req2(
    input [3:0] sw,
    output reg [7:0] seg, // I did this so I could represent a particular digit as an 8 bit string of binary numbers goes from A-DP 0-7
    output [3:0] seg_an
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

assign seg_an [3:0] = 4'b1110; // this will turn off the 3 most sgnificant dislays, leaving the rightmost on.

//assign seg = ((sw == 4'd0) ? (zero) : (
//             (sw == 4'd1) ? (one) : (
//             (sw == 4'd2) ? (two) : (
//             (sw == 4'd3) ? (three) : (
//             (sw == 4'd4) ? (four) : (
//             (sw == 4'd5) ? (five) : (
//             (sw == 4'd6) ? (six) : (
//             (sw == 4'd7) ? (seven) : (
//             (sw == 4'd8) ? (eight) : (
//             (sw == 4'd9) ? (nine) : (
//             (sw == 4'd10) ? (A) : (
//             (sw == 4'd11) ? (b) : (
//             (sw == 4'd12) ? (C) : (
//             (sw == 4'd13) ? (d) : (
//             (sw == 4'd14) ? (E) : (F))))))))))))))));

always @ (sw)
begin
    case(sw)    // I took the bitwise compliment because the letters encoded above work for a common cathode (segments are anodes).
        4'b0000:
            seg = ~zero;
        4'b0001:
            seg = ~one;
        4'b0010:
            seg = ~two;
        4'b0011:
            seg = ~three;
        4'b0100:
            seg = ~four;
        4'b0101:
            seg = ~five;
        4'b0110:
            seg = ~six;
        4'b0111:
            seg = ~seven;
        4'b1000:
            seg = ~eight;
        4'b1001:
            seg = ~nine;
        4'b1010:
            seg = ~A;
        4'b1011:
            seg = ~b;
        4'b1100:
            seg = ~C;
        4'b1101:
            seg = ~d;
        4'b1110:
            seg = ~E;
        4'b1111:
            seg = ~F;
        default:
        seg = 0;
    endcase
end

    
endmodule

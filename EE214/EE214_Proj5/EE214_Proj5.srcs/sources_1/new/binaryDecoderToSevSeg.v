`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
//  Name: Devin Moore
//  Date: 2020/10/14
//
//  Description: Impliments a binary decoder to seven segment display 
//////////////////////////////////////////////////////////////////////////////////


module binaryDecoderToSevSeg(
    input [3:0] sw,
    output reg [7:0] seg_cat // I did this so I could represent a particular digit as an 8 bit string of binary numbers goes from A-DP 0-7
    );
    
reg [7:0] zero = 8'b11111100; // gives us a 0 on an SSD
reg [7:0] one = 8'b01100000; // 1
reg [7:0] two = 8'b11011010; // 2
reg [7:0] three = 8'b11110010; // 3
reg [7:0] four = 8'b01100110; // 4
reg [7:0] five = 8'b10110110; // 5
reg [7:0] six = 8'b10111110; // 6
reg [7:0] seven = 8'b11100000; // 7
reg [7:0] eight = 8'b11111110; // 8
reg [7:0] nine = 8'b11100110; // 9
reg [7:0] A = 8'b11101110; // A
reg [7:0] b = 8'b00111110; // b
reg [7:0] C = 8'b10011100; // C
reg [7:0] d = 8'b01111010; // d
reg [7:0] E = 8'b10011110; // E
reg [7:0] F = 8'b10001110; // F

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
    case(sw)    // I took the bitwise compliment because the letters encoded above work for an common cathode (segments are anodes).
        4'b0000:
            seg_cat = ~zero;
        4'b0001:
            seg_cat = ~one;
        4'b0010:
            seg_cat = ~two;
        4'b0011:
            seg_cat = ~three;
        4'b0100:
            seg_cat = ~four;
        4'b0101:
            seg_cat = ~five;
        4'b0110:
            seg_cat = ~six;
        4'b0111:
            seg_cat = ~seven;
        4'b1000:
            seg_cat = ~eight;
        4'b1001:
            seg_cat = ~nine;
        4'b1010:
            seg_cat = ~A;
        4'b1011:
            seg_cat = ~b;
        4'b1100:
            seg_cat = ~C;
        4'b1101:
            seg_cat = ~d;
        4'b1110:
            seg_cat = ~E;
        4'b1111:
            seg_cat = ~F;
        
    endcase
end
endmodule

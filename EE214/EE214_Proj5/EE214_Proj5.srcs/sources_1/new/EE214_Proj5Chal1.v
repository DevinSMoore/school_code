////////////////////////////////////////////////////////////////////////////////// 
// Name: Devin Moore
// Class: EE214 Clint Cole
// Assignment: Project 5 Challenge 1
// TA: Logan Dihel
//
// Date Created: 2020/10/14
// Date Modified: 2020/10/15
// Modlule Name: EE214_Proj5Chal1
//
// Description: Using a clock signal, a mux, and a decimal decoder to output
//              digits on two seven segment displays
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps


module EE214_Proj5Chal1(
    input [3:0] I0, // switches 3-0 control the value of the rightmost
    input [3:0] I1, // switches 7-4 controls second from right value
    input clk,
    output [7:0] Y, // SSD cathodes
    output [3:0] digit // SSD anodes
    );

wire [3:0] link;
wire sel;

assign digit = (sel == 0) ? (4'b1110) : // for rightmost SSD
                            (4'b1101); // for second SSD from right

bus_4_mux_2_1 mux( // 4 wide bus 2:1 mux wich divided clock controling select
    .I0(I0),
    .I1(I1),
    .S(sel),
    .Y(link)
);    

binaryDecoderToSevSeg decoder( // 4:16 deocoder for hex digits 0-f put onto a seven segment display
    .sw(link),
    .seg_cat(Y)
);

clock counter (
    .clk(clk),
    .Y(sel)
);

endmodule

module clock (
input clk,
output Y
);

reg [27:0] counter = 0; //

always @ (posedge clk)
begin 
counter <= counter + 1;
end

assign Y = counter[20];

endmodule

module bus_4_mux_2_1(
    input [3:0] I0, // switches 3 - 0
    input [3:0] I1, // switches 7 - 4
    input S, // button 0
    output reg [3:0] Y
    );

always @ (S, I0, I1)
begin 
    if (S == 0)
        Y = I0; // will pass the data on switches 3 - 0 if sel is set low
    else
        Y = I1; // will pass sw7 - sw4
end
    
endmodule

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

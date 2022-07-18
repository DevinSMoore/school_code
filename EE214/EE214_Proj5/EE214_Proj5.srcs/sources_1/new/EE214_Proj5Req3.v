////////////////////////////////////////////////////////////////////////////////// 
// Name: Devin Moore
// Class: EE214 Clint Cole
// Assignment: Project 5 Requirement 3
// TA: Logan Dihel
//
// Date Created: 2020/10/14
// Date Modified: 2020/10/15
// Modlule Name: EE214_Proj5Req3
//
// Description: Impliments a 2 digit SevSegDisplay decoder using a 
//              4-bit wide 2:1 mux
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps

module EE214_Proj5Req3(
    input [7:0] sw,
    input sel, // btn[0]
    output [7:0] seg_cat, // SSD cathodes
    output [3:0] seg_an // SSD anodes
    );
    
wire [3:0] aWire; // A wire between mux and decoder

assign seg_an = (sel == 0) ? (4'b1110) : (4'b1101);

bus_4_mux_2_1 muxBus ( // 4 bit bus 2:1 mux
    .I0(sw[3:0]),
    .I1(sw[7:4]),
    .S(sel),
    .Y(aWire) // mux output 
);
binaryDecoderToSevSeg sevSeg1 ( // seven segment display binary decoder for 0-f
    .sw(aWire),
    .seg_cat(seg_cat)
);
endmodule

//////////////////////////////////////////////////////////////////////////////////
//  Name: Devin Moore
//  Class: EE214 Clint Cole
//  TA: Logan Dihel
// 
//  Assignment: Project 7 Latches and Flip-Flops
//  Date Created: 2020/10/26
//  Date Modified: 2020/10/30
//  Module Name: EE214_Proj7Req5
//
//  Description: This requirement impliments a 16-bit PISO shifter that will
//               loop (rotate) around, instead of being shifted off the edge
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps

module EE214_Proj7Req5(
    input [7:0] i_D, // sw[7:0]
    input i_clk, i_rst, i_S, // i_rst = btn[1], i_S = btn[0]
    output [15:0] o_led
);

wire i_serialData, o_serialData, o_clock;

// Instantiating the 8-PISO shifters
shiftReg_8bit_PISO shiftReg1 (
    .i_SD(i_serialData),
    .i_S(i_S),
    .i_clk(o_clk),
    .i_rst(i_rst),
    .i_PD(i_D[7:0]),
    .o_SD(o_serialData), // output of 1 goes to Serial in of 2
    .o_Q(o_led[7:0])
    
);

shiftReg_8bit_PISO shiftReg2 (
    .i_SD(o_serialData),
    .i_S(i_S),
    .i_clk(o_clk),
    .i_rst(i_rst),
    .o_SD(i_serialData), // output of 2 goes to serial in of 1\
    .o_Q(o_led[15:8])    
);

clockDivider clock(
    .clk(i_clk),
    .Y1(o_clk)
);


endmodule
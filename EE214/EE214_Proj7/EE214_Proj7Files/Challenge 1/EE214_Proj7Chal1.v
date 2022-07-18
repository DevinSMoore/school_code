//////////////////////////////////////////////////////////////////////////////////
//  Name: Devin Moore
//  Class: EE214 Clint Cole
//  TA: Logan Dihel
// 
//  Assignment: Project 7 Latches and Flip-Flops
//  Date Created: 2020/10/30
//  Date Modified: 2020/11/01
//  Module Name: EE214_Proj7Chal1
//
//  Description: This impliments a PIPO reg to store data connected to a barrel
//               shifter. The resources I found said the diference between a
//               barrel shifters, and others is that the barrel shifter is 
//               combinitorial. So i'm not 100% certain this is what was expected
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps

// i_rst = btn[3]
// i_clk = btn[0]
// i_direction = btn[1]
// i_rotate = btn[2]
// i_fill = sw[11]


module EE214_Proj7Chal1(
    input [7:0] i_sw,
    input i_rst, i_clk, i_fill, i_rotate, i_direction, /// for rotate 1 = yes 0 = no; for direction 1 = right 0 = left
    output [7:0] o_led 
);

wire [7:0] regToBarrel;
wire [7:0] o_leftShift;
wire [7:0] o_rightShift;
wire [7:0] o_leftRotate;
wire [7:0] o_rightRotate; // creating independant outputs for each operation then selecting those

wire [3:0] i_amt; // assigning the amount of the shift to the first 4 switches

  

// Instantiating the PIPO register

PIPO_ShiftReg pipoReg (
    .i_data(i_sw),
    .i_clk(i_clk),
    .i_rst(i_rst),
    .o_storedValue(regToBarrel)
);

// Instantiating the left and right shifter/rotator

shiftLeft (
    .i_data(regToBarrel),
    .i_amt(i_amt),
    .i_fill(i_fill),
    .o_shiftedData(o_leftShift)
); 

shiftRight (
    .i_data(regToBarrel),
    .i_amt(i_amt),
    .i_fill(i_fill),
    .o_shiftedData(o_rightShift)
); 

rotateLeft (
    .i_data(regToBarrel),
    .i_amt(i_amt),
    .o_rotatedData(o_leftRotate)
); 

rotateRight (
    .i_data(regToBarrel),
    .i_amt(i_amt),
    .o_rotatedData(o_rightRotate)
); 

assign i_amt = i_sw[3:0];
assign o_led = (i_rotate == 1) ? ((i_direction == 1) ? (o_rightRotate) : (o_leftRotate)) :
                            ((i_direction == 1) ? (o_rightShift) : (o_leftShift));   


endmodule
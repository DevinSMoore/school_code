`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/31/2020 09:01:19 PM
// Design Name: 
// Module Name: shiftReg_8bit
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module shiftReg_8bit_PISO(
    input i_SD, i_clk, i_S, i_rst, // serial data in, clock in, paralel data in enable
    input [7:0] i_PD, // parallel data in
    output o_SD, // serial data out
    output [7:0] o_Q
    
    );
    wire [7:0] i_D; // data in for DFFs
    wire [7:0] o_temp;
    
    mux_2_1 muxD0(
    .I0(i_SD), // serial data in muxD0 because it's the first DFF in the chain
    .I1(i_PD[0]),
    .S(i_S),
    .Y(i_D[0])
);
    mux_2_1 muxD1(
    .I0(o_temp[0]),
    .I1(i_PD[1]),
    .S(i_S),
    .Y(i_D[1])
);
    mux_2_1 muxD2(
    .I0(o_temp[1]),
    .I1(i_PD[2]),
    .S(i_S),
    .Y(i_D[2])
);
    mux_2_1 muxD3(
    .I0(o_temp[2]),
    .I1(i_PD[3]),
    .S(i_S),
    .Y(i_D[3])
);
    mux_2_1 muxD4(
    .I0(o_temp[3]),
    .I1(i_PD[4]),
    .S(i_S),
    .Y(i_D[4])
);
    mux_2_1 muxD5(
    .I0(o_temp[4]),
    .I1(i_PD[5]),
    .S(i_S),
    .Y(i_D[5])
);
    mux_2_1 muxD6(
    .I0(o_temp[5]),
    .I1(i_PD[6]),
    .S(i_S),
    .Y(i_D[6])
);
    mux_2_1 muxD7(
    .I0(o_temp[6]),
    .I1(i_PD[7]),
    .S(i_S),
    .Y(i_D[7])
);


// D[0] -> Q[0]
DFF DFF0 (
    .D(i_D[0]),
    .Q(o_temp[0]),
    .rst(i_rst),
    .clk(i_clk)
);
// D[1] -> Q[1]
DFF DFF1 (
    .D(i_D[1]),
    .Q(o_temp[1]),
    .rst(i_rst),
    .clk(i_clk)
);
// D[2] -> Q[2]
DFF DFF2 (
    .D(i_D[2]),
    .Q(o_temp[2]),
    .rst(i_rst),
    .clk(i_clk)
);
// D[3] -> Q[3]
DFF DFF3 (
    .D(i_D[3]),
    .Q(o_temp[3]),
    .rst(i_rst),
    .clk(i_clk)
);
// D[4] -> Q[4]
DFF DFF4 (
    .D(i_D[4]),
    .Q(o_temp[4]),
    .rst(i_rst),
    .clk(i_clk)
);
// D[5] -> Q[5]
DFF DFF5 (
    .D(i_D[5]),
    .Q(o_temp[5]),
    .rst(i_rst),
    .clk(i_clk)
);
// D[6] -> Q[6]
DFF DFF6 (
    .D(i_D[6]),
    .Q(o_temp[6]),
    .rst(i_rst),
    .clk(i_clk)
);
// D[7] -> Q[7]
DFF DFF7 (
    .D(i_D[7]),
    .Q(o_SD),
    .rst(i_rst),
    .clk(i_clk)
);

assign o_Q = o_temp;
assign o_temp[7] = o_SD;
endmodule

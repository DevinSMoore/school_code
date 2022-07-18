`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/31/2020 11:59:33 PM
// Design Name: 
// Module Name: shiftReg_8bit_SIPO
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


module shiftReg_8bit_SIPO(
  input i_SD, i_clk, i_S, i_rst, // serial data in, clock in, paralel data in enable
  output o_SD, // serial data out
  output [7:0] o_Q
    
    );
    wire [7:0] o_temp;
    
// D[0] -> Q[0]
DFF DFF0 (
    .D(i_SD),
    .Q(o_temp[0]),
    .rst(i_rst),
    .clk(i_clk)
);
// D[1] -> Q[1]
DFF DFF1 (
    .D(o_temp[0]),
    .Q(o_temp[1]),
    .rst(i_rst),
    .clk(i_clk)
);
// D[2] -> Q[2]
DFF DFF2 (
    .D(o_temp[1]),
    .Q(o_temp[2]),
    .rst(i_rst),
    .clk(i_clk)
);
// D[3] -> Q[3]
DFF DFF3 (
    .D(o_temp[2]),
    .Q(o_temp[3]),
    .rst(i_rst),
    .clk(i_clk)
);
// D[4] -> Q[4]
DFF DFF4 (
    .D(o_temp[3]),
    .Q(o_temp[4]),
    .rst(i_rst),
    .clk(i_clk)
);
// D[5] -> Q[5]
DFF DFF5 (
    .D(o_temp[4]),
    .Q(o_temp[5]),
    .rst(i_rst),
    .clk(i_clk)
);
// D[6] -> Q[6]
DFF DFF6 (
    .D(o_temp[5]),
    .Q(o_temp[6]),
    .rst(i_rst),
    .clk(i_clk)
);
// D[7] -> Q[7]
DFF DFF7 (
    .D(o_temp[6]),
    .Q(o_SD),
    .rst(i_rst),
    .clk(i_clk)
);

assign o_Q = o_temp;
assign o_temp[7] = o_SD;
endmodule

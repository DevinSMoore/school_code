`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/01/2020 12:31:21 AM
// Design Name: 
// Module Name: shiftReg_8bit_PIPO
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


module shiftReg_8bit_PIPO(
    input [7:0] D,
    input S, rst, clk, // D is sw[7:0], S is btn[1], rst is btn[3], clk is btn[0]
    output [7:0] led
);
wire [7:0] Q;
// Instantiating Dflipflops and mux

mux_2_1 mux(
    .I0(D),
    .I1(Q),
    .S(S),
    .Y(led)
);


// D[0] -> Q[0]
DFF DFF0 (
    .D(D[0]),
    .Q(Q[0]),
    .rst(rst),
    .clk(clk)
);
// D[1] -> Q[1]
DFF DFF1 (
    .D(D[1]),
    .Q(Q[1]),
    .rst(rst),
    .clk(clk)
);
// D[2] -> Q[2]
DFF DFF2 (
    .D(D[2]),
    .Q(Q[2]),
    .rst(rst),
    .clk(clk)
);
// D[3] -> Q[3]
DFF DFF3 (
    .D(D[3]),
    .Q(Q[3]),
    .rst(rst),
    .clk(clk)
);
// D[4] -> Q[4]
DFF DFF4 (
    .D(D[4]),
    .Q(Q[4]),
    .rst(rst),
    .clk(clk)
);
// D[5] -> Q[5]
DFF DFF5 (
    .D(D[5]),
    .Q(Q[5]),
    .rst(rst),
    .clk(clk)
);
// D[6] -> Q[6]
DFF DFF6 (
    .D(D[6]),
    .Q(Q[6]),
    .rst(rst),
    .clk(clk)
);
// D[7] -> Q[7]
DFF DFF7 (
    .D(D[7]),
    .Q(Q[7]),
    .rst(rst),
    .clk(clk)
);

endmodule
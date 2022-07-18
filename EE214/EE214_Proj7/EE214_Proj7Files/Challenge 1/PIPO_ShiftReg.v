`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/30/2020 11:09:45 PM
// Design Name: 
// Module Name: PIPO_ShiftReg
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


module PIPO_ShiftReg(
    input [7:0] i_data,
    input i_rst, i_clk,
    output [7:0] o_storedValue
    );

    
// Instantiating the DFFs

DFF Dff_0 (
    .D(i_data[0]),
    .clk(i_clk),
    .rst(i_rst),
    .Q(o_storedValue[0])
);

DFF Dff_1 (
    .D(i_data[1]),
    .clk(i_clk),
    .rst(i_rst),
    .Q(o_storedValue[1])
);

DFF Dff_2 (
    .D(i_data[2]),
    .clk(i_clk),
    .rst(i_rst),
    .Q(o_storedValue[2])
);

DFF Dff_3 (
    .D(i_data[3]),
    .clk(i_clk),
    .rst(i_rst),
    .Q(o_storedValue[3])
);

DFF Dff_4 (
    .D(i_data[4]),
    .clk(i_clk),
    .rst(i_rst),
    .Q(o_storedValue[4])
);

DFF Dff_5 (
    .D(i_data[5]),
    .clk(i_clk),
    .rst(i_rst),
    .Q(o_storedValue[5])
);

DFF Dff_6 (
    .D(i_data[6]),
    .clk(i_clk),
    .rst(i_rst),    
    .Q(o_storedValue[6])
);

DFF Dff_7 (
    .D(i_data[7]),
    .clk(i_clk),
    .rst(i_rst),    
    .Q(o_storedValue[7])
);

    
endmodule

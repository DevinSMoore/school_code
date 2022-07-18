`timescale 1ns / 1ps

module mux_4bit_4_1(
    input [3:0] i_0, i_1, i_2, i_3,
    input [1:0] i_select,
    output [3:0] o_Y
    );

assign o_Y = ((i_select == 2'b00) ? (i_0) : (
               (i_select == 2'b01) ? (i_1) : (
               (i_select == 2'b10) ? (i_2) : (i_3))));

endmodule

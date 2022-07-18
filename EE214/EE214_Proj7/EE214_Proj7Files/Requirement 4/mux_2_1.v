`timescale 1ns / 1ps

module mux_2_1(
    input [7:0] I0, I1,
    input S,
    output [7:0] Y
    );

assign Y = (S == 1) ? (I1) : (I0);
    
endmodule

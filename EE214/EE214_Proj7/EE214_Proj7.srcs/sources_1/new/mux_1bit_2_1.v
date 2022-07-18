`timescale 1ns / 1ps

module mux_1bit_2_1(
    input I0, I1,
    input S,
    output Y
    );

assign Y = (S == 1) ? (I1) : (I0);
    
endmodule
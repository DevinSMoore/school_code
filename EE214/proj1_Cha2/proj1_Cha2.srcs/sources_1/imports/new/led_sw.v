`timescale 1ns / 1ps
// Devin Moore
// 2020/08/31
// Assignment 1 Challenge 2

module led_sw(
    // Challenge 2 statements
    input sw,
    input [2:0] btn,
    output [2:0] RGB_led_A

);

always@(sw == 1

// Statements for Challenge 2
assign RGB_led_A[0] = btn[0] & sw;
assign RGB_led_A[1] = btn[1] & sw;
assign RGB_led_A[2] = btn[2] & sw;

endmodule



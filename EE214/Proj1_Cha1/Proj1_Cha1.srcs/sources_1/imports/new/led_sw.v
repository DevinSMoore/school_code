`timescale 1ns / 1ps
// Devin Moore
// 2020/08/31
// Assignment 1 Challenge 1

module led_sw(
// Challenge statements
    input [2:0] btn,
    output [2:0] RGB_led_A

);


//// Statements for Challenge 1
assign RGB_led_A[0] = btn[0];
assign RGB_led_A[1] = btn[1];
assign RGB_led_A[2] = btn[2];

endmodule



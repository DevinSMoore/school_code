`timescale 1ns / 1ps

module EE214_Proj8Req1_TB;
// Inputs
reg i_clk = 0;
reg i_rst;

// Outputs
wire o_led;

// Instantiate the Unit Under Test (UUT)
EE214_Proj8Req1 uut (
    .i_clk(i_clk),
    .i_rst(i_rst),
    .o_led(o_led)
);

always
    #5 i_clk = ~i_clk;

initial begin
        // Initialize Inputs
        i_clk = 0;
        i_rst = 1;

        #10 i_rst = 0;

        // Wait 100 ns for global reset to finish
        #100;


    end
endmodule

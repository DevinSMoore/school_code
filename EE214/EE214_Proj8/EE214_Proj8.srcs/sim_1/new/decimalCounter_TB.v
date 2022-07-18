`timescale 1ns / 1ps

module decimalCounter_TB;

// IO
reg i_clk = 0;
reg i_rst;
wire [3:0] o_bcd_digit;

// Instantiating the CUT
decimalCounter cut(
    .i_clk(i_clk),
    .i_rst(i_rst),
    .o_bcd_digit(o_bcd_digit)
    );

always #5 i_clk = ~i_clk;

initial begin
#20;
i_rst = 0;


#5 i_rst = 1;
#5 i_rst = 0;

#100
#5 i_rst = 1;
#5 i_rst = 0;

#1000 $finish;
end
endmodule

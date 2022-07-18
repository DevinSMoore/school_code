`timescale 1ns / 1ps

module ringCounter_TB;
//  declaring and intializing IO
reg i_clk = 0;
reg i_rst;

wire [3:0] o_ringCounter;


// Instantiating the CUT

ringCounter cut(
    .i_clk(i_clk),
    .i_rst(i_rst),
    .o_ringCounter(o_ringCounter)
    );
    
always #5 i_clk = ~i_clk;

initial begin
#10;
i_rst = 0;

#20 i_rst = 1;
#20 i_rst = 0;

#100;
#20 i_rst = 1;
#20 i_rst = 0;

#1000 $finish;
end
endmodule

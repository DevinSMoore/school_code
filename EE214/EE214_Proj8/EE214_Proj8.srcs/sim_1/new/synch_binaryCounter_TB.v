`timescale 1ns / 1ps
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Description: Binary counter that outputs a .373Hz [3], .745Hz [2], 1.49Hz [1], and 2.98Hz [0] divided clock signal 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

module synch_binaryCounter_TB;
reg i_clk = 0;
reg i_rst;
wire [7:0] o_bCounter;

// Instantiating CUT
synch_binaryCounter cut (
    .i_clk(i_clk),
    .i_rst(i_rst),
    .o_bCounter(o_bCounter)
);

 // sends out the 4 upper bits to the output

always #5 i_clk = ~i_clk;

initial begin
#10;
#7 i_rst = 1;
#8 i_rst = 0;

#100;
#7 i_rst = 1;
#8 i_rst = 0;

#1400 $finish; 
end
endmodule

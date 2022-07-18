`timescale 1ns / 1ps
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Description: Binary counter that outputs a .373Hz [3], .745Hz [2], 1.49Hz [1], and 2.98Hz [0] divided clock signal 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

module synch_binaryCounter(
    input i_clk, i_rst,
    output reg [7:0] o_bCounter
    );

always @ (posedge (i_clk), posedge(i_rst))
begin
    if (i_rst) begin o_bCounter <=0; end // if we hit the reset, the counter will go to 0.
    else o_bCounter <= o_bCounter + 1;
end
endmodule

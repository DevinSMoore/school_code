`timescale 1ns / 1ps

module ringCounter(
    input i_clk, i_rst,
    output reg [3:0] o_ringCounter
    );


always @ (posedge(i_clk), posedge(i_rst))
begin
    if (i_rst) o_ringCounter <= 0;
    else o_ringCounter <= {o_ringCounter[2:0], !o_ringCounter[3]};
end
endmodule

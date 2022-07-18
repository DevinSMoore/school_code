`timescale 1ns / 1ps

module counter_2bit (
    input i_clk, i_rst,
    output reg [1:0] o_2bitCounter
);

always @ (posedge(i_clk), posedge(i_rst))
begin
    if (i_rst) begin o_2bitCounter <= 0; end
    else begin o_2bitCounter <= o_2bitCounter + 1; end
end  
endmodule


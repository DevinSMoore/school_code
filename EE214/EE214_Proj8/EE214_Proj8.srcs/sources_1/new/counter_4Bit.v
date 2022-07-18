`timescale 1ns / 1ps

module counter_4Bit(
    input i_clk, i_rst, i_ce, i_le,
    input [3:0] i_loadVal,
    output reg [3:0] o_counter
    );

// Declaring/Initializing Variables

always @ (negedge(i_clk), posedge(i_rst))
begin 
    if (i_rst) begin o_counter <= 0; end
    else if (!i_ce && i_le) begin o_counter <= i_loadVal; end // if i_ce = 0 and i_loadEn is asserted the clock will be filled with the value passed 
    else if (!i_ce) begin o_counter <= o_counter; end // if i_ce = 0 and i_loadEn = 0 then the counter will be paused and stored in itself.
    else begin o_counter <= o_counter + 1; end
end
endmodule

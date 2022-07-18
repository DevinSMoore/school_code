`timescale 1ns / 1ps

module BCDcounter(
    input i_clk, i_rst, i_ce,
    output reg [3:0] o_divClk,
    output o_carryBit
    );
// Declaring variables

always @ (negedge(i_clk), posedge(i_rst))
begin
    if (i_rst) o_divClk <= 0;
    else if (o_divClk == 4'b1001)
    begin 
        o_divClk <= 0; 
//        o_carryBit <= o_carryBit + 1;
    end 		// When we reach the terminal count counter will be reset
    else if (i_ce == 0) begin o_divClk <= o_divClk; end	// Will fill counter with it's own value if clock enable is low. 1 = clock running 0 = clock paused
    else begin o_divClk <= o_divClk + 1; end
end

assign o_carryBit = (o_divClk == 4'b1001);
endmodule


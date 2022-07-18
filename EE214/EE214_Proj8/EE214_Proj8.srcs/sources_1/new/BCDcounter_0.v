`timescale 1ns / 1ps

module BCDcounter_0(
    input i_clk, i_rst, i_ce,
    input [1:0] i_loadSelect,
    input [3:0] i_loadValue,
    output reg [3:0] o_divClk,
    output o_carryBit
    );
// Declaring variables
wire loadCheck;
assign loadCheck = (i_loadSelect == 2'b00); // Will check if load select is 0
always @ (posedge(i_clk), posedge(i_rst))
begin
    if (i_rst) o_divClk <= 0;
    else if (o_divClk == 4'b1001)
    begin 
        o_divClk <= 0; 	// When we reach the terminal count counter will be reset
    end 	
    else if (i_ce == 0 && loadCheck) begin o_divClk <= i_loadValue; end	// Will fill counter with it's own value if clock enable is low. 1 = clock running 0 = clock paused
    else if (i_ce == 0 && !loadCheck) begin o_divClk <= o_divClk; end	// Will fill counter with it's own value if clock enable is low. 1 = clock running 0 = clock paused
    else begin o_divClk <= o_divClk + 1; end
end

assign o_carryBit = (o_divClk == 4'b1001);
endmodule


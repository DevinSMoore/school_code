`timescale 1ns / 1ps

module clkDiv_1kHz_to_1Hz(
    input i_clk, i_rst, i_ce,
    output reg o_divClk
    );
    
localparam terminatingCount = (500 - 1);  // Ending count is ( (amount we want to divide i_clk by) / 2 ) - 1
reg [15:0] counter;
wire w_terminalCount;

assign w_terminalCount = (counter == terminatingCount);

always @ (posedge(i_clk), negedge(i_rst)) // incrementing this clock on the posedge of the 1kHz couner
begin
    if (i_rst) begin counter <= 0; end // if we enable reset count gets set to 0
    else if (w_terminalCount) begin counter <= 0; end // if we hit the terminal count reset counter to divide it down to 1kHz
    else if (i_ce == 0) begin counter <= counter; end // just feeds the value into itself, I don't know if this is a good solution or not
    else begin counter <= counter + 1; end // else counts like normal
end

always @ (posedge(i_clk), negedge(i_rst))
begin
    if (i_rst) begin o_divClk <= 0; end
    else if (w_terminalCount) begin o_divClk = !o_divClk; end	// TFF with the second counters terminal count as the trigger
end
endmodule

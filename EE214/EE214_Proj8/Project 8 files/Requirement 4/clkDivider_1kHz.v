`timescale 1ns / 1ps

module clkDivider_1kHz(
    input i_clk, i_rst, i_ce,
    output reg o_divClk
    );
// Declaring variables
reg [15:0] counter;
wire terminalCountCheck;
localparam terminalCount = (50000 - 1);


assign terminalCountCheck = (counter == terminalCount);	// Place a comparator on the counter output

always @ (posedge(i_clk), posedge(i_rst))
begin
    if (i_rst) counter <= 0;
    else if (terminalCountCheck) counter <= 0;		// When we reach the terminal count counter will be reset
    else if (i_ce == 0) counter <= counter;		// Will fill counter with it's own value if clock enable is low. 1 = clock running 0 = clock paused
    else counter <= counter + 1;
end

always @ (posedge(i_clk), posedge(i_rst))
begin
    if (i_rst) o_divClk <= 0;
    else if (terminalCountCheck) o_divClk = !o_divClk;	// T-FF with tc as input signal
end
endmodule


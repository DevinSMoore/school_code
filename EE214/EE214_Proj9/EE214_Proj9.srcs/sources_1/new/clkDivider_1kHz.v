module clkDivider_1kHz (
    input i_clk, i_rst,
    output reg o_divClk
);
	
localparam terminalcount = (25000 - 1);
reg [15:0] count;
wire w_terminalCountCheck;

assign w_terminalCountCheck = (count == terminalcount);	// Place a comparator on the counter output

always @ (posedge(i_clk), negedge(i_rst))
begin
    if (i_rst) count <= 0;
    else if (w_terminalCountCheck) count <= 0;		// Reset counter when terminal count reached
    else count <= count + 1;
end

always @ (posedge(i_clk), negedge(i_rst))
begin
    if (i_rst) o_divClk <= 0;
    else if (w_terminalCountCheck) o_divClk = !o_divClk;	// T-FF with terminalCountCheck as input signal
end
endmodule


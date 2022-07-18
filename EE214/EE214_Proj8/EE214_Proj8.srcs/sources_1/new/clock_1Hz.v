`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// 
//  Description: This will produce a 
// 
// 
//////////////////////////////////////////////////////////////////////////////////
module clock_1Hz (
    input i_clk, // 100MHz in
          i_rst, // i_rst: rest = 1 (sets o_clk to 0), reset = 0 clock runs like normal
          i_ce,  // i_ce: 1 = run, 0 = pause
    output reg o_divClk // 1Hz out  
    );

// Declaring/Initializing varibales
wire w_clk, w_terminaterCheck;
reg [15:0] counter = 0;
// Instantiating clock to bring it down to 1kHz
clkDivider_1kHz clk_1kHz (
    .i_clk(i_clk),
    .i_rst(i_rst),
    .o_divClk(w_clk)
);


localparam terminalcount = (500 - 1);
reg [15:0] count;
wire terminalCountCheck;

assign terminalCountCheck = (count == terminalcount);	// Place a comparator on the counter output

always @ (posedge(w_clk), posedge(i_rst))
begin
    if (i_rst) count <= 0;
    else if (i_ce == 0) count <= count;		// Reset counter when terminal count reached
    else if (terminalCountCheck) count <= 0;		// Reset counter when terminal count reached
    else count <= count + 1;
end

always @ (posedge(w_clk), posedge(i_rst))
begin
    if (i_rst) o_divClk <= 0;
    else if (terminalCountCheck) o_divClk = !o_divClk;	// T-FF with terminalCountCheck as input signal
end
endmodule

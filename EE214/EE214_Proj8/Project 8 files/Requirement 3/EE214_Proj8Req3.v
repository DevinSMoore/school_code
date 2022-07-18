`timescale 1ns / 1ps

module EE214_Proj8Req3(
    input i_clk, i_rst, i_ce, // i_clk is input clock at 100MHz; i_rst is btn[0] and sets count to 0; i_ce is count eneable, 1 = counting 0 = pause counting
    output o_dividedClock // down to 1Hz
    );

// Declaring wire that will run between clocks
wire clkWire;


// Instantiating 1kHz clock divider
clkDivider_1kHz clkDiv1kHz (
    .i_clk(i_clk),
    .i_rst(i_rst),
    .i_ce(i_ce),
    .o_divClk(clkWire)
);

clkDiv_1kHz_to_1Hz clkDiv1Hz (
    .i_clk(clkWire), // input f this clock is our 1kHz oscilator
    .i_rst(i_rst),
    .i_ce(i_ce),
    .o_divClk(o_dividedClock)
);


endmodule

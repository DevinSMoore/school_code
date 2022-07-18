`timescale 1ns / 1ps

module EE214_Proj8Req4 (
    input i_clk, i_rst, i_ce, // i_clk is input clock at 100MHz; i_rst is btn[0] and sets count to 0; i_ce is count eneable, 1 = counting 0 = pause counting
    output [7:0] o_segCathode, // down to 1Hz
    output [3:0] o_segAnode
    // output [5:0] o_led
    );

assign o_segAnode = 4'b1110; // this will turn off the 3 most sgnificant dislays, leaving the least significant on.
// Declaring wire that will run between clocks
wire w_clkWire1, w_clkWire2;
wire [3:0] w_BCDClock; // Wire that runs from the BCD clock to the decoder

// Instantiating 1kHz clock divider
clkDivider_1kHz clkDiv1kHz (
    .i_clk(i_clk),
    .i_rst(i_rst),
    .i_ce(i_ce),
    .o_divClk(w_clkWire1)
    );

clkDiv_1kHz_to_1Hz (
        .i_clk(w_clkWire1),
    .i_rst(i_rst),
    .i_ce(i_ce),
    .o_divClk(w_clkWire2)
);

BCDcounter bcdClk (
    .i_clk(w_clkWire2),
    .i_rst(i_rst),
    .i_ce(i_ce),
    .o_divClk(w_BCDClock)
);

SSD_Decoder1 SSDDecoder (
    .i_data(w_BCDClock),
    .o_seg(o_segCathode)
);

endmodule
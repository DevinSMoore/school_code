`timescale 1ns / 1ps

module EE214_Proj8Req5 (
    input i_clk, i_rst, i_ce, // i_clk is input clock at 100MHz; i_rst is btn[0] and sets count to 0; i_ce is count eneable, 1 = counting 0 = pause counting
    output [7:0] o_segCathode, // down to 1Hz
    output [3:0] o_segAnode
    );

// Declaring wires that will run between clocks
wire w_clkWire, w_cBit0, w_cBit1, w_cBit2;
wire [3:0] w_BCDClock0, w_BCDClock1, w_BCDClock2, w_BCDClock3; // Wire that runs from the BCD clock to the decoderfor each one

// Instantiating 1kHz clock divider
clkDivider_1kHz clkDiv1kHz (
    .i_clk(i_clk),
    .i_rst(i_rst),
    .o_divClk(w_clkWire)
);

// BCD counters
BCDcounter bcdClk0 (
    .i_clk(w_clkWire),
    .i_rst(i_rst),
    .i_ce(i_ce),
    .o_divClk(w_BCDClock0),
    .o_carryBit(w_cBit0)
);

BCDcounter bcdClk1 (
    .i_clk(w_cBit0),
    .i_rst(i_rst),
    .i_ce(i_ce),
    .o_divClk(w_BCDClock1),
    .o_carryBit(w_cBit1)
);

BCDcounter bcdClk2 (
    .i_clk(w_cBit1),
    .i_rst(i_rst),
    .i_ce(i_ce),
    .o_divClk(w_BCDClock2),
    .o_carryBit(w_cBit2)
);

BCDcounter bcdClk3 (
    .i_clk(w_cBit2),
    .i_rst(i_rst),
    .i_ce(i_ce),
    .o_divClk(w_BCDClock3)
);

// Instantiating the SSD controller
displayController DspCtrlr_0 (
    .i_clk(i_clk),
    .i_0(w_BCDClock0),
    .i_1(w_BCDClock1),
    .i_2(w_BCDClock2),
    .i_3(w_BCDClock3),
    .o_segCat(o_segCathode),
    .o_segAn(o_segAnode)
);
endmodule
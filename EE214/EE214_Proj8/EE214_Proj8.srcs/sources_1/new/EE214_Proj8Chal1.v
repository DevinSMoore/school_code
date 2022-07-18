`timescale 1ns / 1ps

module EE214_Proj8Chal1(
    input i_clk, i_rst, i_ce, // i_rst: btn[0]; i_ce: sw[0] (clock enable 1 = run, 0 = load values);
    input [1:0] i_loadSelect, // sw[1]:sw[0]
    input [3:0] i_loadValue, // sw[7]:sw[4]
    output [7:0] o_segCat, 
    output [3:0] o_segAn,
    output [6:0] o_led
    );

wire [3:0] w_BCDClock0, w_BCDClock1, w_BCDClock2, w_BCDClock3;
wire w_clk;

// Instantiating the 1Hz clock
clock_1Hz clk (
    .i_clk(i_clk),
    .i_rst(i_rst),
    .i_ce(i_ce),
    .o_divClk(w_clk)
);

BCDcounter_0 bcdClk_0 (
    .i_clk(w_clk),
    .i_rst(i_rst),
    .i_ce(i_ce),
    .i_loadSelect(i_loadSelect),
    .i_loadValue(i_loadValue),
    .o_divClk(w_BCDClock0),
    .o_carryBit(w_cBit0)
);

BCDcounter_1 bcdClk_1 (
    .i_clk(w_cBit0),
    .i_rst(i_rst),
    .i_ce(i_ce),
    .i_loadSelect(i_loadSelect),
    .i_loadValue(i_loadValue),
    .o_divClk(w_BCDClock1),
    .o_carryBit(w_cBit1)
);

BCDcounter_2 bcdClk_2 (
    .i_clk(w_cBit1),
    .i_rst(i_rst),
    .i_ce(i_ce),
    .i_loadSelect(i_loadSelect),
    .i_loadValue(i_loadValue),
    .o_divClk(w_BCDClock2),
    .o_carryBit(w_cBit2)
);

BCDcounter_3 bcdClk_3 (
    .i_clk(w_cBit2),
    .i_rst(i_rst),
    .i_ce(i_ce),
    .i_loadSelect(i_loadSelect),
    .i_loadValue(i_loadValue),
    .o_divClk(w_BCDClock3)
);

// display controller
displayController dsplCtrl_0 ( // Display controller, will be passed the outputs of our 4 counters
    .i_clk(i_clk),
    .i_rst(i_rst),
    .i_ce(i_ce),
    .i_loadSel(i_loadSel),
    .i_0(w_BCDClock0),
    .i_1(w_BCDClock1),
    .i_2(w_BCDClock2),
    .i_3(w_BCDClock3),
    .o_segCat(o_segCat),
    .o_segAn(o_segAn)
);

assign o_led[0] = w_clk;
assign o_led[4:1] = i_loadValue;
assign o_led[6:5] = i_loadSelect;
endmodule

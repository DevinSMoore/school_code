`timescale 1ns / 1ps

module displayController (
    input i_clk, i_rst, i_ce, i_le,
    input [1:0] i_loadSel,
    input [3:0] i_0, i_1, i_2, i_3,
    output [7:0] o_segCat,
    output [3:0] o_segAn
);

wire [1:0] w_muxSelect;
wire [3:0] segSelect;
wire w_clkWire;

// Instantiating 1kHz clock divider
clkDivider_1kHz clkDiv1kHz (
    .i_clk(i_clk),
    .i_rst(i_rst),
    .o_divClk(w_clkWire)
);
// counter 2 bi8t
counter_2bit counter (
    .i_clk(w_clkWire),
    .i_rst(i_rst),
    .o_2bitCounter(w_muxSelect)
);

mux_4bit_4_1 mux ( // 4 bit 4:1 mux. i_select is a 2 bit bus (2^n input n select)
    .i_0(i_0),
    .i_1(i_1),
    .i_2(i_2),
    .i_3(i_3),
    .i_select(w_muxSelect),
    .o_Y(segSelect)
);

SSD_Decoder1 SSD ( // pass in which letter you would like, and the segments needed to light up (as an 8 bit binary number) will be retruned
    .i_data(segSelect),
    .o_seg(o_segCat)
);

decoder_2_4 decoder24(
    .i_select(w_muxSelect),
    .o_Y(o_segAn)
);
endmodule
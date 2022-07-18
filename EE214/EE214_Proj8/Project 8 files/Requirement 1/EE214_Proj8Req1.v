`timescale 1ns / 1ps

module EE214_Proj8Req1(
    input i_clk, i_rst, i_ce,
    output [7:0] o_segCat,
    output [3:0] o_segAn
    );

wire [26:0] i_data, o_clkDiv;

FDC dff_inst0 ( // Instantiating the 0th flipflop
    .C(i_clk),
    .CLR(i_rst),
    .D(i_data[0]),
    .Q(o_clkDiv[0])
);

// Instantiating the rest of the DFF with a generator block
genvar i;
generate
for (i = 1; i < 28; i = i + 1)
begin: FDC_gen_label
    FDC dff_inst (
    .C(o_clkDiv[i-1]),
    .CLR(i_rst),
    .D(i_data[i]),
    .Q(o_clkDiv[i])
    );
end
endgenerate

assign i_data = ~o_clkDiv;

assign o_led = o_clkDiv[26]; // will pass a .745Hz divided clock out to o_led
    

endmodule

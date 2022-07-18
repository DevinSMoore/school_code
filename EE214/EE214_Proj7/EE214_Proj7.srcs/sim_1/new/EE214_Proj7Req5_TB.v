`timescale 1ns / 1ps
module EE214_Proj7Req5_TB;


reg [7:0] i_D; // sw[7:0]
reg i_clk, i_rst, i_S; // i_rst = btn[1], i_S = btn[0]
wire [15:0] o_led;

EE214_Proj7Req5 cut(
    .i_D(i_D),
    .i_clk(i_clk),
    .i_rst(i_rst),
    .i_S(i_S),
    .o_led(o_led)
);

always #1 i_clk = ~i_clk; // implementing clock

initial
begin
i_D = 8'b00110000;
i_rst = 0;
i_S = 0;
#20;

#2 i_S = 1;
#2 i_S = 0;


#20 $finish;
end
endmodule
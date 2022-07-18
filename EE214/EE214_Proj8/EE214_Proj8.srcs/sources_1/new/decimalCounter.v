`timescale 1ns / 1ps

module decimalCounter(
    input i_clk, i_rst,
    output reg [3:0] o_bcd_digit
    );

always @ (posedge(i_clk), posedge(i_rst))
begin
    if (i_rst) o_bcd_digit <= 0;
    else if (o_bcd_digit == 4'b1001) o_bcd_digit <= 0; // if we hit 9 (1001) set all bits to '0'
    else o_bcd_digit <= o_bcd_digit + 1;
end
endmodule

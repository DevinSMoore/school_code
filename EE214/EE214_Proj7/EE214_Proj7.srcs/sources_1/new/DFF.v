`timescale 1ns / 1ps

module DFF(
    input D, rst, clk,
    output reg Q
    );

always @ (posedge(clk), posedge(rst))
begin
   if (rst == 1)
       Q <= 1'b0;	// Q is reset to 0
   else
       Q <= D;
end
endmodule

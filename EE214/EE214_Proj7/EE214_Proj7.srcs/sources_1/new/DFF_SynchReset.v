`timescale 1ns / 1ps

module DFF_SynchReset(
    input D, rst, clk

);
reg Q;
always @ (posedge(clk))
begin
   if (rst == 1)
       Q <= 1'b0;	// Q is reset to 0
   else
       Q <= D;
end
endmodule
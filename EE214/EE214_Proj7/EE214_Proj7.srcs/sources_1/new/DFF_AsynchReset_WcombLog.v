`timescale 1ns / 1ps

module DFF_AsynchReset_WcombLog(
    input D, rst, clk, A, B
);
 reg Q;
always @ (posedge(clk), posedge(rst))
begin
   if (rst == 1)
       Q <= 1'b0;	// Q is reset to 0
   else
       Q <= (A & B);
end

endmodule
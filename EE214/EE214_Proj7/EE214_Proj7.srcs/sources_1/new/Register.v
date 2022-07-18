`timescale 1ns / 1ps

module Register(
    input D, rst, clk, A, B
);
reg [7:0] Q;

always @ (posedge(clk), posedge(rst))
begin
   if (rst == 1)
       Q <= 8'b00000000;	// Q is reset to 0
   else
       Q <= D;
end
endmodule
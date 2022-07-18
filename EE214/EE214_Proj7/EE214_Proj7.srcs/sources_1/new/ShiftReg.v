`timescale 1ns / 1ps

module ShiftReg(
    input clk, rst, [7:0] DIN,
    output [7:0] DOUT
);
// reg [7:0] DOUT;

assign DOUT = (rst == 1) ? (DOUT <= 0) : DOUT <= { DIN[7:1], DIN[0] };

//always @ (posedge(clk), posedge(rst))
//begin
//   if (rst == 1)   DOUT <= 0;
//   else
//       DOUT <= { DIN[6:0], 1'b0 };
//end
endmodule
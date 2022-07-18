`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/04/2020 03:10:13 PM
// Design Name: 
// Module Name: asynch_binaryCounter_TB
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module asynch_binaryCounter_TB;
reg i_clk = 0;
reg i_rst;
wire [3:0] o_asynchCounter;


// Instantiating the CUT
asynch_binaryCounter cut(
    .i_clk(i_clk),
    .i_rst(i_rst),
    .o_asynchCounter(o_asynchCounter)
);

always #5 i_clk = ~i_clk;

initial begin
#10;
i_rst = 0;

#5 i_rst = 1;
#5 i_rst = 0;

#100;
#5 i_rst = 1;
#5 i_rst = 0;

#500 $finish;
end
endmodule

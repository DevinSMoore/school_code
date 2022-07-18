`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/05/2020 04:48:58 PM
// Design Name: 
// Module Name: EE214_Proj8Req5_TB
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


module EE214_Proj8Req5_TB;
// Initializing IO
reg i_clk = 0;
reg i_rst;
reg i_ce; // i_clk is input clock at 100MHz; i_rst is btn[0] and sets count to 0; i_ce is count eneable, 1 = counting 0 = pause counting
wire [7:0] o_segCathode; // down to 1Hz
wire [3:0] o_segAnode;

// Instantiating the CUT
EE214_Proj8Req5 cut (
    .i_clk(i_clk),
    .i_rst(i_rst),
    .i_ce(i_ce),
    .o_segCathode(o_segCathode),
    .o_segAnode(o_segAnode)
);


always #5 i_clk = ~i_clk;
initial begin
#20;
i_clk = 0;
i_rst = 0;
i_ce = 0;


#5 i_rst = 1;
#5 i_rst = 0;
#5 i_ce = 1;
#5 i_ce = 0;

#1000;


#20 $finish;
end
endmodule

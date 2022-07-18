`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/04/2020 03:05:16 PM
// Design Name: 
// Module Name: asynch_binaryCounter
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


module asynch_binaryCounter(
    input i_clk, i_rst,
    output reg [3:0] o_asynchCounter
    );
    
always @ (posedge(i_clk), posedge(i_rst))
begin
   if (i_rst) o_asynchCounter[0] <= 0;
   else o_asynchCounter[0] <= ~o_asynchCounter[0];
end
    
always @ (posedge(o_asynchCounter[0]), posedge(i_rst)) // each FF from here to the end will trigger on the change of state of the previous FF
begin
   if (i_rst) o_asynchCounter[1] <= 0;
   else o_asynchCounter[1] <= ~o_asynchCounter[1];
end
       
always @ (posedge(o_asynchCounter[1]), posedge(i_rst))
begin
   if (i_rst) o_asynchCounter[2] <= 0;
   else o_asynchCounter[2] <= ~o_asynchCounter[2];
end
    
always @ (posedge(o_asynchCounter[2]), posedge(i_rst))
begin
   if (i_rst) o_asynchCounter[3] <= 0;
   else o_asynchCounter[3] <= !o_asynchCounter[3];
end

endmodule

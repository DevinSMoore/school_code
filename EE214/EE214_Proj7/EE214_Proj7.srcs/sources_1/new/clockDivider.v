`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/31/2020 09:32:24 PM
// Design Name: 
// Module Name: clockDivider
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


module clockDivider(
	input clk,
	output Y2, Y1, Y0
);

reg [27:0] counter;

always @ (posedge clk)
begin
	counter <= counter + 1;
end

assign Y2 = counter[27];
assign Y1 = counter[26];
assign Y0 = counter[25];
endmodule

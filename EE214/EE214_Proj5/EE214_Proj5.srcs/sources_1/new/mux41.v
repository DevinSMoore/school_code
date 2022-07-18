`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/23/2020 12:03:00 PM
// Design Name: 
// Module Name: mux41
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

module mux41( // actually an 8:1 mux
    input [3:0] I,
    input [1:0] sel,
    output reg Y
);


always @ (sel, I)
begin
    case (sel)
        2'd0:
            Y = I[0];
        2'd1:
            Y = I[1];
        2'd2:
            Y = I[2];
        2'd3:
            Y = I[3];
        default:
            Y = 0;          
    endcase
end
endmodule
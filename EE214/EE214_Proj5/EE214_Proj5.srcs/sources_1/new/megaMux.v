`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/23/2020 12:05:02 PM
// Design Name: 
// Module Name: megaMux
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


module megaMux(
    input [7:0] D, [2:0] S,
    output Y, Y1, Y2
    );

assign Y = (S[3] == 0) ? (Y1) : (Y2);
    
mux41 muxA(
    .I(D[3:0]),
    .sel(S[2:0]),
    .Y(Y1)
);
mux41 muxB(
    .I(D[7:4]),
    .sel(S[2:0]),
    .Y(Y2)
);

endmodule

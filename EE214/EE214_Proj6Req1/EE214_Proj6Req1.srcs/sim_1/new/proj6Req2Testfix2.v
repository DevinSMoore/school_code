`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/20/2020 11:14:13 AM
// Design Name: 
// Module Name: proj6Req2Testfix2
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


module proj6Req2Testfix2;

reg A, B, C; // Inputs
wire X; // Outputs

// Instantiating the CUT
EE214_Proj6Req2 cut(
    .A(A),
    .B(B),
    .C(C),
    .X(X)
);

integer k = 0;

// Input Stimulus
initial
begin
    A = 0;
    B = 0;
    C = 0;


#20 A = 1;
#20 C = 1;
#20 B = 0;
#80 B = 1;


end
endmodule

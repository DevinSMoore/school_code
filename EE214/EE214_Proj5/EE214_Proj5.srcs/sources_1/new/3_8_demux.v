`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/14/2020 08:22:42 PM
// Design Name: 
// Module Name: 3_8_demux
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


module demux_3_8(
    input EN,
    input I0,
    input I1,
    input I2,
    output reg Y0,
    output reg Y1,
    output reg Y2,
    output reg Y3,
    output reg Y4,
    output reg Y5,
    output reg Y6,
    output reg Y7
    );
    
always @ (EN, I0, I1, I2)
begin
    if (~I2 & ~I1 & ~I0 & EN)
        Y0 = 8'b00000001;
    else if (~I2 & ~I1 & I0 & EN)
        Y1 = 8'b00000010;
    else if (~I2 & I1 & ~I0 & EN)
        Y2 = 8'b00000100;
    else if (~I2 & I1 & I0 & EN)
        Y3 = 8'b00001000;
    else if (I2 & ~I1 & ~I0 & EN)
        Y4 = 8'b00010000;
    else if (I2 & ~I1 & I0 & EN)
        Y5 = 8'b00100000;
    else if (I2 & I1 & ~I0 & EN)
        Y6 = 8'b01000000;
    else if (I2 & I1 & I0 & EN)
        Y7 = 8'b10000000;
    else
        Y0 <= 0; 
        Y1 <= 0; 
        Y2 <= 0; 
        Y3 <= 0; 
        Y4 <= 0; 
        Y5 <= 0; 
        Y6 <= 0; 
        Y7 <= 0; 
end


endmodule

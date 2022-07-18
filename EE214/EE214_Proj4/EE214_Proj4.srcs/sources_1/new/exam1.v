`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/23/2020 11:29:51 AM
// Design Name: 
// Module Name: exam1
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


module exam1(
    input [7:0] sw, D, S, btn,
    output [7:0] led
    );
    
reg led_reg, amt;

always @ (*)
begin
    case(amt)
                1'b0:
                if (S == 1) // shifts/rotates by 1 bit
                    led_reg = (D == 1) ? {sw[6:0], 1'b0} : {1'b0, sw[7:1]}; // Shifts
                else
                    led_reg = (D == 1) ? {sw[6:0], sw[7]} : {sw[0], sw[7:1]}; // Rotates
                1'b1:
                if (S == 1) // Shifts/Rotates by 2 bit
                    led_reg = (D == 1) ? {sw[6:0], 1'b0, 1'b0} : {1'b0, 1'b0, sw[7:1]}; // Shifts and fills with value of F
                else
                    led_reg = (D == 1) ? {sw[5:0], sw[7:6]} : {sw[1:0], sw[7:2]}; // Rotates
     endcase
end

assign led = led_reg;
assign btn = amt;
endmodule

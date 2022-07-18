//////////////////////////////////////////////////////////////////////////////////
//  Name: Devin Moore
//  Class: EE214 Clint Cole
//  TA: Logan Dihel
// 
//  Assignment: Project 6 Delays and Glitches
//  Date Created: 2020/10/19
//  Date Modified: 2020/10/23
//  Module Name: EE214_Proj6Chal1
//
//  Description: This requirement is to impliment a 4:16 decoder then assign 
//               the 4 select signals to sw0-sw4 and the 16 outputs to ld0-ld16
//               then we find out what the exact delay is between setting sw0 to 1
//               and led0 getting asserted as a response.
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps


module EE214_Proj6Chal1(
    input [3:0] sw,
    output reg [15:0] led // set RGBs 10 and 11 as led 10-15
    );
    
always @ (sw)
begin
    case (sw) // 4:16 decoder
        4'b0000:
            led = 16'd1;
        4'b0001:
            led = 16'd2;
        4'b0010:
            led = 16'd4;
        4'b0011:
            led = 16'd8;
        4'b0100:
            led = 16'd16;
        4'b0101:
            led = 16'd32;
        4'b0110:
            led = 16'd64;
        4'b0111:
            led = 16'd128;
        4'b1000:
            led = 16'd256;
        4'b1001:
            led = 16'd512;
        4'b1010:
            led = 16'd1024;
        4'b1011:
            led = 16'd2048;
        4'b1100:
            led = 16'd4096;
        4'b1101:
            led = 16'd8192;
        4'b1110:
            led = 16'd16384;
        4'b1111:
            led = 16'd32768; // it's easier to just do the doubling than to write out a 16 bit number every time
        default
            led = 0;            
    endcase
end
endmodule

`timescale 1ns / 1ps
////////////////////////////////////////////////////////////////////////////////// 
// Name: Devin Moore
// Class EE214 Clint Cole Section
// Assignment Project 3 Challenge 1
// 
// Create Date: 2020/09/22
// Last Modified: 2020/09/22
// Module Name: EE214_Proj3Chal1
//
// Description: This is an odd and even number detector.
//              If and odd number of switches are on led[0] will go high
//              If and even number of switches are on led[1] will go high
//////////////////////////////////////////////////////////////////////////////////


module EE214_Proj3Chal1(
    output [1:0] led,
    input [11:0] sw
    );

// Added wire syntax after meeting with TA (Logan)
wire x = (sw[0] ^ sw[1] ^ sw[2] ^ sw[3] ^ sw[4] ^ sw[5] ^ sw[6] ^ sw[7] ^ sw[8] ^ sw[9] ^ sw[10] ^ sw[11]);

assign led[0] = x;
assign led[1] = ~x;

// assign led[1] = ~(sw[0] ^ sw[1] ^ sw[2] ^ sw[3] ^ sw[4] ^ sw[5] ^ sw[6] ^ sw[7] ^ sw[8] ^ sw[9] ^ sw[10] ^ sw[11]);

endmodule

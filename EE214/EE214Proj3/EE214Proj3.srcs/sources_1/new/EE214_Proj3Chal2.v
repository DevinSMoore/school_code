`timescale 1ns / 1ps
////////////////////////////////////////////////////////////////////////////////// 
// Name: Devin Moore
// Class EE214 Clint Cole Section
// Assignment Project 3 Challenge 2
// 
// Create Date: 2020/09/22
// Last Modified: 2020/09/22
// Module Name: EE214_Proj3Chal2
//
// Description: This is an odd and even number detector using switches and buttons.
//              If and odd number of switches are on led[0] will go high
//              If and even number of buttons are on led[1] will go high
//////////////////////////////////////////////////////////////////////////////////


module EE214_Proj3Chal2(
    output [1:0] led,
    input [11:0] sw,
    input [3:0] btn
    );

wire x = (sw[0] ^ sw[1] ^ sw[2] ^ sw[3] ^ sw[4] ^ sw[5] ^ sw[6] ^ sw[7] ^ sw[8] ^ sw[9] ^ sw[10] ^ sw[11]);
// assign x;
assign led[0] = x;
assign led[1] = ((~(btn[0] ^ btn[1] ^ btn[2] ^ btn[3])) & x); 

endmodule

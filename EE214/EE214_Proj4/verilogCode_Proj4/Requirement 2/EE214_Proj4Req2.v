/////////////////////////////////////////////////////////////////////////////////////
// Name: Devin Moore
// Class: EE214 Clint Cole
// Assignment: Project 4 Requirement 1
// TA: Logan Dihel
// 
// Date Created: 2020/10/02
// Date Modified: 2020/10/09
// Module Name: EE214_Proj4Req2
//
// Description: Implements a decoder that will set led high, when certain 
//              combinations of sw[0] - sw[2] and btn[0] - btn[3] are set high
////////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps

module EE214_Proj4Req2(
    input [1:0] sw,
    input [3:0] btn,
    output [3:0] led

    );             

reg [3:0] led;

always @ (sw)
begin // this impliments the decoder including ANDing the switch states with buttons.
    if ((sw == 2'd0) && (btn[0] == 1))
        led = 4'b0001;
    else if ((sw == 2'd1) && (btn[1] == 1))
        led = 4'b0010;
    else if ((sw == 2'd2) && (btn[2] == 1))
        led = 4'd0100;
    else if ((sw == 2'd3) && (btn[3] == 1))
        led = 4'b1000;
    else // need to make sure to include this or things get a bit funky
        led = 4'd0;
end
endmodule

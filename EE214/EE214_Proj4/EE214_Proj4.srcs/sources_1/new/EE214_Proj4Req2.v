////////////////////////////////////////////////////////////////////////////////// 
// Name: Devin Moore
// Class EE214 Clint Cole Section
// Assignment Project 4 Requirement 2
// 
// Create Date: 2020/10/02
// Last Modified: 2020/10/19
// Module Name: EE214_Proj4Req2
//
// Description: Implements a decoder that will assert led high, when certain 
//              combinations of sw[0] - sw[2] and btn[0] - btn[3] are asserted high
//
//
// Updates: 
////////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps

module EE214_Proj4Req2(
    input [1:0] sw,
    input [3:0] btn,
    output [3:0] led
);             

reg [3:0] outputReg;

always @ (sw, btn)
begin // this impliments the decoder including ANDing the switch states with buttons.
    if ((sw == 2'd0) && (btn[0] == 1))
        outputReg = 4'b0001;
    else if ((sw == 2'd1) && (btn[1] == 1))
        outputReg = 4'b0010;
    else if ((sw == 2'd2) && (btn[2] == 1))
        outputReg = 4'b0100;
    else if ((sw == 2'd3) && (btn[3] == 1))
        outputReg = 4'b1000;
    else // need to make sure to include this or things get a bit funky
        outputReg = 4'b0000;
end

assign led = outputReg;

endmodule

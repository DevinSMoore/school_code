`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
//  Name: Devin Moore
//  Date: 2020/10/14
//
//  Description: This just impliments a 4 bit wide bus 2:1 mux
//////////////////////////////////////////////////////////////////////////////////


module bus_4_mux_2_1(
    input [3:0] I0, // switches 3 - 0
    input [3:0] I1, // switches 7 - 4
    input S, // button 0
    output reg [3:0] Y
    );

always @ (S, I0, I1)
begin 
    if (S == 0)
        Y = I0; // will pass the data on switches 3 - 0 if sel is set low
    else
        Y = I1; // will pass sw7 - sw4
end
    
endmodule

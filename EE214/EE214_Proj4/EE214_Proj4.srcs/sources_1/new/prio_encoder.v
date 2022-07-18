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
`timescale 1 ns/1 ps


module prio_encoder(
    input [3:0] I,
    input Ein,
    output [1:0] Y,
    output GS,
    output Eout
    );

reg [1:0] Y;
reg GS;
reg Eout;

always @ (I, Ein)
begin
    if (Ein == 1) // if Ein is 1 then the outputs go into a priority system I3 gets priority over I2> I1 > I0
        Y = (I[3] == 1) ? 2'd3 : (
                    (I[2] == 1) ? 2'd2 : (
                            (I[1] == 1) ? 2'd1 : 2'd0
                    )
             );
     else // this takes care of the condition where Ein = 0 then all outputs are 0
        Y = 2'd0;
end

always @ (I, Ein)
begin
    if (Ein == 1 && I == 0) // if Ein is asserted high, and ALL inputs are off then Eout will be asserted high
        Eout = 1'b1;
    else
        Eout = 1'b0; // Eout will be asserted low if Ein and ANY output are high.
end

always @ (I, Ein)
begin
    if (Ein == 1 && I != 0) // if Ein and ANY inputs are on then Eout will be asserted high
        GS = 1'b1;
    else
        GS = 1'b0; // GS is asserted low if Ein is high and ALL outputs are low.
end



endmodule

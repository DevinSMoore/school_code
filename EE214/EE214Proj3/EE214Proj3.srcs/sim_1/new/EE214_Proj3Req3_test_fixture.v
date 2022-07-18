`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////
// Name: Devin Moore
// Class EE214 Clint Cole
// Assignment Project 3 Requirement 3
// 
// Create Date: 09/22/2020
// Last Modified: 09/22/2020
// Module Name: EE214_Proj3Req3
//
// Description: 
//////////////////////////////////////////////////////////////


module EE214_Proj3Req3_test_fixture;

// Inputs
reg [7:0] sw;
// Outputs
wire led;

// Instantiate the Circuit Under Test (CUT)
EE214_Proj3Req3 cut (
    .sw(sw),
    .led(led)
);

// Declare loop index variable
integer k;

// Apply input stimulus
initial
begin
    sw = 0;

    for (k=0; k<256; k=k+1)
        #20 sw = k;

    #20	$finish;
end
endmodule

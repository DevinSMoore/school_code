//////////////////////////////////////////////////////////////////////////////////
//  Name: Devin Moore
//  Class: EE214 Clint Cole
//  TA: Logan Dihel
// 
//  Assignment: Project 6 Delays and Glitches
//  Date Created: 2020/10/19
//  Date Modified: 2020/10/23
//  Module Name: EE214_Proj6Req3_test_fixture
//
//  Description: This requirement is basically identical to Req1 but everything
//               takes 5 times longer to happen. so the glitch takes 10ns to
//               reach the output then it lasts for 5ns which is the INV delay
//               which checks out.
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps


module EE214_Proj6Req3_test_fixture;
reg A, B, C; // Inputs
wire X; // Outputs

// Instantiating the CUT
EE214_Proj6Req3 cut(
    .A(A),
    .B(B),
    .C(C),
    .X(X)
);

integer k = 0;

// Input Stimulus
initial
begin
    A = 0;
    B = 0;
    C = 0;
    
    for(k = 0; k < 4; k=k+1)
    begin
        {A,C} = k;
        #25 B = 1;
        #25 B = 0;
        #25;
    end
    
end
endmodule

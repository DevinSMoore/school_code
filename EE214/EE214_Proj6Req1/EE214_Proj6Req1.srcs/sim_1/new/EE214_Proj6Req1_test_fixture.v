//////////////////////////////////////////////////////////////////////////////////
//  Name: Devin Moore
//  Class: EE214 Clint Cole
//  TA: Logan Dihel
// 
//  Assignment: Project 6 Delays and Glitches
//  Date Created: 2020/10/19
//  Date Modified: 2020/10/19
//  Module Name: EE214_Proj6Req1_test_fixture
//
//  Description: This requirement is implementing a circuit then hard coding
//               circuit delays into the simulation then simulating it.
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps

module EE214_Proj6Req1_test_fixture;
reg A, B, C; // Inputs
wire X; // Outputs

// Instantiating the CUT
EE214_Proj6Req1 cut(
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
        #5 B = 1;
        #5 B = 0;
        #5;
    end

#20 $finish;
end
endmodule

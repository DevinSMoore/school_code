//////////////////////////////////////////////////////////////////////////////////
//  Name: Devin Moore
//  Class: EE214 Clint Cole
//  TA: Logan Dihel
// 
//  Date Created: 2020/10/19
//  Date Modified: 2020/10/23
//  Module Name: EE214_Proj6Req2_test_fixture
//
//  Description: This requirement modifies the first adding an addition delay
//               of 1ns to the or gate for a total of 2 ns then finding 
//               where the glitch is if/when it happens.
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps

module EE214_Proj6Req2_test_fixture;
reg A, B, C; // Inputs
wire X; // Outputs

// Instantiating the CUT
EE214_Proj6Req2 cut(
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

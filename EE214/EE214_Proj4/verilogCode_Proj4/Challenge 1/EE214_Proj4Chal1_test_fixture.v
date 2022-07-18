////////////////////////////////////////////////////////////////////////////////// 
// Name: Devin Moore
// Class: EE214 Clint Cole
// Assignment: Project 4 Challenge 1
// TA: Logan Dihel
// 
// Date Created: 2020/10/02
// Date Modified: 2020/10/09
// Module Name: EE214_Proj4Chal1_test_fixture
//
// Description: This implements a mux that will turn the output on for minterms
// 3, 4, 6, 8, 9, 10, 13
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps

module EE214_Proj4Chal1_test_fixture;

// Inputs
reg [1:0] I;
reg [1:0] sel;
// Outputs
wire led;

// instantiating the CUT
EE214_Proj4Chal1 cut(
    .I(I),
    .sel(sel),
    .led(led)
);

// Applying input stimulus
initial
begin

    I <= 2'd0;
    sel <= 2'd0;
    #20
    
    I <= 2'd1;
    sel <= 2'd0;
    #20   
    
    I <= 2'd2;
    sel <= 2'd0;
    #20
    
    I <= 2'd3;
    sel <= 2'd0;
    #20
    
    I <= 2'd0;
    sel <= 2'd1;
    #20
    
    I <= 2'd1;
    sel <= 2'd1;
    #20   
    
    I <= 2'd2;
    sel <= 2'd1;
    #20
    
    I <= 2'd3;
    sel <= 2'd1;
    #20
    
    I <= 2'd0;
    sel <= 2'd2;
    #20
    
    I <= 2'd1;
    sel <= 2'd2;
    #20  
    
    I <= 2'd2;
    sel <= 2'd2;
    #20
    
    I <= 2'd3;
    sel <= 2'd2;
    #20
    
    I <= 2'd0;
    sel <= 2'd3;
    #20
    
    I <= 2'd1;
    sel <= 2'd3;
    #20  
    
    I <= 2'd2;
    sel <= 2'd3;
    #20
    
    I <= 2'd3;
    sel <= 2'd3;
    #20 $finish;
end
endmodule

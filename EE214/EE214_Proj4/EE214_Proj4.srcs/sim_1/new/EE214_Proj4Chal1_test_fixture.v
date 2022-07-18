////////////////////////////////////////////////////////////////////////////////////
// Name: Devin Moore
// Class EE214 Clint Cole
// Assignment Project 4 Requirement 2
// 
// Create Date: 2020/10/02
// Last Modified: 2020/10/05
// Module Name: EE214_Proj4Req2
//
// Description:  Implements a decoder that will assert led high, when certain 
//              combinations of sw[0] - sw[2] and btn[0] - btn[3] are asserted high
////////////////////////////////////////////////////////////////////////////////////
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

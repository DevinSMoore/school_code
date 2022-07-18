////////////////////////////////////////////////////////////////////////////////// 
// Name: Devin Moore
// Class: EE214 Clint Cole
// Assignment: Project 4 Requirement 1
// TA: Logan Dihel
//
// Date Created: 2020/10/02
// Date Modified: 2020/10/09
// Modlule Name: EE214_Proj4Req1_test_fixture
//
// Description: Create a 4:1 mux and an 8 bit wide 4:1 mux
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps

module EE214_Proj4Req1_test_fixture;

// inputs
reg [1:0] sel;
reg [7:0] I0;
reg [7:0] I1;
reg [7:0] I2;
reg [7:0] I3;
// outputs
wire [7:0] led;

// instantiating the CUT
EE214_Proj4Req1 cut(
    .sel(sel),
    .I0(I0),
    .I1(I1),
    .I2(I2),
    .I3(I3),
    .led(led)
);

// initializing loop variables
integer i, j;

// Applying the inputs 
initial
begin
    I0 = 0;
    I1 = 0;
    I2 = 0;
    I3 = 0;
    sel = 0;
    
    // Runs through the select switches and I0 input
    for (i = 0; i < 4; i = i + 1)
    begin
        #20 sel = i;
        for (j = 0; j < 256; j = j + 1)
        begin
            #20 I0 = j;
        end  #20 I0 = 8'd0; // Sets I0 back to 0
    end
    
    // Runs through the select switches and I1 input
    for (i = 0; i < 4; i = i + 1) 
    begin
        #20 sel = i;
        for (j = 0; j < 256; j = j + 1)
        begin
            #20 I1 = j;
        end #20 I1 = 8'd0; // Sets I1 back to 0
    end
    
    // Runs through the select switches and I2 input
    for (i = 0; i < 4; i = i + 1)
    begin
        #20 sel = i;
        for (j = 0; j < 256; j = j + 1)
        begin
            #20 I2 = j;
        end #20 I2 = 8'd0; // Sets I2 to 0
    end
    
    // Runs through the select switches and I3 input
    for (i = 0; i < 4; i = i + 1)
    begin
        #20 sel = i;
        for (j = 0; j < 256; j = j + 1)
        begin
            #20 I3 = j;
        end #20 I2 = 8'd0; // Sets I2 to 0
    end
                 
    #20 $finish;
end   
   
endmodule 
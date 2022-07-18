////////////////////////////////////////////////////////////////////////////////// 
// Name: Devin Moore
// Class: EE214 Clint Cole
// Assignment: Project 5 Requirement 1
// TA: Logan Dihel
//
// Date Created: 2020/10/12
// Date Modified: 2020/10/12
// Modlule Name: EE214_proj5Req1_muxDemuxWrapper
//
// Description: Create a mux to demux transmission system
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps


module EE214_proj5Req1_muxDemuxWrapper(
    input [7:0] I,
    input clk,
    output [7:0] Y,
    output red_led
);
wire [2:0] sel;
wire sdata;

assign red_led = sdata;

// Instantiating the 4:1 mux
mux_4_1 input_mux (
    .I(I),
    .sel(sel),
    .Y(sdata)   
);
// Instantiating the 2:4 demux
demux_2_4 output_demux ( 
    .Y(Y),
    .I(sel),
    .EN(sdata)
);

counter counter_output (
    .Y(sel),
    .clk(clk)
);

endmodule




module mux_4_1( // actually an 8:1 mux
    input [7:0] I,
    input [2:0] sel,
    output reg Y
);


always @ (sel, I)
begin
    case (sel)
        3'd0:
            Y = I[0];
        3'd1:
            Y = I[1];
        3'd2:
            Y = I[2];
        3'd3:
            Y = I[3];
        3'd4:
            Y = I[4];
        3'd5:
            Y = I[5];
        3'd6:
            Y = I[6];
        3'd7:
            Y = I[7];           
    endcase
end
endmodule

module demux_2_4 ( // is actually a 3:8 demux
    input [2:0] I,
    input EN,
    output reg [7:0] Y
);


always @ (I, EN)
begin
    if(I == 3'd0 & EN)
        Y = 8'b00000001;
    else if(I == 3'd1 & EN)
        Y = 8'b00000010;
    else if(I == 3'd2 & EN)
        Y = 8'b00000100;
    else if(I == 3'd3 & EN)
        Y = 8'b00001000;
    else if(I == 3'd4 & EN)
        Y = 8'b00010000;
    else if(I == 3'd5 & EN)
        Y = 8'b00100000;
    else if(I == 3'd6 & EN)
        Y = 8'b01000000;
    else if(I == 3'd7 & EN)
        Y = 8'b10000000;
	else
		Y <= 8'd0;
end
endmodule

module counter (
	input clk,
	output [2:0] Y
);

reg [27:0] counter = 0;

always @ (posedge clk)
begin
	counter <= counter + 1;
end

assign Y[2] = counter[26];
assign Y[1] = counter[25];
assign Y[0] = counter[24];


endmodule
    

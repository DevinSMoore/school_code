`timescale 1ns / 1ps

module decoder_2_4(
    input [1:0] i_select,
    output reg [3:0] o_Y
    );



always @ (i_select)
case(i_select)
    2'b00:
        o_Y = 4'b1110;
     2'b01:
        o_Y = 4'b1101;
     2'b10:
        o_Y = 4'b1011;
     2'b11:
        o_Y = 4'b0111;
    default:
        o_Y = 4'd1;
endcase

endmodule

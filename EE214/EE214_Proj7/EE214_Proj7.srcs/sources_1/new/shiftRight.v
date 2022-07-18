`timescale 1ns / 1ps

module shiftRight(
    input [7:0] i_data,
    input [3:0] i_amt,
    input i_fill, // fill bit value
    output reg [7:0] o_shiftedData
);

always @ (*)
begin
    case(i_amt)
        4'b0000: o_shiftedData = i_data;
        4'b0001: o_shiftedData = {i_fill, i_data[7:1]};
        4'b0010: o_shiftedData = {{2{i_fill}}, i_data[7:2]};
        4'b0011: o_shiftedData = {{3{i_fill}}, i_data[7:3]};
        4'b0100: o_shiftedData = {{4{i_fill}}, i_data[7:4]};
        4'b0101: o_shiftedData = {{5{i_fill}}, i_data[7:5]};
        4'b0110: o_shiftedData = {{6{i_fill}}, i_data[7:6]};
        4'b0111: o_shiftedData = {{7{i_fill}}, i_data[7:6]};
        4'b1000: o_shiftedData = {8{i_fill}};
        default: o_shiftedData = i_data;
    endcase
end
endmodule
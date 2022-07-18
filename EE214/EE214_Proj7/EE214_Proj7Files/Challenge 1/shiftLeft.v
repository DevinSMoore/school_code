`timescale 1ns / 1ps

module shiftLeft(
    input [7:0] i_data,
    input [3:0] i_amt,
    input i_fill, // fill bit value
    output reg [7:0] o_shiftedData
);

always @ (*)
begin
    case(i_amt)
        4'b0000: o_shiftedData = i_data;
        4'b0001: o_shiftedData = {i_data[6:0], i_fill};
        4'b0010: o_shiftedData = {i_data[5:0], {2{i_fill}}};
        4'b0011: o_shiftedData = {i_data[4:0], {3{i_fill}}};
        4'b0100: o_shiftedData = {i_data[3:0], {4{i_fill}}};
        4'b0101: o_shiftedData = {i_data[2:0], {5{i_fill}}};
        4'b0110: o_shiftedData = {i_data[1:0], {6{i_fill}}};
        4'b0111: o_shiftedData = {i_data[0], {7{i_fill}}};
        4'b1000: o_shiftedData =  {8{i_fill}};
        default: o_shiftedData = i_data;
    endcase
end
endmodule

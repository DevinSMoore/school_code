`timescale 1ns / 1ps

module rotateLeft(
    input [7:0] i_data,
    input [3:0] i_amt,
    output reg [7:0] o_rotatedData
);

always @ (*)
begin
    case(i_amt)
        4'b0000: o_rotatedData = i_data;
        4'b0001: o_rotatedData = {i_data[6:0], i_data[7]};
        4'b0010: o_rotatedData = {i_data[5:0], i_data[7:6]};
        4'b0011: o_rotatedData = {i_data[4:0], i_data[7:5]};
        4'b0100: o_rotatedData = {i_data[3:0], i_data[7:4]};
        4'b0101: o_rotatedData = {i_data[2:0], i_data[7:3]};
        4'b0110: o_rotatedData = {i_data[1:0], i_data[7:2]};
        4'b0111: o_rotatedData = {i_data[0], i_data[7:1]};
        4'b1000: o_rotatedData =  i_data;
        default: o_rotatedData = i_data;
    endcase
end



endmodule
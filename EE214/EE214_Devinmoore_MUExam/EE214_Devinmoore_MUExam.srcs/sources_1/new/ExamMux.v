//////////////////////////////////////////////////////////////////////////////////
//  Name: Devin More
//  Class: EE214 Clint Cole
//  TA: Logan Dihel
//  Assignment: Exam 1 Makeup
//
//  Date Created: 2020/11/02
//  Description: Define a 4:1 mux that outputs the minterm equation:
//                  y<=m(3,5,6,7,10,12,14)
//              No dont cares, max size assumed 16 bits
// 
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps

module ExamMux(
    input C, D, 
    input [1:0] sel, // A, B inputs
    output reg Y // mux out
    );

always @ (sel, C, D)
begin
    case(sel)
        0:  Y = (C & D);
        1:  Y = (C | D);
        2:  Y = (C & ~D);
        3:  Y = ~D;
        default: Y = 1'b0;
    endcase
end

endmodule

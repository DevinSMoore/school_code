`timescale 1ns / 1ps
////////////////////////////////////////////////////////////////////////////////// 
// Name: Devin Moore
// Class EE214 Clint Cole Section whatever
// Assignment Project 2 Requirement 4
// 
// Create Date: 09/15/2020
// Module Name: EE214Proj2Req4
//////////////////////////////////////////////////////////////////////////////////


module EE214Proj2Req4(
    input [3:0] sw,
    // rgb_yellow is the combination of the red and green LEDs on RGB LED 11
    output [1:0] rgb_yellow,
    // rgb red is the red segment of RGB LED 10
    output rgb_red
);

// This is minimized SOP logic for the yellow RGB out
assign rgb_yellow[1:0] = ((~sw[3] & sw[2] & ~sw[0])
                         | (~sw[2] & ~sw[1] & sw[0])
                         | (sw[3] & sw[0])
                         | (sw[3] & sw[1])
                         | (sw[1] & ~sw[0])) 
                         ? 2'b11 : 2'b00;

// Minimized SOP logic for red RBG out
assign rgb_red = ((sw[1] & sw[0])
                | (sw[3] & sw[2])
                | (sw[3] & sw[1]))
                ? 2'b11 : 2'b00;


//// Minimized POS for yellow RGB out
//assign rgb_yellow[1:0] = ((sw[2] | sw[1] | sw[0])
//                        & (~sw[3] | sw[1] | sw[0])
//                        & (sw[3] | ~sw[2] | ~sw[0]) 
//                        & (sw[3] | ~sw[1] | ~sw[0])) ? 2'b11 : 2'b00;
                        
//// Minimized POS for red RGB out
//assign rgb_red = ((sw[3] | sw[1])
//                & (sw[3] | sw[0])
//                & (sw[2] | sw[1])) ? 2'b11 : 2'b00;

 
//   used ternary operator to effectively create a two wide bus for the result of our logic
//   to be sent to two segments of and RGB LED simultaniously.

//assign rgb_yellow[1:0] = ((sw[3] | sw[2] | sw[1] | sw[0])
//                  & (sw[3] | sw[2] | ~sw[1] | ~sw[0])
//                  & (sw[3] | ~sw[2] | sw[1] | ~sw[0])
//                  & (sw[3] | ~sw[2] | ~sw[1] | ~sw[0])
//                  & (~sw[3] | sw[2] | sw[1] | sw[0])
//                  & (~sw[3] | ~sw[2] | sw[1] | sw[0])) ? 2'b11 : 2'b00;

// Old solution for yellow RGB
//assign rgb_yellow[0] = (sw[3] | sw[2] | sw[1] | sw[0])
//                  & (sw[3] | sw[2] | ~sw[1] | ~sw[0])
//                  & (sw[3] | ~sw[2] | sw[1] | ~sw[0])
//                  & (sw[3] | ~sw[2] | ~sw[1] | ~sw[0])
//                  & (~sw[3] | sw[2] | sw[1] | sw[0])
//                  & (~sw[3] | ~sw[2] | sw[1] | sw[0]);
                  
//assign rgb_yellow[1] = (sw[3] | sw[2] | sw[1] | sw[0])
//                  & (sw[3] | sw[2] | ~sw[1] | ~sw[0])
//                  & (sw[3] | ~sw[2] | sw[1] | ~sw[0])
//                  & (sw[3] | ~sw[2] | ~sw[1] | ~sw[0])
//                  & (~sw[3] | sw[2] | sw[1] | sw[0])
//                  & (~sw[3] | ~sw[2] | sw[1] | sw[0]);

// old RGB code
//assign rgb_red = (sw[3] | sw[2] | sw[1] | sw[0])
//               & (sw[3] | sw[2] | sw[1] | ~sw[0])
//               & (sw[3] | sw[2] | ~sw[1] | sw[0])
//               & (sw[3] | ~sw[2] | sw[1] | sw[0])
//               & (sw[3] | ~sw[2] | sw[1] | ~sw[0])
//               & (sw[3] | ~sw[2] | ~sw[1] | sw[0])
//               & (~sw[3] | sw[2] | sw[1] | sw[0])
//               & (~sw[3] | sw[2] | sw[1] | ~sw[0]);
endmodule

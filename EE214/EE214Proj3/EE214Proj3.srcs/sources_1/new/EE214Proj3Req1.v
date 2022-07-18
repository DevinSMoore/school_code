////////////////////////////////////////////////////////////////////////////////////
// Name: Devin Moore
// Class EE214 Clint Cole Section whatever
// Assignment Project 3 Requirement 1
// 
// Create Date: 2020/09/18
// Last Modified: 2020/09/22
// Module Name: EE214Proj3Req1
// 
// Description: This requirement is for an LED to turn on every time that a switch
//      		is flipped. There are 5 total switches that will alternate turning 
//				the output on.
////////////////////////////////////////////////////////////////////////////////////

module EE214Proj3Req1(
    input [4:0] sw,
    output led
);

// Added this after meeting with TA (Logan), the alternating nature of the inputs/outputs can be described with XOR gats
assign led = sw[4] ^ sw[3] ^ sw[2] ^ sw[1] ^ sw[0];

// This will turn the led on if it is off, and off if it is on.
//assign led = (~sw[4] & ~sw[3] & ~sw[2] & ~sw[1] & sw[0])
//           | (~sw[4] & ~sw[3] & ~sw[2] & sw[1] & ~sw[0])
//           | (~sw[4] & ~sw[3] & sw[2] & ~sw[1] & ~sw[0])
//           | (~sw[4] & ~sw[3] & sw[2] & sw[1] & sw[0])
//           | (~sw[4] & sw[3] & ~sw[2] & ~sw[1] & ~sw[0])
//           | (~sw[4] & sw[3] & ~sw[2] & sw[1] & sw[0])
//           | (~sw[4] & sw[3] & sw[2] & ~sw[1] & sw[0])
//           | (~sw[4] & sw[3] & sw[2] & sw[1] & ~sw[0])
//           | (sw[4] & ~sw[3] & ~sw[2] & ~sw[1] & ~sw[0])
//           | (sw[4] & ~sw[3] & ~sw[2] & sw[1] & sw[0])
//           | (sw[4] & ~sw[3] & sw[2] & ~sw[1] & sw[0])
//           | (sw[4] & ~sw[3] & sw[2] & sw[1] & ~sw[0])
//           | (sw[4] & sw[3] & ~sw[2] & ~sw[1] & sw[0])
//           | (sw[4] & sw[3] & ~sw[2] & sw[1] & ~sw[0])
//           | (sw[4] & sw[3] & sw[2] & ~sw[1] & ~sw[0])
//           | (sw[4] & sw[3] & sw[2] & sw[1] & sw[0]);
            

endmodule
////////////////////////////////////////////////////////////////////////////////// 
// Name: Devin Moore
// Class EE214 Clint Cole
// Assignment Project 4 Requirement 3
// TA: Logan 
// 
// Create Date: 2020/10/02
// Last Modified: 2020/10/02
// Module Name: EE214_Proj4Req3
//
// Description: This implements a mux that will turn the output on for minterms
// 3, 4, 6, 8, 9, 10, 13
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns/1ps


module EE214_Proj4Chal1(
    input [1:0] I, // Inputs sw[0] = I[0], and sw[1] = I[1]
    input [1:0] sel, // mux selects sw[2] = sel[0] sw[3] = sel[1]
    output led // led[0]
);

// This will turn on the led for minterms 3,4,6,8,9,10,13 using a multiplexor 
          
reg led;

always @ (I, sel)
begin
    case (sel)
        2'd0:
            led = (I[1] & I[0]);
        2'd1:
            led = ~I[0];            
        2'd2:
            led = ~(I[1] & I[0]);           
        2'd3:
            led = (~I[1] & I[0]);            
        default:
            led = 0;        
    endcase;
end

endmodule

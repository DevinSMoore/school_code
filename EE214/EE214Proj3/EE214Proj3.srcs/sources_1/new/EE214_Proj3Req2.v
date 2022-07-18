`timescale 1ns / 1ps



module EE214_Proj3Req2(
    input [4:0] sw,
    output led
);


 // POS minimization (40 inputs & 11 gates)
 assign led = (sw[3] | sw[2] | sw[4]) 
            & (sw[3] | sw[2] | sw[1]) 
            & (sw[3] | sw[2] | sw[0]) & (sw[3] | sw[4] | sw[1]) 
            & (sw[3] | sw[4] | sw[0]) & (sw[3] | sw[1] | sw[0]) 
            & (sw[2] | sw[4] | sw[1]) & (sw[2] | sw[4] | sw[0]) 
            & (sw[2] | sw[1] | sw[0]) & (sw[4] | sw[1] | sw[0]);

//// SOP minimization 40 inputs & 11 gates)
//assign led = (sw[4] & sw[1] & sw[0]) 
//           | (sw[2] & sw[1] & sw[0]) 
//           | (sw[4] & sw[2] & sw[0]) 
//           | (sw[4] & sw[2] & sw[1]) 
//           | (sw[3] & sw[1] & sw[0]) 
//           | (sw[4] & sw[3] & sw[0]) 
//           | (sw[4] & sw[3] & sw[1]) 
//           | (sw[3] & sw[2] & sw[0]) 
//           | (sw[3] & sw[2] & sw[1]) 
//           | (sw[4] & sw[2] & sw[3]);
 
            
endmodule

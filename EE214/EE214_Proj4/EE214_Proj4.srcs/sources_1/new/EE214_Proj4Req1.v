/////////////////////////////////////////////////////////////////////////////////////////
// Devin Moore  
// EE214 Clint Cole Fall 2020
// 
// Date Created: 2020/10/02
// Date Modified: 2020/10/04
// Design Name: Project 4 Requirement 1
//
// Description: Create a 4:1 
/////////////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps


module EE214_Proj4Req1(
     // 4:1 I/O
     // input [7:4] I0, // btn[3] - btn[0] for I0[7] - [4]    
     // output [1:0] led // led[0] - led[1]
      
    // 4:1 8 bit BUS mux inputs/outputs
     input [7:0] I0, // btn[3] - btn[0] for I 7 - 4, sw[11] - sw[8] for I 3 - 0
     input [7:0] I1, 
     input [7:0] I2, 
     input [7:0] I3, 
     input [1:0] sel, // sw[1] & sw[0]
     output [7:0] led
);

//// 4:1 1 bit BUS mux code using case statement in always block
//reg led;

//always @ (sel, I0)
//begin
//    case (sel)
//        2'd0:
//            led = I0[4]; 
//        2'd1:
//            led = I0[5]; 
//        2'd2:
//            led = I0[6]; 
//        2'd3:
//            led = I0[7];    
//        default:
//            led <= 1'd0;
//    endcase
//end         
//endmodule


// 4:1 mux code using case statement in always block
reg [7:0] led;

always @ (sel, I0, I1, I2, I3)
begin
    case (sel)
        2'd0:
            led = I0; 
        2'd1:
            led = I1; 
        2'd2:
            led = I2; 
        2'd3:
            led = I3;    
        default:
            led <= 8'd0;
    endcase
end         
endmodule

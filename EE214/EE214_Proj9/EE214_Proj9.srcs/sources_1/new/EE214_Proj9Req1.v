`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: WSU 
// Engineer: Devin Moore
// 
// Create Date: 12/20/2020 05:20:32 PM
// Design Name: Serial Adder 
// Module Name: EE214_Proj9Req1
// Project Name: State Machines Intro
// Description: 
// 
//////////////////////////////////////////////////////////////////////////////////


module EE214_Proj9Req1(
    input i_A, i_B, i_clk, i_rst,
    output o_F, o_Cout
    );

// Defining State Codes 
localparam S0 = 2'b00,
           S1 = 2'b01,
           S2 = 2'b10,
           S3 = 2'b11;
           
reg [1:0] r_currentState, r_nextState;

always @ (i_A, i_B, r_currentState) 
begin
    case(r_currentState)
        S0: // F = 0; Cout = 0;
            if (i_A ^ i_B) r_nextState = S1; // blocking assignments so it evaluates line by line
            else if (i_A & i_B) r_nextState = S2;
            else r_nextState = r_currentState;
        S1: // F = 1; Cout = 0;
            if (i_A ^ i_B) r_nextState = r_currentState;
            else if (i_A & i_B) r_nextState = S2;
            else r_nextState = S0;
        S2: // F = 0; Cout = 1;
            if (i_A ^ i_B) r_nextState = r_currentState;
            else if (i_A & i_B) r_nextState = S3;
            else r_nextState = S1;
        S3: // F = 1; Cout = 1;
            if (i_A ^ i_B) r_nextState = S2;
            else if (i_A & i_B) r_nextState = r_currentState;
            else r_nextState = S1;            
    default: 
            r_nextState = S0;
    endcase
end

always @ (posedge (i_clk), negedge (i_rst))
begin
    if (!i_rst) r_currentState <= r_nextState; // non-blocking for simultanious assignment
    else r_currentState <= 0;
end

// Setting outputs depending on state;
assign o_F = (r_currentState == S1 || r_currentState == S3) ? (1'b1) : (1'b0);
assign o_Cout = (r_currentState == S2 || r_currentState == S3) ? (1'b1) : (1'b0);

endmodule

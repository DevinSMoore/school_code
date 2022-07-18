`timescale 1ns / 1ps

module EE214_Proj9Req1_TB;

reg i_A, i_B, i_clk, i_rst;
wire o_F, o_Cout;

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
            if (i_A ^ i_B) r_nextState = S1; // blocking assignments so it evaluates line by line; 10 or 01
            else if (i_A & i_B) r_nextState = S2; // 11
            else r_nextState = r_currentState; // 00
        S1: // F = 1; Cout = 0;
            if (i_A ^ i_B) r_nextState = r_currentState; // 10 or 01
            else if (i_A & i_B) r_nextState = S2; // 11
            else r_nextState = S0; // 00
        S2: // F = 0; Cout = 1;
            if (i_A ^ i_B) r_nextState = r_currentState; // 10 or 01
            else if (i_A & i_B) r_nextState = S3; // 11
            else r_nextState = S1; // 00
        S3: // F = 1; Cout = 1;
            if (i_A ^ i_B) r_nextState = S2; // 10 or 01
            else if (i_A & i_B) r_nextState = r_currentState; // 11
            else r_nextState = S1; // 00
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

always #5 i_clk = ~i_clk;

initial
begin
#20;
// initializing inputs
i_A = 0;
i_B = 0;
i_rst = 0;
i_clk = 0;

// S0 -(A^B)-> S1 -(A&B)-> S2 -(A&B)-> S3
#9 i_A = 1;
#5 i_B = 1;
#10; // waiting 5ns so A & B goes through on next posedge i_clk

// back to S0 (initial state)
#10 i_rst = 1;
   i_A = 0;
   i_B = 0;
#10 i_rst = 0;

// S0 -(A&B)-> S2 -(A&B)-> S3
#20 i_A = 1;
    i_B = 1;


#18 i_rst = 1;
#20 i_A = 0;
   i_B = 0;
#10 i_rst = 0;





#20 $finish;
end
endmodule

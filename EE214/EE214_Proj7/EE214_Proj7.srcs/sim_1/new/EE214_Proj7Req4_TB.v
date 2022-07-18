`timescale 1ns / 1ps

module EE214_Proj7Req4_TB;
reg [7:0] D;
reg S, rst, clk; // D is sw[7:0], S is btn[1], rst is btn[3], clk is btn[0]
wire [7:0] Q;  




// Instantiating the CUT
EE214_Proj7Req4 cut(
    .D(D),
    .S(S),
    .rst(rst),
    .clk(clk),
    .Q(Q)
);

initial
begin
#20;
D = 0;
S = 0;
rst = 0;
clk = 0;

#1 S = 1;
#1 S = 0;

D = 8'b01000010;
#1 clk = 1;
#1 clk = 0;


#20 $finish;
end
endmodule
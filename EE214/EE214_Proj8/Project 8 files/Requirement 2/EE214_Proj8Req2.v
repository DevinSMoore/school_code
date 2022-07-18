`timescale 1ns / 1ps
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Description:
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

module EE214_Proj8Req2(
    input i_clk, i_rst, i_ce, // i_ce is counter enable. 1 = halt count 0 = resume count sw[0]; i_rst will set all bits to 0, btn[0]
    output [3:0] o_dividedClock 
    );
reg [27:0] counter;

always @ (posedge (i_clk), posedge(i_rst))
begin
    if (i_rst) begin counter <=0; end // if we hit the reset, the counter will go to 0.
    else if (i_ce) begin counter <= counter; end
    else counter <= counter + 1;
end

reg [3:0] counter2;

always @ (posedge (counter[27]), posedge(i_rst))
begin
    if (i_rst) begin counter2 <=0; end // if we hit the reset, the counter will go to 0.
    else if (i_ce) begin counter2 <= counter2; end
    else counter2 <= counter2 + 1;
end

assign o_dividedClock = counter2; // divided down to 0.37Hz apx SHOULD BE BUT CRAPPY HAND TIMING PUTS PERIOD AT ABOUT 1.3 sec but that's closer to .745Hz
endmodule
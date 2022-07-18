`timescale 1ns / 1ps
// This is going to be a pain to code



module barrelShfiter_8bit(
    input [7:0] i_data,
    input [3:0] i_sel, amt,
    input i_fill, i_rotate, i_direction, // i_rotate = 1 is rotate right 0 is rotate left; i_direction = 1 is right 0 is left
    output [7:0] o_led
    );


reg o_shiftedData;

always @ (*)
begin
case(amt)
    0: o_shiftedData = i_data;
    1: if (i_rotate) begin if (i_direction)begin
        
        end end
endcase
end  
assign o_led = o_shiftedData;

// instantiating two-hundred and fifty-six 2:1 muxs this is probably not the way we're supposed to do this

mux_1bit_2_1 m0(
    
);
endmodule

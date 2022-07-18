`timescale 1ns / 1ps

module mux_4_1(
    // input [1:0] I0,
    // input [1:0] I1,
    // input [1:0] I2,
    // input [1:0] I3,
    // input [1:0] sel,
    // output [1:0] Y
    input [3:0] sw,
    input [1:0] btn,
    output led
);


reg led_var;

//assign led = (btn == 2'd0) ? sw[0] : (
//                        (btn == 2'd1) ? sw[1] : (
//                            (btn == 2'd2) ? sw[2] : sw[3]
//                            )
//                         );
                         
//always @ (sel, I0, I1, I2, I3)
//begin
//if (sel == 2'd0)
//    Y = I0;
//else if (sel == 2'd1)
//    Y = I1;
//else if (sel == 2'd3)
//    Y = I2;
//else
//    Y = I3;
//end

always @ (btn, sw[0], sw[1], sw[2], sw[3])
begin
case (btn)
    2'd0:
        led = sw[0];
    2'd1:
        led = sw[1];
    2'd2:
        led = sw[2];
    2'd3:
        led = sw[3];
    default
        led = 2'd0;
endcase
end



endmodule

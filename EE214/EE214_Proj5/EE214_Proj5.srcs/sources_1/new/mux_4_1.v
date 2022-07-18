//////////////////////////////////////////////////////////////////////
// just a 8:1 mux name of thin gis wrong
//
//
//
//////////////////////////////////////////////////////////////////////

module mux_4_1(
    input I0,
    input I1,
    input I2,
    input I3,
    input I4,
    input I5,
    input I6,
    input I7,
    input S0,
    input S1,
    input S2,
    output reg led
);

always @(S0, S1, S2, I0, I1, I2, I3, I4, I5, I6, I7)
begin
    if (~S2 & ~S1 & ~S0)
        led = I0;

    else if (~S2 & ~S1 & S0)
        led = I1;

    else if (~S2 & S1 & ~S0)
        led = I2;

    else if (~S2 & S1 & S0)
        led = I3;

    else if (S2 & ~S1 & ~S0)
        led = I4;

    else if (S2 & ~S1 & S0)
        led = I5;
    
    else if (S2 & S1 & ~S0)
        led = I6;

    else
        led = I7;
end


endmodule

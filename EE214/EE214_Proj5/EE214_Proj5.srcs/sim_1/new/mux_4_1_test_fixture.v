module mux_4_1_test_fixture;

// Inputs
reg I0;
reg I1;
reg I2;
reg I3;
reg I4;
reg I5;
reg I6;
reg I7;
reg S0;
reg S1;
reg S2;

// Outputs
wire led;

// Instantiating the CUT
mux_4_1 cut(
    .I0(I0),
    .I1(I1),
    .I2(I2),
    .I3(I3),
    .I4(I4),
    .I5(I5),
    .I6(I6),
    .I7(I7),
    .S0(S0),
    .S1(S1),
    .S2(S2),
    .led(led)
);


// Input stimulus

initial
begin 
// Setting initial states
I0 = 0;
I1 = 0;
I2 = 0;
I3 = 0;
I4 = 0;
I5 = 0;
I6 = 0;
I7 = 0;
S0 = 0; // S0 & S1 & S2 are the 3 select signals
S1 = 0; 
S2 = 0;

#20 I0 <= 1;
#20 I0 <= 0; // turning I0 on then off while both selects are low

#20 S0 <= 1; // 001

#20 I1 <= 1;
#20 I1 <= 0; // address 0 0 1 turning I1 on then off

#20 S0 <= 0; // 000
#20 S1 <= 1; // 010

#20 I2 <= 1;
#20 I2 <= 0; // address 0 1 0 turning I1 on then off

#20 S0 <= 1; // 011

#20 I3 <= 1;
#20 I3 <= 0; // address 0 1 1 turning I1 on then off

#20 S0 <= 0; // 010
#20 S1 <= 0; // 000
#20 S2 <= 1; // 100

#20 I4 <= 1;
#20 I4 <= 0; // address 1 0 0 turning I1 on then off

#20 S0 <= 1; // 101

#20 I5 <= 1;
#20 I5 <= 0; // address 1 0 1 turning I1 on then off

#20 S0 <= 0; // 100
#20 S1 <= 1; // 110

#20 I6 <= 1;
#20 I6 <= 0; // address 1 1 0 turning I1 on then off

#20 S0 <= 1; // 111

#20 I7 <= 1;
#20 I7 <= 0; // address 1 1 1 turning I1 on then off

#20 $finish;
end
endmodule
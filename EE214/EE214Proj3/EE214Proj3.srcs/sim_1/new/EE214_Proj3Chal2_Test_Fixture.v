`timescale 1ns / 1ps

module EE214_Proj3Chal2_test_fixture;

// Inputs
reg [11:0] sw;
reg [4:0] btn;
// Outputs
wire led;

// Instantiate the Circuit Under Test (CUT)
EE214_Proj3Chal2 cut (
    .sw(sw),
    .led(led),
    .btn(btn)
);

// Declare loop index variable
integer k, j;

// Apply input stimulus
initial
begin
    sw = 0;
    btn = 0;
    
    for (k = 0; k < 2048; k = k + 1)
        #20 sw = k;
        for (j = 0; j < 16; j = j + 1)
            #20 btn = j;

    #20	$finish;
end

endmodule
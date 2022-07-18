`timescale 1ns / 1ps

module EE214_Proj3Req2_test_fixture;

// Inputs
reg [4:0] sw;
// Outputs
wire led;

// Instantiate the Circuit Under Test (CUT)
EE214_Proj3Req2 cut (
    .sw(sw),
    .led(led)
);

// Declare loop index variable
integer k;

// Apply input stimulus
initial
begin
    sw = 0;

    for (k = 0; k < 32; k = k + 1)
        #20 sw = k;

    #20	$finish;
end

endmodule
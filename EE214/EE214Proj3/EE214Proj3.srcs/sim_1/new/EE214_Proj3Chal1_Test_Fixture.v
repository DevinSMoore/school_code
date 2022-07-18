`timescale 1ns / 1ps

module EE214_Proj3Cal1_test_fixture;

// Inputs
reg [11:0] sw;
// Outputs
wire [1:0] led;

// Instantiate the Circuit Under Test (CUT)
EE214_Proj3Chal1 cut (
    .sw(sw),
    .led(led)
);

// Declare loop index variable
integer k;

// Apply input stimulus
initial
begin
    sw = 0;

    for (k = 0; k < 2048; k = k + 1)
        #20 sw = k;

    #20	$finish;
end

endmodule
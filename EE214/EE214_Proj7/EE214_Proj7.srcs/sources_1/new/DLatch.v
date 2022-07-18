`timescale 1ns / 1ps

module DLatch(
    input D, G, rst
);

reg Q;

always @ (*)
begin
if (rst == 1) begin Q <= 1'b0; end // if rst is asserted Q is driven  to 0
else if (G == 1)
begin Q <= D; end
end


endmodule
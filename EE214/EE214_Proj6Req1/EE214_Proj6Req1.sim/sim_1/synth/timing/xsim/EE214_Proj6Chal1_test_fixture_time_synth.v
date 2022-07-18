// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2020.1.1 (win64) Build 2960000 Wed Aug  5 22:57:20 MDT 2020
// Date        : Sat Oct 24 00:33:44 2020
// Host        : LAPTOP-SKTNOLCK running 64-bit major release  (build 9200)
// Command     : write_verilog -mode timesim -nolib -sdf_anno true -force -file
//               C:/EE214_Projects/EE214_Proj6Req1/EE214_Proj6Req1.sim/sim_1/synth/timing/xsim/EE214_Proj6Chal1_test_fixture_time_synth.v
// Design      : EE214_Proj6Chal1
// Purpose     : This verilog netlist is a timing simulation representation of the design and should not be modified or
//               synthesized. Please ensure that this netlist is used with the corresponding SDF file.
// Device      : xc7z007sclg400-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps
`define XIL_TIMING

(* NotValidForBitStream *)
module EE214_Proj6Chal1
   (sw,
    led);
  input [3:0]sw;
  output [15:0]led;

  wire [15:0]led;
  wire [15:0]led_OBUF;
  wire [3:0]sw;
  wire [3:0]sw_IBUF;

initial begin
 $sdf_annotate("EE214_Proj6Chal1_test_fixture_time_synth.sdf",,,,"tool_control");
end
  OBUF \led_OBUF[0]_inst 
       (.I(led_OBUF[0]),
        .O(led[0]));
  (* SOFT_HLUTNM = "soft_lutpair7" *) 
  LUT4 #(
    .INIT(16'h0001)) 
    \led_OBUF[0]_inst_i_1 
       (.I0(sw_IBUF[2]),
        .I1(sw_IBUF[1]),
        .I2(sw_IBUF[0]),
        .I3(sw_IBUF[3]),
        .O(led_OBUF[0]));
  OBUF \led_OBUF[10]_inst 
       (.I(led_OBUF[10]),
        .O(led[10]));
  (* SOFT_HLUTNM = "soft_lutpair2" *) 
  LUT4 #(
    .INIT(16'h0020)) 
    \led_OBUF[10]_inst_i_1 
       (.I0(sw_IBUF[3]),
        .I1(sw_IBUF[2]),
        .I2(sw_IBUF[1]),
        .I3(sw_IBUF[0]),
        .O(led_OBUF[10]));
  OBUF \led_OBUF[11]_inst 
       (.I(led_OBUF[11]),
        .O(led[11]));
  (* SOFT_HLUTNM = "soft_lutpair0" *) 
  LUT4 #(
    .INIT(16'h2000)) 
    \led_OBUF[11]_inst_i_1 
       (.I0(sw_IBUF[3]),
        .I1(sw_IBUF[2]),
        .I2(sw_IBUF[1]),
        .I3(sw_IBUF[0]),
        .O(led_OBUF[11]));
  OBUF \led_OBUF[12]_inst 
       (.I(led_OBUF[12]),
        .O(led[12]));
  (* SOFT_HLUTNM = "soft_lutpair2" *) 
  LUT4 #(
    .INIT(16'h0200)) 
    \led_OBUF[12]_inst_i_1 
       (.I0(sw_IBUF[3]),
        .I1(sw_IBUF[1]),
        .I2(sw_IBUF[0]),
        .I3(sw_IBUF[2]),
        .O(led_OBUF[12]));
  OBUF \led_OBUF[13]_inst 
       (.I(led_OBUF[13]),
        .O(led[13]));
  (* SOFT_HLUTNM = "soft_lutpair1" *) 
  LUT4 #(
    .INIT(16'h0800)) 
    \led_OBUF[13]_inst_i_1 
       (.I0(sw_IBUF[3]),
        .I1(sw_IBUF[0]),
        .I2(sw_IBUF[1]),
        .I3(sw_IBUF[2]),
        .O(led_OBUF[13]));
  OBUF \led_OBUF[14]_inst 
       (.I(led_OBUF[14]),
        .O(led[14]));
  (* SOFT_HLUTNM = "soft_lutpair1" *) 
  LUT4 #(
    .INIT(16'h0800)) 
    \led_OBUF[14]_inst_i_1 
       (.I0(sw_IBUF[3]),
        .I1(sw_IBUF[1]),
        .I2(sw_IBUF[0]),
        .I3(sw_IBUF[2]),
        .O(led_OBUF[14]));
  OBUF \led_OBUF[15]_inst 
       (.I(led_OBUF[15]),
        .O(led[15]));
  (* SOFT_HLUTNM = "soft_lutpair0" *) 
  LUT4 #(
    .INIT(16'h8000)) 
    \led_OBUF[15]_inst_i_1 
       (.I0(sw_IBUF[3]),
        .I1(sw_IBUF[1]),
        .I2(sw_IBUF[0]),
        .I3(sw_IBUF[2]),
        .O(led_OBUF[15]));
  OBUF \led_OBUF[1]_inst 
       (.I(led_OBUF[1]),
        .O(led[1]));
  (* SOFT_HLUTNM = "soft_lutpair7" *) 
  LUT4 #(
    .INIT(16'h0004)) 
    \led_OBUF[1]_inst_i_1 
       (.I0(sw_IBUF[2]),
        .I1(sw_IBUF[0]),
        .I2(sw_IBUF[1]),
        .I3(sw_IBUF[3]),
        .O(led_OBUF[1]));
  OBUF \led_OBUF[2]_inst 
       (.I(led_OBUF[2]),
        .O(led[2]));
  (* SOFT_HLUTNM = "soft_lutpair6" *) 
  LUT4 #(
    .INIT(16'h0004)) 
    \led_OBUF[2]_inst_i_1 
       (.I0(sw_IBUF[2]),
        .I1(sw_IBUF[1]),
        .I2(sw_IBUF[0]),
        .I3(sw_IBUF[3]),
        .O(led_OBUF[2]));
  OBUF \led_OBUF[3]_inst 
       (.I(led_OBUF[3]),
        .O(led[3]));
  (* SOFT_HLUTNM = "soft_lutpair4" *) 
  LUT4 #(
    .INIT(16'h0040)) 
    \led_OBUF[3]_inst_i_1 
       (.I0(sw_IBUF[2]),
        .I1(sw_IBUF[1]),
        .I2(sw_IBUF[0]),
        .I3(sw_IBUF[3]),
        .O(led_OBUF[3]));
  OBUF \led_OBUF[4]_inst 
       (.I(led_OBUF[4]),
        .O(led[4]));
  (* SOFT_HLUTNM = "soft_lutpair6" *) 
  LUT4 #(
    .INIT(16'h0010)) 
    \led_OBUF[4]_inst_i_1 
       (.I0(sw_IBUF[1]),
        .I1(sw_IBUF[0]),
        .I2(sw_IBUF[2]),
        .I3(sw_IBUF[3]),
        .O(led_OBUF[4]));
  OBUF \led_OBUF[5]_inst 
       (.I(led_OBUF[5]),
        .O(led[5]));
  (* SOFT_HLUTNM = "soft_lutpair5" *) 
  LUT4 #(
    .INIT(16'h0020)) 
    \led_OBUF[5]_inst_i_1 
       (.I0(sw_IBUF[0]),
        .I1(sw_IBUF[1]),
        .I2(sw_IBUF[2]),
        .I3(sw_IBUF[3]),
        .O(led_OBUF[5]));
  OBUF \led_OBUF[6]_inst 
       (.I(led_OBUF[6]),
        .O(led[6]));
  (* SOFT_HLUTNM = "soft_lutpair5" *) 
  LUT4 #(
    .INIT(16'h0020)) 
    \led_OBUF[6]_inst_i_1 
       (.I0(sw_IBUF[1]),
        .I1(sw_IBUF[0]),
        .I2(sw_IBUF[2]),
        .I3(sw_IBUF[3]),
        .O(led_OBUF[6]));
  OBUF \led_OBUF[7]_inst 
       (.I(led_OBUF[7]),
        .O(led[7]));
  (* SOFT_HLUTNM = "soft_lutpair4" *) 
  LUT4 #(
    .INIT(16'h0080)) 
    \led_OBUF[7]_inst_i_1 
       (.I0(sw_IBUF[1]),
        .I1(sw_IBUF[0]),
        .I2(sw_IBUF[2]),
        .I3(sw_IBUF[3]),
        .O(led_OBUF[7]));
  OBUF \led_OBUF[8]_inst 
       (.I(led_OBUF[8]),
        .O(led[8]));
  (* SOFT_HLUTNM = "soft_lutpair3" *) 
  LUT4 #(
    .INIT(16'h0002)) 
    \led_OBUF[8]_inst_i_1 
       (.I0(sw_IBUF[3]),
        .I1(sw_IBUF[2]),
        .I2(sw_IBUF[1]),
        .I3(sw_IBUF[0]),
        .O(led_OBUF[8]));
  OBUF \led_OBUF[9]_inst 
       (.I(led_OBUF[9]),
        .O(led[9]));
  (* SOFT_HLUTNM = "soft_lutpair3" *) 
  LUT4 #(
    .INIT(16'h0020)) 
    \led_OBUF[9]_inst_i_1 
       (.I0(sw_IBUF[3]),
        .I1(sw_IBUF[2]),
        .I2(sw_IBUF[0]),
        .I3(sw_IBUF[1]),
        .O(led_OBUF[9]));
  IBUF \sw_IBUF[0]_inst 
       (.I(sw[0]),
        .O(sw_IBUF[0]));
  IBUF \sw_IBUF[1]_inst 
       (.I(sw[1]),
        .O(sw_IBUF[1]));
  IBUF \sw_IBUF[2]_inst 
       (.I(sw[2]),
        .O(sw_IBUF[2]));
  IBUF \sw_IBUF[3]_inst 
       (.I(sw[3]),
        .O(sw_IBUF[3]));
endmodule
`ifndef GLBL
`define GLBL
`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;
    parameter GRES_WIDTH = 10000;
    parameter GRES_START = 10000;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    wire GRESTORE;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;
    wire FCSBO_GLBL;
    wire [3:0] DO_GLBL;
    wire [3:0] DI_GLBL;
   
    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;
    reg GRESTORE_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (strong1, weak0) GSR = GSR_int;
    assign (strong1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;
    assign (strong1, weak0) GRESTORE = GRESTORE_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

    initial begin 
	GRESTORE_int = 1'b0;
	#(GRES_START);
	GRESTORE_int = 1'b1;
	#(GRES_WIDTH);
	GRESTORE_int = 1'b0;
    end

endmodule
`endif

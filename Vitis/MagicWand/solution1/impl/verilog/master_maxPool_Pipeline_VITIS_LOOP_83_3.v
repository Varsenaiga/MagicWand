// ==============================================================
// RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.1 (64-bit)
// Version: 2021.1
// Copyright (C) Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

module master_maxPool_Pipeline_VITIS_LOOP_83_3 (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        out_0_load,
        data_V_2,
        p_Result_6,
        dc_2,
        conv2221_out,
        conv2221_out_ap_vld
);

parameter    ap_ST_fsm_pp0_stage0 = 1'd1;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
input  [31:0] out_0_load;
input  [62:0] data_V_2;
input  [0:0] p_Result_6;
input  [63:0] dc_2;
output  [31:0] conv2221_out;
output   conv2221_out_ap_vld;

reg ap_done;
reg ap_idle;
reg ap_ready;
reg conv2221_out_ap_vld;

(* fsm_encoding = "none" *) reg   [0:0] ap_CS_fsm;
wire    ap_CS_fsm_pp0_stage0;
wire    ap_enable_reg_pp0_iter0;
reg    ap_enable_reg_pp0_iter1;
reg    ap_enable_reg_pp0_iter2;
reg    ap_enable_reg_pp0_iter3;
reg    ap_idle_pp0;
wire    ap_block_state1_pp0_stage0_iter0;
wire    ap_block_state2_pp0_stage0_iter1;
wire    ap_block_state3_pp0_stage0_iter2;
wire    ap_block_state4_pp0_stage0_iter3;
wire    ap_block_pp0_stage0_subdone;
wire    ap_block_pp0_stage0_11001;
reg   [63:0] dc_2_read_reg_419;
reg   [0:0] p_Result_6_read_reg_426;
reg   [62:0] data_V_2_read_reg_432;
reg   [0:0] p_Result_s_reg_442;
wire   [0:0] icmp_ln1003_2_fu_142_p2;
reg   [0:0] icmp_ln1003_2_reg_449;
wire   [0:0] icmp_ln1003_3_fu_148_p2;
reg   [0:0] icmp_ln1003_3_reg_455;
wire   [0:0] icmp_ln1003_5_fu_154_p2;
reg   [0:0] icmp_ln1003_5_reg_461;
wire   [0:0] icmp_ln1007_fu_160_p2;
reg   [0:0] icmp_ln1007_reg_467;
wire   [63:0] grp_fu_104_p1;
reg   [63:0] dc_reg_473;
wire   [0:0] and_ln18_fu_214_p2;
reg   [0:0] and_ln18_reg_478;
wire   [63:0] res_4_fu_360_p3;
reg   [63:0] res_4_reg_483;
wire   [0:0] or_ln18_1_fu_385_p2;
reg   [0:0] or_ln18_1_reg_488;
reg   [31:0] conv2221_fu_66;
wire   [31:0] grp_fu_101_p1;
reg   [31:0] ap_sig_allocacmp_conv2221_load_1;
wire    ap_block_pp0_stage0;
reg   [31:0] ap_sig_allocacmp_conv2221_load;
wire    ap_block_pp0_stage0_01001;
wire   [63:0] grp_fu_101_p0;
wire   [31:0] bitcast_ln483_fu_116_p1;
wire   [10:0] tmp_3_fu_128_p4;
wire   [51:0] tmp_4_fu_138_p1;
wire   [63:0] data_V_fu_166_p1;
wire   [10:0] tmp_fu_170_p4;
wire   [51:0] tmp_2_fu_180_p1;
wire   [0:0] icmp_ln1003_fu_184_p2;
wire   [0:0] icmp_ln1003_1_fu_190_p2;
wire   [0:0] and_ln25_1_fu_218_p2;
wire   [0:0] and_ln25_fu_196_p2;
wire   [0:0] xor_ln25_fu_222_p2;
wire   [51:0] p_Result_1_fu_234_p4;
wire   [63:0] p_Result_2_fu_244_p4;
wire   [62:0] trunc_ln368_fu_257_p1;
wire   [63:0] p_Result_3_fu_261_p3;
wire   [63:0] p_Result_4_fu_268_p3;
wire   [0:0] ymaggreater_fu_274_p2;
wire   [0:0] xor_ln39_fu_280_p2;
wire   [0:0] select_ln39_fu_286_p3;
wire   [0:0] ymaggreater_1_fu_293_p3;
wire   [0:0] icmp_ln1003_4_fu_202_p2;
wire   [0:0] xor_ln1007_fu_208_p2;
wire   [0:0] and_ln18_1_fu_307_p2;
wire   [0:0] and_ln18_2_fu_313_p2;
wire   [63:0] res_fu_253_p1;
wire   [63:0] res_1_fu_300_p3;
wire   [0:0] and_ln25_3_fu_327_p2;
wire   [0:0] and_ln25_4_fu_332_p2;
wire   [63:0] res_2_fu_319_p3;
wire   [0:0] and_ln18_3_fu_344_p2;
wire   [0:0] xor_ln18_fu_348_p2;
wire   [0:0] and_ln18_4_fu_354_p2;
wire   [63:0] res_3_fu_337_p3;
wire   [0:0] xor_ln18_1_fu_367_p2;
wire   [0:0] or_ln18_fu_373_p2;
wire   [0:0] and_ln25_2_fu_228_p2;
wire   [0:0] xor_ln18_2_fu_379_p2;
wire   [0:0] and_ln18_5_fu_391_p2;
reg   [0:0] ap_NS_fsm;
reg    ap_idle_pp0_0to2;
reg    ap_reset_idle_pp0;
wire    ap_enable_pp0;
wire    ap_ce_reg;

// power-on initialization
initial begin
#0 ap_CS_fsm = 1'd1;
#0 ap_enable_reg_pp0_iter1 = 1'b0;
#0 ap_enable_reg_pp0_iter2 = 1'b0;
#0 ap_enable_reg_pp0_iter3 = 1'b0;
end

master_fptrunc_64ns_32_2_no_dsp_1 #(
    .ID( 1 ),
    .NUM_STAGE( 2 ),
    .din0_WIDTH( 64 ),
    .dout_WIDTH( 32 ))
fptrunc_64ns_32_2_no_dsp_1_U72(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(grp_fu_101_p0),
    .ce(1'b1),
    .dout(grp_fu_101_p1)
);

master_fpext_32ns_64_2_no_dsp_1 #(
    .ID( 1 ),
    .NUM_STAGE( 2 ),
    .din0_WIDTH( 32 ),
    .dout_WIDTH( 64 ))
fpext_32ns_64_2_no_dsp_1_U73(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(ap_sig_allocacmp_conv2221_load_1),
    .ce(1'b1),
    .dout(grp_fu_104_p1)
);

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_pp0_stage0;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter1 <= 1'b0;
    end else begin
        if (((1'b0 == ap_block_pp0_stage0_subdone) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
            ap_enable_reg_pp0_iter1 <= ap_start;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter2 <= 1'b0;
    end else begin
        if ((1'b0 == ap_block_pp0_stage0_subdone)) begin
            ap_enable_reg_pp0_iter2 <= ap_enable_reg_pp0_iter1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter3 <= 1'b0;
    end else begin
        if ((1'b0 == ap_block_pp0_stage0_subdone)) begin
            ap_enable_reg_pp0_iter3 <= ap_enable_reg_pp0_iter2;
        end
    end
end

always @ (posedge ap_clk) begin
    if ((1'b0 == ap_block_pp0_stage0_11001)) begin
        if (((ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
            conv2221_fu_66 <= out_0_load;
        end else if ((ap_enable_reg_pp0_iter3 == 1'b1)) begin
            conv2221_fu_66 <= grp_fu_101_p1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        and_ln18_reg_478 <= and_ln18_fu_214_p2;
        data_V_2_read_reg_432 <= data_V_2;
        dc_2_read_reg_419 <= dc_2;
        dc_reg_473 <= grp_fu_104_p1;
        icmp_ln1003_2_reg_449 <= icmp_ln1003_2_fu_142_p2;
        icmp_ln1003_3_reg_455 <= icmp_ln1003_3_fu_148_p2;
        icmp_ln1003_5_reg_461 <= icmp_ln1003_5_fu_154_p2;
        icmp_ln1007_reg_467 <= icmp_ln1007_fu_160_p2;
        or_ln18_1_reg_488 <= or_ln18_1_fu_385_p2;
        p_Result_6_read_reg_426 <= p_Result_6;
        p_Result_s_reg_442 <= bitcast_ln483_fu_116_p1[32'd31];
        res_4_reg_483 <= res_4_fu_360_p3;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_subdone) & (ap_enable_reg_pp0_iter3 == 1'b1))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = 1'b0;
    end
end

always @ (*) begin
    if (((ap_start == 1'b0) & (ap_idle_pp0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter3 == 1'b0) & (ap_enable_reg_pp0_iter2 == 1'b0) & (ap_enable_reg_pp0_iter1 == 1'b0) & (ap_enable_reg_pp0_iter0 == 1'b0))) begin
        ap_idle_pp0 = 1'b1;
    end else begin
        ap_idle_pp0 = 1'b0;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter2 == 1'b0) & (ap_enable_reg_pp0_iter1 == 1'b0) & (ap_enable_reg_pp0_iter0 == 1'b0))) begin
        ap_idle_pp0_0to2 = 1'b1;
    end else begin
        ap_idle_pp0_0to2 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_subdone) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if (((ap_start == 1'b0) & (ap_idle_pp0_0to2 == 1'b1))) begin
        ap_reset_idle_pp0 = 1'b1;
    end else begin
        ap_reset_idle_pp0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0) & (ap_enable_reg_pp0_iter3 == 1'b1))) begin
        ap_sig_allocacmp_conv2221_load = grp_fu_101_p1;
    end else begin
        ap_sig_allocacmp_conv2221_load = conv2221_fu_66;
    end
end

always @ (*) begin
    if ((1'b0 == ap_block_pp0_stage0)) begin
        if (((ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
            ap_sig_allocacmp_conv2221_load_1 = out_0_load;
        end else if ((ap_enable_reg_pp0_iter3 == 1'b1)) begin
            ap_sig_allocacmp_conv2221_load_1 = grp_fu_101_p1;
        end else begin
            ap_sig_allocacmp_conv2221_load_1 = conv2221_fu_66;
        end
    end else begin
        ap_sig_allocacmp_conv2221_load_1 = conv2221_fu_66;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter3 == 1'b1))) begin
        conv2221_out_ap_vld = 1'b1;
    end else begin
        conv2221_out_ap_vld = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_pp0_stage0 : begin
            ap_NS_fsm = ap_ST_fsm_pp0_stage0;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign and_ln18_1_fu_307_p2 = (xor_ln1007_fu_208_p2 & icmp_ln1003_4_fu_202_p2);

assign and_ln18_2_fu_313_p2 = (and_ln18_fu_214_p2 & and_ln18_1_fu_307_p2);

assign and_ln18_3_fu_344_p2 = (icmp_ln1007_reg_467 & icmp_ln1003_5_reg_461);

assign and_ln18_4_fu_354_p2 = (xor_ln18_fu_348_p2 & and_ln18_1_fu_307_p2);

assign and_ln18_5_fu_391_p2 = (or_ln18_1_reg_488 & and_ln18_reg_478);

assign and_ln18_fu_214_p2 = (icmp_ln1007_reg_467 & icmp_ln1003_5_reg_461);

assign and_ln25_1_fu_218_p2 = (icmp_ln1003_3_reg_455 & icmp_ln1003_2_reg_449);

assign and_ln25_2_fu_228_p2 = (xor_ln25_fu_222_p2 & and_ln25_fu_196_p2);

assign and_ln25_3_fu_327_p2 = (icmp_ln1003_3_reg_455 & and_ln25_fu_196_p2);

assign and_ln25_4_fu_332_p2 = (icmp_ln1003_2_reg_449 & and_ln25_3_fu_327_p2);

assign and_ln25_fu_196_p2 = (icmp_ln1003_fu_184_p2 & icmp_ln1003_1_fu_190_p2);

assign ap_CS_fsm_pp0_stage0 = ap_CS_fsm[32'd0];

assign ap_block_pp0_stage0 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage0_01001 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage0_11001 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage0_subdone = ~(1'b1 == 1'b1);

assign ap_block_state1_pp0_stage0_iter0 = ~(1'b1 == 1'b1);

assign ap_block_state2_pp0_stage0_iter1 = ~(1'b1 == 1'b1);

assign ap_block_state3_pp0_stage0_iter2 = ~(1'b1 == 1'b1);

assign ap_block_state4_pp0_stage0_iter3 = ~(1'b1 == 1'b1);

assign ap_enable_pp0 = (ap_idle_pp0 ^ 1'b1);

assign ap_enable_reg_pp0_iter0 = ap_start;

assign bitcast_ln483_fu_116_p1 = ap_sig_allocacmp_conv2221_load_1;

assign conv2221_out = ap_sig_allocacmp_conv2221_load;

assign data_V_fu_166_p1 = grp_fu_104_p1;

assign grp_fu_101_p0 = ((and_ln18_5_fu_391_p2[0:0] == 1'b1) ? dc_reg_473 : res_4_reg_483);

assign icmp_ln1003_1_fu_190_p2 = ((tmp_2_fu_180_p1 == 52'd0) ? 1'b1 : 1'b0);

assign icmp_ln1003_2_fu_142_p2 = ((tmp_3_fu_128_p4 == 11'd0) ? 1'b1 : 1'b0);

assign icmp_ln1003_3_fu_148_p2 = ((tmp_4_fu_138_p1 == 52'd0) ? 1'b1 : 1'b0);

assign icmp_ln1003_4_fu_202_p2 = ((tmp_fu_170_p4 == 11'd2047) ? 1'b1 : 1'b0);

assign icmp_ln1003_5_fu_154_p2 = ((tmp_3_fu_128_p4 == 11'd2047) ? 1'b1 : 1'b0);

assign icmp_ln1003_fu_184_p2 = ((tmp_fu_170_p4 == 11'd0) ? 1'b1 : 1'b0);

assign icmp_ln1007_fu_160_p2 = ((tmp_4_fu_138_p1 != 52'd0) ? 1'b1 : 1'b0);

assign or_ln18_1_fu_385_p2 = (xor_ln18_2_fu_379_p2 | and_ln25_2_fu_228_p2);

assign or_ln18_fu_373_p2 = (xor_ln18_1_fu_367_p2 | icmp_ln1003_1_fu_190_p2);

assign p_Result_1_fu_234_p4 = {|(1'd1), tmp_2_fu_180_p1[51 - 1:0]};

assign p_Result_2_fu_244_p4 = {{{p_Result_s_reg_442}, {11'd2047}}, {p_Result_1_fu_234_p4}};

assign p_Result_3_fu_261_p3 = {{p_Result_s_reg_442}, {trunc_ln368_fu_257_p1}};

assign p_Result_4_fu_268_p3 = {{p_Result_6_read_reg_426}, {data_V_2_read_reg_432}};

assign res_1_fu_300_p3 = ((ymaggreater_1_fu_293_p3[0:0] == 1'b1) ? dc_2_read_reg_419 : grp_fu_104_p1);

assign res_2_fu_319_p3 = ((and_ln18_2_fu_313_p2[0:0] == 1'b1) ? res_fu_253_p1 : res_1_fu_300_p3);

assign res_3_fu_337_p3 = ((and_ln25_4_fu_332_p2[0:0] == 1'b1) ? dc_2_read_reg_419 : res_2_fu_319_p3);

assign res_4_fu_360_p3 = ((and_ln18_4_fu_354_p2[0:0] == 1'b1) ? dc_2_read_reg_419 : res_3_fu_337_p3);

assign res_fu_253_p1 = p_Result_2_fu_244_p4;

assign select_ln39_fu_286_p3 = ((p_Result_s_reg_442[0:0] == 1'b1) ? xor_ln39_fu_280_p2 : ymaggreater_fu_274_p2);

assign tmp_2_fu_180_p1 = data_V_fu_166_p1[51:0];

assign tmp_3_fu_128_p4 = {{data_V_2[62:52]}};

assign tmp_4_fu_138_p1 = data_V_2[51:0];

assign tmp_fu_170_p4 = {{data_V_fu_166_p1[62:52]}};

assign trunc_ln368_fu_257_p1 = data_V_fu_166_p1[62:0];

assign xor_ln1007_fu_208_p2 = (icmp_ln1003_1_fu_190_p2 ^ 1'd1);

assign xor_ln18_1_fu_367_p2 = (icmp_ln1003_4_fu_202_p2 ^ 1'd1);

assign xor_ln18_2_fu_379_p2 = (or_ln18_fu_373_p2 ^ and_ln25_fu_196_p2);

assign xor_ln18_fu_348_p2 = (1'd1 ^ and_ln18_3_fu_344_p2);

assign xor_ln25_fu_222_p2 = (1'd1 ^ and_ln25_1_fu_218_p2);

assign xor_ln39_fu_280_p2 = (ymaggreater_fu_274_p2 ^ 1'd1);

assign ymaggreater_1_fu_293_p3 = ((p_Result_6_read_reg_426[0:0] == 1'b1) ? select_ln39_fu_286_p3 : ymaggreater_fu_274_p2);

assign ymaggreater_fu_274_p2 = (($signed(p_Result_3_fu_261_p3) < $signed(p_Result_4_fu_268_p3)) ? 1'b1 : 1'b0);

endmodule //master_maxPool_Pipeline_VITIS_LOOP_83_3
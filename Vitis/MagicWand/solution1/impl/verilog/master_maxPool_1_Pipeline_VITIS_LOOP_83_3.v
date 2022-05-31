// ==============================================================
// RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.1 (64-bit)
// Version: 2021.1
// Copyright (C) Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

module master_maxPool_1_Pipeline_VITIS_LOOP_83_3 (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        out_0_load,
        out_0_address0,
        out_0_ce0,
        out_0_we0,
        out_0_d0,
        arrayidx121_sum_cast,
        empty,
        zext_ln77,
        m_address0,
        m_ce0,
        m_q0
);

parameter    ap_ST_fsm_pp0_stage0 = 3'd1;
parameter    ap_ST_fsm_pp0_stage1 = 3'd2;
parameter    ap_ST_fsm_pp0_stage2 = 3'd4;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
input  [31:0] out_0_load;
output  [8:0] out_0_address0;
output   out_0_ce0;
output   out_0_we0;
output  [31:0] out_0_d0;
input  [8:0] arrayidx121_sum_cast;
input  [8:0] empty;
input  [2:0] zext_ln77;
output  [11:0] m_address0;
output   m_ce0;
input  [31:0] m_q0;

reg ap_idle;
reg out_0_ce0;
reg out_0_we0;
reg m_ce0;

(* fsm_encoding = "none" *) reg   [2:0] ap_CS_fsm;
wire    ap_CS_fsm_pp0_stage0;
reg    ap_enable_reg_pp0_iter0;
reg    ap_enable_reg_pp0_iter1;
reg    ap_idle_pp0;
wire    ap_CS_fsm_pp0_stage1;
wire    ap_block_state2_pp0_stage1_iter0;
wire    ap_block_state5_pp0_stage1_iter1;
wire    ap_block_pp0_stage1_subdone;
reg   [0:0] icmp_ln83_reg_559;
reg    ap_condition_exit_pp0_iter0_stage1;
wire    ap_loop_exit_ready;
reg    ap_ready_int;
wire    ap_CS_fsm_pp0_stage2;
wire    ap_block_state3_pp0_stage2_iter0;
wire    ap_block_pp0_stage2_subdone;
wire    ap_block_state1_pp0_stage0_iter0;
wire    ap_block_state4_pp0_stage0_iter1;
wire    ap_block_pp0_stage0_11001;
reg   [8:0] out_0_addr_reg_554;
reg   [8:0] out_0_addr_reg_554_pp0_iter1_reg;
wire   [0:0] icmp_ln83_fu_164_p2;
wire   [0:0] ifzero_fu_205_p2;
reg   [0:0] ifzero_reg_568;
reg   [0:0] ifzero_reg_568_pp0_iter1_reg;
wire    ap_block_pp0_stage1_11001;
reg   [0:0] p_Result_s_reg_582;
reg   [0:0] p_Result_5_reg_589;
wire   [63:0] grp_fu_135_p1;
reg   [63:0] dc_reg_595;
wire    ap_block_pp0_stage2_11001;
wire   [63:0] grp_fu_138_p1;
reg   [63:0] dc_1_reg_602;
reg    ap_enable_reg_pp0_iter0_reg;
wire   [63:0] arrayidx121_sum_cast_cast_fu_146_p1;
wire    ap_block_pp0_stage0;
wire   [63:0] zext_ln84_fu_200_p1;
reg   [31:0] conv2221_fu_74;
wire   [31:0] grp_fu_131_p1;
reg   [31:0] ap_sig_allocacmp_conv2221_load;
wire    ap_block_pp0_stage1;
wire    ap_loop_init;
reg   [1:0] j_fu_78;
reg   [1:0] ap_sig_allocacmp_j_1;
wire   [1:0] add_ln83_fu_170_p2;
wire   [63:0] grp_fu_131_p0;
wire   [8:0] j_cast_fu_176_p1;
wire   [8:0] tmp3_fu_180_p2;
wire   [11:0] tmp2_fu_186_p3;
wire   [11:0] zext_ln77_cast_fu_142_p1;
wire   [11:0] add_ln84_fu_194_p2;
wire   [31:0] bitcast_ln483_fu_220_p1;
wire   [31:0] bitcast_ln483_2_fu_232_p1;
wire   [63:0] data_V_fu_244_p1;
wire   [63:0] data_V_1_fu_261_p1;
wire   [10:0] tmp_fu_247_p4;
wire   [51:0] tmp_8_fu_257_p1;
wire   [0:0] icmp_ln1003_fu_278_p2;
wire   [0:0] icmp_ln1003_1_fu_284_p2;
wire   [10:0] tmp_9_fu_264_p4;
wire   [51:0] tmp_10_fu_274_p1;
wire   [0:0] icmp_ln1003_5_fu_320_p2;
wire   [0:0] icmp_ln1007_fu_326_p2;
wire   [0:0] icmp_ln1003_2_fu_296_p2;
wire   [0:0] icmp_ln1003_3_fu_302_p2;
wire   [0:0] and_ln25_1_fu_338_p2;
wire   [0:0] and_ln25_fu_290_p2;
wire   [0:0] xor_ln25_fu_344_p2;
wire   [51:0] p_Result_6_fu_356_p4;
wire   [63:0] p_Result_7_fu_366_p4;
wire   [62:0] trunc_ln368_fu_379_p1;
wire   [62:0] trunc_ln368_1_fu_390_p1;
wire   [63:0] p_Result_8_fu_383_p3;
wire   [63:0] p_Result_9_fu_394_p3;
wire   [0:0] ymaggreater_fu_401_p2;
wire   [0:0] xor_ln39_fu_407_p2;
wire   [0:0] select_ln39_fu_413_p3;
wire   [0:0] ymaggreater_2_fu_420_p3;
wire   [0:0] icmp_ln1003_4_fu_308_p2;
wire   [0:0] xor_ln1007_fu_314_p2;
wire   [0:0] and_ln18_1_fu_433_p2;
wire   [0:0] and_ln18_fu_332_p2;
wire   [0:0] and_ln18_2_fu_439_p2;
wire   [63:0] res_fu_375_p1;
wire   [63:0] res_6_fu_427_p3;
wire   [0:0] and_ln25_3_fu_453_p2;
wire   [0:0] and_ln25_4_fu_459_p2;
wire   [63:0] res_7_fu_445_p3;
wire   [0:0] and_ln18_6_fu_472_p2;
wire   [0:0] xor_ln18_fu_478_p2;
wire   [0:0] and_ln18_4_fu_484_p2;
wire   [63:0] res_8_fu_465_p3;
wire   [0:0] xor_ln18_1_fu_497_p2;
wire   [0:0] or_ln18_fu_503_p2;
wire   [0:0] and_ln25_2_fu_350_p2;
wire   [0:0] xor_ln18_2_fu_509_p2;
wire   [0:0] or_ln18_1_fu_515_p2;
wire   [0:0] and_ln18_5_fu_521_p2;
wire   [63:0] res_9_fu_490_p3;
reg    ap_done_reg;
wire    ap_continue_int;
reg    ap_done_int;
reg   [2:0] ap_NS_fsm;
wire    ap_block_pp0_stage0_subdone;
reg    ap_idle_pp0_1to1;
wire    ap_enable_pp0;
wire    ap_start_int;
wire    ap_ce_reg;

// power-on initialization
initial begin
#0 ap_CS_fsm = 3'd1;
#0 ap_enable_reg_pp0_iter1 = 1'b0;
#0 ap_enable_reg_pp0_iter0_reg = 1'b0;
#0 ap_done_reg = 1'b0;
end

master_fptrunc_64ns_32_2_no_dsp_1 #(
    .ID( 1 ),
    .NUM_STAGE( 2 ),
    .din0_WIDTH( 64 ),
    .dout_WIDTH( 32 ))
fptrunc_64ns_32_2_no_dsp_1_U14(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(grp_fu_131_p0),
    .ce(1'b1),
    .dout(grp_fu_131_p1)
);

master_fpext_32ns_64_2_no_dsp_1 #(
    .ID( 1 ),
    .NUM_STAGE( 2 ),
    .din0_WIDTH( 32 ),
    .dout_WIDTH( 64 ))
fpext_32ns_64_2_no_dsp_1_U15(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(ap_sig_allocacmp_conv2221_load),
    .ce(1'b1),
    .dout(grp_fu_135_p1)
);

master_fpext_32ns_64_2_no_dsp_1 #(
    .ID( 1 ),
    .NUM_STAGE( 2 ),
    .din0_WIDTH( 32 ),
    .dout_WIDTH( 64 ))
fpext_32ns_64_2_no_dsp_1_U16(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(m_q0),
    .ce(1'b1),
    .dout(grp_fu_138_p1)
);

master_flow_control_loop_pipe_sequential_init flow_control_loop_pipe_sequential_init_U(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(ap_start),
    .ap_ready(ap_ready),
    .ap_done(ap_done),
    .ap_start_int(ap_start_int),
    .ap_loop_init(ap_loop_init),
    .ap_ready_int(ap_ready_int),
    .ap_loop_exit_ready(ap_condition_exit_pp0_iter0_stage1),
    .ap_loop_exit_done(ap_done_int),
    .ap_continue_int(ap_continue_int),
    .ap_done_int(ap_done_int)
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
        ap_done_reg <= 1'b0;
    end else begin
        if ((ap_continue_int == 1'b1)) begin
            ap_done_reg <= 1'b0;
        end else if (((ap_loop_exit_ready == 1'b1) & (1'b0 == ap_block_pp0_stage1_subdone) & (1'b1 == ap_CS_fsm_pp0_stage1))) begin
            ap_done_reg <= 1'b1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter0_reg <= 1'b0;
    end else begin
        if ((1'b1 == ap_condition_exit_pp0_iter0_stage1)) begin
            ap_enable_reg_pp0_iter0_reg <= 1'b0;
        end else if ((1'b1 == ap_CS_fsm_pp0_stage0)) begin
            ap_enable_reg_pp0_iter0_reg <= ap_start_int;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter1 <= 1'b0;
    end else begin
        if (((1'b0 == ap_block_pp0_stage1_subdone) & (ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage1))) begin
            ap_enable_reg_pp0_iter1 <= 1'b0;
        end else if (((1'b0 == ap_block_pp0_stage2_subdone) & (1'b1 == ap_CS_fsm_pp0_stage2))) begin
            ap_enable_reg_pp0_iter1 <= ap_enable_reg_pp0_iter0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_loop_init == 1'b1))) begin
        conv2221_fu_74 <= out_0_load;
    end else if (((1'b0 == ap_block_pp0_stage1_11001) & (ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage1))) begin
        conv2221_fu_74 <= grp_fu_131_p1;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        if (((ap_enable_reg_pp0_iter0 == 1'b1) & (icmp_ln83_fu_164_p2 == 1'd0))) begin
            j_fu_78 <= add_ln83_fu_170_p2;
        end else if ((ap_loop_init == 1'b1)) begin
            j_fu_78 <= 2'd0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln83_reg_559 == 1'd0) & (1'b0 == ap_block_pp0_stage2_11001) & (1'b1 == ap_CS_fsm_pp0_stage2))) begin
        dc_1_reg_602 <= grp_fu_138_p1;
        dc_reg_595 <= grp_fu_135_p1;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        icmp_ln83_reg_559 <= icmp_ln83_fu_164_p2;
        ifzero_reg_568_pp0_iter1_reg <= ifzero_reg_568;
        out_0_addr_reg_554 <= arrayidx121_sum_cast_cast_fu_146_p1;
        out_0_addr_reg_554_pp0_iter1_reg <= out_0_addr_reg_554;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0) & (icmp_ln83_fu_164_p2 == 1'd0))) begin
        ifzero_reg_568 <= ifzero_fu_205_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln83_reg_559 == 1'd0) & (1'b0 == ap_block_pp0_stage1_11001) & (1'b1 == ap_CS_fsm_pp0_stage1))) begin
        p_Result_5_reg_589 <= bitcast_ln483_2_fu_232_p1[32'd31];
        p_Result_s_reg_582 <= bitcast_ln483_fu_220_p1[32'd31];
    end
end

always @ (*) begin
    if (((icmp_ln83_reg_559 == 1'd1) & (1'b0 == ap_block_pp0_stage1_subdone) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage1))) begin
        ap_condition_exit_pp0_iter0_stage1 = 1'b1;
    end else begin
        ap_condition_exit_pp0_iter0_stage1 = 1'b0;
    end
end

always @ (*) begin
    if (((ap_loop_exit_ready == 1'b1) & (1'b0 == ap_block_pp0_stage1_subdone) & (1'b1 == ap_CS_fsm_pp0_stage1))) begin
        ap_done_int = 1'b1;
    end else begin
        ap_done_int = ap_done_reg;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_pp0_stage0)) begin
        ap_enable_reg_pp0_iter0 = ap_start_int;
    end else begin
        ap_enable_reg_pp0_iter0 = ap_enable_reg_pp0_iter0_reg;
    end
end

always @ (*) begin
    if (((ap_start_int == 1'b0) & (ap_idle_pp0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter1 == 1'b0) & (ap_enable_reg_pp0_iter0 == 1'b0))) begin
        ap_idle_pp0 = 1'b1;
    end else begin
        ap_idle_pp0 = 1'b0;
    end
end

always @ (*) begin
    if ((ap_enable_reg_pp0_iter1 == 1'b0)) begin
        ap_idle_pp0_1to1 = 1'b1;
    end else begin
        ap_idle_pp0_1to1 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage2_subdone) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage2))) begin
        ap_ready_int = 1'b1;
    end else begin
        ap_ready_int = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage1) & (ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage1))) begin
        ap_sig_allocacmp_conv2221_load = grp_fu_131_p1;
    end else begin
        ap_sig_allocacmp_conv2221_load = conv2221_fu_74;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_loop_init == 1'b1))) begin
        ap_sig_allocacmp_j_1 = 2'd0;
    end else begin
        ap_sig_allocacmp_j_1 = j_fu_78;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        m_ce0 = 1'b1;
    end else begin
        m_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage1_11001) & (ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage1))) begin
        out_0_ce0 = 1'b1;
    end else begin
        out_0_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage1_11001) & (ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage1) & (ifzero_reg_568_pp0_iter1_reg == 1'd1))) begin
        out_0_we0 = 1'b1;
    end else begin
        out_0_we0 = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_pp0_stage0 : begin
            if ((~((ap_start_int == 1'b0) & (ap_idle_pp0_1to1 == 1'b1)) & (1'b0 == ap_block_pp0_stage0_subdone))) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end
        end
        ap_ST_fsm_pp0_stage1 : begin
            if ((1'b1 == ap_condition_exit_pp0_iter0_stage1)) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end else if ((1'b0 == ap_block_pp0_stage1_subdone)) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage1;
            end
        end
        ap_ST_fsm_pp0_stage2 : begin
            if ((1'b0 == ap_block_pp0_stage2_subdone)) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage2;
            end
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign add_ln83_fu_170_p2 = (ap_sig_allocacmp_j_1 + 2'd1);

assign add_ln84_fu_194_p2 = (tmp2_fu_186_p3 + zext_ln77_cast_fu_142_p1);

assign and_ln18_1_fu_433_p2 = (xor_ln1007_fu_314_p2 & icmp_ln1003_4_fu_308_p2);

assign and_ln18_2_fu_439_p2 = (and_ln18_fu_332_p2 & and_ln18_1_fu_433_p2);

assign and_ln18_4_fu_484_p2 = (xor_ln18_fu_478_p2 & and_ln18_1_fu_433_p2);

assign and_ln18_5_fu_521_p2 = (or_ln18_1_fu_515_p2 & and_ln18_fu_332_p2);

assign and_ln18_6_fu_472_p2 = (icmp_ln1007_fu_326_p2 & icmp_ln1003_5_fu_320_p2);

assign and_ln18_fu_332_p2 = (icmp_ln1007_fu_326_p2 & icmp_ln1003_5_fu_320_p2);

assign and_ln25_1_fu_338_p2 = (icmp_ln1003_3_fu_302_p2 & icmp_ln1003_2_fu_296_p2);

assign and_ln25_2_fu_350_p2 = (xor_ln25_fu_344_p2 & and_ln25_fu_290_p2);

assign and_ln25_3_fu_453_p2 = (icmp_ln1003_3_fu_302_p2 & and_ln25_fu_290_p2);

assign and_ln25_4_fu_459_p2 = (icmp_ln1003_2_fu_296_p2 & and_ln25_3_fu_453_p2);

assign and_ln25_fu_290_p2 = (icmp_ln1003_fu_278_p2 & icmp_ln1003_1_fu_284_p2);

assign ap_CS_fsm_pp0_stage0 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_pp0_stage1 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_pp0_stage2 = ap_CS_fsm[32'd2];

assign ap_block_pp0_stage0 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage0_11001 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage0_subdone = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage1 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage1_11001 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage1_subdone = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage2_11001 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage2_subdone = ~(1'b1 == 1'b1);

assign ap_block_state1_pp0_stage0_iter0 = ~(1'b1 == 1'b1);

assign ap_block_state2_pp0_stage1_iter0 = ~(1'b1 == 1'b1);

assign ap_block_state3_pp0_stage2_iter0 = ~(1'b1 == 1'b1);

assign ap_block_state4_pp0_stage0_iter1 = ~(1'b1 == 1'b1);

assign ap_block_state5_pp0_stage1_iter1 = ~(1'b1 == 1'b1);

assign ap_enable_pp0 = (ap_idle_pp0 ^ 1'b1);

assign ap_loop_exit_ready = ap_condition_exit_pp0_iter0_stage1;

assign arrayidx121_sum_cast_cast_fu_146_p1 = arrayidx121_sum_cast;

assign bitcast_ln483_2_fu_232_p1 = m_q0;

assign bitcast_ln483_fu_220_p1 = ap_sig_allocacmp_conv2221_load;

assign data_V_1_fu_261_p1 = dc_1_reg_602;

assign data_V_fu_244_p1 = dc_reg_595;

assign grp_fu_131_p0 = ((and_ln18_5_fu_521_p2[0:0] == 1'b1) ? dc_reg_595 : res_9_fu_490_p3);

assign icmp_ln1003_1_fu_284_p2 = ((tmp_8_fu_257_p1 == 52'd0) ? 1'b1 : 1'b0);

assign icmp_ln1003_2_fu_296_p2 = ((tmp_9_fu_264_p4 == 11'd0) ? 1'b1 : 1'b0);

assign icmp_ln1003_3_fu_302_p2 = ((tmp_10_fu_274_p1 == 52'd0) ? 1'b1 : 1'b0);

assign icmp_ln1003_4_fu_308_p2 = ((tmp_fu_247_p4 == 11'd2047) ? 1'b1 : 1'b0);

assign icmp_ln1003_5_fu_320_p2 = ((tmp_9_fu_264_p4 == 11'd2047) ? 1'b1 : 1'b0);

assign icmp_ln1003_fu_278_p2 = ((tmp_fu_247_p4 == 11'd0) ? 1'b1 : 1'b0);

assign icmp_ln1007_fu_326_p2 = ((tmp_10_fu_274_p1 != 52'd0) ? 1'b1 : 1'b0);

assign icmp_ln83_fu_164_p2 = ((ap_sig_allocacmp_j_1 == 2'd3) ? 1'b1 : 1'b0);

assign ifzero_fu_205_p2 = ((add_ln83_fu_170_p2 == 2'd3) ? 1'b1 : 1'b0);

assign j_cast_fu_176_p1 = ap_sig_allocacmp_j_1;

assign m_address0 = zext_ln84_fu_200_p1;

assign or_ln18_1_fu_515_p2 = (xor_ln18_2_fu_509_p2 | and_ln25_2_fu_350_p2);

assign or_ln18_fu_503_p2 = (xor_ln18_1_fu_497_p2 | icmp_ln1003_1_fu_284_p2);

assign out_0_address0 = out_0_addr_reg_554_pp0_iter1_reg;

assign out_0_d0 = grp_fu_131_p1;

assign p_Result_6_fu_356_p4 = {|(1'd1), tmp_8_fu_257_p1[51 - 1:0]};

assign p_Result_7_fu_366_p4 = {{{p_Result_s_reg_582}, {11'd2047}}, {p_Result_6_fu_356_p4}};

assign p_Result_8_fu_383_p3 = {{p_Result_s_reg_582}, {trunc_ln368_fu_379_p1}};

assign p_Result_9_fu_394_p3 = {{p_Result_5_reg_589}, {trunc_ln368_1_fu_390_p1}};

assign res_6_fu_427_p3 = ((ymaggreater_2_fu_420_p3[0:0] == 1'b1) ? dc_1_reg_602 : dc_reg_595);

assign res_7_fu_445_p3 = ((and_ln18_2_fu_439_p2[0:0] == 1'b1) ? res_fu_375_p1 : res_6_fu_427_p3);

assign res_8_fu_465_p3 = ((and_ln25_4_fu_459_p2[0:0] == 1'b1) ? dc_1_reg_602 : res_7_fu_445_p3);

assign res_9_fu_490_p3 = ((and_ln18_4_fu_484_p2[0:0] == 1'b1) ? dc_1_reg_602 : res_8_fu_465_p3);

assign res_fu_375_p1 = p_Result_7_fu_366_p4;

assign select_ln39_fu_413_p3 = ((p_Result_s_reg_582[0:0] == 1'b1) ? xor_ln39_fu_407_p2 : ymaggreater_fu_401_p2);

assign tmp2_fu_186_p3 = {{tmp3_fu_180_p2}, {3'd0}};

assign tmp3_fu_180_p2 = (j_cast_fu_176_p1 + empty);

assign tmp_10_fu_274_p1 = data_V_1_fu_261_p1[51:0];

assign tmp_8_fu_257_p1 = data_V_fu_244_p1[51:0];

assign tmp_9_fu_264_p4 = {{data_V_1_fu_261_p1[62:52]}};

assign tmp_fu_247_p4 = {{data_V_fu_244_p1[62:52]}};

assign trunc_ln368_1_fu_390_p1 = data_V_1_fu_261_p1[62:0];

assign trunc_ln368_fu_379_p1 = data_V_fu_244_p1[62:0];

assign xor_ln1007_fu_314_p2 = (icmp_ln1003_1_fu_284_p2 ^ 1'd1);

assign xor_ln18_1_fu_497_p2 = (icmp_ln1003_4_fu_308_p2 ^ 1'd1);

assign xor_ln18_2_fu_509_p2 = (or_ln18_fu_503_p2 ^ and_ln25_fu_290_p2);

assign xor_ln18_fu_478_p2 = (1'd1 ^ and_ln18_6_fu_472_p2);

assign xor_ln25_fu_344_p2 = (1'd1 ^ and_ln25_1_fu_338_p2);

assign xor_ln39_fu_407_p2 = (ymaggreater_fu_401_p2 ^ 1'd1);

assign ymaggreater_2_fu_420_p3 = ((p_Result_5_reg_589[0:0] == 1'b1) ? select_ln39_fu_413_p3 : ymaggreater_fu_401_p2);

assign ymaggreater_fu_401_p2 = (($signed(p_Result_8_fu_383_p3) < $signed(p_Result_9_fu_394_p3)) ? 1'b1 : 1'b0);

assign zext_ln77_cast_fu_142_p1 = zext_ln77;

assign zext_ln84_fu_200_p1 = add_ln84_fu_194_p2;

endmodule //master_maxPool_1_Pipeline_VITIS_LOOP_83_3
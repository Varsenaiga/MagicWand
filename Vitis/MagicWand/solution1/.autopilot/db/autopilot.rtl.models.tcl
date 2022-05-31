set SynModuleInfo {
  {SRCNAME convolution1.1 MODELNAME convolution1_1 RTLNAME master_convolution1_1
    SUBMODULES {
      {MODELNAME master_fadd_32ns_32ns_32_4_full_dsp_1 RTLNAME master_fadd_32ns_32ns_32_4_full_dsp_1 BINDTYPE op TYPE fadd IMPL fulldsp LATENCY 3 ALLOW_PRAGMA 1}
      {MODELNAME master_fmul_32ns_32ns_32_3_max_dsp_1 RTLNAME master_fmul_32ns_32ns_32_3_max_dsp_1 BINDTYPE op TYPE fmul IMPL maxdsp LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME master_fcmp_32ns_32ns_1_2_no_dsp_1 RTLNAME master_fcmp_32ns_32ns_1_2_no_dsp_1 BINDTYPE op TYPE fcmp IMPL auto LATENCY 1 ALLOW_PRAGMA 1}
      {MODELNAME master_convolution1_1_firstKernel RTLNAME master_convolution1_1_firstKernel BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME master_convolution1_1_firstBias RTLNAME master_convolution1_1_firstBias BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME maxPool.1 MODELNAME maxPool_1 RTLNAME master_maxPool_1
    SUBMODULES {
      {MODELNAME master_fptrunc_64ns_32_2_no_dsp_1 RTLNAME master_fptrunc_64ns_32_2_no_dsp_1 BINDTYPE op TYPE fptrunc IMPL auto LATENCY 1 ALLOW_PRAGMA 1}
      {MODELNAME master_fpext_32ns_64_2_no_dsp_1 RTLNAME master_fpext_32ns_64_2_no_dsp_1 BINDTYPE op TYPE fpext IMPL auto LATENCY 1 ALLOW_PRAGMA 1}
      {MODELNAME master_mul_7ns_9ns_15_1_1 RTLNAME master_mul_7ns_9ns_15_1_1 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME master_urem_7ns_3ns_2_11_seq_1 RTLNAME master_urem_7ns_3ns_2_11_seq_1 BINDTYPE op TYPE urem IMPL auto_seq LATENCY 10 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME convolution2 MODELNAME convolution2 RTLNAME master_convolution2
    SUBMODULES {
      {MODELNAME master_convolution2_secondBias RTLNAME master_convolution2_secondBias BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME master_convolution2_secondKernel RTLNAME master_convolution2_secondKernel BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME maxPool MODELNAME maxPool RTLNAME master_maxPool}
  {SRCNAME master_Pipeline_VITIS_LOOP_143_2 MODELNAME master_Pipeline_VITIS_LOOP_143_2 RTLNAME master_master_Pipeline_VITIS_LOOP_143_2
    SUBMODULES {
      {MODELNAME master_ddiv_64ns_64ns_64_17_no_dsp_1 RTLNAME master_ddiv_64ns_64ns_64_17_no_dsp_1 BINDTYPE op TYPE ddiv IMPL fabric LATENCY 16 ALLOW_PRAGMA 1}
      {MODELNAME master_dexp_64ns_64ns_64_11_full_dsp_1 RTLNAME master_dexp_64ns_64ns_64_11_full_dsp_1 BINDTYPE op TYPE dexp IMPL fulldsp LATENCY 10 ALLOW_PRAGMA 1}
      {MODELNAME master_mux_42_32_1_1 RTLNAME master_mux_42_32_1_1 BINDTYPE op TYPE mux IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME master_flow_control_loop_pipe_sequential_init RTLNAME master_flow_control_loop_pipe_sequential_init BINDTYPE interface TYPE internal_upc_flow_control INSTNAME master_flow_control_loop_pipe_sequential_init_U}
    }
  }
  {SRCNAME master MODELNAME master RTLNAME master IS_TOP 1
    SUBMODULES {
      {MODELNAME master_dadd_64ns_64ns_64_5_full_dsp_1 RTLNAME master_dadd_64ns_64ns_64_5_full_dsp_1 BINDTYPE op TYPE dadd IMPL fulldsp LATENCY 4 ALLOW_PRAGMA 1}
      {MODELNAME master_thirdBias RTLNAME master_thirdBias BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME master_firstDense RTLNAME master_firstDense BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME master_secondDense RTLNAME master_secondDense BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME master_conv1 RTLNAME master_conv1 BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME master_max1_0 RTLNAME master_max1_0 BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME master_conv2_0 RTLNAME master_conv2_0 BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME master_max2_0 RTLNAME master_max2_0 BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME master_den1_0 RTLNAME master_den1_0 BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
    }
  }
}

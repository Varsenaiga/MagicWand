set moduleName convolution2
set isTopModule 0
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {convolution2}
set C_modelType { void 0 }
set C_modelArgList {
	{ m_0 float 32 regular {array 336 { 1 1 } 1 1 }  }
	{ out_0 float 32 regular {array 672 { 0 3 } 0 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "m_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "out_0", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 34
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ m_0_address0 sc_out sc_lv 9 signal 0 } 
	{ m_0_ce0 sc_out sc_logic 1 signal 0 } 
	{ m_0_q0 sc_in sc_lv 32 signal 0 } 
	{ m_0_address1 sc_out sc_lv 9 signal 0 } 
	{ m_0_ce1 sc_out sc_logic 1 signal 0 } 
	{ m_0_q1 sc_in sc_lv 32 signal 0 } 
	{ out_0_address0 sc_out sc_lv 10 signal 1 } 
	{ out_0_ce0 sc_out sc_logic 1 signal 1 } 
	{ out_0_we0 sc_out sc_logic 1 signal 1 } 
	{ out_0_d0 sc_out sc_lv 32 signal 1 } 
	{ grp_fu_371_p_din0 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_371_p_din1 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_371_p_opcode sc_out sc_lv 2 signal -1 } 
	{ grp_fu_371_p_dout0 sc_in sc_lv 32 signal -1 } 
	{ grp_fu_371_p_ce sc_out sc_logic 1 signal -1 } 
	{ grp_fu_377_p_din0 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_377_p_din1 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_377_p_dout0 sc_in sc_lv 32 signal -1 } 
	{ grp_fu_377_p_ce sc_out sc_logic 1 signal -1 } 
	{ grp_fu_1002_p_din0 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_1002_p_din1 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_1002_p_dout0 sc_in sc_lv 32 signal -1 } 
	{ grp_fu_1002_p_ce sc_out sc_logic 1 signal -1 } 
	{ grp_fu_388_p_din0 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_388_p_din1 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_388_p_opcode sc_out sc_lv 5 signal -1 } 
	{ grp_fu_388_p_dout0 sc_in sc_lv 1 signal -1 } 
	{ grp_fu_388_p_ce sc_out sc_logic 1 signal -1 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "m_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":9, "type": "signal", "bundle":{"name": "m_0", "role": "address0" }} , 
 	{ "name": "m_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "m_0", "role": "ce0" }} , 
 	{ "name": "m_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "m_0", "role": "q0" }} , 
 	{ "name": "m_0_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":9, "type": "signal", "bundle":{"name": "m_0", "role": "address1" }} , 
 	{ "name": "m_0_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "m_0", "role": "ce1" }} , 
 	{ "name": "m_0_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "m_0", "role": "q1" }} , 
 	{ "name": "out_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "out_0", "role": "address0" }} , 
 	{ "name": "out_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "out_0", "role": "ce0" }} , 
 	{ "name": "out_0_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "out_0", "role": "we0" }} , 
 	{ "name": "out_0_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "out_0", "role": "d0" }} , 
 	{ "name": "grp_fu_371_p_din0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_371_p_din0", "role": "default" }} , 
 	{ "name": "grp_fu_371_p_din1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_371_p_din1", "role": "default" }} , 
 	{ "name": "grp_fu_371_p_opcode", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "grp_fu_371_p_opcode", "role": "default" }} , 
 	{ "name": "grp_fu_371_p_dout0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_371_p_dout0", "role": "default" }} , 
 	{ "name": "grp_fu_371_p_ce", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_371_p_ce", "role": "default" }} , 
 	{ "name": "grp_fu_377_p_din0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_377_p_din0", "role": "default" }} , 
 	{ "name": "grp_fu_377_p_din1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_377_p_din1", "role": "default" }} , 
 	{ "name": "grp_fu_377_p_dout0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_377_p_dout0", "role": "default" }} , 
 	{ "name": "grp_fu_377_p_ce", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_377_p_ce", "role": "default" }} , 
 	{ "name": "grp_fu_1002_p_din0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_1002_p_din0", "role": "default" }} , 
 	{ "name": "grp_fu_1002_p_din1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_1002_p_din1", "role": "default" }} , 
 	{ "name": "grp_fu_1002_p_dout0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_1002_p_dout0", "role": "default" }} , 
 	{ "name": "grp_fu_1002_p_ce", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_1002_p_ce", "role": "default" }} , 
 	{ "name": "grp_fu_388_p_din0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_388_p_din0", "role": "default" }} , 
 	{ "name": "grp_fu_388_p_din1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_388_p_din1", "role": "default" }} , 
 	{ "name": "grp_fu_388_p_opcode", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "grp_fu_388_p_opcode", "role": "default" }} , 
 	{ "name": "grp_fu_388_p_dout0", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_388_p_dout0", "role": "default" }} , 
 	{ "name": "grp_fu_388_p_ce", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_388_p_ce", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2"],
		"CDFG" : "convolution2",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "46417", "EstimateLatencyMax" : "154609",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "m_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "out_0", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "secondBias", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "secondKernel", "Type" : "Memory", "Direction" : "I"}],
		"Loop" : [
			{"Name" : "VITIS_LOOP_54_4", "PipelineType" : "no",
				"LoopDec" : {"FSMBitwidth" : "42", "FirstState" : "ap_ST_fsm_state5", "LastState" : ["ap_ST_fsm_state12"], "QuitState" : ["ap_ST_fsm_state5"], "PreState" : ["ap_ST_fsm_state4"], "PostState" : ["ap_ST_fsm_state13"], "OneDepthLoop" : "0", "OneStateBlock": ""}},
			{"Name" : "VITIS_LOOP_59_5", "PipelineType" : "no",
				"LoopDec" : {"FSMBitwidth" : "42", "FirstState" : "ap_ST_fsm_state13", "LastState" : ["ap_ST_fsm_state20"], "QuitState" : ["ap_ST_fsm_state13"], "PreState" : ["ap_ST_fsm_state5"], "PostState" : ["ap_ST_fsm_state41", "ap_ST_fsm_state21", "ap_ST_fsm_state29"], "OneDepthLoop" : "0", "OneStateBlock": ""}},
			{"Name" : "VITIS_LOOP_64_6", "PipelineType" : "no",
				"LoopDec" : {"FSMBitwidth" : "42", "FirstState" : "ap_ST_fsm_state29", "LastState" : ["ap_ST_fsm_state40"], "QuitState" : ["ap_ST_fsm_state29"], "PreState" : ["ap_ST_fsm_state13"], "PostState" : ["ap_ST_fsm_state41"], "OneDepthLoop" : "0", "OneStateBlock": ""}},
			{"Name" : "VITIS_LOOP_68_7", "PipelineType" : "no",
				"LoopDec" : {"FSMBitwidth" : "42", "FirstState" : "ap_ST_fsm_state21", "LastState" : ["ap_ST_fsm_state28"], "QuitState" : ["ap_ST_fsm_state21"], "PreState" : ["ap_ST_fsm_state13"], "PostState" : ["ap_ST_fsm_state41"], "OneDepthLoop" : "0", "OneStateBlock": ""}},
			{"Name" : "VITIS_LOOP_48_2", "PipelineType" : "no",
				"LoopDec" : {"FSMBitwidth" : "42", "FirstState" : "ap_ST_fsm_state4", "LastState" : ["ap_ST_fsm_state42"], "QuitState" : ["ap_ST_fsm_state4"], "PreState" : ["ap_ST_fsm_state3"], "PostState" : ["ap_ST_fsm_state2"], "OneDepthLoop" : "0", "OneStateBlock": ""}},
			{"Name" : "VITIS_LOOP_46_1", "PipelineType" : "no",
				"LoopDec" : {"FSMBitwidth" : "42", "FirstState" : "ap_ST_fsm_state2", "LastState" : ["ap_ST_fsm_state4"], "QuitState" : ["ap_ST_fsm_state2"], "PreState" : ["ap_ST_fsm_state1"], "PostState" : ["ap_ST_fsm_state1"], "OneDepthLoop" : "0", "OneStateBlock": ""}}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.secondBias_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.secondKernel_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	convolution2 {
		m_0 {Type I LastRead 7 FirstWrite -1}
		out_0 {Type O LastRead -1 FirstWrite 4}
		secondBias {Type I LastRead -1 FirstWrite -1}
		secondKernel {Type I LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "46417", "Max" : "154609"}
	, {"Name" : "Interval", "Min" : "46417", "Max" : "154609"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	m_0 { ap_memory {  { m_0_address0 mem_address 1 9 }  { m_0_ce0 mem_ce 1 1 }  { m_0_q0 mem_dout 0 32 }  { m_0_address1 MemPortADDR2 1 9 }  { m_0_ce1 MemPortCE2 1 1 }  { m_0_q1 MemPortDOUT2 0 32 } } }
	out_0 { ap_memory {  { out_0_address0 mem_address 1 10 }  { out_0_ce0 mem_ce 1 1 }  { out_0_we0 mem_we 1 1 }  { out_0_d0 mem_din 1 32 } } }
}

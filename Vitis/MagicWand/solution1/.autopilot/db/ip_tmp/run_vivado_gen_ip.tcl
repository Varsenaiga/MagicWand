create_project prj -part xczu7ev-ffvf1517-3-e -force
set_property target_language verilog [current_project]
set vivado_ver [version -short]
set COE_DIR "../../syn/verilog"
source "C:/Users/tiago/OneDrive/Desktop/Universidade/Tese/Dissertacao/MagicWand/Vitis/MagicWand/solution1/syn/verilog/master_dadd_64ns_64ns_64_5_full_dsp_1_ip.tcl"
source "C:/Users/tiago/OneDrive/Desktop/Universidade/Tese/Dissertacao/MagicWand/Vitis/MagicWand/solution1/syn/verilog/master_ddiv_64ns_64ns_64_17_no_dsp_1_ip.tcl"
source "C:/Users/tiago/OneDrive/Desktop/Universidade/Tese/Dissertacao/MagicWand/Vitis/MagicWand/solution1/syn/verilog/master_dexp_64ns_64ns_64_11_full_dsp_1_ip.tcl"
source "C:/Users/tiago/OneDrive/Desktop/Universidade/Tese/Dissertacao/MagicWand/Vitis/MagicWand/solution1/syn/verilog/master_fadd_32ns_32ns_32_4_full_dsp_1_ip.tcl"
source "C:/Users/tiago/OneDrive/Desktop/Universidade/Tese/Dissertacao/MagicWand/Vitis/MagicWand/solution1/syn/verilog/master_fcmp_32ns_32ns_1_2_no_dsp_1_ip.tcl"
source "C:/Users/tiago/OneDrive/Desktop/Universidade/Tese/Dissertacao/MagicWand/Vitis/MagicWand/solution1/syn/verilog/master_fmul_32ns_32ns_32_3_max_dsp_1_ip.tcl"
source "C:/Users/tiago/OneDrive/Desktop/Universidade/Tese/Dissertacao/MagicWand/Vitis/MagicWand/solution1/syn/verilog/master_fpext_32ns_64_2_no_dsp_1_ip.tcl"
source "C:/Users/tiago/OneDrive/Desktop/Universidade/Tese/Dissertacao/MagicWand/Vitis/MagicWand/solution1/syn/verilog/master_fptrunc_64ns_32_2_no_dsp_1_ip.tcl"

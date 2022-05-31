# This script segment is generated automatically by AutoPilot

set name master_fadd_32ns_32ns_32_4_full_dsp_1
if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler $name BINDTYPE {op} TYPE {fadd} IMPL {fulldsp} LATENCY 3 ALLOW_PRAGMA 1
}


set name master_fmul_32ns_32ns_32_3_max_dsp_1
if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler $name BINDTYPE {op} TYPE {fmul} IMPL {maxdsp} LATENCY 2 ALLOW_PRAGMA 1
}


set name master_fcmp_32ns_32ns_1_2_no_dsp_1
if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler $name BINDTYPE {op} TYPE {fcmp} IMPL {auto} LATENCY 1 ALLOW_PRAGMA 1
}


# Memory (RAM/ROM)  definition:
set ID 8
set hasByteEnable 0
set MemName master_convolution1_1_firstKernel
set CoreName ap_simcore_mem
set PortList { 1 1 1 1 1 1 1 1 1 1 1 1 }
set DataWd 32
set AddrRange 96
set AddrWd 7
set impl_style auto
set TrueReset 0
set IsROM 1
set ROMData { "10111101111101100110101000011100" "10111011101111001101110111000111" "00111110010001101111000100001111" "10111100001001110001000111010110" "10111101101000011010000101110100" "00111101101011011101111000010111" "10111100111010000100101110110101" "00111100101001011011100101111110" "00111101001010101010001100111110" "00111101100100101010011101011010" "10111101101011101101111111100011" "10111101110110100000111011110001" "00111100111111010001011010101010" "10111110001001001001110010000111" "10111111000000101011110100011100" "00111101111100110111111011001100" "10111110000111010100100011000111" "10111101011101001110111011010111" "10111110010111000000010101001000" "00111110010010010111000001001110" "00111101001100010111001110100001" "10111110001101010110000010111000" "10111110010110010101111010000000" "10111110101110000000100101001000" "00111110001000001101100111110110" "10111101011010100000100001110010" "00111110000001111011110001010110" "00111101101010100100110111110011" "00111011101100100101001100111010" "00111101110000100101110010110110" "00111110000011011111101010101111" "10111110000100101111111000111001" "10111101000000111100011111001000" "00111101100011111101111110100111" "10111101110000000001010110001000" "10111110010011011110001010101101" "00111101110111011111100001100100" "00111110011000010001101100010000" "10111110001110011001001001100011" "00111110001010001000101010111100" "10111101101001010101000110010010" "10111110011001011000100100011100" "00111101101001001000010001110100" "10111110000000011000101111111010" "10111101101011110111000100000111" "00111110010000101111110010111100" "10111101101010101000011011101010" "10111110100110010010011001101001" "10111110100000101100000000000111" "10111110000110000100100101111001" "00111110100001001101111001001110" "10111101110110101011010110100010" "10111101001111001100010001101010" "00111110010010001100010011111101" "00111110000001001000010001001100" "10111100111001101000111010111001" "10111110001010110110101110110010" "10111100011111011000011001000010" "00111101011001000100101000111011" "10111110110011010011110010000110" "10111101001110001010001110011110" "10111110100010000000100111011010" "10111101100010000011100001100100" "10111101101101100001101010010010" "10111101011011010110000111011011" "00111101000100110010100110110010" "00111100101110100111101000001001" "10111101101100110010111111001000" "10111110000111111100001000000110" "00111100110110001101000000111010" "10111110010000100010010110001001" "10111101010011101110011000000101" "00111101101000010100000100010011" "00111101010011010111000000101101" "10111101110000110011001010100000" "00111101101100010100100110011010" "10111110000000111001111101111000" "00111101000100110101011011001100" "00111110000001111010011010110011" "10111101100111100010101100011011" "10111110001100001011111100111011" "10111100010000000100010111101010" "10111110100100110010100111000010" "00111101111110111000111111011011" "10111101100100001000000110110000" "10111101100111100100101001011100" "10111110101101111001010000001111" "00111101000111001001001111111100" "10111101001100000001111101000000" "10111100000110111100111011111000" "00111101111001011110010101111101" "00111101000011100111111111100111" "00111110001000100101000101111110" "10110111100111011101001100000100" "00111110000000001000010101100010" "00111110100101111111010111000110" }
set HasInitializer 1
set Initializer $ROMData
set NumOfStage 2
set DelayBudget 1.099
set ClkPeriod 10
if {${::AESL::PGuard_simmodel_gen}} {
if {[info proc ap_gen_simcore_mem] == "ap_gen_simcore_mem"} {
    eval "ap_gen_simcore_mem { \
    id ${ID} \
    name ${MemName} \
    corename ${CoreName}  \
    op mem  \
    hasByteEnable ${hasByteEnable} \
    reset_level 1 \
    sync_rst true \
    stage_num ${NumOfStage}  \
    port_num 12 \
    port_list \{${PortList}\} \
    data_wd ${DataWd} \
    addr_wd ${AddrWd} \
    addr_range ${AddrRange} \
    style ${impl_style} \
    true_reset ${TrueReset} \
    delay_budget ${DelayBudget} \
    clk_period ${ClkPeriod} \
    HasInitializer ${HasInitializer} \
    rom_data \{${ROMData}\} \
 } "
} else {
    puts "@W \[IMPL-102\] Cannot find ap_gen_simcore_mem, check your platform lib"
}
}


if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler $MemName BINDTYPE {storage} TYPE {rom} IMPL {auto} LATENCY 2 ALLOW_PRAGMA 1
}


set CoreName ROM
if {${::AESL::PGuard_autocg_gen} && ${::AESL::PGuard_autocg_ipmgen}} {
if {[info proc ::AESL_LIB_VIRTEX::xil_gen_ROM] == "::AESL_LIB_VIRTEX::xil_gen_ROM"} {
    eval "::AESL_LIB_VIRTEX::xil_gen_ROM { \
    id ${ID} \
    name ${MemName} \
    corename ${CoreName}  \
    op mem  \
    hasByteEnable ${hasByteEnable} \
    reset_level 1 \
    sync_rst true \
    stage_num ${NumOfStage}  \
    port_num 12 \
    port_list \{${PortList}\} \
    data_wd ${DataWd} \
    addr_wd ${AddrWd} \
    addr_range ${AddrRange} \
    style ${impl_style} \
    true_reset ${TrueReset} \
    delay_budget ${DelayBudget} \
    clk_period ${ClkPeriod} \
    HasInitializer ${HasInitializer} \
    rom_data \{${ROMData}\} \
 } "
  } else {
    puts "@W \[IMPL-104\] Cannot find ::AESL_LIB_VIRTEX::xil_gen_ROM, check your platform lib"
  }
}


# Memory (RAM/ROM)  definition:
set ID 9
set hasByteEnable 0
set MemName master_convolution1_1_firstBias
set CoreName ap_simcore_mem
set PortList { 1 }
set DataWd 32
set AddrRange 8
set AddrWd 3
set impl_style auto
set TrueReset 0
set IsROM 1
set ROMData { "11000000001111101110010111100100" "00111111100100101110011100100010" "10111111110111100000010001010111" "00111110000111001000111111011010" "11000000000001011011111101000111" "10111111110010111010101101010011" "10111111011010100110101001101000" "10111111111001000000101111010010" }
set HasInitializer 1
set Initializer $ROMData
set NumOfStage 2
set DelayBudget 0.614
set ClkPeriod 10
if {${::AESL::PGuard_simmodel_gen}} {
if {[info proc ap_gen_simcore_mem] == "ap_gen_simcore_mem"} {
    eval "ap_gen_simcore_mem { \
    id ${ID} \
    name ${MemName} \
    corename ${CoreName}  \
    op mem  \
    hasByteEnable ${hasByteEnable} \
    reset_level 1 \
    sync_rst true \
    stage_num ${NumOfStage}  \
    port_num 1 \
    port_list \{${PortList}\} \
    data_wd ${DataWd} \
    addr_wd ${AddrWd} \
    addr_range ${AddrRange} \
    style ${impl_style} \
    true_reset ${TrueReset} \
    delay_budget ${DelayBudget} \
    clk_period ${ClkPeriod} \
    HasInitializer ${HasInitializer} \
    rom_data \{${ROMData}\} \
 } "
} else {
    puts "@W \[IMPL-102\] Cannot find ap_gen_simcore_mem, check your platform lib"
}
}


if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler $MemName BINDTYPE {storage} TYPE {rom} IMPL {auto} LATENCY 2 ALLOW_PRAGMA 1
}


set CoreName ROM
if {${::AESL::PGuard_autocg_gen} && ${::AESL::PGuard_autocg_ipmgen}} {
if {[info proc ::AESL_LIB_VIRTEX::xil_gen_ROM] == "::AESL_LIB_VIRTEX::xil_gen_ROM"} {
    eval "::AESL_LIB_VIRTEX::xil_gen_ROM { \
    id ${ID} \
    name ${MemName} \
    corename ${CoreName}  \
    op mem  \
    hasByteEnable ${hasByteEnable} \
    reset_level 1 \
    sync_rst true \
    stage_num ${NumOfStage}  \
    port_num 1 \
    port_list \{${PortList}\} \
    data_wd ${DataWd} \
    addr_wd ${AddrWd} \
    addr_range ${AddrRange} \
    style ${impl_style} \
    true_reset ${TrueReset} \
    delay_budget ${DelayBudget} \
    clk_period ${ClkPeriod} \
    HasInitializer ${HasInitializer} \
    rom_data \{${ROMData}\} \
 } "
  } else {
    puts "@W \[IMPL-104\] Cannot find ::AESL_LIB_VIRTEX::xil_gen_ROM, check your platform lib"
  }
}


# clear list
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_begin
    cg_default_interface_gen_bundle_begin
    AESL_LIB_XILADAPTER::native_axis_begin
}

# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 10 \
    name input_r \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename input_r \
    op interface \
    ports { input_r_address0 { O 9 vector } input_r_ce0 { O 1 bit } input_r_q0 { I 32 vector } input_r_address1 { O 9 vector } input_r_ce1 { O 1 bit } input_r_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'input_r'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 11 \
    name out_r \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename out_r \
    op interface \
    ports { out_r_address0 { O 12 vector } out_r_ce0 { O 1 bit } out_r_we0 { O 1 bit } out_r_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'out_r'"
}
}


# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id -1 \
    name ap_ctrl \
    type ap_ctrl \
    reset_level 1 \
    sync_rst true \
    corename ap_ctrl \
    op interface \
    ports { ap_start { I 1 bit } ap_ready { O 1 bit } ap_done { O 1 bit } ap_idle { O 1 bit } } \
} "
}


# Adapter definition:
set PortName ap_clk
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_clock] == "cg_default_interface_gen_clock"} {
eval "cg_default_interface_gen_clock { \
    id -2 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_clk \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-113\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}


# Adapter definition:
set PortName ap_rst
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_reset] == "cg_default_interface_gen_reset"} {
eval "cg_default_interface_gen_reset { \
    id -3 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_rst \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-114\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}



# merge
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_end
    cg_default_interface_gen_bundle_end
    AESL_LIB_XILADAPTER::native_axis_end
}



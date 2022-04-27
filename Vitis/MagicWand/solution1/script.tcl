############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
############################################################
open_project MagicWand
set_top master
add_files MagicWand/file.c
add_files MagicWand/file.h
add_files MagicWand/master.c
add_files MagicWand/master.h
add_files MagicWand/model_functions.c
add_files MagicWand/model_functions.h
add_files MagicWand/parameters.h
add_files MagicWand/utils.c
add_files MagicWand/utils.h
add_files -tb MagicWand/main.c -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1" -flow_target vivado
set_part {xczu7ev-ffvf1517-3-e}
create_clock -period 10 -name default
source "./MagicWand/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog

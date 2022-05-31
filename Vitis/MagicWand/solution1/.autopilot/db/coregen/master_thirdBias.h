// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.1 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __master_thirdBias_H__
#define __master_thirdBias_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct master_thirdBias_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 32;
  static const unsigned AddressRange = 16;
  static const unsigned AddressWidth = 4;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(master_thirdBias_ram) {
        ram[0] = "0b00111111100100111010100110101001";
        ram[1] = "0b10111110001000011101101000111100";
        ram[2] = "0b00111101001111011110001100110011";
        ram[3] = "0b10111111001100111110110111011000";
        ram[4] = "0b10111111001111101001110101001100";
        ram[5] = "0b00111111101001100100000010111010";
        ram[6] = "0b10111110001001010100111001101110";
        ram[7] = "0b00111111100100110101111001101110";
        ram[8] = "0b10111110110001011010001001001000";
        ram[9] = "0b00111110001100111010101001100111";
        ram[10] = "0b00111111001000000110011011000000";
        ram[11] = "0b10111110011111100010010110110011";
        ram[12] = "0b10111110110110010010111110001010";
        ram[13] = "0b00111111110010000110010011011010";
        ram[14] = "0b10111101100010010001010000011010";
        ram[15] = "0b00111110100010010100100011101010";


SC_METHOD(prc_write_0);
  sensitive<<clk.pos();
   }


void prc_write_0()
{
    if (ce0.read() == sc_dt::Log_1) 
    {
            if(address0.read().is_01() && address0.read().to_uint()<AddressRange)
              q0 = ram[address0.read().to_uint()];
            else
              q0 = sc_lv<DataWidth>();
    }
}


}; //endmodule


SC_MODULE(master_thirdBias) {


static const unsigned DataWidth = 32;
static const unsigned AddressRange = 16;
static const unsigned AddressWidth = 4;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


master_thirdBias_ram* meminst;


SC_CTOR(master_thirdBias) {
meminst = new master_thirdBias_ram("master_thirdBias_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~master_thirdBias() {
    delete meminst;
}


};//endmodule
#endif

// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.1 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __master_convolution1_1_firstBias_H__
#define __master_convolution1_1_firstBias_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct master_convolution1_1_firstBias_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 32;
  static const unsigned AddressRange = 8;
  static const unsigned AddressWidth = 3;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(master_convolution1_1_firstBias_ram) {
        ram[0] = "0b11000000001111101110010111100100";
        ram[1] = "0b00111111100100101110011100100010";
        ram[2] = "0b10111111110111100000010001010111";
        ram[3] = "0b00111110000111001000111111011010";
        ram[4] = "0b11000000000001011011111101000111";
        ram[5] = "0b10111111110010111010101101010011";
        ram[6] = "0b10111111011010100110101001101000";
        ram[7] = "0b10111111111001000000101111010010";


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


SC_MODULE(master_convolution1_1_firstBias) {


static const unsigned DataWidth = 32;
static const unsigned AddressRange = 8;
static const unsigned AddressWidth = 3;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


master_convolution1_1_firstBias_ram* meminst;


SC_CTOR(master_convolution1_1_firstBias) {
meminst = new master_convolution1_1_firstBias_ram("master_convolution1_1_firstBias_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~master_convolution1_1_firstBias() {
    delete meminst;
}


};//endmodule
#endif

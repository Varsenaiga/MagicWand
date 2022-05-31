// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.1 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __master_convolution2_secondBias_H__
#define __master_convolution2_secondBias_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct master_convolution2_secondBias_ram : public sc_core::sc_module {

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


   SC_CTOR(master_convolution2_secondBias_ram) {
        ram[0] = "0b00111110101101110001010110100011";
        ram[1] = "0b00111111100101010110011100101001";
        ram[2] = "0b10111110011000101001011001001011";
        ram[3] = "0b00111110111111000101111101100001";
        ram[4] = "0b10111111001111101101010010100010";
        ram[5] = "0b10111111000011010001110001000101";
        ram[6] = "0b10111110011100001101110100101001";
        ram[7] = "0b10111111100101110111010110011010";
        ram[8] = "0b10111110011011110000101011111100";
        ram[9] = "0b00111111001001010101011011001100";
        ram[10] = "0b10111111100110001010110011011111";
        ram[11] = "0b10111111100010110001110000001110";
        ram[12] = "0b00111111100011001101100010100101";
        ram[13] = "0b00111100110101010100001010100101";
        ram[14] = "0b10111111011110101000111010101001";
        ram[15] = "0b10111110011100011101101110011110";


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


SC_MODULE(master_convolution2_secondBias) {


static const unsigned DataWidth = 32;
static const unsigned AddressRange = 16;
static const unsigned AddressWidth = 4;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


master_convolution2_secondBias_ram* meminst;


SC_CTOR(master_convolution2_secondBias) {
meminst = new master_convolution2_secondBias_ram("master_convolution2_secondBias_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~master_convolution2_secondBias() {
    delete meminst;
}


};//endmodule
#endif

// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.1 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __master_secondDense_H__
#define __master_secondDense_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct master_secondDense_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 32;
  static const unsigned AddressRange = 64;
  static const unsigned AddressWidth = 6;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(master_secondDense_ram) {
        ram[0] = "0b10111110100010100101110001000000";
        ram[1] = "0b00111110101010101000100011000101";
        ram[2] = "0b10111110000111110111011010110000";
        ram[3] = "0b00111110010110000011101000110101";
        ram[4] = "0b00111110101000111010010110000100";
        ram[5] = "0b00111101010010011101100100111000";
        ram[6] = "0b10111100011110000110001101011000";
        ram[7] = "0b10111110001011101001010010000010";
        ram[8] = "0b10111110011011101101111010010111";
        ram[9] = "0b10111110100111110010011111101010";
        ram[10] = "0b00111101110000000010010000011101";
        ram[11] = "0b00111100011001100011000100100001";
        ram[12] = "0b10111110100010001111100010000000";
        ram[13] = "0b10111110000110010000011011011101";
        ram[14] = "0b10111110101100110100101100111111";
        ram[15] = "0b00111110100011011101110001110000";
        ram[16] = "0b10111110100100111110111000100000";
        ram[17] = "0b10111110101111110111110011011110";
        ram[18] = "0b10111110010100000011101011011010";
        ram[19] = "0b00111110011011101001000100001110";
        ram[20] = "0b00111110100000011011110000011000";
        ram[21] = "0b10111001111111101001110000011000";
        ram[22] = "0b10111110100110110010110100010001";
        ram[23] = "0b10111110001111110111001110100010";
        ram[24] = "0b10111110101000110110110000001100";
        ram[25] = "0b10111110100011000100101100110111";
        ram[26] = "0b00111101101000000010011010010001";
        ram[27] = "0b00111110101111010000010010110011";
        ram[28] = "0b10111110011100000011111000000001";
        ram[29] = "0b10111110011010011101101111010001";
        ram[30] = "0b10111110100110001100000010110100";
        ram[31] = "0b00111110100000001101100111010100";
        ram[32] = "0b10111110011101001010100101100010";
        ram[33] = "0b10111110100000111110100110001010";
        ram[34] = "0b10111110010101001001001001111010";
        ram[35] = "0b00111110010000110101110110010010";
        ram[36] = "0b00111110011110110011010111100011";
        ram[37] = "0b00111101001011101000000111101110";
        ram[38] = "0b00111101111011000110100010111011";
        ram[39] = "0b10111110000110110111001001110000";
        ram[40] = "0b10111110101001000010000001100100";
        ram[41] = "0b10111101100011010001111101001111";
        ram[42] = "0b00111101111110001101011011101110";
        ram[43] = "0b00111110101100001000001111011011";
        ram[44] = "0b10111110100011001001100111010001";
        ram[45] = "0b10111110010001010010000110011001";
        ram[46] = "0b10111110100000100000010010010111";
        ram[47] = "0b00111110100010001101111100100101";
        ram[48] = "0b10111110010110111110011011100010";
        ram[49] = "0b00111101011010000101001111100101";
        ram[50] = "0b10111110010000001100110100001011";
        ram[51] = "0b00111110010101011110101001001110";
        ram[52] = "0b00111110100001011101100001010100";
        ram[53] = "0b00111101100000101011101000111100";
        ram[54] = "0b00111110111010011100000001011000";
        ram[55] = "0b10111110001010011100110000001100";
        ram[56] = "0b10111110101000100110111000111010";
        ram[57] = "0b00111110000100100100101010000100";
        ram[58] = "0b00111101110010111101100100110010";
        ram[59] = "0b00111110110101000001011010101101";
        ram[60] = "0b10111110100001011010100011110101";
        ram[61] = "0b10111101110010000011010001011100";
        ram[62] = "0b10111110101011000000001000110001";
        ram[63] = "0b00111110100111100001010100111110";


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


SC_MODULE(master_secondDense) {


static const unsigned DataWidth = 32;
static const unsigned AddressRange = 64;
static const unsigned AddressWidth = 6;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


master_secondDense_ram* meminst;


SC_CTOR(master_secondDense) {
meminst = new master_secondDense_ram("master_secondDense_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~master_secondDense() {
    delete meminst;
}


};//endmodule
#endif

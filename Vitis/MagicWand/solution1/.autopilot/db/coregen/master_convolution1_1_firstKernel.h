// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.1 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __master_convolution1_1_firstKernel_H__
#define __master_convolution1_1_firstKernel_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct master_convolution1_1_firstKernel_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 32;
  static const unsigned AddressRange = 96;
  static const unsigned AddressWidth = 7;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in <sc_lv<AddressWidth> > address1;
sc_core::sc_in <sc_logic> ce1;
sc_core::sc_out <sc_lv<DataWidth> > q1;
sc_core::sc_in <sc_lv<AddressWidth> > address2;
sc_core::sc_in <sc_logic> ce2;
sc_core::sc_out <sc_lv<DataWidth> > q2;
sc_core::sc_in <sc_lv<AddressWidth> > address3;
sc_core::sc_in <sc_logic> ce3;
sc_core::sc_out <sc_lv<DataWidth> > q3;
sc_core::sc_in <sc_lv<AddressWidth> > address4;
sc_core::sc_in <sc_logic> ce4;
sc_core::sc_out <sc_lv<DataWidth> > q4;
sc_core::sc_in <sc_lv<AddressWidth> > address5;
sc_core::sc_in <sc_logic> ce5;
sc_core::sc_out <sc_lv<DataWidth> > q5;
sc_core::sc_in <sc_lv<AddressWidth> > address6;
sc_core::sc_in <sc_logic> ce6;
sc_core::sc_out <sc_lv<DataWidth> > q6;
sc_core::sc_in <sc_lv<AddressWidth> > address7;
sc_core::sc_in <sc_logic> ce7;
sc_core::sc_out <sc_lv<DataWidth> > q7;
sc_core::sc_in <sc_lv<AddressWidth> > address8;
sc_core::sc_in <sc_logic> ce8;
sc_core::sc_out <sc_lv<DataWidth> > q8;
sc_core::sc_in <sc_lv<AddressWidth> > address9;
sc_core::sc_in <sc_logic> ce9;
sc_core::sc_out <sc_lv<DataWidth> > q9;
sc_core::sc_in <sc_lv<AddressWidth> > address10;
sc_core::sc_in <sc_logic> ce10;
sc_core::sc_out <sc_lv<DataWidth> > q10;
sc_core::sc_in <sc_lv<AddressWidth> > address11;
sc_core::sc_in <sc_logic> ce11;
sc_core::sc_out <sc_lv<DataWidth> > q11;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(master_convolution1_1_firstKernel_ram) {
        ram[0] = "0b10111101111101100110101000011100";
        ram[1] = "0b10111011101111001101110111000111";
        ram[2] = "0b00111110010001101111000100001111";
        ram[3] = "0b10111100001001110001000111010110";
        ram[4] = "0b10111101101000011010000101110100";
        ram[5] = "0b00111101101011011101111000010111";
        ram[6] = "0b10111100111010000100101110110101";
        ram[7] = "0b00111100101001011011100101111110";
        ram[8] = "0b00111101001010101010001100111110";
        ram[9] = "0b00111101100100101010011101011010";
        ram[10] = "0b10111101101011101101111111100011";
        ram[11] = "0b10111101110110100000111011110001";
        ram[12] = "0b00111100111111010001011010101010";
        ram[13] = "0b10111110001001001001110010000111";
        ram[14] = "0b10111111000000101011110100011100";
        ram[15] = "0b00111101111100110111111011001100";
        ram[16] = "0b10111110000111010100100011000111";
        ram[17] = "0b10111101011101001110111011010111";
        ram[18] = "0b10111110010111000000010101001000";
        ram[19] = "0b00111110010010010111000001001110";
        ram[20] = "0b00111101001100010111001110100001";
        ram[21] = "0b10111110001101010110000010111000";
        ram[22] = "0b10111110010110010101111010000000";
        ram[23] = "0b10111110101110000000100101001000";
        ram[24] = "0b00111110001000001101100111110110";
        ram[25] = "0b10111101011010100000100001110010";
        ram[26] = "0b00111110000001111011110001010110";
        ram[27] = "0b00111101101010100100110111110011";
        ram[28] = "0b00111011101100100101001100111010";
        ram[29] = "0b00111101110000100101110010110110";
        ram[30] = "0b00111110000011011111101010101111";
        ram[31] = "0b10111110000100101111111000111001";
        ram[32] = "0b10111101000000111100011111001000";
        ram[33] = "0b00111101100011111101111110100111";
        ram[34] = "0b10111101110000000001010110001000";
        ram[35] = "0b10111110010011011110001010101101";
        ram[36] = "0b00111101110111011111100001100100";
        ram[37] = "0b00111110011000010001101100010000";
        ram[38] = "0b10111110001110011001001001100011";
        ram[39] = "0b00111110001010001000101010111100";
        ram[40] = "0b10111101101001010101000110010010";
        ram[41] = "0b10111110011001011000100100011100";
        ram[42] = "0b00111101101001001000010001110100";
        ram[43] = "0b10111110000000011000101111111010";
        ram[44] = "0b10111101101011110111000100000111";
        ram[45] = "0b00111110010000101111110010111100";
        ram[46] = "0b10111101101010101000011011101010";
        ram[47] = "0b10111110100110010010011001101001";
        ram[48] = "0b10111110100000101100000000000111";
        ram[49] = "0b10111110000110000100100101111001";
        ram[50] = "0b00111110100001001101111001001110";
        ram[51] = "0b10111101110110101011010110100010";
        ram[52] = "0b10111101001111001100010001101010";
        ram[53] = "0b00111110010010001100010011111101";
        ram[54] = "0b00111110000001001000010001001100";
        ram[55] = "0b10111100111001101000111010111001";
        ram[56] = "0b10111110001010110110101110110010";
        ram[57] = "0b10111100011111011000011001000010";
        ram[58] = "0b00111101011001000100101000111011";
        ram[59] = "0b10111110110011010011110010000110";
        ram[60] = "0b10111101001110001010001110011110";
        ram[61] = "0b10111110100010000000100111011010";
        ram[62] = "0b10111101100010000011100001100100";
        ram[63] = "0b10111101101101100001101010010010";
        ram[64] = "0b10111101011011010110000111011011";
        ram[65] = "0b00111101000100110010100110110010";
        ram[66] = "0b00111100101110100111101000001001";
        ram[67] = "0b10111101101100110010111111001000";
        ram[68] = "0b10111110000111111100001000000110";
        ram[69] = "0b00111100110110001101000000111010";
        ram[70] = "0b10111110010000100010010110001001";
        ram[71] = "0b10111101010011101110011000000101";
        ram[72] = "0b00111101101000010100000100010011";
        ram[73] = "0b00111101010011010111000000101101";
        ram[74] = "0b10111101110000110011001010100000";
        ram[75] = "0b00111101101100010100100110011010";
        ram[76] = "0b10111110000000111001111101111000";
        ram[77] = "0b00111101000100110101011011001100";
        ram[78] = "0b00111110000001111010011010110011";
        ram[79] = "0b10111101100111100010101100011011";
        ram[80] = "0b10111110001100001011111100111011";
        ram[81] = "0b10111100010000000100010111101010";
        ram[82] = "0b10111110100100110010100111000010";
        ram[83] = "0b00111101111110111000111111011011";
        ram[84] = "0b10111101100100001000000110110000";
        ram[85] = "0b10111101100111100100101001011100";
        ram[86] = "0b10111110101101111001010000001111";
        ram[87] = "0b00111101000111001001001111111100";
        ram[88] = "0b10111101001100000001111101000000";
        ram[89] = "0b10111100000110111100111011111000";
        ram[90] = "0b00111101111001011110010101111101";
        ram[91] = "0b00111101000011100111111111100111";
        ram[92] = "0b00111110001000100101000101111110";
        ram[93] = "0b10110111100111011101001100000100";
        ram[94] = "0b00111110000000001000010101100010";
        ram[95] = "0b00111110100101111111010111000110";


SC_METHOD(prc_write_0);
  sensitive<<clk.pos();


SC_METHOD(prc_write_1);
  sensitive<<clk.pos();


SC_METHOD(prc_write_2);
  sensitive<<clk.pos();


SC_METHOD(prc_write_3);
  sensitive<<clk.pos();


SC_METHOD(prc_write_4);
  sensitive<<clk.pos();


SC_METHOD(prc_write_5);
  sensitive<<clk.pos();


SC_METHOD(prc_write_6);
  sensitive<<clk.pos();


SC_METHOD(prc_write_7);
  sensitive<<clk.pos();


SC_METHOD(prc_write_8);
  sensitive<<clk.pos();


SC_METHOD(prc_write_9);
  sensitive<<clk.pos();


SC_METHOD(prc_write_10);
  sensitive<<clk.pos();


SC_METHOD(prc_write_11);
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


void prc_write_1()
{
    if (ce1.read() == sc_dt::Log_1) 
    {
            if(address1.read().is_01() && address1.read().to_uint()<AddressRange)
              q1 = ram[address1.read().to_uint()];
            else
              q1 = sc_lv<DataWidth>();
    }
}


void prc_write_2()
{
    if (ce2.read() == sc_dt::Log_1) 
    {
            if(address2.read().is_01() && address2.read().to_uint()<AddressRange)
              q2 = ram[address2.read().to_uint()];
            else
              q2 = sc_lv<DataWidth>();
    }
}


void prc_write_3()
{
    if (ce3.read() == sc_dt::Log_1) 
    {
            if(address3.read().is_01() && address3.read().to_uint()<AddressRange)
              q3 = ram[address3.read().to_uint()];
            else
              q3 = sc_lv<DataWidth>();
    }
}


void prc_write_4()
{
    if (ce4.read() == sc_dt::Log_1) 
    {
            if(address4.read().is_01() && address4.read().to_uint()<AddressRange)
              q4 = ram[address4.read().to_uint()];
            else
              q4 = sc_lv<DataWidth>();
    }
}


void prc_write_5()
{
    if (ce5.read() == sc_dt::Log_1) 
    {
            if(address5.read().is_01() && address5.read().to_uint()<AddressRange)
              q5 = ram[address5.read().to_uint()];
            else
              q5 = sc_lv<DataWidth>();
    }
}


void prc_write_6()
{
    if (ce6.read() == sc_dt::Log_1) 
    {
            if(address6.read().is_01() && address6.read().to_uint()<AddressRange)
              q6 = ram[address6.read().to_uint()];
            else
              q6 = sc_lv<DataWidth>();
    }
}


void prc_write_7()
{
    if (ce7.read() == sc_dt::Log_1) 
    {
            if(address7.read().is_01() && address7.read().to_uint()<AddressRange)
              q7 = ram[address7.read().to_uint()];
            else
              q7 = sc_lv<DataWidth>();
    }
}


void prc_write_8()
{
    if (ce8.read() == sc_dt::Log_1) 
    {
            if(address8.read().is_01() && address8.read().to_uint()<AddressRange)
              q8 = ram[address8.read().to_uint()];
            else
              q8 = sc_lv<DataWidth>();
    }
}


void prc_write_9()
{
    if (ce9.read() == sc_dt::Log_1) 
    {
            if(address9.read().is_01() && address9.read().to_uint()<AddressRange)
              q9 = ram[address9.read().to_uint()];
            else
              q9 = sc_lv<DataWidth>();
    }
}


void prc_write_10()
{
    if (ce10.read() == sc_dt::Log_1) 
    {
            if(address10.read().is_01() && address10.read().to_uint()<AddressRange)
              q10 = ram[address10.read().to_uint()];
            else
              q10 = sc_lv<DataWidth>();
    }
}


void prc_write_11()
{
    if (ce11.read() == sc_dt::Log_1) 
    {
            if(address11.read().is_01() && address11.read().to_uint()<AddressRange)
              q11 = ram[address11.read().to_uint()];
            else
              q11 = sc_lv<DataWidth>();
    }
}


}; //endmodule


SC_MODULE(master_convolution1_1_firstKernel) {


static const unsigned DataWidth = 32;
static const unsigned AddressRange = 96;
static const unsigned AddressWidth = 7;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in <sc_lv<AddressWidth> > address1;
sc_core::sc_in<sc_logic> ce1;
sc_core::sc_out <sc_lv<DataWidth> > q1;
sc_core::sc_in <sc_lv<AddressWidth> > address2;
sc_core::sc_in<sc_logic> ce2;
sc_core::sc_out <sc_lv<DataWidth> > q2;
sc_core::sc_in <sc_lv<AddressWidth> > address3;
sc_core::sc_in<sc_logic> ce3;
sc_core::sc_out <sc_lv<DataWidth> > q3;
sc_core::sc_in <sc_lv<AddressWidth> > address4;
sc_core::sc_in<sc_logic> ce4;
sc_core::sc_out <sc_lv<DataWidth> > q4;
sc_core::sc_in <sc_lv<AddressWidth> > address5;
sc_core::sc_in<sc_logic> ce5;
sc_core::sc_out <sc_lv<DataWidth> > q5;
sc_core::sc_in <sc_lv<AddressWidth> > address6;
sc_core::sc_in<sc_logic> ce6;
sc_core::sc_out <sc_lv<DataWidth> > q6;
sc_core::sc_in <sc_lv<AddressWidth> > address7;
sc_core::sc_in<sc_logic> ce7;
sc_core::sc_out <sc_lv<DataWidth> > q7;
sc_core::sc_in <sc_lv<AddressWidth> > address8;
sc_core::sc_in<sc_logic> ce8;
sc_core::sc_out <sc_lv<DataWidth> > q8;
sc_core::sc_in <sc_lv<AddressWidth> > address9;
sc_core::sc_in<sc_logic> ce9;
sc_core::sc_out <sc_lv<DataWidth> > q9;
sc_core::sc_in <sc_lv<AddressWidth> > address10;
sc_core::sc_in<sc_logic> ce10;
sc_core::sc_out <sc_lv<DataWidth> > q10;
sc_core::sc_in <sc_lv<AddressWidth> > address11;
sc_core::sc_in<sc_logic> ce11;
sc_core::sc_out <sc_lv<DataWidth> > q11;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


master_convolution1_1_firstKernel_ram* meminst;


SC_CTOR(master_convolution1_1_firstKernel) {
meminst = new master_convolution1_1_firstKernel_ram("master_convolution1_1_firstKernel_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->address1(address1);
meminst->ce1(ce1);
meminst->q1(q1);

meminst->address2(address2);
meminst->ce2(ce2);
meminst->q2(q2);

meminst->address3(address3);
meminst->ce3(ce3);
meminst->q3(q3);

meminst->address4(address4);
meminst->ce4(ce4);
meminst->q4(q4);

meminst->address5(address5);
meminst->ce5(ce5);
meminst->q5(q5);

meminst->address6(address6);
meminst->ce6(ce6);
meminst->q6(q6);

meminst->address7(address7);
meminst->ce7(ce7);
meminst->q7(q7);

meminst->address8(address8);
meminst->ce8(ce8);
meminst->q8(q8);

meminst->address9(address9);
meminst->ce9(ce9);
meminst->q9(q9);

meminst->address10(address10);
meminst->ce10(ce10);
meminst->q10(q10);

meminst->address11(address11);
meminst->ce11(ce11);
meminst->q11(q11);

meminst->reset(reset);
meminst->clk(clk);
}
~master_convolution1_1_firstKernel() {
    delete meminst;
}


};//endmodule
#endif

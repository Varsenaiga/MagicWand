-- ==============================================================
-- Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.1 (64-bit)
-- Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity master_convolution2_secondBias is 
    generic(
             DataWidth     : integer := 32; 
             AddressWidth     : integer := 4; 
             AddressRange    : integer := 16
    ); 
    port (
          address0      : in std_logic_vector(AddressWidth-1 downto 0); 
          ce0       : in std_logic; 
          q0         : out std_logic_vector(DataWidth-1 downto 0);
          reset     : in std_logic;
          clk       : in std_logic
    ); 
end entity; 


architecture rtl of master_convolution2_secondBias is 

signal address0_tmp : std_logic_vector(AddressWidth-1 downto 0); 
type mem_array is array (0 to AddressRange-1) of std_logic_vector (DataWidth-1 downto 0); 
signal mem : mem_array := (
    0 => "00111110101101110001010110100011", 
    1 => "00111111100101010110011100101001", 
    2 => "10111110011000101001011001001011", 
    3 => "00111110111111000101111101100001", 
    4 => "10111111001111101101010010100010", 
    5 => "10111111000011010001110001000101", 
    6 => "10111110011100001101110100101001", 
    7 => "10111111100101110111010110011010", 
    8 => "10111110011011110000101011111100", 
    9 => "00111111001001010101011011001100", 
    10 => "10111111100110001010110011011111", 
    11 => "10111111100010110001110000001110", 
    12 => "00111111100011001101100010100101", 
    13 => "00111100110101010100001010100101", 
    14 => "10111111011110101000111010101001", 
    15 => "10111110011100011101101110011110" );


begin 


memory_access_guard_0: process (address0) 
begin
      address0_tmp <= address0;
--synthesis translate_off
      if (CONV_INTEGER(address0) > AddressRange-1) then
           address0_tmp <= (others => '0');
      else 
           address0_tmp <= address0;
      end if;
--synthesis translate_on
end process;

p_rom_access: process (clk)  
begin 
    if (clk'event and clk = '1') then
        if (ce0 = '1') then 
            q0 <= mem(CONV_INTEGER(address0_tmp)); 
        end if;
    end if;
end process;

end rtl;


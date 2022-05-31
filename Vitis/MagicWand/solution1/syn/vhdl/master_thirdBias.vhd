-- ==============================================================
-- Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.1 (64-bit)
-- Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity master_thirdBias is 
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


architecture rtl of master_thirdBias is 

signal address0_tmp : std_logic_vector(AddressWidth-1 downto 0); 
type mem_array is array (0 to AddressRange-1) of std_logic_vector (DataWidth-1 downto 0); 
signal mem : mem_array := (
    0 => "00111111100100111010100110101001", 
    1 => "10111110001000011101101000111100", 
    2 => "00111101001111011110001100110011", 
    3 => "10111111001100111110110111011000", 
    4 => "10111111001111101001110101001100", 
    5 => "00111111101001100100000010111010", 
    6 => "10111110001001010100111001101110", 
    7 => "00111111100100110101111001101110", 
    8 => "10111110110001011010001001001000", 
    9 => "00111110001100111010101001100111", 
    10 => "00111111001000000110011011000000", 
    11 => "10111110011111100010010110110011", 
    12 => "10111110110110010010111110001010", 
    13 => "00111111110010000110010011011010", 
    14 => "10111101100010010001010000011010", 
    15 => "00111110100010010100100011101010" );


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


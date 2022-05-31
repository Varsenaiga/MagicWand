-- ==============================================================
-- Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.1 (64-bit)
-- Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity master_convolution1_1_firstKernel is 
    generic(
             DataWidth     : integer := 32; 
             AddressWidth     : integer := 7; 
             AddressRange    : integer := 96
    ); 
    port (
          address0      : in std_logic_vector(AddressWidth-1 downto 0); 
          ce0       : in std_logic; 
          q0         : out std_logic_vector(DataWidth-1 downto 0);
          address1      : in std_logic_vector(AddressWidth-1 downto 0); 
          ce1       : in std_logic; 
          q1         : out std_logic_vector(DataWidth-1 downto 0);
          address2      : in std_logic_vector(AddressWidth-1 downto 0); 
          ce2       : in std_logic; 
          q2         : out std_logic_vector(DataWidth-1 downto 0);
          address3      : in std_logic_vector(AddressWidth-1 downto 0); 
          ce3       : in std_logic; 
          q3         : out std_logic_vector(DataWidth-1 downto 0);
          address4      : in std_logic_vector(AddressWidth-1 downto 0); 
          ce4       : in std_logic; 
          q4         : out std_logic_vector(DataWidth-1 downto 0);
          address5      : in std_logic_vector(AddressWidth-1 downto 0); 
          ce5       : in std_logic; 
          q5         : out std_logic_vector(DataWidth-1 downto 0);
          address6      : in std_logic_vector(AddressWidth-1 downto 0); 
          ce6       : in std_logic; 
          q6         : out std_logic_vector(DataWidth-1 downto 0);
          address7      : in std_logic_vector(AddressWidth-1 downto 0); 
          ce7       : in std_logic; 
          q7         : out std_logic_vector(DataWidth-1 downto 0);
          address8      : in std_logic_vector(AddressWidth-1 downto 0); 
          ce8       : in std_logic; 
          q8         : out std_logic_vector(DataWidth-1 downto 0);
          address9      : in std_logic_vector(AddressWidth-1 downto 0); 
          ce9       : in std_logic; 
          q9         : out std_logic_vector(DataWidth-1 downto 0);
          address10      : in std_logic_vector(AddressWidth-1 downto 0); 
          ce10       : in std_logic; 
          q10         : out std_logic_vector(DataWidth-1 downto 0);
          address11      : in std_logic_vector(AddressWidth-1 downto 0); 
          ce11       : in std_logic; 
          q11         : out std_logic_vector(DataWidth-1 downto 0);
          reset     : in std_logic;
          clk       : in std_logic
    ); 
end entity; 


architecture rtl of master_convolution1_1_firstKernel is 

signal address0_tmp : std_logic_vector(AddressWidth-1 downto 0); 
signal address1_tmp : std_logic_vector(AddressWidth-1 downto 0); 
signal address2_tmp : std_logic_vector(AddressWidth-1 downto 0); 
signal address3_tmp : std_logic_vector(AddressWidth-1 downto 0); 
signal address4_tmp : std_logic_vector(AddressWidth-1 downto 0); 
signal address5_tmp : std_logic_vector(AddressWidth-1 downto 0); 
signal address6_tmp : std_logic_vector(AddressWidth-1 downto 0); 
signal address7_tmp : std_logic_vector(AddressWidth-1 downto 0); 
signal address8_tmp : std_logic_vector(AddressWidth-1 downto 0); 
signal address9_tmp : std_logic_vector(AddressWidth-1 downto 0); 
signal address10_tmp : std_logic_vector(AddressWidth-1 downto 0); 
signal address11_tmp : std_logic_vector(AddressWidth-1 downto 0); 
type mem_array is array (0 to AddressRange-1) of std_logic_vector (DataWidth-1 downto 0); 
signal mem0 : mem_array := (
    0 => "10111101111101100110101000011100", 
    1 => "10111011101111001101110111000111", 
    2 => "00111110010001101111000100001111", 
    3 => "10111100001001110001000111010110", 
    4 => "10111101101000011010000101110100", 
    5 => "00111101101011011101111000010111", 
    6 => "10111100111010000100101110110101", 
    7 => "00111100101001011011100101111110", 
    8 => "00111101001010101010001100111110", 
    9 => "00111101100100101010011101011010", 
    10 => "10111101101011101101111111100011", 
    11 => "10111101110110100000111011110001", 
    12 => "00111100111111010001011010101010", 
    13 => "10111110001001001001110010000111", 
    14 => "10111111000000101011110100011100", 
    15 => "00111101111100110111111011001100", 
    16 => "10111110000111010100100011000111", 
    17 => "10111101011101001110111011010111", 
    18 => "10111110010111000000010101001000", 
    19 => "00111110010010010111000001001110", 
    20 => "00111101001100010111001110100001", 
    21 => "10111110001101010110000010111000", 
    22 => "10111110010110010101111010000000", 
    23 => "10111110101110000000100101001000", 
    24 => "00111110001000001101100111110110", 
    25 => "10111101011010100000100001110010", 
    26 => "00111110000001111011110001010110", 
    27 => "00111101101010100100110111110011", 
    28 => "00111011101100100101001100111010", 
    29 => "00111101110000100101110010110110", 
    30 => "00111110000011011111101010101111", 
    31 => "10111110000100101111111000111001", 
    32 => "10111101000000111100011111001000", 
    33 => "00111101100011111101111110100111", 
    34 => "10111101110000000001010110001000", 
    35 => "10111110010011011110001010101101", 
    36 => "00111101110111011111100001100100", 
    37 => "00111110011000010001101100010000", 
    38 => "10111110001110011001001001100011", 
    39 => "00111110001010001000101010111100", 
    40 => "10111101101001010101000110010010", 
    41 => "10111110011001011000100100011100", 
    42 => "00111101101001001000010001110100", 
    43 => "10111110000000011000101111111010", 
    44 => "10111101101011110111000100000111", 
    45 => "00111110010000101111110010111100", 
    46 => "10111101101010101000011011101010", 
    47 => "10111110100110010010011001101001", 
    48 => "10111110100000101100000000000111", 
    49 => "10111110000110000100100101111001", 
    50 => "00111110100001001101111001001110", 
    51 => "10111101110110101011010110100010", 
    52 => "10111101001111001100010001101010", 
    53 => "00111110010010001100010011111101", 
    54 => "00111110000001001000010001001100", 
    55 => "10111100111001101000111010111001", 
    56 => "10111110001010110110101110110010", 
    57 => "10111100011111011000011001000010", 
    58 => "00111101011001000100101000111011", 
    59 => "10111110110011010011110010000110", 
    60 => "10111101001110001010001110011110", 
    61 => "10111110100010000000100111011010", 
    62 => "10111101100010000011100001100100", 
    63 => "10111101101101100001101010010010", 
    64 => "10111101011011010110000111011011", 
    65 => "00111101000100110010100110110010", 
    66 => "00111100101110100111101000001001", 
    67 => "10111101101100110010111111001000", 
    68 => "10111110000111111100001000000110", 
    69 => "00111100110110001101000000111010", 
    70 => "10111110010000100010010110001001", 
    71 => "10111101010011101110011000000101", 
    72 => "00111101101000010100000100010011", 
    73 => "00111101010011010111000000101101", 
    74 => "10111101110000110011001010100000", 
    75 => "00111101101100010100100110011010", 
    76 => "10111110000000111001111101111000", 
    77 => "00111101000100110101011011001100", 
    78 => "00111110000001111010011010110011", 
    79 => "10111101100111100010101100011011", 
    80 => "10111110001100001011111100111011", 
    81 => "10111100010000000100010111101010", 
    82 => "10111110100100110010100111000010", 
    83 => "00111101111110111000111111011011", 
    84 => "10111101100100001000000110110000", 
    85 => "10111101100111100100101001011100", 
    86 => "10111110101101111001010000001111", 
    87 => "00111101000111001001001111111100", 
    88 => "10111101001100000001111101000000", 
    89 => "10111100000110111100111011111000", 
    90 => "00111101111001011110010101111101", 
    91 => "00111101000011100111111111100111", 
    92 => "00111110001000100101000101111110", 
    93 => "10110111100111011101001100000100", 
    94 => "00111110000000001000010101100010", 
    95 => "00111110100101111111010111000110" );
signal mem1 : mem_array := (
    0 => "10111101111101100110101000011100", 
    1 => "10111011101111001101110111000111", 
    2 => "00111110010001101111000100001111", 
    3 => "10111100001001110001000111010110", 
    4 => "10111101101000011010000101110100", 
    5 => "00111101101011011101111000010111", 
    6 => "10111100111010000100101110110101", 
    7 => "00111100101001011011100101111110", 
    8 => "00111101001010101010001100111110", 
    9 => "00111101100100101010011101011010", 
    10 => "10111101101011101101111111100011", 
    11 => "10111101110110100000111011110001", 
    12 => "00111100111111010001011010101010", 
    13 => "10111110001001001001110010000111", 
    14 => "10111111000000101011110100011100", 
    15 => "00111101111100110111111011001100", 
    16 => "10111110000111010100100011000111", 
    17 => "10111101011101001110111011010111", 
    18 => "10111110010111000000010101001000", 
    19 => "00111110010010010111000001001110", 
    20 => "00111101001100010111001110100001", 
    21 => "10111110001101010110000010111000", 
    22 => "10111110010110010101111010000000", 
    23 => "10111110101110000000100101001000", 
    24 => "00111110001000001101100111110110", 
    25 => "10111101011010100000100001110010", 
    26 => "00111110000001111011110001010110", 
    27 => "00111101101010100100110111110011", 
    28 => "00111011101100100101001100111010", 
    29 => "00111101110000100101110010110110", 
    30 => "00111110000011011111101010101111", 
    31 => "10111110000100101111111000111001", 
    32 => "10111101000000111100011111001000", 
    33 => "00111101100011111101111110100111", 
    34 => "10111101110000000001010110001000", 
    35 => "10111110010011011110001010101101", 
    36 => "00111101110111011111100001100100", 
    37 => "00111110011000010001101100010000", 
    38 => "10111110001110011001001001100011", 
    39 => "00111110001010001000101010111100", 
    40 => "10111101101001010101000110010010", 
    41 => "10111110011001011000100100011100", 
    42 => "00111101101001001000010001110100", 
    43 => "10111110000000011000101111111010", 
    44 => "10111101101011110111000100000111", 
    45 => "00111110010000101111110010111100", 
    46 => "10111101101010101000011011101010", 
    47 => "10111110100110010010011001101001", 
    48 => "10111110100000101100000000000111", 
    49 => "10111110000110000100100101111001", 
    50 => "00111110100001001101111001001110", 
    51 => "10111101110110101011010110100010", 
    52 => "10111101001111001100010001101010", 
    53 => "00111110010010001100010011111101", 
    54 => "00111110000001001000010001001100", 
    55 => "10111100111001101000111010111001", 
    56 => "10111110001010110110101110110010", 
    57 => "10111100011111011000011001000010", 
    58 => "00111101011001000100101000111011", 
    59 => "10111110110011010011110010000110", 
    60 => "10111101001110001010001110011110", 
    61 => "10111110100010000000100111011010", 
    62 => "10111101100010000011100001100100", 
    63 => "10111101101101100001101010010010", 
    64 => "10111101011011010110000111011011", 
    65 => "00111101000100110010100110110010", 
    66 => "00111100101110100111101000001001", 
    67 => "10111101101100110010111111001000", 
    68 => "10111110000111111100001000000110", 
    69 => "00111100110110001101000000111010", 
    70 => "10111110010000100010010110001001", 
    71 => "10111101010011101110011000000101", 
    72 => "00111101101000010100000100010011", 
    73 => "00111101010011010111000000101101", 
    74 => "10111101110000110011001010100000", 
    75 => "00111101101100010100100110011010", 
    76 => "10111110000000111001111101111000", 
    77 => "00111101000100110101011011001100", 
    78 => "00111110000001111010011010110011", 
    79 => "10111101100111100010101100011011", 
    80 => "10111110001100001011111100111011", 
    81 => "10111100010000000100010111101010", 
    82 => "10111110100100110010100111000010", 
    83 => "00111101111110111000111111011011", 
    84 => "10111101100100001000000110110000", 
    85 => "10111101100111100100101001011100", 
    86 => "10111110101101111001010000001111", 
    87 => "00111101000111001001001111111100", 
    88 => "10111101001100000001111101000000", 
    89 => "10111100000110111100111011111000", 
    90 => "00111101111001011110010101111101", 
    91 => "00111101000011100111111111100111", 
    92 => "00111110001000100101000101111110", 
    93 => "10110111100111011101001100000100", 
    94 => "00111110000000001000010101100010", 
    95 => "00111110100101111111010111000110" );
signal mem2 : mem_array := (
    0 => "10111101111101100110101000011100", 
    1 => "10111011101111001101110111000111", 
    2 => "00111110010001101111000100001111", 
    3 => "10111100001001110001000111010110", 
    4 => "10111101101000011010000101110100", 
    5 => "00111101101011011101111000010111", 
    6 => "10111100111010000100101110110101", 
    7 => "00111100101001011011100101111110", 
    8 => "00111101001010101010001100111110", 
    9 => "00111101100100101010011101011010", 
    10 => "10111101101011101101111111100011", 
    11 => "10111101110110100000111011110001", 
    12 => "00111100111111010001011010101010", 
    13 => "10111110001001001001110010000111", 
    14 => "10111111000000101011110100011100", 
    15 => "00111101111100110111111011001100", 
    16 => "10111110000111010100100011000111", 
    17 => "10111101011101001110111011010111", 
    18 => "10111110010111000000010101001000", 
    19 => "00111110010010010111000001001110", 
    20 => "00111101001100010111001110100001", 
    21 => "10111110001101010110000010111000", 
    22 => "10111110010110010101111010000000", 
    23 => "10111110101110000000100101001000", 
    24 => "00111110001000001101100111110110", 
    25 => "10111101011010100000100001110010", 
    26 => "00111110000001111011110001010110", 
    27 => "00111101101010100100110111110011", 
    28 => "00111011101100100101001100111010", 
    29 => "00111101110000100101110010110110", 
    30 => "00111110000011011111101010101111", 
    31 => "10111110000100101111111000111001", 
    32 => "10111101000000111100011111001000", 
    33 => "00111101100011111101111110100111", 
    34 => "10111101110000000001010110001000", 
    35 => "10111110010011011110001010101101", 
    36 => "00111101110111011111100001100100", 
    37 => "00111110011000010001101100010000", 
    38 => "10111110001110011001001001100011", 
    39 => "00111110001010001000101010111100", 
    40 => "10111101101001010101000110010010", 
    41 => "10111110011001011000100100011100", 
    42 => "00111101101001001000010001110100", 
    43 => "10111110000000011000101111111010", 
    44 => "10111101101011110111000100000111", 
    45 => "00111110010000101111110010111100", 
    46 => "10111101101010101000011011101010", 
    47 => "10111110100110010010011001101001", 
    48 => "10111110100000101100000000000111", 
    49 => "10111110000110000100100101111001", 
    50 => "00111110100001001101111001001110", 
    51 => "10111101110110101011010110100010", 
    52 => "10111101001111001100010001101010", 
    53 => "00111110010010001100010011111101", 
    54 => "00111110000001001000010001001100", 
    55 => "10111100111001101000111010111001", 
    56 => "10111110001010110110101110110010", 
    57 => "10111100011111011000011001000010", 
    58 => "00111101011001000100101000111011", 
    59 => "10111110110011010011110010000110", 
    60 => "10111101001110001010001110011110", 
    61 => "10111110100010000000100111011010", 
    62 => "10111101100010000011100001100100", 
    63 => "10111101101101100001101010010010", 
    64 => "10111101011011010110000111011011", 
    65 => "00111101000100110010100110110010", 
    66 => "00111100101110100111101000001001", 
    67 => "10111101101100110010111111001000", 
    68 => "10111110000111111100001000000110", 
    69 => "00111100110110001101000000111010", 
    70 => "10111110010000100010010110001001", 
    71 => "10111101010011101110011000000101", 
    72 => "00111101101000010100000100010011", 
    73 => "00111101010011010111000000101101", 
    74 => "10111101110000110011001010100000", 
    75 => "00111101101100010100100110011010", 
    76 => "10111110000000111001111101111000", 
    77 => "00111101000100110101011011001100", 
    78 => "00111110000001111010011010110011", 
    79 => "10111101100111100010101100011011", 
    80 => "10111110001100001011111100111011", 
    81 => "10111100010000000100010111101010", 
    82 => "10111110100100110010100111000010", 
    83 => "00111101111110111000111111011011", 
    84 => "10111101100100001000000110110000", 
    85 => "10111101100111100100101001011100", 
    86 => "10111110101101111001010000001111", 
    87 => "00111101000111001001001111111100", 
    88 => "10111101001100000001111101000000", 
    89 => "10111100000110111100111011111000", 
    90 => "00111101111001011110010101111101", 
    91 => "00111101000011100111111111100111", 
    92 => "00111110001000100101000101111110", 
    93 => "10110111100111011101001100000100", 
    94 => "00111110000000001000010101100010", 
    95 => "00111110100101111111010111000110" );
signal mem3 : mem_array := (
    0 => "10111101111101100110101000011100", 
    1 => "10111011101111001101110111000111", 
    2 => "00111110010001101111000100001111", 
    3 => "10111100001001110001000111010110", 
    4 => "10111101101000011010000101110100", 
    5 => "00111101101011011101111000010111", 
    6 => "10111100111010000100101110110101", 
    7 => "00111100101001011011100101111110", 
    8 => "00111101001010101010001100111110", 
    9 => "00111101100100101010011101011010", 
    10 => "10111101101011101101111111100011", 
    11 => "10111101110110100000111011110001", 
    12 => "00111100111111010001011010101010", 
    13 => "10111110001001001001110010000111", 
    14 => "10111111000000101011110100011100", 
    15 => "00111101111100110111111011001100", 
    16 => "10111110000111010100100011000111", 
    17 => "10111101011101001110111011010111", 
    18 => "10111110010111000000010101001000", 
    19 => "00111110010010010111000001001110", 
    20 => "00111101001100010111001110100001", 
    21 => "10111110001101010110000010111000", 
    22 => "10111110010110010101111010000000", 
    23 => "10111110101110000000100101001000", 
    24 => "00111110001000001101100111110110", 
    25 => "10111101011010100000100001110010", 
    26 => "00111110000001111011110001010110", 
    27 => "00111101101010100100110111110011", 
    28 => "00111011101100100101001100111010", 
    29 => "00111101110000100101110010110110", 
    30 => "00111110000011011111101010101111", 
    31 => "10111110000100101111111000111001", 
    32 => "10111101000000111100011111001000", 
    33 => "00111101100011111101111110100111", 
    34 => "10111101110000000001010110001000", 
    35 => "10111110010011011110001010101101", 
    36 => "00111101110111011111100001100100", 
    37 => "00111110011000010001101100010000", 
    38 => "10111110001110011001001001100011", 
    39 => "00111110001010001000101010111100", 
    40 => "10111101101001010101000110010010", 
    41 => "10111110011001011000100100011100", 
    42 => "00111101101001001000010001110100", 
    43 => "10111110000000011000101111111010", 
    44 => "10111101101011110111000100000111", 
    45 => "00111110010000101111110010111100", 
    46 => "10111101101010101000011011101010", 
    47 => "10111110100110010010011001101001", 
    48 => "10111110100000101100000000000111", 
    49 => "10111110000110000100100101111001", 
    50 => "00111110100001001101111001001110", 
    51 => "10111101110110101011010110100010", 
    52 => "10111101001111001100010001101010", 
    53 => "00111110010010001100010011111101", 
    54 => "00111110000001001000010001001100", 
    55 => "10111100111001101000111010111001", 
    56 => "10111110001010110110101110110010", 
    57 => "10111100011111011000011001000010", 
    58 => "00111101011001000100101000111011", 
    59 => "10111110110011010011110010000110", 
    60 => "10111101001110001010001110011110", 
    61 => "10111110100010000000100111011010", 
    62 => "10111101100010000011100001100100", 
    63 => "10111101101101100001101010010010", 
    64 => "10111101011011010110000111011011", 
    65 => "00111101000100110010100110110010", 
    66 => "00111100101110100111101000001001", 
    67 => "10111101101100110010111111001000", 
    68 => "10111110000111111100001000000110", 
    69 => "00111100110110001101000000111010", 
    70 => "10111110010000100010010110001001", 
    71 => "10111101010011101110011000000101", 
    72 => "00111101101000010100000100010011", 
    73 => "00111101010011010111000000101101", 
    74 => "10111101110000110011001010100000", 
    75 => "00111101101100010100100110011010", 
    76 => "10111110000000111001111101111000", 
    77 => "00111101000100110101011011001100", 
    78 => "00111110000001111010011010110011", 
    79 => "10111101100111100010101100011011", 
    80 => "10111110001100001011111100111011", 
    81 => "10111100010000000100010111101010", 
    82 => "10111110100100110010100111000010", 
    83 => "00111101111110111000111111011011", 
    84 => "10111101100100001000000110110000", 
    85 => "10111101100111100100101001011100", 
    86 => "10111110101101111001010000001111", 
    87 => "00111101000111001001001111111100", 
    88 => "10111101001100000001111101000000", 
    89 => "10111100000110111100111011111000", 
    90 => "00111101111001011110010101111101", 
    91 => "00111101000011100111111111100111", 
    92 => "00111110001000100101000101111110", 
    93 => "10110111100111011101001100000100", 
    94 => "00111110000000001000010101100010", 
    95 => "00111110100101111111010111000110" );
signal mem4 : mem_array := (
    0 => "10111101111101100110101000011100", 
    1 => "10111011101111001101110111000111", 
    2 => "00111110010001101111000100001111", 
    3 => "10111100001001110001000111010110", 
    4 => "10111101101000011010000101110100", 
    5 => "00111101101011011101111000010111", 
    6 => "10111100111010000100101110110101", 
    7 => "00111100101001011011100101111110", 
    8 => "00111101001010101010001100111110", 
    9 => "00111101100100101010011101011010", 
    10 => "10111101101011101101111111100011", 
    11 => "10111101110110100000111011110001", 
    12 => "00111100111111010001011010101010", 
    13 => "10111110001001001001110010000111", 
    14 => "10111111000000101011110100011100", 
    15 => "00111101111100110111111011001100", 
    16 => "10111110000111010100100011000111", 
    17 => "10111101011101001110111011010111", 
    18 => "10111110010111000000010101001000", 
    19 => "00111110010010010111000001001110", 
    20 => "00111101001100010111001110100001", 
    21 => "10111110001101010110000010111000", 
    22 => "10111110010110010101111010000000", 
    23 => "10111110101110000000100101001000", 
    24 => "00111110001000001101100111110110", 
    25 => "10111101011010100000100001110010", 
    26 => "00111110000001111011110001010110", 
    27 => "00111101101010100100110111110011", 
    28 => "00111011101100100101001100111010", 
    29 => "00111101110000100101110010110110", 
    30 => "00111110000011011111101010101111", 
    31 => "10111110000100101111111000111001", 
    32 => "10111101000000111100011111001000", 
    33 => "00111101100011111101111110100111", 
    34 => "10111101110000000001010110001000", 
    35 => "10111110010011011110001010101101", 
    36 => "00111101110111011111100001100100", 
    37 => "00111110011000010001101100010000", 
    38 => "10111110001110011001001001100011", 
    39 => "00111110001010001000101010111100", 
    40 => "10111101101001010101000110010010", 
    41 => "10111110011001011000100100011100", 
    42 => "00111101101001001000010001110100", 
    43 => "10111110000000011000101111111010", 
    44 => "10111101101011110111000100000111", 
    45 => "00111110010000101111110010111100", 
    46 => "10111101101010101000011011101010", 
    47 => "10111110100110010010011001101001", 
    48 => "10111110100000101100000000000111", 
    49 => "10111110000110000100100101111001", 
    50 => "00111110100001001101111001001110", 
    51 => "10111101110110101011010110100010", 
    52 => "10111101001111001100010001101010", 
    53 => "00111110010010001100010011111101", 
    54 => "00111110000001001000010001001100", 
    55 => "10111100111001101000111010111001", 
    56 => "10111110001010110110101110110010", 
    57 => "10111100011111011000011001000010", 
    58 => "00111101011001000100101000111011", 
    59 => "10111110110011010011110010000110", 
    60 => "10111101001110001010001110011110", 
    61 => "10111110100010000000100111011010", 
    62 => "10111101100010000011100001100100", 
    63 => "10111101101101100001101010010010", 
    64 => "10111101011011010110000111011011", 
    65 => "00111101000100110010100110110010", 
    66 => "00111100101110100111101000001001", 
    67 => "10111101101100110010111111001000", 
    68 => "10111110000111111100001000000110", 
    69 => "00111100110110001101000000111010", 
    70 => "10111110010000100010010110001001", 
    71 => "10111101010011101110011000000101", 
    72 => "00111101101000010100000100010011", 
    73 => "00111101010011010111000000101101", 
    74 => "10111101110000110011001010100000", 
    75 => "00111101101100010100100110011010", 
    76 => "10111110000000111001111101111000", 
    77 => "00111101000100110101011011001100", 
    78 => "00111110000001111010011010110011", 
    79 => "10111101100111100010101100011011", 
    80 => "10111110001100001011111100111011", 
    81 => "10111100010000000100010111101010", 
    82 => "10111110100100110010100111000010", 
    83 => "00111101111110111000111111011011", 
    84 => "10111101100100001000000110110000", 
    85 => "10111101100111100100101001011100", 
    86 => "10111110101101111001010000001111", 
    87 => "00111101000111001001001111111100", 
    88 => "10111101001100000001111101000000", 
    89 => "10111100000110111100111011111000", 
    90 => "00111101111001011110010101111101", 
    91 => "00111101000011100111111111100111", 
    92 => "00111110001000100101000101111110", 
    93 => "10110111100111011101001100000100", 
    94 => "00111110000000001000010101100010", 
    95 => "00111110100101111111010111000110" );
signal mem5 : mem_array := (
    0 => "10111101111101100110101000011100", 
    1 => "10111011101111001101110111000111", 
    2 => "00111110010001101111000100001111", 
    3 => "10111100001001110001000111010110", 
    4 => "10111101101000011010000101110100", 
    5 => "00111101101011011101111000010111", 
    6 => "10111100111010000100101110110101", 
    7 => "00111100101001011011100101111110", 
    8 => "00111101001010101010001100111110", 
    9 => "00111101100100101010011101011010", 
    10 => "10111101101011101101111111100011", 
    11 => "10111101110110100000111011110001", 
    12 => "00111100111111010001011010101010", 
    13 => "10111110001001001001110010000111", 
    14 => "10111111000000101011110100011100", 
    15 => "00111101111100110111111011001100", 
    16 => "10111110000111010100100011000111", 
    17 => "10111101011101001110111011010111", 
    18 => "10111110010111000000010101001000", 
    19 => "00111110010010010111000001001110", 
    20 => "00111101001100010111001110100001", 
    21 => "10111110001101010110000010111000", 
    22 => "10111110010110010101111010000000", 
    23 => "10111110101110000000100101001000", 
    24 => "00111110001000001101100111110110", 
    25 => "10111101011010100000100001110010", 
    26 => "00111110000001111011110001010110", 
    27 => "00111101101010100100110111110011", 
    28 => "00111011101100100101001100111010", 
    29 => "00111101110000100101110010110110", 
    30 => "00111110000011011111101010101111", 
    31 => "10111110000100101111111000111001", 
    32 => "10111101000000111100011111001000", 
    33 => "00111101100011111101111110100111", 
    34 => "10111101110000000001010110001000", 
    35 => "10111110010011011110001010101101", 
    36 => "00111101110111011111100001100100", 
    37 => "00111110011000010001101100010000", 
    38 => "10111110001110011001001001100011", 
    39 => "00111110001010001000101010111100", 
    40 => "10111101101001010101000110010010", 
    41 => "10111110011001011000100100011100", 
    42 => "00111101101001001000010001110100", 
    43 => "10111110000000011000101111111010", 
    44 => "10111101101011110111000100000111", 
    45 => "00111110010000101111110010111100", 
    46 => "10111101101010101000011011101010", 
    47 => "10111110100110010010011001101001", 
    48 => "10111110100000101100000000000111", 
    49 => "10111110000110000100100101111001", 
    50 => "00111110100001001101111001001110", 
    51 => "10111101110110101011010110100010", 
    52 => "10111101001111001100010001101010", 
    53 => "00111110010010001100010011111101", 
    54 => "00111110000001001000010001001100", 
    55 => "10111100111001101000111010111001", 
    56 => "10111110001010110110101110110010", 
    57 => "10111100011111011000011001000010", 
    58 => "00111101011001000100101000111011", 
    59 => "10111110110011010011110010000110", 
    60 => "10111101001110001010001110011110", 
    61 => "10111110100010000000100111011010", 
    62 => "10111101100010000011100001100100", 
    63 => "10111101101101100001101010010010", 
    64 => "10111101011011010110000111011011", 
    65 => "00111101000100110010100110110010", 
    66 => "00111100101110100111101000001001", 
    67 => "10111101101100110010111111001000", 
    68 => "10111110000111111100001000000110", 
    69 => "00111100110110001101000000111010", 
    70 => "10111110010000100010010110001001", 
    71 => "10111101010011101110011000000101", 
    72 => "00111101101000010100000100010011", 
    73 => "00111101010011010111000000101101", 
    74 => "10111101110000110011001010100000", 
    75 => "00111101101100010100100110011010", 
    76 => "10111110000000111001111101111000", 
    77 => "00111101000100110101011011001100", 
    78 => "00111110000001111010011010110011", 
    79 => "10111101100111100010101100011011", 
    80 => "10111110001100001011111100111011", 
    81 => "10111100010000000100010111101010", 
    82 => "10111110100100110010100111000010", 
    83 => "00111101111110111000111111011011", 
    84 => "10111101100100001000000110110000", 
    85 => "10111101100111100100101001011100", 
    86 => "10111110101101111001010000001111", 
    87 => "00111101000111001001001111111100", 
    88 => "10111101001100000001111101000000", 
    89 => "10111100000110111100111011111000", 
    90 => "00111101111001011110010101111101", 
    91 => "00111101000011100111111111100111", 
    92 => "00111110001000100101000101111110", 
    93 => "10110111100111011101001100000100", 
    94 => "00111110000000001000010101100010", 
    95 => "00111110100101111111010111000110" );


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

memory_access_guard_1: process (address1) 
begin
      address1_tmp <= address1;
--synthesis translate_off
      if (CONV_INTEGER(address1) > AddressRange-1) then
           address1_tmp <= (others => '0');
      else 
           address1_tmp <= address1;
      end if;
--synthesis translate_on
end process;

memory_access_guard_2: process (address2) 
begin
      address2_tmp <= address2;
--synthesis translate_off
      if (CONV_INTEGER(address2) > AddressRange-1) then
           address2_tmp <= (others => '0');
      else 
           address2_tmp <= address2;
      end if;
--synthesis translate_on
end process;

memory_access_guard_3: process (address3) 
begin
      address3_tmp <= address3;
--synthesis translate_off
      if (CONV_INTEGER(address3) > AddressRange-1) then
           address3_tmp <= (others => '0');
      else 
           address3_tmp <= address3;
      end if;
--synthesis translate_on
end process;

memory_access_guard_4: process (address4) 
begin
      address4_tmp <= address4;
--synthesis translate_off
      if (CONV_INTEGER(address4) > AddressRange-1) then
           address4_tmp <= (others => '0');
      else 
           address4_tmp <= address4;
      end if;
--synthesis translate_on
end process;

memory_access_guard_5: process (address5) 
begin
      address5_tmp <= address5;
--synthesis translate_off
      if (CONV_INTEGER(address5) > AddressRange-1) then
           address5_tmp <= (others => '0');
      else 
           address5_tmp <= address5;
      end if;
--synthesis translate_on
end process;

memory_access_guard_6: process (address6) 
begin
      address6_tmp <= address6;
--synthesis translate_off
      if (CONV_INTEGER(address6) > AddressRange-1) then
           address6_tmp <= (others => '0');
      else 
           address6_tmp <= address6;
      end if;
--synthesis translate_on
end process;

memory_access_guard_7: process (address7) 
begin
      address7_tmp <= address7;
--synthesis translate_off
      if (CONV_INTEGER(address7) > AddressRange-1) then
           address7_tmp <= (others => '0');
      else 
           address7_tmp <= address7;
      end if;
--synthesis translate_on
end process;

memory_access_guard_8: process (address8) 
begin
      address8_tmp <= address8;
--synthesis translate_off
      if (CONV_INTEGER(address8) > AddressRange-1) then
           address8_tmp <= (others => '0');
      else 
           address8_tmp <= address8;
      end if;
--synthesis translate_on
end process;

memory_access_guard_9: process (address9) 
begin
      address9_tmp <= address9;
--synthesis translate_off
      if (CONV_INTEGER(address9) > AddressRange-1) then
           address9_tmp <= (others => '0');
      else 
           address9_tmp <= address9;
      end if;
--synthesis translate_on
end process;

memory_access_guard_10: process (address10) 
begin
      address10_tmp <= address10;
--synthesis translate_off
      if (CONV_INTEGER(address10) > AddressRange-1) then
           address10_tmp <= (others => '0');
      else 
           address10_tmp <= address10;
      end if;
--synthesis translate_on
end process;

memory_access_guard_11: process (address11) 
begin
      address11_tmp <= address11;
--synthesis translate_off
      if (CONV_INTEGER(address11) > AddressRange-1) then
           address11_tmp <= (others => '0');
      else 
           address11_tmp <= address11;
      end if;
--synthesis translate_on
end process;

p_rom_access: process (clk)  
begin 
    if (clk'event and clk = '1') then
        if (ce0 = '1') then 
            q0 <= mem0(CONV_INTEGER(address0_tmp)); 
        end if;
        if (ce1 = '1') then 
            q1 <= mem0(CONV_INTEGER(address1_tmp)); 
        end if;
        if (ce2 = '1') then 
            q2 <= mem1(CONV_INTEGER(address2_tmp)); 
        end if;
        if (ce3 = '1') then 
            q3 <= mem1(CONV_INTEGER(address3_tmp)); 
        end if;
        if (ce4 = '1') then 
            q4 <= mem2(CONV_INTEGER(address4_tmp)); 
        end if;
        if (ce5 = '1') then 
            q5 <= mem2(CONV_INTEGER(address5_tmp)); 
        end if;
        if (ce6 = '1') then 
            q6 <= mem3(CONV_INTEGER(address6_tmp)); 
        end if;
        if (ce7 = '1') then 
            q7 <= mem3(CONV_INTEGER(address7_tmp)); 
        end if;
        if (ce8 = '1') then 
            q8 <= mem4(CONV_INTEGER(address8_tmp)); 
        end if;
        if (ce9 = '1') then 
            q9 <= mem4(CONV_INTEGER(address9_tmp)); 
        end if;
        if (ce10 = '1') then 
            q10 <= mem5(CONV_INTEGER(address10_tmp)); 
        end if;
        if (ce11 = '1') then 
            q11 <= mem5(CONV_INTEGER(address11_tmp)); 
        end if;
    end if;
end process;

end rtl;

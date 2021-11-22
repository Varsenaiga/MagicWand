/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "tensorflow/lite/micro/examples/magic_wand/slope_micro_features_data.h"

const int g_slope_micro_f2e59fea_nohash_1_length = 128;
const int g_slope_micro_f2e59fea_nohash_1_dim = 3;
// Raw accelerometer data with a sample rate of 25Hz
const float g_slope_micro_f2e59fea_nohash_1_data[] = {
    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
    0.0,    0.0,    0.0,    -766.0, 132.0,  709.0,  -751.0, 249.0,  659.0,
    -714.0, 314.0,  630.0,  -709.0, 244.0,  623.0,  -707.0, 230.0,  659.0,
    -704.0, 202.0,  748.0,  -714.0, 219.0,  728.0,  -722.0, 239.0,  710.0,
    -744.0, 116.0,  612.0,  -753.0, -49.0,  570.0,  -748.0, -279.0, 527.0,
    -668.0, -664.0, 592.0,  -601.0, -635.0, 609.0,  -509.0, -559.0, 606.0,
    -286.0, -162.0, 536.0,  -255.0, -144.0, 495.0,  -209.0, -85.0,  495.0,
    6.0,    416.0,  698.0,  -33.0,  304.0,  1117.0, -82.0,  405.0,  1480.0,
    -198.0, 1008.0, 1908.0, -229.0, 990.0,  1743.0, -234.0, 934.0,  1453.0,
    -126.0, 838.0,  896.0,  -78.0,  792.0,  911.0,  -27.0,  741.0,  918.0,
    114.0,  734.0,  960.0,  135.0,  613.0,  959.0,  152.0,  426.0,  1015.0,
    106.0,  -116.0, 1110.0, 63.0,   -314.0, 1129.0, -12.0,  -486.0, 1179.0,
    -118.0, -656.0, 1510.0, -116.0, -558.0, 1553.0, -126.0, -361.0, 1367.0,
    -222.0, -76.0,  922.0,  -210.0, -26.0,  971.0,  -194.0, 50.0,   1053.0,
    -178.0, 72.0,   1082.0, -169.0, 100.0,  1073.0, -162.0, 133.0,  1050.0,
    -156.0, 226.0,  976.0,  -154.0, 323.0,  886.0,  -130.0, 240.0,  1154.0,
    -116.0, 124.0,  916.0,  -132.0, 124.0,  937.0,  -153.0, 115.0,  981.0,
    -184.0, 94.0,   962.0,  -177.0, 85.0,   1017.0, -173.0, 92.0,   1027.0,
    -168.0, 158.0,  1110.0, -181.0, 101.0,  1030.0, -180.0, 139.0,  1054.0,
    -152.0, 10.0,   1044.0, -169.0, 74.0,   1007.0,
};/*
const int g_slope_micro_f2e59fea_nohash_1_data[] = {
    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    -665, 228,  827,  -680, 339,  716,
    -680, 564,  812,  -679, 552,  818,  -665, 528,  751,
    -658, 432,  618,  -655, 445,  592,  -667, 484,  556,
    -684, 590,  510,  -674, 672,  475,  -660, 786,  390,
    -562, 1124, 128,  -526, 1140, 111,  -486, 1044, 33,
    -416, 652,  -134, -390, 534,  -143, -365, 381,  -117,
    -314, 60,   94,   -322, 7,    190,  -338, -95,  342,
    -360, -106, 842,  -351, -41,  965,  -352, 12,   960,
    -366, 42,   1124, -322, 56,   1178, -312, 15,   1338,
    -254, 10,   1532, -241, 5,    1590, -227, 60,   1565,
    -204, 282,  1560, -180, 262,  1524, -138, 385,  1522,
    -84,  596,  1626, -55,  639,  1604, -19,  771,  1511,
    16,   932,  1132, 15,   924,  1013, 1,    849,  812,
    -88,  628,  500,  -114, 609,  463,  -155, 559,  382,
    -234, 420,  278,  -254, 390,  272,  -327, 200,  336,
    -558, -556, 630,  -640, -607, 740,  -706, -430, 868,
    -778, 42,   1042, -763, 84,   973,  -735, 185,  931,
    -682, 252,  766,  -673, 230,  757,  -671, 218,  757,
    -656, 222,  714,  -659, 238,  746,  -640, 276,  731,
    -634, 214,  754,  -637, 207,  735,  -637, 194,  742,
    -634, 248,  716,  -631, 265,  697,  -628, 252,  797,
    -592, 204,  816,  -618, 218,  812,  -633, 231,  828,
    -640, 222,  736,  -634, 221,  787,
};*/

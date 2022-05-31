#ifndef MAGICWAND_MASTER_H
#define MAGICWAND_MASTER_H

#include "model_functions.h"

void master(float input[BATCH][DATA_SIZE], float out[1][FOURTH_NUM_KERNELS]);
//void master(float input[BATCH][DATA_SIZE], float conv[BATCH][DATA_SIZE][FIRST_NUM_KERNELS]);

#endif //MAGICWAND_MASTER_H


#include "master.h"
#include "model_functions.h"
#include "parameters.h"

void master(float input[BATCH][DATA_SIZE], float out[1][FOURTH_NUM_KERNELS]) {

	float conv1[BATCH][DATA_SIZE][FIRST_NUM_KERNELS];
	float max1[42][1][FIRST_NUM_KERNELS];
	float conv2[42][1][SECOND_NUM_KERNELS];
	float max2[14][1][SECOND_NUM_KERNELS];
	float den1[1][THIRD_NUM_KERNELS];
	float den2[1][FOURTH_NUM_KERNELS];
	float sMax[1][FOURTH_NUM_KERNELS];

	convolution1(BATCH, DATA_SIZE, input, FIRST_NUM_ROWS, FIRST_NUM_COLS, FIRST_NUM_KERNELS, firstKernel, firstBias, conv1);
	maxPool(BATCH, DATA_SIZE, FIRST_NUM_KERNELS, conv1, 42, 1, max1, 3, 3);
	convolution2(42, 1, FIRST_NUM_KERNELS, max1, SECOND_NUM_ROWS, SECOND_NUM_COLS, SECOND_NUM_KERNELS, secondKernel, secondBias, conv2);
	maxPool(42, 1, SECOND_NUM_KERNELS, conv2, 14, 1, max2, 3, 1);
	dense1(14, 1, SECOND_NUM_KERNELS, max2, THIRD_NUM_ROWS, THIRD_NUM_COLS, THIRD_NUM_KERNELS, firstDense, thirdBias, THIRD_NUM_KERNELS, den1[0]);
	dense2(THIRD_NUM_KERNELS, den1[0], FOURTH_NUM_SIZE, FOURTH_NUM_KERNELS, secondDense, fourthBias, FOURTH_NUM_KERNELS, den2[0]);
	softmax(FOURTH_NUM_KERNELS, den2[0], out[0]);

}

/*void master(float input[BATCH][DATA_SIZE], float conv[BATCH][DATA_SIZE][FIRST_NUM_KERNELS]) {

	convolution1(BATCH, DATA_SIZE, input, FIRST_NUM_ROWS, FIRST_NUM_COLS, FIRST_NUM_KERNELS, firstKernel, firstBias, conv);

}*/

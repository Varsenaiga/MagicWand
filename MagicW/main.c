#include <stdio.h>
#include "utils.h"
#include "model_functions.h"
#include "file.h"

int main() {

    float data [BATCH][DATA_SIZE];
    /*float conv1[BATCH][DATA_SIZE][FIRST_NUM_KERNELS];
    float max1[42][1][FIRST_NUM_KERNELS];
    float conv2[42][1][SECOND_NUM_KERNELS];
    float max2[14][1][SECOND_NUM_KERNELS];
    float den1[1][THIRD_NUM_KERNELS];
    float den2[1][FOURTH_NUM_KERNELS];
    float sMax[1][FOURTH_NUM_KERNELS];

    convolution1(BATCH, DATA_SIZE, data1, FIRST_NUM_ROWS, FIRST_NUM_COLS, FIRST_NUM_KERNELS, firstKernel, firstBias, conv1);
    maxPool(BATCH, DATA_SIZE, FIRST_NUM_KERNELS, conv1, 42, 1, max1, 3, 3);
    convolution2(42, 1, FIRST_NUM_KERNELS, max1, SECOND_NUM_ROWS, SECOND_NUM_COLS, SECOND_NUM_KERNELS, secondKernel, secondBias, conv2);
    maxPool(42, 1, SECOND_NUM_KERNELS, conv2, 14, 1, max2, 3, 1);
    dense1(14, 1, SECOND_NUM_KERNELS, max2, THIRD_NUM_ROWS, THIRD_NUM_COLS, THIRD_NUM_KERNELS, firstDense, thirdBias, THIRD_NUM_KERNELS, den1[0]);
    dense2(THIRD_NUM_KERNELS, den1[0], FOURTH_NUM_SIZE, FOURTH_NUM_KERNELS, secondDense, fourthBias, FOURTH_NUM_KERNELS, den2[0]);
    softmax(FOURTH_NUM_KERNELS, den2[0], sMax[0]);


    printf("\n\nOut:\n");
    printData2D(1, FOURTH_NUM_KERNELS, sMax);

    write2File(sMax[0], FOURTH_NUM_KERNELS, "../test.txt");*/

    FILE* file = openFile("../wing/output_wing_dengyl.txt", "r");
    readFile(file);
    closeFile(file);

    //printf("\n\nComparing Files:\n");
    //compareFiles("../test.txt","../original.txt");

    return 0;
}

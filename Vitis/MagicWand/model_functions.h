#ifndef MAGICWAND_MODEL_FUNCTIONS_H
#define MAGICWAND_MODEL_FUNCTIONS_H

#define BATCH 128
#define DATA_SIZE 3
#define FIRST_NUM_ROWS 4
#define FIRST_NUM_COLS 3
#define FIRST_NUM_KERNELS 8
#define SECOND_NUM_ROWS 4
#define SECOND_NUM_COLS 8
#define SECOND_NUM_KERNELS 16
#define THIRD_NUM_ROWS 14
#define THIRD_NUM_COLS 16
#define THIRD_NUM_KERNELS 16
#define FOURTH_NUM_SIZE 16
#define FOURTH_NUM_KERNELS 4

void convolution1(int mRow, int mCol, float m[mRow][mCol], int kRow, int kCol, int kNum, float k[kNum][kRow][kCol], float bias[kNum], float out[mRow][mCol][kNum]);
void convolution2(int mRow, int mCol, int mDep, float m[mRow][mCol][mDep], int kRow, int kCol, int kNum, float k[kNum][kRow][kCol], float bias[kNum], float out[mRow][mCol][kNum]);
void maxPool(int mRow, int mCol, int mDep, float m[mRow][mCol][mDep], int oRow, int oCol, float out[mRow][mCol][mDep], int kRow, int kCol);
void dense1(int mRow, int mCol, int mDep, float m[mRow][mCol][mDep], int kRow, int kCol, int kNum, float k[kNum][kRow][kCol], float bias[kNum], int oSize, float out[oSize]);
void dense2(int mSize, const float m[mSize], int kSize, int kNum, float k[kNum][kSize], const float bias[kNum], int oSize, float out[oSize]);
void softmax(int mSize, float m[mSize], float out[mSize]);

#endif //MAGICWAND_MODEL_FUNCTIONS_H

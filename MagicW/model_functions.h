#ifndef MAGICW_MODEL_FUNCTIONS_H
#define MAGICW_MODEL_FUNCTIONS_H

void convolution1(int mRow, int mCol, float m[mRow][mCol], int kRow, int kCol, int kNum, float k[kNum][kRow][kCol], float bias[kNum], float out[mRow][mCol][kNum]);
void convolution2(int mRow, int mCol, int mDep, float m[mRow][mCol][mDep], int kRow, int kCol, int kNum, float k[kNum][kRow][kCol], float bias[kNum], float out[mRow][mCol][kNum]);
void maxPool(int mRow, int mCol, int mDep, float m[mRow][mCol][mDep], int oRow, int oCol, float out[mRow][mCol][mDep], int kRow, int kCol);
void dense1(int mRow, int mCol, int mDep, float m[mRow][mCol][mDep], int kRow, int kCol, int kNum, float k[kNum][kRow][kCol], float bias[kNum], int oSize, float out[oSize]);
void dense2(int mSize, const float m[mSize], int kSize, int kNum, float k[kNum][kSize], const float bias[kNum], int oSize, float out[oSize]);
void softmax(int mSize, float m[mSize], float out[mSize]);

#endif //MAGICW_MODEL_FUNCTIONS_H

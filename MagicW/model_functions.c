#include <stdio.h>
#include "utils.h"
#include "model_functions.h"
#include <math.h>

void convolution1(int mRow, int mCol, float m[mRow][mCol], int kRow, int kCol, int kNum, float k[kNum][kRow][kCol], float bias[kNum], float out[mRow][mCol][kNum]){

    int d, i, j;

    for (d = 0; d < kNum; d++){
        for (i = 0; i < mRow; i++){
            for (j = 0; j < mCol; j++) {

                out[i][j][d] = m[i][j] * k[d][1][1] + bias[d];

                if (i - 1 >= 0) {
                    out[i][j][d] += m[i-1][j] * k[d][0][1];
                    if (j - 1 >= 0) out[i][j][d] += m[i-1][j-1] * k[d][0][0] + m[i][j-1] * k[d][1][0];
                    if (j + 1 < mCol) out[i][j][d] += m[i-1][j+1] * k[d][0][2] + m[i][j+1] * k[d][1][2];
                } else {
                    if (j - 1 >= 0) out[i][j][d] += m[i][j-1] * k[d][1][0];
                    if (j + 1 < mCol) out[i][j][d] += m[i][j+1] * k[d][1][2];
                }
                if (i + 2 < mRow) {
                    out[i][j][d] += m[i+1][j] * k[d][2][1] + m[i+2][j] * k[d][3][1];
                    if (j - 1 >= 0) out[i][j][d] += m[i+1][j-1] * k[d][2][0] + m[i+2][j-1] * k[d][3][0];
                    if (j + 1 < mCol) out[i][j][d] += m[i+1][j+1] * k[d][2][2] + m[i+2][j+1] * k[d][3][2];
                } else if (i + 1 < mRow) {
                    out[i][j][d] += m[i+1][j] * k[d][2][1];
                    if (j - 1 >= 0) out[i][j][d] += m[i+1][j-1] * k[d][2][0];
                    if (j + 1 < mCol) out[i][j][d] += m[i+1][j+1] * k[d][2][2];
                }

                if (out[i][j][d] < 0) out[i][j][d] = 0;
            }
        }
    }
}

void convolution2(int mRow, int mCol, int mDep, float m[mRow][mCol][mDep], int kRow, int kCol, int kNum, float k[kNum][kRow][kCol], float bias[kNum], float out[mRow][mCol][kNum]){

    int d, h, i, j;

    for (d = 0; d < kNum; d++){
        for (i = 0; i < mRow; i++){
            for (j = 0; j < mCol; j++) {

                out[i][j][d] = bias[d];
                for(h = 0; h < mDep; h++) {
                    out[i][j][d] += m[i][j][h] * k[d][1][h];
                }

                if (i - 1 >= 0) {
                    for(h = 0; h < mDep; h++) {
                        out[i][j][d] += m[i-1][j][h] * k[d][0][h];
                    }
                }
                if (i + 2 < mRow) {
                    for(h = 0; h < mDep; h++) {
                        out[i][j][d] += m[i+1][j][h] * k[d][2][h] + m[i+2][j][h] * k[d][3][h];
                    }
                } else if (i + 1 < mRow) {
                    for(h = 0; h < mDep; h++) {
                        out[i][j][d] += m[i+1][j][h] * k[d][2][h];
                    }
                }

                if (out[i][j][d] < 0) out[i][j][d] = 0;
            }
        }
    }
}

void maxPool(int mRow, int mCol, int mDep, float m[mRow][mCol][mDep], int oRow, int oCol, float out[oRow][oCol][mDep], int kRow, int kCol){

    int i, j, d;

    for (d = 0; d < mDep; d++) {
        for (i = 0; i < mRow; i++) {
            if (i/kRow == oRow) break;
            if (i%kRow == 0){
                out[i/kRow][0][d] = 0;
            }
            for (j = 0; j < mCol; j++) {
                out[i/kRow][0][d] = max(out[i/kRow][0][d], m[i][j][d]);
            }
        }
    }
}

void dense1(int mRow, int mCol, int mDep, float m[mRow][mCol][mDep], int kRow, int kCol, int kNum, float k[kNum][kRow][kCol], float bias[kNum], int oSize, float out[oSize]){

    int d, h, i, j;

    for (d = 0; d < kNum; d++) {
        out[d] = bias[d];
        for (i = 0; i < mRow; i++) {
            for (j = 0; j < mCol; j++) {
                for (h = 0; h < mDep; h++) {
                    out[d] += m[i][j][h] * k[d][i][h];
                }
            }
        }
        if (out[d] < 0) out[d] = 0;
    }
}

void dense2(int mSize, const float m[mSize], int kSize, int kNum, float k[kNum][kSize], const float bias[kNum], int oSize, float out[oSize]){

    int d, i;

    for (d = 0; d < kNum; d++) {
        out[d] = bias[d];
        for (i = 0; i < mSize; i++) {
            out[d] += m[i] * k[d][i];
        }
    }
}

void softmax(int mSize, float m[mSize], float out[mSize]) {

    int i;
    double sum = 0;

    for (i = 0; i < mSize; i++){
        sum += exp((double)m[i]);
    }

    for (i = 0; i < mSize; i++){
        out[i] = (float)(exp((double)m[i])/sum);
    }
}

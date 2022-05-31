#ifndef MAGICWAND_UTILS_H
#define MAGICWAND_UTILS_H

#include <stdio.h>

#define WING 0
#define RING 1
#define SLOPE 2
#define NEGATIVE 3
#define ERROR_THRESHOLD 0.00001

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

void printData2D(int row, int column, float matrix[row][column]);
void printData3D(int row, int column, int depth, float matrix[row][column][depth]);
void write2File(float data[], int size, char fileName[]);
int compareFiles(char file1Name[], char file2Name[]);
void twoComplement(float val, int out[64]);
void twoComplement2File(FILE* file, float val, int out[64]);

#endif //MAGICWAND_UTILS_H

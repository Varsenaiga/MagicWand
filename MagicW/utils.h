#ifndef MAGICW_UTILS_H
#define MAGICW_UTILS_H

#define BATCH 128
#define DATA_SIZE 3
#define WING 0
#define RING 1
#define SLOPE 2
#define NEGATIVE 3

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

void printData2D(int row, int column, float matrix[row][column]);
void printData3D(int row, int column, int depth, float matrix[row][column][depth]);
void write2File(float data[], int size, char fileName[]);
void compareFiles(char file1Name[], char file2Name[]);
void twoComplement(float val, int out[64]);
void twoComplement2File(FILE* file, float val, int out[64]);

#endif //MAGICW_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "file.h"
#include "model_functions.h"
#include "utils.h"
#include "master.h"

FILE* openFile(char name[], const char * mode) {
    FILE * file;

    file = fopen(name, mode);

    if (NULL == file) {
        printf("File can't be opened \n");
    }

    return file;
}

void closeFile(FILE* file) {
    fclose(file);
}

void readFile(FILE* file) {

    char buff[BUFFER_SIZE];
    bool init = true, isReading = false, wasReading = false;
    float dt[BATCH][DATA_SIZE];
    int i, cnt = 0;

    FILE *out = fopen("test.txt", "w");
    if (out == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    for (i = 0; i < BATCH; i++) {
        dt[i][0] = 0;
        dt[i][1] = 0;
        dt[i][2] = 0;
    }

    while (fgets(buff, BUFFER_SIZE, file) != NULL) {
        if (wasReading && !isReading) {
            float data[BATCH][DATA_SIZE];

            for (i = 0; i < cnt; i++) {
                data[BATCH-cnt+i][0] = dt[i][0];
                data[BATCH-cnt+i][1] = dt[i][1];
                data[BATCH-cnt+i][2] = dt[i][2];
            }
            for (i = cnt; i < BATCH; i++) {
                data[i-cnt][0] = 0;
                data[i-cnt][1] = 0;
                data[i-cnt][2] = 0;
            }

            float sMax[1][4];
            //float conv[BATCH][DATA_SIZE][FIRST_NUM_KERNELS];

            master(data, sMax);
            //master(data, conv);

            printf("\nOut:\n");
            printData2D(1, 4, sMax);
            printf("\n\n\n\n");
            for(i = 0; i < 4; i++) {
                fprintf(out, "%.30f\n", sMax[0][i]);
            }
            fprintf(out, "\n");

            /*int d, j;
            for(d = 0; d < FIRST_NUM_KERNELS; d++) {
            	for(i = 0; i < BATCH; i++) {
            		for(j = 0; j < DATA_SIZE; j++) {
            			fprintf(out, "%.30f\t", conv[i][j][d]);
            		}
            		fprintf(out, "\n");
            	}
            	fprintf(out, "\n");
            }
            fprintf(out, "\n");*/

            for (i = 0; i < DATA_SIZE; i++) {
                dt[0][i] = 0;
                dt[1][i] = 0;
                dt[2][i] = 0;
            }
            cnt = 0;
        }
        wasReading = isReading;

        if (strcmp(buff, " -,-,-\n") == 0 || strcmp(buff, "-,-,-\n") == 0) init = true, isReading = true;
        else if (strcmp(buff, "\n") == 0) isReading = false;
        else if (isReading){
            float f1, f2, f3;
            isReading = false;

            char *pt = strtok(buff, ",");
            if (pt != NULL) {
                f1 = strtof(pt, NULL);
            } else continue;
            pt = strtok(NULL, ",");
            if (pt != NULL) {
                f2 = strtof(pt, NULL);
            } else continue;
            pt = strtok(NULL, ",");
            if (pt != NULL) {
                f3 = strtof(pt, NULL);
            } else continue;

            if (init) init = false;

            dt[cnt][0] = f1;
            dt[cnt][1] = f2;
            dt[cnt][2] = f3;
            cnt++;
            if (cnt == 128) isReading = false;
            else isReading = true;
        }
    }
    fclose(out);
}

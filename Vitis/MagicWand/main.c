#include <stdio.h>
#include "utils.h"
#include "file.h"
#include "model_functions.h"

int main() {

	//float data [BATCH][DATA_SIZE];

	FILE* file = openFile("../../../data/negative/output_teste.txt", "r");
	readFile(file);
	closeFile(file);

	printf("\n\nComparing Files:\n");
	int r = compareFiles("original.txt", "test.txt");
	return r;
}

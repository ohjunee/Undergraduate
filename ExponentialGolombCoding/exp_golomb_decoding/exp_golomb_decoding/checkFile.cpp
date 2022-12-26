#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uint8;

void checkFile(FILE* fp_1, FILE* fp_2)
{
	uint8 file_1_val = 0;
	uint8 file_2_val = 0;

	while (feof(fp_2) == 0 && feof(fp_1) == 0) {

		fread(&file_1_val, sizeof(uint8), 1, fp_1);
		fread(&file_2_val, sizeof(uint8), 1, fp_2);

		if (file_1_val != file_2_val)
		{
			printf("두 파일이 다릅니다.\n\n");
			break;
		}
		else
			continue;
	}
}
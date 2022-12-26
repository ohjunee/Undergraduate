#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef unsigned char uint8;

void encoding(uint8* input, uint8* output, uint8* size, FILE* fp_out);

int main()
{
	FILE* fpOutImg = 0;
	FILE* fpInImg = 0;
	uint8 InImg = 0;
	uint8 OutImg = 0;
	uint8 ptr = 0;

	uint8 *ori;

	ori = (uint8*)malloc(sizeof(uint8) * 6);

	ori[0] = 255;
	ori[1] = 253;
	ori[2] = 220;
	ori[3] = 4;
	ori[4] = 18;
	ori[5] = 230;

	//fpInImg = fopen("lena.img", "rb");
	fpOutImg = fopen("lena_sample_e.img", "wb");

	/*if (fpInImg == NULL)
	{
	printf("파일 열기 실패");
	return 1;
	}*/

	//while (true)
	for (int i = 0; i<6; i++)
	{
		//if (feof(fpInImg) != 1)

		//fread(&InImg, sizeof(uint8), 1, fpInImg);

		//encoding(&InImg, &OutImg, &ptr, fpOutImg);
		encoding(&ori[i], &OutImg, &ptr, fpOutImg);
		//}
		//else if (feof(fpInImg) == 1)
		if (i == 5)
		{
			OutImg = OutImg << (8 - (ptr % 8));
			fwrite(&OutImg, sizeof(uint8), 1, fpOutImg);
			//			fprintf(fpOutImg, "%d", OutImg);
			//			printf("%d", OutImg);
			break;
		}
	}
	//fclose(fpInImg);
	free(ori);
	fclose(fpOutImg);
	return 0;
}
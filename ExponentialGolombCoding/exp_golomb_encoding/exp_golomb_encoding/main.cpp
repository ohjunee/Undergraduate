#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef unsigned char uint8;
typedef unsigned int uint32;
void encoding(uint8* input, uint8* output, uint32* size, FILE* fp_in, FILE* fp_out);

int main()
{
	FILE* fpOutImg = 0;
	FILE* fpInImg = 0;
	uint8 InImg = 0;
	uint8 OutImg = 0;
	uint32 ptr = 0;

	fpInImg = fopen("C:\\images\\lena.img", "rb");
	fpOutImg = fopen("C:\\images\\lena_compressed.img", "wb");

	if (fpInImg == NULL)
	{
		printf("파일 열기 실패");
		return 1;
	}
	encoding(&InImg, &OutImg, &ptr, fpInImg, fpOutImg);

	fclose(fpInImg);
	fclose(fpOutImg);
	return 0;
}
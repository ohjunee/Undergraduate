#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uint8;

void checkFile(FILE* fp_1, FILE* fp_2);
void decoding(uint8* input, uint8* output, FILE* fp_in, FILE* fp_out);

int main()

{
	FILE* fp_ori = 0;
	FILE* fp_comp = 0;
	FILE* fp_recon = 0;

	uint8 InImg = 0;
	uint8 OutImg = 0;
	
	fp_comp = fopen("C:\\images\\lena_compressed.img", "rb");
	fp_recon = fopen("C:\\images\\lena_recon.img", "wb");
	
	if (fp_comp == NULL)
	{
		printf("파일 열기 실패\n");
		return 1;
	}

	decoding(&InImg, &OutImg, fp_comp, fp_recon);

	fclose(fp_comp);
	fclose(fp_recon);


	fp_ori = fopen("C:\\images\\lena.img", "rb");			//원본이미지 읽기
	fp_recon = fopen("C:\\images\\lena_recon.img", "rb");	// 복원파일 읽기

	checkFile(fp_ori, fp_recon);

	fclose(fp_ori);
	fclose(fp_comp);
	fclose(fp_recon);

	return 0;
}
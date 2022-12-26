#include <stdio.h>
#include <math.h>

#define log(x,base) (uint8)(log(x)/log(base))

typedef unsigned char uint8;
typedef unsigned int uint32;

uint8 set_bits(uint32 code, uint8 pNum, uint8 bCnt);

void encoding(uint8* input, uint8* output, uint8* size, FILE* fp_out)
{
	uint32 code_num = *input + 1;
	uint8 buffer = 0;
	uint8 cnt = 0;
	uint8 prefixNum = log(code_num, 2);
	uint8 bitLen = prefixNum * 2 + 1;

	while (cnt < bitLen)
	{
		buffer = set_bits(code_num, prefixNum, cnt);
		*output = ((*output << 1) | buffer);
		(*size)++;
		cnt++;

		if (*size % 8 == 0)
		{
			fwrite(output, sizeof(uint8), 1, fp_out);
//			printf("%d ", *output);
			*output = 0;
		}
	}
}

#include <stdio.h>

typedef unsigned char uint8;
typedef unsigned int  uint32;

void decoding(uint8* input, uint8* output, FILE* fp_in, FILE* fp_out)
{
	uint8 buffer = 0;
	uint8 size = 0;
	uint8 lsb = 0;
	uint8 bitLen = 0;

	while (feof(fp_in) == 0)
	{
		fread(input, sizeof(uint8), 1, fp_in); // fread�� �� ����Ʈ ������ ���������Ͱ� �� ĭ �̵�

		if (feof(fp_in) != 0)				// ���������Ͱ� �� ĭ �̵��������� ���� �ƴϸ� ����
		{	
			break;
		}

		for (int cnt = 0; cnt < 8; cnt++)
		{
			buffer = (*input << cnt) & 128 ? 1 : 0;
			*output = *output << 1 | buffer;
			size++;

			if (*output == 1)
			{
				bitLen = (size - 1) * 2 + 1;
			}

			if (size == bitLen)
			{
				*output -= 1;
				fwrite(output, sizeof(uint8), 1, fp_out);
				size = 0;
				bitLen = 0;
				*output = 0;
			}
		}
	}
}
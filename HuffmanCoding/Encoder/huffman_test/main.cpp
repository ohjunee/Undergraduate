#include "Node.h"
#include "input.h"

int main()
{
	Data data;

	checkFile(&data, true);

	int pred_err[PSIZE*PSIZE] =
	{
		-4, -1,  1, -2,
		-6, -4, -1, -1,
		-4, -3, -3, -2,
		-3, -3, -2, -3
	};

	encoding(&data, pred_err, PSIZE);
	checkFile(&data, false);

#if TEST_STRUCT == 0
	printf("\n\n");

	FILE* fp;
	uint8 val;
	fopen_s(&fp, "C:\\images\\TEST_Huffman_Encoder.raw", "rb");

	while (true)
	{
		fread(&val, sizeof(uint8), 1, fp);

		if (feof(fp) != 0)
		{
			break;
		}

		printf("%u ", val);
	}
	fclose(fp);
#endif

	return 0;
}
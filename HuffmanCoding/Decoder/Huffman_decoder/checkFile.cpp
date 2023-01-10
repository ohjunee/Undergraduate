#include "Node.h"
#include "input.h"

void OpenFile(Data* data)
{
	data->fp_in  = fopen(INPUT_FILE, "rb");
	data->fp_out = fopen(OUTPUT_FILE, "wb");

	data->bitCnt = 0;
	data->output = 0;
}

void CloseFile(Data* data)
{
	fclose(data->fp_in);
	fclose(data->fp_out);
}

void checkFile(Data* data, bool Bool)
{
	Bool ? OpenFile(data) : CloseFile(data);
}

void memory_alloc1D(Data* data)
{
	data->symbol = (uint8*)calloc(sizeof(uint8), data->n_symbol);
	data->freq = (uint8*)calloc(sizeof(uint8), data->n_symbol);
}

void memory_free1D(Data* data)
{
	free(data->symbol);
	free(data->freq);
}


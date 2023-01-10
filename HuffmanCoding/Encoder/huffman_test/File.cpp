#include "Node.h"
#include "input.h"

void OpenFile(Data* data)
{
	data->fp_out = fopen(OUTPUT_FILE, "wb");
	memory_alloc1D(data, PSIZE*PSIZE);
}

void CloseFile(Data* data)
{
	fclose(data->fp_out);
	memory_free1D(data);
}

void checkFile(Data* data, bool Bool)
{
	Bool ? OpenFile(data) : CloseFile(data);
}
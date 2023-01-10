#include "Node.h"
#include "input.h"

int main()
{
	Data data;
	checkFile(&data, true);
	decoding(&data, PSIZE);
	checkFile(&data, false);

	return 0;
}
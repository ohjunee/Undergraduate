#include <stdio.h>	
#include <stdlib.h>

double* memory_alloc1D(int size) {

	double* p = (double*)malloc(size * sizeof(double));

	if (p == 0) {
		return 0;
	}
	return p;
}

double memory_free1D(double* p_allocated) {

	if (p_allocated == 0) {
		printf("메모리 부족");
		return -1;
	}
	free(p_allocated);
	return 0;
}

double** memory_alloc2D(int row, int column)

{
	double** ppMem2D = 0;
	int j;

	ppMem2D = (double**)calloc(sizeof(double*), row);

	if (ppMem2D == 0)

	{
		return 0;
	}

	*ppMem2D = (double*)calloc(sizeof(double), column * row);

	if ((*ppMem2D) == 0)
	{
		free(ppMem2D);
		return 0;
	}

	for (j = 1; j < row; j++)
	{
		ppMem2D[j] = ppMem2D[j - 1] + column; // ppMem2D[j], (j=1,2,3 ... row-1)에는 새로운 주소값으로 초기화된다.
	}
	return ppMem2D;
}

double memory_free2D(double** ppMemAllocated) {

	if (ppMemAllocated == 0)

	{
		return -1;
	}
	free(ppMemAllocated[0]);
	free(ppMemAllocated);

	return 0;
}

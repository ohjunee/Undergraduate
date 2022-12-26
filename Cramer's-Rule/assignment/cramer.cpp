#include <stdio.h>
#include <stdlib.h>

double** memory_alloc2D(int row, int column);
double memory_free2D(double** ppMemAllocated);
double cal_det(int size, double** in_matrix);

double do_cramer(double** in_matrix, double* b_matrix, int input_column, int size, int row, int column) {

	int i, j, m, n;

	double** cramer_matrix = 0;

	cramer_matrix = memory_alloc2D(size, size);

	for (i = 0; i < row; i++) {

		for (j = 0; j < column; j++) {

			cramer_matrix[i][j] = in_matrix[i][j];

		}
	}

	for (n = 0; n < row; n++) {

		for (j = input_column, i = 0; i < row; i++) {

			cramer_matrix[i][j] = b_matrix[i];

		}

		m = cal_det(size, cramer_matrix);

		memory_free2D(cramer_matrix);

		return m;
	}
}
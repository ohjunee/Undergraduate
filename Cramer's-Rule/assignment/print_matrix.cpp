#include <stdio.h>	
#include <stdlib.h>

void print_A_matrix(double** input_matrix, int row, int column) {
	int i, j;
	for (i = 0; i < row; i++) {

		printf("|");

		for (j = 0; j < column; j++)
		{
			printf("%3.2lf ", input_matrix[i][j]);
		}

		printf("|\n");
	}
}

void print_det_A(double det_value) {


	if (det_value == 0) {
		printf("\nA 행렬의 Determinant : %4.2f, A 행렬은 비가역행렬입니다.\n", det_value);

		exit(0);
	}

	else {
		printf("\nA행렬의 Determinant : %4.2f\n", det_value);
	}
}
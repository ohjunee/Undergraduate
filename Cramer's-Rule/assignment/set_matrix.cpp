#include <stdio.h>	
#include <stdlib.h>

int set_matrix_size() {

	int matrix_size;

	printf("A 행렬의 크기 입력 : ");
	scanf_s("%d", &matrix_size);
	printf("\n");

	return matrix_size;
}

void set_A_matrix_value(double** A_matrix, int row, int column) {

	int i, j;
	double result;

	for (i = 0; i < row; i++) {

		for (j = 0; j < column; j++) {
			printf("A 행렬의 <%d, %d> 지점 값 입력 : ", i + 1, j + 1);
			scanf_s("%lf", &result);

			A_matrix[i][j] = result;
		}
	}
	printf("\n");
}

void set_b_matrix_value(double* b_matrix, int row) {

	int i;
	double b_value;

	for (i = 0; i < row; i++) {

		printf("b 행렬의 %d 행의 값 입력 : ", i + 1);
		scanf_s("%lf", &b_value);
		b_matrix[i] = b_value;
	}
}
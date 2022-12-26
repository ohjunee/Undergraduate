#include <stdio.h>	
#include <stdlib.h>

double* memory_alloc1D(int size);
double memory_free1D(double* p_allocated);
double** memory_alloc2D(int row, int column);
double memory_free2D(double** ppMemAllocated);

void print_A_matrix(double** input_matrix, int row, int column);
void print_det_A(double det_value);

int set_matrix_size();
void set_A_matrix_value(double** A_matrix, int row, int column);
void set_b_matrix_value(double* b_matrix, int row);

double cal_det(int size, double** in_matrix);
double do_cramer(double** in_matrix, double* b_matrix, int input_column, int size, int row, int column);

int main() {

	int m_size;

	double det_cramer = 0;
	double det = 0;

	int j;

	double** matrix_A;			//in_matrix
	double* matrix_b = NULL;	//b_matrix

	m_size = set_matrix_size();

	while (m_size < 2) {

		printf("행렬의 크기는 2보다 작을 수 없습니다. 다시 입력해주세요.\n");
		printf("\n");
		m_size = set_matrix_size();

	}

	matrix_A = memory_alloc2D(m_size, m_size);
	matrix_b = memory_alloc1D(m_size);

	set_A_matrix_value(matrix_A, m_size, m_size);
	print_A_matrix(matrix_A, m_size, m_size);

	det = cal_det(m_size, matrix_A);

	print_det_A(det);
	printf("\n");

	set_b_matrix_value(matrix_b, m_size);
	printf("\n");

	for (j = 0; j < m_size; j++) {

		det_cramer = do_cramer(matrix_A, matrix_b, j, m_size, m_size, m_size);

		printf("A%d 행렬의 Determinant : %3.2f, x%d = det<A%d> / det<A> = %3.2f\n", j + 1, det_cramer, j + 1, j + 1, det_cramer / det);

	}

	memory_free2D(matrix_A);
	memory_free1D(matrix_b);

	system("pause");
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

double** memory_alloc2D(int row, int column);
double memory_free2D(double** ppMemAllocated);

double cal_det(int size, double** in_matrix) {

	int m = 0;
	int n = 0;
	int i, j, k;
	double det = 0;

	double** out_matrix;

	out_matrix = memory_alloc2D((size - 1), (size - 1));

	if (size == 1) {

		memory_free2D(out_matrix);

		return in_matrix[0][0];

	}

	else if (size == 2) {

		det = in_matrix[0][0] * in_matrix[1][1] - in_matrix[0][1] * in_matrix[1][0];

		memory_free2D(out_matrix);

		return det;
	}

	else {
		for (k = 0; k < size; k++) {

			for (i = 0; i < size; i++) {

				for (j = 0; j < size; j++) {

					if (i != 0 && j != k) {

						out_matrix[m][n] = in_matrix[i][j];

						if ((n % (size - 1)) != size - 2) {

							n = n + 1;
						}

						else {

							n = 0;
							m = m + 1;
						}
					}
				}
			}

			m = 0;

			n = 0;

			if (k % 2 == 0)
			{
				det += in_matrix[0][k] * cal_det(size - 1, out_matrix);
			}

			else {
				det -= in_matrix[0][k] * cal_det(size - 1, out_matrix);
			}
		}

		memory_free2D(out_matrix);

		return det;
	}
}
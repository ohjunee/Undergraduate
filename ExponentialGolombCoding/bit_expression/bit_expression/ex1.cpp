#include <stdio.h>
#include <math.h>

#define log(x, base) (int)(log(x)/log(base))

int main() {

	while (true) {

		int a = 0;
		int b = 0;
		int a1 = 0;

		printf("input the integer number: ");
		scanf_s("%d", &a);
		printf("\n");

		a1 = a + 1; // �Է� ���� 1�� ���Ѵ�.

		if (a < 0) {
			printf("The number is negative. please retry");
			continue;
		}

		b = 2 * log(a1, 2) + 1; //��ȣȭ ��Ʈ ���� ���

		printf("%d\n", b);

		for (int i = log(a, 2); i >= 0; i--) {

			printf("%d", (a & (1 << i)) ? 1 : 0);
		}
		
		printf("\n");

		for (int i = b - 1; i >= 0; i--) { // -1 : 0���� ���� ������ 1�� ���� 

			printf("%d", (a1 & (1 << i)) ? 1 : 0);

		}
	
		printf("\n");
	}
}

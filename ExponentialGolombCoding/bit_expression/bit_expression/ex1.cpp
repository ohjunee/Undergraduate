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

		a1 = a + 1; // 입력 값에 1을 더한다.

		if (a < 0) {
			printf("The number is negative. please retry");
			continue;
		}

		b = 2 * log(a1, 2) + 1; //부호화 비트 길이 계산

		printf("%d\n", b);

		for (int i = log(a, 2); i >= 0; i--) {

			printf("%d", (a & (1 << i)) ? 1 : 0);
		}
		
		printf("\n");

		for (int i = b - 1; i >= 0; i--) { // -1 : 0부터 세기 때문에 1을 빼줌 

			printf("%d", (a1 & (1 << i)) ? 1 : 0);

		}
	
		printf("\n");
	}
}

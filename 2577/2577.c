#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int A, B, C;
	int sum;
	int count[10] = {0};

	scanf("%d %d %d", &A, &B, &C);

	sum = A * B * C;

	while (sum != 0) {
		count[sum % 10] ++;
		sum /= 10;
	}
	for (int i = 0; i < 10; i++)
		printf("%d\n", count[i]);
	return 0;
}
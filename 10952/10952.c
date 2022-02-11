#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int A, B;

	scanf("%d %d", &A, &B);

	while (A || B) {
		printf("%d\n", A + B);
		scanf("%d %d", &A, &B);
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i;
	int T;
	int A, B;

	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		scanf("%d %d", &A, &B);
		printf("%d", A + B);
		printf("\n");
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ARRAY_MAX 10000

int main(void)
{
	int N, X;
	int A[ARRAY_MAX];

	scanf("%d %d", &N, &X);

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	for (int i = 0; i < N; i++)
		if (A[i] < X)
			printf("%d ", A[i]);

	return 0;
}
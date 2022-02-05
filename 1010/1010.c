#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int arr[31][31];
	int i, j;

	int T;
	int N, M;

	for (i = 1; i <= 30; i++) {
		arr[i][0] = 1;
		arr[i][i] = 1;
	}

	for (i = 2; i <= 30; i++) {
		for (j = 1; j < i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}

	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		scanf("%d %d", &N, &M);

		printf("%d\n", arr[M][N]);
	}

	return 0;
}
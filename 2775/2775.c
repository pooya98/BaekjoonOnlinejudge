#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define K_MAX 14
#define N_MAX 14

int main(void)
{
	int T;
	int k, n;
	int room[K_MAX + 1][N_MAX + 1];

	for (int i = 1; i <= N_MAX; i++) {
		room[0][i] = i;
		room[i][0] = 0;
	}

	for (int i = 1; i <= K_MAX; i++)
		for (int j = 1; j <= N_MAX; j++)
			room[i][j] = (room[i - 1][j] + room[i][j - 1]);
	
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &k);
		scanf("%d", &n);

		printf("%d\n", room[k][n]);
	}
	return 0;
}
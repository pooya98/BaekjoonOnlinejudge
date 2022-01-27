#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define BLACK 0
#define WHITE 1

int main(void)
{
	int i, j, x, y;
	int N, M;
	int board[51][51];
	char input[51];
	int cur;
	int min_count = 64;
	int count;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++) {
		scanf("%s", input);
		for (j = 0; j < M; j++) {

			if (input[j] == 'W')
				board[i][j] = WHITE;
			else
				board[i][j] = BLACK;
		}
	}

	for (i = 0; i <= N - 8; i++) {
		for (j = 0; j <= M - 8; j++) {

			cur = BLACK;
			count = 0;
			for (x = i; x <= i + 7; x++) {
				for (y = j; y <= j + 7; y++) {
					if (board[x][y] != cur)
						count++;

					cur = (cur + 1) % 2;
				}
				cur = (cur + 1) % 2;
			}
			if (count < min_count)
				min_count = count;

			if (64 - count < min_count)
				min_count = 64 - count;
		}
	}

	printf("%d", min_count);
	
	return 0;
}
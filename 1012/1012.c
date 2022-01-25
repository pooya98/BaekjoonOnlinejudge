#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_CABBAGE 2500

typedef struct spot {
	int x;
	int y;
}_spot;

int main(void)
{
	int T, M, N, K;
	int i, j, k;
	int count;
	int front, rear;
	int Farm[52][52];
	_spot Queue[MAX_CABBAGE + 1];
	int x, y;
	int cur_x, cur_y;
	int next_x, next_y;

	int dir_x[5] = { 0, 1, 0, -1, 0 };
	int dir_y[5] = { 0, 0, 1, 0, -1 };
	

	scanf("%d", &T);
	
	for (i = 0; i < T; i++) {
		scanf("%d %d %d", &M, &N, &K);

		count = 0;

		for (j = 0; j <= 51; j++)
			for (k = 0; k <= 51; k++)
				Farm[j][k] = 0;

		for (j = 0; j < K; j++) {
			scanf("%d %d", &x, &y);
			Farm[y + 1][x + 1] = 1;
		}

		for (y = 1; y <= N; y++) {
			for (x = 1; x <= M; x++) {
				if (Farm[y][x] == 1) {
					count++;
					front = 0;
					rear = 0;
					Queue[rear].x = x;
					Queue[rear].y = y;
					Farm[y][x] = 2;

					do {
						cur_x = Queue[front].x;
						cur_y = Queue[front].y;
						front++;
						
						for (k = 1; k <= 4; k++) {
							next_x = cur_x + dir_x[k];
							next_y = cur_y + dir_y[k];

							if (Farm[next_y][next_x] == 1) {
								rear++;
								Queue[rear].x = next_x;
								Queue[rear].y = next_y;
								Farm[next_y][next_x]++;
							}
						}
					} while (front <= rear);
					
				}
			}
		}
		printf("%d\n", count);
	}

	return 0;
}
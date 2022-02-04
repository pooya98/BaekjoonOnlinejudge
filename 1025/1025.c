#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
	int N, M;
	char matrix[11][11];
	int max = -1;
	int cur_x, cur_y;
	int value;
	int next_x, next_y;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%s", &matrix[i][1]);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			matrix[i][j] -= 48;
		}
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cur_y = i;
			cur_x = j;
			
			for (int a = -8; a <= 8; a++) {
				if (cur_y + a > 0 && cur_y + a <= N) {
					for (int b = -8; b <= 8; b++) {
						if (cur_x + b > 0 && cur_x + b <= M) {

							if (a == 0 && b == 0) {
								value = matrix[cur_y][cur_x];
								if (sqrt(value) == (int)sqrt(value) && value > max)
									max = value;
							}
							else {
								value = matrix[cur_y][cur_x];
								next_y = cur_y + a;
								next_x = cur_x + b;

								while (next_x > 0 && next_x <= M && next_y > 0 && next_y <= N) {
									value *= 10;
									value += matrix[next_y][next_x];
									next_y += a;
									next_x += b;

									if (sqrt(value) == (int)sqrt(value) && value > max)
										max = value;
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%d", max);

	return 0;
}

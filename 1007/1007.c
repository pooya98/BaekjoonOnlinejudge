#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int N;
int X[21];
int Y[21];
int mark[21];
int complete_num;
int sum_X;
int sum_Y;

long long min_distance;

void marking(int index, int count){
	
	mark[index] = 1;

	if (count == complete_num) {
		long long final_x = sum_X;
		long long final_y = sum_Y;

		for (int i = 1; i <= N; i++) {
			if (mark[i]) {
				final_x -= 2 * X[i];
				final_y -= 2 * Y[i];
			}
		}
		if (final_x * final_x + final_y * final_y < min_distance)
			min_distance = final_x * final_x + final_y * final_y;


		mark[index] = 0;
		return;
	}

	for (int i = index + 1; i <= N; i++) {
		marking(i, count + 1);
	}
	mark[index] = 0;
}

int main(void)
{
	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &N);

		complete_num = N / 2;
		sum_X = 0;
		sum_Y = 0;
		min_distance = 184467440737095;

		for (int j = 1; j <= N; j++) {
			scanf("%d %d", &X[j], &Y[j]);
			sum_X += X[j];
			sum_Y += Y[j];
		}
			

		marking(0, 0);

		printf("%f\n", sqrt(min_distance));
	}

	scanf("%d", &T);
	return 0;
}
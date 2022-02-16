#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define BLACK 1
#define WHITE 0

int main(void)
{
	long long s, N, K, R1, R2, C1, C2;
	long long divisor;
	long long current_divisor;
	long long current_checker;
	long long current_color;
	long long cur_row, cur_col;
	long long gap;

	scanf("%lld %lld %lld %lld %lld %lld %lld", &s, &N, &K, &R1, &R2, &C1, &C2);

	divisor = (long long)pow(N, s);

	for (int row = R1; row <= R2; row++) {
		for (int col = C1; col <= C2; col++) {
			current_color = WHITE;
			current_divisor = divisor;
			cur_row = row;
			cur_col = col;

			while (current_divisor >= N) {
				current_checker = K * current_divisor / N;
				gap = (current_divisor - current_checker) / 2;

				cur_row %= current_divisor;
				cur_col %= current_divisor;

				if ((gap <= cur_row && cur_row < gap + current_checker) && (gap <= cur_col && cur_col < gap + current_checker)) {
					current_color = BLACK;
					break;
				}

				current_divisor /= N;
			}
			printf("%lld", current_color);
		}
		printf("\n");
	}
	return 0;
}
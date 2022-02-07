#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MAX_BUILDING 50

int main(void)
{
	int N;
	int height[MAX_BUILDING + 1];
	int max = 0;
	double max_ratio = 0.0;
	double cur_ratio;
	int count = 0;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d", &height[i]);

	for (int i = 1; i <= N; i++) {
		count = 0;
		max_ratio = -1000000000.0;
		for (int j = i - 1; j > 0; j--) {

			cur_ratio = ((double)(height[j] - height[i])) / (i - j);
			if (max_ratio < cur_ratio) {
				count++;
				max_ratio = cur_ratio;
			}
		}

		max_ratio = -1000000000.0;

		for (int j = i + 1; j <= N; j++) {
			cur_ratio = ((double)height[j] - height[i]) / (j - i);
			if (max_ratio < cur_ratio) {
				count++;
				max_ratio = cur_ratio;
			}
		}

		if (max < count) {
			max = count;
		}
	}

	printf("%d", max);

	return 0;
}
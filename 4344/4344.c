#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ARR_MAX 1000

int main(void)
{
	int C;
	int N;
	int arr[ARR_MAX + 1];
	int sum;
	double average;
	int count;
	
	scanf("%d", &C);

	for (int i = 0; i < C; i++) {
		scanf("%d", &N);

		sum = 0;

		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[j]);
			sum += arr[j];
		}

		average = (double)sum / N;
		count = 0;

		for (int j = 0; j < N; j++) {
			if ((double)arr[j] > average)
				count++;
		}

		printf("%.3f%%\n", (double)count / N * 100);
	}
	return 0;
}
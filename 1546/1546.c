#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int arr[1000];
	int N;
	int max = 0;
	double sum = 0.0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);

		if (arr[i] > max)
			max = arr[i];
	}

	for (int i = 0; i < N; i++) {
		sum += (double)arr[i] / max * 100;
	}

	printf("%.1f", sum / N);

	return 0;
}
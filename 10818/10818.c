#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int min = 1000001;
	int max = -1000001;
	int N;
	int input;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		if (input > max)
			max = input;
		if (input < min)
			min = input;
	}

	printf("%d %d", min, max);
	return 0;
}
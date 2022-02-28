#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int input, min, max;
	int N;

	scanf("%d", &N);

	scanf("%d", &input);

	min = input;
	max = input;

	for (int i = 1; i < N; i++) {
		scanf("%d", &input);

		if (input < min)
			min = input;
		
		if (input > max)
			max = input;
	}

	printf("%d", max * min);
	return 0;
}
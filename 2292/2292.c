#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N;
	int count = 1;
	int upper_bound = 1;

	scanf("%d", &N);

	while (1) {
		if (N <= upper_bound)
			break;

		upper_bound += 6 * count;
		count++;
	}

	printf("%d", count);
	return 0;
}
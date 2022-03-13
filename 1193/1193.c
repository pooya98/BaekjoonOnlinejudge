#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int X;
	int layer = 2;
	int upper_bound = 0;

	scanf("%d", &X);

	for (int i = 1;; i++) {
		upper_bound += i;

		if (X <= upper_bound)
			break;

		layer++;
	}
	if (!(layer % 2)) {
		printf("%d/%d", upper_bound - X + 1, layer - (upper_bound - X + 1));
	}
	else {
		printf("%d/%d", layer - (upper_bound - X + 1), upper_bound - X + 1);

	}

	return 0;
}
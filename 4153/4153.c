#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int side[3];
	int max, max_index;
	int remain;

	while (1) {
		max = 0;
		remain = 0;
		for (int i = 0; i < 3; i++) {
			scanf("%d", &side[i]);

			remain += (side[i] * side[i]);

			if (max < side[i]) {
				max = side[i];
				max_index = i;
			}
		}

		remain -= (side[max_index] * side[max_index]);

		if (remain == 0)
			break;

		if ((side[max_index] * side[max_index]) == remain)
			printf("right\n");
		else
			printf("wrong\n");
	}

	return 0;
}
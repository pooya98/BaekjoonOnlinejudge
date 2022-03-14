#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int A, B, V;
	int day;
	int cur_height;

	scanf("%d %d %d", &A, &B, &V);

	day = (V - A) / (A - B);
	cur_height = day * (A - B);

	while (1) {
		day += 1;
		cur_height += A;

		if (cur_height >= V)
			break;

		cur_height -= B;
	}

	printf("%d", day);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x1, y1;
	int x2, y2;

	int C, N;

	int cx, cy, r;

	int i, j;

	int c_to_1, c_to_2;

	int count;

	scanf("%d", &C);

	for (i = 0; i < C; i++)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		scanf("%d", &N);

		count = 0;

		for (j = 0; j < N; j++)
		{
			scanf("%d %d %d", &cx, &cy, &r);

			c_to_1 = (cx - x1)*(cx - x1) + (cy - y1)*(cy - y1);
			c_to_2 = (cx - x2)*(cx - x2) + (cy - y2)*(cy - y2);

			if (((c_to_1 < r*r) && (c_to_2 > r*r)) || ((c_to_1 > r*r) && (c_to_2 < r*r))) {
				count++;
			}
		}
		printf("%d\n", count);
	}

	return 0;
}
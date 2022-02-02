#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N;
	int x1, x2, y1, y2, r1, r2;
	int i;
	int distance_squal;
	int distance_between_turret_squal;
	int distance_neg_squal;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		distance_between_turret_squal = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
		distance_squal = (r1 + r2)*(r1 + r2);

		if (r1 > r2) {
			distance_neg_squal = (r1 - r2)*(r1 - r2);
		}
		else {
			distance_neg_squal = (r2 - r1)*(r2 - r1);
		}


		if (distance_between_turret_squal)
		{
			if (distance_between_turret_squal > distance_squal)
			{
				printf("0\n");
			}
			else if (distance_between_turret_squal == distance_squal || distance_between_turret_squal == distance_neg_squal)
			{
				printf("1\n");
			}
			else if (distance_neg_squal > distance_between_turret_squal)
			{
				printf("0\n");
			}
			else
			{
				printf("2\n");
			}
		}
		else {
			if (r1 == r2)
			{
				if (r1 == 0)
					printf("1\n");
				else
					printf("-1\n");
			}
			else {
				printf("0\n");
			}
		}

	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
	int T;
	long long x, y;
	int i;
	double gap;
	double sqrt_gap;
	long long low_limit;

	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		scanf("%lld %lld", &x, &y);
		gap = (double)(y - x);

		sqrt_gap = sqrt(gap);
		low_limit = (long long)floor(sqrt_gap);

		if (pow((double)low_limit, 2) == gap)
			printf("%lld\n", 2 * low_limit - 1);
		else if (pow((double)low_limit, 2) + (double)low_limit >= gap)
			printf("%lld\n", 2 * low_limit);
		else
			printf("%lld\n", 2 * low_limit + 1);

	}
	return 0;
}
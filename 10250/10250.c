#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int T;
	int H, W, N;

	int floor;
	int unit;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &H, &W, &N);

		floor = N % H;
		if (floor == 0)
			floor = H;

		unit = N / H;
		if (N % H != 0)
			unit++;
		printf("%d%02d\n", floor, unit);
	}
	return 0;
}
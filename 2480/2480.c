#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int try1, try2, try3;
	int prize = 0;
	int max = 0;

	scanf("%d %d %d", &try1, &try2, &try3);

	if (try1 == try2 && try1 == try3) {
		prize = 10000 + try1 * 1000;
	}
	else if (try1 != try2 && try2 != try3 && try3 != try1) {
		int max = 0;
		if (try1 > max)
			max = try1;
		if (try2 > max)
			max = try2;
		if (try3 > max)
			max = try3;

		prize = max * 100;
	}
	else {
		if (try1 == try2) {
			prize = 1000 + try1 * 100;
		}
		else if (try2 == try3) {
			prize = 1000 + try2 * 100;
		}
		else {
			prize = 1000 + try3 * 100;
		}
	}

	printf("%d", prize);
	return 0;
}
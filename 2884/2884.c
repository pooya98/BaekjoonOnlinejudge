#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int H, M;

	scanf("%d %d", &H, &M);

	M -= 45;

	if (M < 0) {
		H -= 1;
		M += 60;
	}

	if (H < 0)
		H += 24;

	printf("%d %d", H, M);
	return 0;
}
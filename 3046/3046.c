#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int R1, S;
	int R2;

	scanf("%d %d", &R1, &S);

	R2 = 2 * S - R1;

	printf("%d", R2);
	return 0;
}
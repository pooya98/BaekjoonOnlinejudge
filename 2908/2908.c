#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int A, B;

	scanf("%d %d", &A, &B);

	A += (A % 10) * 10000;
	A /= 10;
	A += (A % 10) * 100;
	A /= 10;

	B += (B % 10) * 10000;
	B /= 10;
	B += (B % 10) * 100;
	B /= 10;

	if (A > B)
		printf("%d", A);
	else
		printf("%d", B);

	return 0;
}
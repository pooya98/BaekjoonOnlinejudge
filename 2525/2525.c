#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int A, B;
	int C;

	scanf("%d %d", &A, &B);
	scanf("%d", &C);

	B += C;

	while (B > 59) {
		B -= 60;
		A++;
	}

	A = A % 24;

	printf("%d %d", A, B);
	return 0;
}
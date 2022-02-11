#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N;
	int changed_num;
	int A, B;
	int cycle = 0;

	scanf("%d", &N);

	changed_num = N;

	do {
		A = changed_num / 10;
		B = changed_num % 10;

		changed_num = B * 10 + (A + B) % 10;
		cycle++;
	} while (changed_num != N);

	printf("%d", cycle);
	return 0;
}
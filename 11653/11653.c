#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	for (int i = 2; i <= N; i++) {
		while (!(N % i)) {
			printf("%d\n", i);
			N /= i;
		}
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N;
	char string[101];
	int sum = 0;

	scanf("%d", &N);

	scanf("%s", string);
	for (int i = 0; i < N; i++)
		sum += (int)(string[i] - '0');

	printf("%d", sum);

	return 0;
}
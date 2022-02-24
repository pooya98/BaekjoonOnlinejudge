#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int count = 0;
	char input[1000001];

	while (scanf("%s", input) != EOF) {
		count++;
	}

	printf("%d", count);

	return 0;
}
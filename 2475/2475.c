#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int sum = 0;
	int input;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &input);

		sum += (input * input);
	}

	printf("%d", sum % 10);
	return 0;
}
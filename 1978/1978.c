#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N;
	int temp;
	int count;
	int result = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);

		count = 0;
		for (int j = 1; j <= temp; j++)
			if (!(temp % j))
				count++;

		if (count == 2)
			result++;
	}

	printf("%d", result);
	return 0;
}
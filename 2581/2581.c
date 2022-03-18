#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int M, N;
	int sum = 0;
	int min;
	int count[10001] = {0};
	int index;

	scanf("%d %d", &M, &N);

	count[1] = 2;

	for (int i = 2; i <= N; i++) {
		index = i;
		while (index <= N) {
			count[index]++;
			index += i;
		}
	}

	for (int i = M; i <= N; i++) {
		if (count[i] < 2) {
			if (sum == 0)
				min = i;
			sum += i;
		}
	}

	

	if (sum == 0)
		printf("-1");
	else
		printf("%d\n%d", sum, min);

	return 0;
}
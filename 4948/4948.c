#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N_MAX 123456

int arr[2 * N_MAX + 1] = { 0 };

int main(void)
{
	int n;
	int count;
	int index;
	int max = 2 * N_MAX;

	arr[1] = 2;

	for (int i = 2; i <= max; i++) {
		index = i;
		
		while (index <= max) {
			arr[index]++;
			index += i;
		}
	}

	while (1) {
		scanf("%d", &n);

		if (n == 0)
			break;

		count = 0;
		for (int i = n + 1; i <= (2 * n); i++)
			if (arr[i] < 2)
				count++;

		printf("%d\n", count);
	}
	return 0;
}
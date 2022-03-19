#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N_MAX 10000

int arr[N_MAX + 1] = { 0 };

int main(void)
{
	int n;
	int index;
	int T;

	arr[1] = 2;

	for (int i = 2; i <= N_MAX; i++) {
		index = i;

		while (index <= N_MAX) {
			arr[index]++;
			index += i;
		}
	}

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &n);

		for (int i = n / 2; i > 1; i--) {
			if (arr[i] < 2 && arr[n - i] < 2) {
				printf("%d %d\n", i, n - i);
				break;
			}
		}
	}

	return 0;
}
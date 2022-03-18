#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int M, N;
	char arr[1000001] = { 0 };
	// BOJ -> int arr[1000001] = { 0 };
	int index;

	scanf("%d %d", &M, &N);

	for (int i = 2; i <= N; i++) {

		index = i;

		while (index <= N) {
			arr[index]++;
			index += i;
		}
	}

	arr[1] = 2;
	for (int i = M; i <= N; i++)
		if (arr[i] < 2)
			printf("%d\n", i);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int d(int n) {
	int origin = n;
	int result = origin;

	while (origin > 0) {
		result += (origin % 10);
		origin /= 10;
	}

	return result;
}

int main(void)
{
	int generator;
	int arr[10001] = { 0 };

	for (int i = 1; i < 10000; i++) {
		if (arr[i] == 0) {
			generator = d(i);

			while (generator <= 10000) {
				arr[generator]++;
				generator = d(generator);
			}
		}
	}

	for (int i = 1; i <= 10000; i++) {
		if (arr[i] == 0)
			printf("%d\n", i);
	}
	return 0;
}
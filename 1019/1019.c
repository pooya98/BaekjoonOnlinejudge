#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int count[10] = {0};

void Q(int weight, int num);
void P(int weight, int start, int end);

int main(void)
{
	int N;

	scanf("%d", &N);

	Q(1, N);

	for (int i = 0; i < 10; i++)
		printf("%d ", count[i]);


	return 0;
}

void Q(int weight, int num) {
	if (num <= 0)
		return;

	int m = num / 10;
	int n = num % 10;

	count[0] -= weight;

	P(weight * (m + 1), 0, n);
	P(weight * m, n + 1, 9);

	Q(weight * (n + 1), m);
	Q(weight * (9 - n), m - 1);

}

void P(int weight, int start, int end) {

	if (weight == 0)
		return;

	for (int i = start; i <= end; i++) {
		count[i] += weight;
	}
}
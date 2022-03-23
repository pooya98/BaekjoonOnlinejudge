#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int N, M;
int arr[101];
int solution;
int min_gap = 100000000;

void find_solution(int start, int count, int sum) {
	if (start >= N)
		return;
	else {
		if (count == 3) {
			if (min_gap > abs(M - sum)) {
				min_gap = abs(M - sum);
				solution = sum;
			}
			return;
		}
		else {
			for (int i = start; i < N - 2; i++) {
				find_solution(i + 1, count + 1, sum + arr[i]);
				find_solution(i + 1, count, sum);
			}
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	find_solution(0, 0, 0);

	printf("%d", solution);

	return 0;
}
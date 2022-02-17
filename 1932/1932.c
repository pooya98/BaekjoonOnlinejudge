#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void cal(int n);
int arr[501][501] = { 0, };
int max_each[501][501] = { 0, };
int max = 0;

int main(int argc, char *argv[])
{
	//FILE *f;
	int i, j = 1, k = 1;
	int temp;
	int n;
	//f = fopen(argv[1], "r");

	scanf("%d", &n);
	for (i = 1; i <= (n * (n + 1)) / 2; i++) {
		scanf("%d", &temp);
		arr[j][k] = temp;
		k++;
		if (k > j) {
			j++;
			k = 1;
		}
	}

	cal(n);
	printf("%d", max);
}

void cal(int n) {
	int i, j;

	max_each[1][1] = arr[1][1];
	for (i = 1; i < n; i++) {
		for (j = 1; j <= i; j++) {
			if (max_each[i + 1][j] <= max_each[i][j] + arr[i + 1][j])
				max_each[i + 1][j] = max_each[i][j] + arr[i + 1][j];
			if (max_each[i + 1][j + 1] <= max_each[i][j] + arr[i + 1][j + 1])
				max_each[i + 1][j + 1] = max_each[i][j] + arr[i + 1][j + 1];
		}
	}
	for (i = 1; i <= n; i++)
	{
		if (max_each[n][i] > max)
			max = max_each[n][i];
	}
}
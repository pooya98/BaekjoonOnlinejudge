#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int count[40][2] = { 0 };

int main(void)
{
	int n, temp;

	count[0][0] = 1;
	count[0][1] = 0;
	count[1][0] = 0;
	count[1][1] = 1;

	for (int i = 2; i <= 40; i++) {
		count[i][0] = count[i - 1][0] + count[i - 2][0];
		count[i][1] = count[i - 1][1] + count[i - 2][1];
	}

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		printf("%d %d\n", count[temp][0], count[temp][1]);
	}

	return 0;
}
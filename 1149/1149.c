#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_NUMBER 1001

int house[MAX_NUMBER][3] = { 0 };
int min[MAX_NUMBER][3] = { 0 };

int minimum_cost(int n);
int calculate_min(int n, int color);

int main(void)
{
	int n, r, g, b;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &r, &g, &b);
		house[i][0] = r;
		house[i][1] = g;
		house[i][2] = b;
	}

	printf("%d", minimum_cost(n));

	return 0;
}

int minimum_cost(int n) {
	int min;
	int min_R = calculate_min(n, 0);
	int min_G = calculate_min(n, 1);
	int min_B = calculate_min(n, 2);

	min = (min_R < min_G) ? min_R : min_G;
	min = (min < min_B) ? min : min_B;

	return min;
}

int calculate_min(int n, int color) {
	int minimum;
	min[1][0] = 1001;
	min[1][1] = 1001;
	min[1][2] = 1001;

	min[1][color] = house[1][color];
	for (int i = 2; i <= n; i++) {
		min[i][0] = house[i][0] + ((min[i - 1][1] < min[i - 1][2]) ? min[i - 1][1] : min[i - 1][2]);
		min[i][1] = house[i][1] + ((min[i - 1][0] < min[i - 1][2]) ? min[i - 1][0] : min[i - 1][2]);
		min[i][2] = house[i][2] + ((min[i - 1][0] < min[i - 1][1]) ? min[i - 1][0] : min[i - 1][1]);
	}
	minimum = (min[n][0] < min[n][1]) ? min[n][0] : min[n][1];
	minimum = (minimum < min[n][2]) ? minimum : min[n][2];

	return minimum;
}
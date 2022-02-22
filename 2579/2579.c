#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int stairs[301] = { 0 };
int m[301] = { 0 };

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}
int main(void)
{
	int number = 0;
	int temp = 0;

	scanf("%d", &number);
	for (int i = 1; i <= number; i++) {
		scanf("%d", &temp);
		stairs[i] = temp;
	}
	m[1] = stairs[1];
	m[2] = stairs[1] + stairs[2];

	for (int i = 3; i <= number; i++) {
		m[i] = max(stairs[i - 1] + m[i - 3], m[i - 2]) + stairs[i];
	}
	printf("%d", m[number]);
	return 0;
}
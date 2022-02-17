#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>

void HanoiTowerMove(int num, int from, int by, int to);
void print_move_count(int n);

int main(void)
{
	int n;

	scanf("%d", &n);
	print_move_count(n);

	if (n <= 20)
		HanoiTowerMove(n, 1, 2, 3);

	return 0;
}

void HanoiTowerMove(int num, int from, int by, int to) {

	if (num == 1) {
		printf("%d %d\n", from, to);
	}
	else {
		HanoiTowerMove(num - 1, from, to, by);
		printf("%d %d\n", from, to);
		HanoiTowerMove(num - 1, by, from, to);
	}
}

void print_move_count(int n) {
	char cp[100];
	char des[100] = "";

	sprintf(cp, "%.0f", pow(2, n));
	strncpy(des, cp, strlen(cp) - 1);
	printf("%s", des);

	switch (n % 4) {
	case 1:
		printf("1");
		break;
	case 2:
		printf("3");
		break;
	case 3:
		printf("7");
		break;
	case 0:
		printf("5");
		break;
	}
	printf("\n");
}
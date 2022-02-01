#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void) 
{
	int x, y;
	int y1, x1, y2, x2;
	int num;
	int i, j, k;
	int arr[51][51];
	int max;
	int divisor;
	int digit_count;

	scanf("%d %d %d %d", &y1, &x1, &y2, &x2);

	i = 0;
	max = 0;
	for (y = y1; y <= y2; y++) {
		j = 0;
		for (x = x1; x <= x2; x++) {
			if (abs(y) >= abs(x)) {
				if (y < 0) {
					num = (int)pow((1 + 2 * abs(y)), 2) - 5 * abs(y);
					num -= x;
					arr[i][j++] = num;
				}
				else {
					num = (int)pow((1 + 2 * abs(y)), 2) - abs(y);
					num += x;
					arr[i][j++] = num;
				}
			}
			else {
				if (x < 0) {
					num = (int)pow((1 + 2 * abs(x)), 2) - 3 * abs(x);
					num += y;
					arr[i][j++] = num;
				}
				else {
					num = (int)pow((1 + 2 * abs(x)), 2) - 7 * abs(x);
					num -= y;
					arr[i][j++] = num;
				}
			}
			if (num > max)
				max = num;
		}
		i++;
	}


	divisor = 10;
	digit_count = 1;
	while (max / divisor != 0) {
		divisor *= 10;
		digit_count++;
	}

	for (i = 0; i <= y2 - y1; i++) {
		for (j = 0; j <= x2 - x1; j++) {

			int my_digit_count = 1;
			divisor = 10;
			while (arr[i][j] / divisor != 0) {
				divisor *= 10;
				my_digit_count++;
			}
			for (k = 0; k < digit_count - my_digit_count; k++)
				printf(" ");

			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
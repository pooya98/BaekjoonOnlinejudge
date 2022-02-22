#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TRUE 0
#define FALSE 1

int main(void)
{
	int N;
	int count = 0;
	int flag;
	int temp;
	int common_difference;

	scanf("%d", &N);

	for (int i = N; i > 0; i--) {
		flag = TRUE;
		temp = i;

		common_difference = temp % 10 - (temp / 10) % 10;

		while ((temp / 10) != 0) {
			if ((temp % 10 - (temp / 10) % 10) != common_difference) {
				flag = FALSE;
				break;
			}
			temp /= 10;
		}

		if (flag == TRUE)
			count++;
	}

	printf("%d", count);
	return 0;
}
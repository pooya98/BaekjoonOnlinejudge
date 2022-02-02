#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main(void)
{
	int i, j;
	int N, L;
	int num;
	int start;
	int flag_not = TRUE;

	scanf("%d %d", &N, &L);

	for (i = L; i <= 100; i++) {
		if (i % 2 == 0) {
			num = N - i * (i - 1) / 2;

			if (num % i == 0) {
				start = num / i;

				if (start < 0) {
					flag_not = TRUE;
				}
				else {
					flag_not = FALSE;
					for (j = 1; j <= i; j++) {
						if (j == i) {
							printf("%d", start++);
						}
						else {
							printf("%d ", start++);
						}
					}
					break;
				}
			}
		}
		else {
			num = N;

			if (num % i == 0) {
				start = num / i - i / 2;

				if (start < 0) {
					flag_not = TRUE;
				}
				else {
					flag_not = FALSE;
					for (j = 1; j <= i; j++) {
						if (j == i) {
							printf("%d", start++);
						}
						else {
							printf("%d ", start++);
						}
					}
					break;
				}
			}
		}

	}

	if (flag_not == TRUE) {
		printf("-1");
	}
	return 0;
}
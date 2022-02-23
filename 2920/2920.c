#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ASCENDING 0
#define DESCENDING 1
#define MIXED 2

#define TRUE 1
#define FALSE 2

int main(void)
{
	int difference;
	int prev, cur;
	int mixed_flag = FALSE;

	scanf("%d", &prev);
	scanf("%d", &cur);

	difference = cur - prev;

	for (int i = 0; i < 6; i++) {
		prev = cur;
		scanf("%d", &cur);

		if ((cur - prev) != difference) {
			mixed_flag = TRUE;
			break;
		}
	}
	if (mixed_flag == TRUE || (difference != -1 && difference != 1)) {
		printf("mixed");
	}
	else {
		if(difference == 1)
			printf("ascending");
		else
			printf("descending");
	}

	return 0;
}
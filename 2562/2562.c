#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int input;
	int max_index = 0;
	int max_value = 0;
	for (int i = 1; i <= 9; i++) {
		scanf("%d", &input);

		if (input > max_value) {
			max_index = i;
			max_value = input;
		}
	}
	printf("%d\n%d", max_value, max_index);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ARRAY_MAX 80

int main(void)
{
	int i, j;
	int T;
	char input[ARRAY_MAX + 1];
	int point;
	int result;

	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		scanf("%s", input);

		j = 0;
		point = 1;
		result = 0;

		while (input[j]) {
			if (input[j] == 'O')
				result += point++;
			else
				point = 1;

			j++;
		}
		printf("%d\n", result);
	}
	return 0;
}
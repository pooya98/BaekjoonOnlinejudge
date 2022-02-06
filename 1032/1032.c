#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char string[51];
	char comp_string[51];
	int N;
	int i, j;

	scanf("%d", &N);

	scanf("%s", string);

	for (i = 0; i < N - 1; i++)
	{
		scanf("%s", comp_string);

		for (j = 0;; j++) {
			if (string[j] == '\0')
				break;
			if (string[j] != comp_string[j])
				string[j] = '?';
		}
	}

	for (i = 0;; i++) {
		if (string[i] == '\0')
			break;
		if (string[i] != '.')
			printf("%c", string[i]);
		else
			printf(".");
	}

	return 0;
}
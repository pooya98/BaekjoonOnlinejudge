#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char string[16];
	int time = 0;

	scanf("%s", string);

	for (int i = 0; string[i] != '\0'; i++) {
		if (string[i] >= 'A' && string[i] <= 'C')
			time += 3;
		else if (string[i] >= 'D' && string[i] <= 'F')
			time += 4;
		else if (string[i] >= 'G' && string[i] <= 'I')
			time += 5;
		else if (string[i] >= 'J' && string[i] <= 'L')
			time += 6;
		else if (string[i] >= 'M' && string[i] <= 'O')
			time += 7;
		else if (string[i] >= 'P' && string[i] <= 'S')
			time += 8;
		else if (string[i] >= 'T' && string[i] <= 'V')
			time += 9;
		else if (string[i] >= 'W' && string[i] <= 'Z')
			time += 10;
		else
			continue;
	}

	printf("%d", time);

	return 0;
}
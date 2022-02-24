#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MULTI 0
#define SINGLE 1

int main(void)
{
	char input[1000001];
	int length;
	int count[26] = { 0 };
	int max = 0;
	int max_index;
	int flag;

	scanf("%s", input);
	length = strlen(input);

	for (int i = 0; i < length; i++) {
		if (input[i] >= 'a' && input[i] <= 'z')
			count[input[i] - 'a']++;
		else
			count[input[i] - 'A']++;
	}

	for (int i = 0; i < 26; i++) {
		if (count[i] > max) {
			max = count[i];
			max_index = i;
			flag = SINGLE;
		}
		else if (count[i] == max)
			flag = MULTI;
		else
			continue;
	}

	if (flag == SINGLE)
		printf("%c", (char)(max_index + 'A'));
	else
		printf("?");

	return 0;
}
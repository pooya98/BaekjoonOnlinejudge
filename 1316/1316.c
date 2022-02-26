#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define USED 0
#define UNUSED 1

#define PASS 0
#define FAIL 1

int main(void)
{
	int T;
	int count = 0;
	char input[101];
	int alphabet_check[26];
	int length;
	char prev_char;
	int flag;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {

		for (int j = 0; j < 26; j++)
			alphabet_check[j] = UNUSED;

		flag = PASS;
	
		scanf("%s", input);
		length = strlen(input);

		prev_char = '0';

		for (int j = 0; j < length; j++) {
			if (input[j] == prev_char)
				continue;
			else {
				if (alphabet_check[input[j] - 'a'] == USED) {
					flag = FAIL;
					break;
				}
				else {
					alphabet_check[input[j] - 'a'] = USED;
					prev_char = input[j];
				}
			}
		}
		if (flag == PASS)
			count++;
	}

	printf("%d", count);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char input_string[103] = {0};
	int count = 0;
	int length;

	scanf("%s", input_string);
	length = strlen(input_string);

	for (int i = 0; i < length;) {
		if (input_string[i] == 'c') {
			if (input_string[i + 1] == '=' || input_string[i + 1] == '-')
				i++;
		}
		else if (input_string[i] == 'd') {
			if (input_string[i + 1] == 'z' && input_string[i + 2] == '=')
				i += 2;
			else if (input_string[i + 1] == '-')
				i++;
		}
		else if (input_string[i] == 'l') {
			if (input_string[i + 1] == 'j') {
				i++;
			}
		}
		else if (input_string[i] == 'n') {
			if (input_string[i + 1] == 'j')
				i++;
		}
		else if (input_string[i] == 's') {
			if (input_string[i + 1] == '=')
				i++;
		}
		else if (input_string[i] == 'z') {
			if (input_string[i + 1] == '=')
				i++;
		}

		count++;
		i++;
	}

	printf("%d", count);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define STR_MAX_LEN 200

#define TRUE 0
#define FALSE 1

int main(void) 
{
	int i, j;

	int T;
	char input_string[STR_MAX_LEN + 1];

	int top;
	char stack[STR_MAX_LEN + 1];

	int input_string_len;

	int count_zero_flag;
	int start_zero_flag;
	int no_flag;

	char start_char;

	int reduction_count;
	int reduction_zero_count;

	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		scanf("%s", input_string);

		top = -1;

		input_string_len = strlen(input_string);

		for (j = 0; j < input_string_len; j++) {
			if (input_string[j] == '\0')
				break;

			stack[++top] = input_string[j];
		}

		count_zero_flag = TRUE;
		start_zero_flag = FALSE;
		no_flag = FALSE;

		while (top >= 0) {
			count_zero_flag = FALSE;
			start_char = stack[top--];

			if (start_char == '1') {
				reduction_count = 0;
				while (top >= 0 && stack[top] == '0') {
					top--;
					reduction_count++;
				}
				if (reduction_count == 0) {
					if (top == -1) {
						no_flag = TRUE;
						break;
					}
					else {
						while (stack[top] == '1') {
							top--;
						}

						reduction_zero_count = 0;

						if (top >= 2) {
							while (stack[top] == '0') {
								top--;
								reduction_zero_count++;
							}

							if (reduction_zero_count >= 2 && top >= 0) {
								top--;
							}
							else {
								no_flag = TRUE;
								break;
							}
						}
						else {
							no_flag = TRUE;
							break;
						}
					}
				}
				else if (reduction_count == 1) {
					continue;
				}
				else {
					if (top >= 0 && stack[top] == '1') {
						top--;
					}
					else {
						no_flag = TRUE;
						break;
					}
				}
			}
			else {
				start_zero_flag = TRUE;
				break;
			}

		}

		if (start_zero_flag == TRUE || no_flag == TRUE || count_zero_flag == TRUE)
			printf("NO\n");
		else
			printf("YES\n");
	}

	return 0;
}
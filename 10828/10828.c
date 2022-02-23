#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	int N;
	char instruction[10];
	int input;
	int stack[10002];
	int top = -1;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", instruction);

		if (!strcmp(instruction, "push")) {
			scanf("%d", &input);

			stack[++top] = input;
		}
		else if(!strcmp(instruction, "pop")){
			if (top > -1)
				printf("%d\n", stack[top--]);
			else
				printf("-1\n");
		}
		else if (!strcmp(instruction, "size")) {
			printf("%d\n", top + 1);
		}
		else if (!strcmp(instruction, "empty")) {
			if (top > -1)
				printf("0\n");
			else
				printf("1\n");
		}
		else if (!strcmp(instruction, "top")) {
			if (top > -1)
				printf("%d\n", stack[top]);
			else
				printf("-1\n");
		}
		else {
			continue;
		}
	}
	return 0;
}
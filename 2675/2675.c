#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	int T;
	int R;
	char string[21];
	int length;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &R);
		scanf("%s", string);
		
		length = strlen(string);
		
		for (int j = 0; j < length; j++) {
			for (int k = 0; k < R; k++)
				printf("%c", string[j]);
		}
		printf("\n");
	}
	return 0;
}
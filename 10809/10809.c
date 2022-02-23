#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char S[101];
	int arr[26];
	int length;

	scanf("%s", S);

	length = strlen(S);

	for (int i = 0; i < 26; i++)
		arr[i] = 101;

	for (int i = 0; i < length; i++) {
		if (arr[(S[i] - 'a')] > i)
			arr[(S[i] - 'a')] = i;
	}

	for (int i = 0; i < 26; i++) {
		if (arr[i] == 101)
			printf("-1 ");
		else
			printf("%d ", arr[i]);
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char arr1[10001];
	char arr2[10001];
	int result[10002] = { 0 };
	int count = 0;

	int index_arr1;
	int index_arr2;

	scanf("%s %s", arr1, arr2);

	index_arr1 = strlen(arr1) - 1;
	index_arr2 = strlen(arr2) - 1;

	while (index_arr1 >= 0 || index_arr2 >= 0) {
		if (index_arr1 >= 0)
			result[count] += (arr1[index_arr1] - '0');

		if (index_arr2 >= 0)
			result[count] += (arr2[index_arr2] - '0');

		if (result[count] > 9) {
			result[count] -= 10;
			result[count + 1]++;
		}

		index_arr1--;
		index_arr2--;
		count++;

	}
	if (result[count] == 0) {
		for (int i = count - 1; i >= 0; i--)
			printf("%d", result[i]);
	}
	else {
		for (int i = count; i >= 0; i--)
			printf("%d", result[i]);
	}

	return 0;
}
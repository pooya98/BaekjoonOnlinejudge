#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ARR_MAX 5000

int main(void)
{
	int N;
	int arr[ARR_MAX + 1];

	for (int i = 1; i <= ARR_MAX; i++)
		arr[i] = -1;

	arr[3] = 1;
	arr[5] = 1;
	
	scanf("%d", &N);

	for (int i = 6; i <= N; i++) {
		if (arr[i - 3] > 0 && arr[i - 5] > 0)
			arr[i] = (arr[i - 3] < arr[i - 5]) ? arr[i - 3] + 1 : arr[i - 5] + 1;
		
		else if (arr[i - 3] > 0)
			arr[i] = arr[i - 3] + 1;
		
		else if (arr[i - 5] > 0)
			arr[i] = arr[i - 5] + 1;
		
		else
			continue;
	}

	printf("%d", arr[N]);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_N 50

int main(void)
{
	int i, j;

	int N;
	int arr_A[MAX_N + 1];
	int arr_P[MAX_N + 1];
	int count = 0;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &arr_A[i]);
	}

	for (i = 0; i <= 1000; i++) {
		for (j = 0; j < N; j++){
			if (arr_A[j] == i)
				arr_P[j] = count++;
		}
	}
	
	for (i = 0; i < N; i++) {
		printf("%d ", arr_P[i]);
	}
	

	return 0;
}
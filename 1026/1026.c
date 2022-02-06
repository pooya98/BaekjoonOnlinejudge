#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

int partition(int list[], int left, int right) {
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];

	do {
		do {
			low++;
		} while (low <= right && list[low] < pivot);

		do {
			high--;
		} while (high >= left && list[high] > pivot);

		if (low < high)
			SWAP(list[low], list[high], temp);

	} while (low < high);

	SWAP(list[left], list[high], temp);

	return high;
}

void quick_sort(int list[], int left, int right) {

	if (left < right) {
		int q = partition(list, left, right);

		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}

}

int main(void)
{
	int N;
	int A[50], B[50];
	int S = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	for (int i = 0; i < N; i++)
		scanf("%d", &B[i]);

	quick_sort(A, 0, N - 1);
	quick_sort(B, 0, N - 1);

	for (int i = 0; i < N; i++) {
		S += A[i] * B[N - 1 - i];
	}
	printf("%d", S);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N;
	int a, b;
	int i;

	int arr[10][4] = { {10,10,10,10},{1,1,1,1},
					  {6,2,4,8},{1,3,9,7},
					  {6,4,6,4},{5,5,5,5},
					  {6,6,6,6},{1,7,9,3},
					  {6,8,4,2},{1,9,1,9} };

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d %d", &a, &b);

		printf("%d\n", arr[a % 10][b % 4]);
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	int N;
	int front, rear;
	int arr[10001];
	char string[20];
	int temp;

	front = rear = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", string);

		if (strcmp(string, "push") == 0) {
			scanf("%d", &arr[rear++]);
		}
		else if (strcmp(string, "pop") == 0) {
			if (front == rear)
				printf("-1\n");
			else {
				printf("%d\n", arr[front++]);
			}
		}
		else if (strcmp(string, "size") == 0) {
			printf("%d\n", rear - front);
		}
		else if (strcmp(string, "empty") == 0) {
			if (front == rear)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (strcmp(string, "front") == 0) {
			if (front == rear)
				printf("-1\n");
			else
				printf("%d\n", arr[front]);
		}
		else {
			if (front == rear)
				printf("-1\n");
			else
				printf("%d\n", arr[rear - 1]);
		}
	}
	return 0;
}
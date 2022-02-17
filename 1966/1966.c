#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node* next;
};

int main(void)
{
	int T;
	int N, M;
	int input;
	struct Node* front;
	struct Node* rear;
	struct Node* newNode;
	struct Node* pointer;
	struct Node* deleted;
	int count;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);

		count = 0;
		front = NULL;
		rear = NULL;

		for (int j = 0; j < N; j++) {

			scanf("%d", &input);

			newNode = (struct Node*)malloc(sizeof(struct Node));
			newNode->value = input;
			newNode->next = NULL;

			if (front == NULL) {
				front = newNode;
				rear = newNode;
			}
			else {
				rear->next = newNode;
				rear = newNode;
			}
		}

		while (1) {
			pointer = front->next;

			while (pointer) {
				if (pointer->value > front->value)
					break;
				pointer = pointer->next;
			}

			if (pointer == NULL) {
				count++;

				deleted = front;
				front = front->next;
				free(deleted);

				if (M == 0) {
					break;
				}
				else {
					M--;
				}
			}
			else {
				deleted = front;
				front = front->next;
				deleted->next = NULL;
				rear->next = deleted;
				rear = deleted;

				if (M == 0) {
					M = N - count - 1;
				}
				else {
					M--;
				}
			}
		}
		printf("%d\n", count);

		while (front) {
			pointer = front;
			front = front->next;

			free(pointer);
		}
	}
	return 0;
}
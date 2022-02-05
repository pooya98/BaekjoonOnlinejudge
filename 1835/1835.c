#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* prev;
	struct node* next;
}Node;

int main(void)
{
	int N;
	scanf("%d", &N);

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = N;
	newNode->prev = NULL;
	newNode->next = NULL;

	Node* front = newNode;
	Node* rear = newNode;
	Node* cut_node = NULL;

	for (int i = N - 1; i >= 1; i--) {
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = i;
		newNode->prev = NULL;
		newNode->next = front;
		front->prev = newNode;
		front = newNode;

		for (int j = 0; j < i; j++) {
			Node* move_node = rear;
			rear = rear->prev;
			rear->next = NULL;

			move_node->prev = NULL;
			move_node->next = front;
			front->prev = move_node;
			front = move_node;
		}
	}

	for (Node* cur_node = front; cur_node; cur_node = cur_node->next)
		printf("%d ", cur_node->data);


	cut_node = front;

	while (front) {
		cut_node = front;
		front = front->next;
		free(cut_node);
	}

	return 0;
}
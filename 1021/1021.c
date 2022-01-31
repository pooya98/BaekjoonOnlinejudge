#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node* prev;
	int value;
	struct Node* next;
};

struct Node * front;
struct Node * rear;
struct Node * pointer;

int index_count;
int node_count = 0;
int op_count = 0;

int main(void)
{
	int i, j;
	int N, M;
	int temp;

	scanf("%d %d", &N, &M);

	struct Node* new_Node = (struct Node*)malloc(sizeof(struct Node));
	new_Node->value = 1;
	new_Node->prev = NULL;
	new_Node->next = NULL;

	front = new_Node;
	rear = new_Node;

	for (i = 2; i <= N; i++) {
		new_Node = (struct Node*)malloc(sizeof(struct Node));
		new_Node->prev = rear;
		new_Node->next = NULL;
		new_Node->value = i;

		rear->next = new_Node;

		rear = new_Node;
	}

	node_count = N;

	for (i = 0; i < M; i++) {
		scanf("%d", &temp);

		index_count = 0;

		pointer = front;

		while (pointer->value != temp) {
			index_count++;
			pointer = pointer->next;
		}
		if (index_count < node_count - index_count) {
			for (j = 0; j < index_count; j++) {
				op_count++;
				pointer = front;
				front = front->next;
				front->prev = NULL;

				pointer->prev = rear;
				pointer->next = NULL;
				rear->next = pointer;

				rear = pointer;
			}
			pointer = front;
			front = front->next;
			if(front != NULL)
				front->prev = NULL;
			free(pointer);
			node_count--;
		}
		else {
			for (j = 0; j < node_count - index_count; j++) {
				op_count++;
				pointer = rear;
				rear = rear->prev;
				rear->next = NULL;

				pointer->next = front;
				pointer->prev = NULL;
				front->prev = pointer;

				front = pointer;
			}
			pointer = front;
			front = front->next;
			if (front != NULL)
				front->prev = NULL;
			free(pointer);
			node_count--;
		}
	}

	printf("%d", op_count);


	while (front != NULL) {
		pointer = front;
		front = front->next;

		free(pointer);
	}

	return 0;
}
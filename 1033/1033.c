#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define N_MAX 10

#define VISITED 0
#define NOT_VISITED 1

#define SUCCESS 0
#define FAIL 1

typedef struct Node {
	int index;
	int numerator;
	int denominator;
	struct Node* next;
};

int main(void)
{
	int N;
	int a, b, p, q;

	struct Node* arr[N_MAX];
	int ingredient[N_MAX];
	int visited[N_MAX];
	
	int stack[N_MAX + 1];
	int top = 1;

	int current_node;
	
	struct Node* newNode;
	struct Node* pointer;
	struct Node* delNode;

	int min_ingredient = 100000000;
	int success_flag;

	/* 배열 초기화 */
	for (int i = 0; i < N_MAX; i++) {
		arr[i] = NULL;
		ingredient[i] = 1;
		visited[i] = NOT_VISITED;
	}
	
	scanf("%d", &N);

	/* 그래프(인접리스트) 생성 */
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d %d %d", &a, &b, &p, &q);

		newNode = (struct Node*)malloc(sizeof(struct Node));
		
		newNode->numerator = p;
		newNode->denominator = q;
		newNode->index = a;
		newNode->next = arr[b];
		arr[b] = newNode;

		newNode = (struct Node*)malloc(sizeof(struct Node));

		newNode->numerator = q;
		newNode->denominator = p;
		newNode->index = b;
		newNode->next = arr[a];
		arr[a] = newNode;
	}

	/* 0 번 째 재료 관련 초기화*/
	current_node = 0;
	visited[current_node] = VISITED;
	ingredient[current_node] = 1;
	stack[top] = 0;

	do {
		pointer = arr[current_node];

		while (pointer) {
			if (visited[pointer->index] == VISITED)
				pointer = pointer->next;
			else {

				ingredient[pointer->index] *= (pointer->numerator * ingredient[current_node]);

				for (int i = 0; i < N; i++) {
					if(visited[i] == VISITED)
						ingredient[i] *= (pointer->denominator);
				}

				visited[pointer->index] = VISITED;
				stack[++top] = pointer->index;
				current_node = pointer->index;
				break;
			}
		}

		if (pointer == NULL)
			current_node = stack[--top];

	} while (top > 0);

	for (int i = 0; i < N; i++) {
		if (ingredient[i] < min_ingredient)
			min_ingredient = ingredient[i];
	}

	for (int i = min_ingredient; i > 0; i--) {
		success_flag = SUCCESS;
		for (int j = 0; j < N; j++) {
			if (ingredient[j] % i != 0) {
				success_flag = FAIL;
				break;
			}
		}

		if (success_flag == SUCCESS) {
			for (int j = 0; j < N; j++) {
				ingredient[j] /= i;
				printf("%d ", ingredient[j]);
			}
			break;
		}
	}

	/* 동적 할당 해제 */
	for (int i = 0; i < N; i++) {
		pointer = arr[i];

		while (pointer) {
			delNode = pointer;
			pointer = pointer->next;
			free(delNode);
		}
	}

	return 0;
}
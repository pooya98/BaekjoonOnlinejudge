#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int end;
	struct node* next;
}Node;

int main(void)
{
	int T;
	int i, j, k;
	int N, K;

	int* w;
	int* t;
	int* pre;
	int* hit;
	Node** adj_list;

	int X, Y, W;

	Node* temp_p;

	int* que;

	int front, rear;

	int temp_index;

	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		scanf("%d %d", &N, &K);

		w = (int*)malloc(sizeof(int)*(N + 1));
		t = (int*)malloc(sizeof(int)*(N + 1));
		pre = (int*)malloc(sizeof(int)*(N + 1));
		hit = (int*)malloc(sizeof(int)*(N + 1));
		adj_list = (Node**)malloc(sizeof(Node*)*(N + 1));
		que = (int*)malloc(sizeof(int)*(N + 1));

		for (j = 1; j <= N; j++) {
			scanf("%d", &w[j]);
			t[j] = w[j];
		}

		for (j = 1; j <= N; j++) {
			adj_list[j] = NULL;
			pre[j] = 0;
			hit[j] = 0;
		}

		for (j = 1; j <= K; j++)
		{
			scanf("%d %d", &X, &Y);

			temp_p = (Node*)malloc(sizeof(Node));

			temp_p->end = Y;
			temp_p->next = adj_list[X];

			adj_list[X] = temp_p;

			pre[Y]++;
		}

		scanf("%d", &W);

		front = rear = 1;
		for (j = 1; j <= N; j++) {
			if (pre[j] == 0)
				que[rear++] = j;
		}

		while (1) {
			temp_index = que[front++];

			if (temp_index == W)
				break;

			temp_p = adj_list[temp_index];

			while (temp_p) {
				hit[temp_p->end]++;
				if (t[temp_index] + w[temp_p->end] > t[temp_p->end])
					t[temp_p->end] = t[temp_index] + w[temp_p->end];
				if (hit[temp_p->end] == pre[temp_p->end])
					que[rear++] = temp_p->end;

				temp_p = temp_p->next;
			}
		}
		printf("%d\n", t[W]);

		// 동적 할당 해제
		for (j = 1; j <= N; j++)
			free(adj_list[j]);

		free(adj_list);
		free(pre);
		free(hit);
		free(w);
		free(t);
		free(que);
	}

	return 0;
}
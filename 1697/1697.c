#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct node {
	int depth;
	int location;
}Node;

int visited[100001] = { 0, };
struct node queue[2000000];
int front = 0;
int rear = -1;
int target;
int push(int n, int depth);
//struct node pop();

int main(void)
{
	int n, k;
	struct node temp;
	scanf("%d %d", &n, &k);
	target = k;
	if (push(n, 0))
		return 0;

	for (;;) {
		//temp = pop();
		temp = queue[front++];
		if (push(temp.location - 1, temp.depth + 1))
			break;
		if (push(temp.location + 1, temp.depth + 1))
			break;
		if (push(temp.location * 2, temp.depth + 1))
			break;
	}
	return 0;
}

int push(int n, int depth)
{
	if (n < 0 || n>100000)
		return 0;
	if (visited[n])
		return 0;

	if (n == target) {
		printf("%d", depth);
		return 1;
	}
	queue[++rear].location = n;
	queue[rear].depth = depth;
	visited[n]++;

	return 0;
}
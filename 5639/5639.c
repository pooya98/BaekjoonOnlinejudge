// file : bj_5636.c
// 백준 5636번 문제

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node * leftchild;
	struct node * rightchild;
};
typedef struct node Node;

void insert(Node** tree, int num);
Node * create_node(int value);
void free_all(Node * tree);
void postorder(Node * tree);

int main(void)
{
	int num;
	Node * tree = NULL;

	while (scanf("%d\n", &num) != EOF) {
		insert(&tree, num);
		fflush(stdin);
	}

	postorder(tree);
	printf("\n");

	free_all(tree);
	return 0;
}

void insert(Node** tree, int num) {
	Node * temp = *tree;
	if (*tree == NULL) {
		*tree = create_node(num);
		return;
	}
	for (;;) {
		if (temp->value > num) {
			if (temp->leftchild)
				temp = temp->leftchild;
			else {
				temp->leftchild = create_node(num);
				break;
			}
		}
		else if (temp->value < num) {
			if (temp->rightchild)
				temp = temp->rightchild;
			else {
				temp->rightchild = create_node(num);
				break;
			}
		}
	}
}

Node * create_node(int num) {
	Node * temp;

	temp = (Node *)malloc(sizeof(Node));
	temp->value = num;
	temp->leftchild = NULL;
	temp->rightchild = NULL;

	return temp;
}

void postorder(Node * tree) {
	if (tree) {
		postorder(tree->leftchild);
		postorder(tree->rightchild);
		printf("%d\n", tree->value);
	}
}

void free_all(Node * tree) {
	if (tree) {
		free_all(tree->leftchild);
		free_all(tree->rightchild);
		free(tree);
	}
}
// file : bj_1991.c
// 백준 1991번 문제

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

struct node {
	char value;
	struct node * leftchild;
	struct node * rightchild;
};
typedef struct node Node;

int top = -1;
Node * stack[MAX_STACK_SIZE];

void insert(Node** tree, Node * subtree);
Node * create_node(char value);
Node * create_subtree(char center, char left, char right);
void free_all(Node * tree);
Node * find_node(Node * tree, char key);
void preorder(Node * tree);
void inorder(Node * tree);
void postorder(Node * tree);
void push(Node * tree);
Node * pop();

int main(void)
{
	int n;
	char center, left, right;
	Node * tree = NULL;

	scanf("%d\n", &n);

	for (int i = 0; i < n; i++) {
		scanf("%c %c %c\n", &center, &left, &right);
		insert(&tree, create_subtree(center, left, right));
	}

	preorder(tree);
	printf("\n");
	inorder(tree);
	printf("\n");
	postorder(tree);
	printf("\n");

	free_all(tree);
	return 0;
}

void insert(Node** tree, Node * subtree) {
	if (*tree == NULL) {
		*tree = subtree;
		return;
	}
	Node * temp = find_node(*tree, subtree->value);
	temp->leftchild = subtree->leftchild;
	temp->rightchild = subtree->rightchild;
}

Node * create_subtree(char center, char left, char right) {
	Node * subtree;

	subtree = create_node(center);
	subtree->leftchild = create_node(left);
	subtree->rightchild = create_node(right);

	return subtree;
}

Node * create_node(char value) {
	if (value == '.')
		return NULL;

	Node * temp;

	temp = (Node *)malloc(sizeof(Node));
	temp->value = value;
	temp->leftchild = NULL;
	temp->rightchild = NULL;

	return temp;
}

void preorder(Node * tree) {
	if (tree) {
		printf("%c", tree->value);
		preorder(tree->leftchild);
		preorder(tree->rightchild);
	}
}
void inorder(Node * tree) {
	if (tree) {
		inorder(tree->leftchild);
		printf("%c", tree->value);
		inorder(tree->rightchild);
	}
}
void postorder(Node * tree) {
	if (tree) {
		postorder(tree->leftchild);
		postorder(tree->rightchild);
		printf("%c", tree->value);
	}
}

Node * find_node(Node * tree, char key) {
	for (;;) {
		for (; tree; tree = tree->leftchild)
			push(tree);
		tree = pop();
		if (!tree)
			break;
		if (tree->value == key)
			return tree;
		tree = tree->rightchild;
	}
	printf("노드를 찾을 수 없습니다.\n");
	exit(1);
}

void push(Node * tree) {
	stack[++top] = tree;
}

Node * pop() {
	return stack[top--];
}

void free_all(Node * tree) {
	if (tree) {
		free_all(tree->leftchild);
		free_all(tree->rightchild);
		free(tree);
	}
}
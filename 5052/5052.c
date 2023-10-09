#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 0
#define FALSE 1
#define CAUTION 2

typedef struct k_tree {
	int rear;					    // 전화번호의 마지막을 나타내는 변수 ( 마지막이면 TRUE, 아니면 FALSE )
	struct k_tree* child[10];		// k진 트리의 자식노드들을 가리키는 구조체 포인터 배열
};

int check_consistency();			// 전화번호 목록의 일관성을 검사하는 함수( 일관성이 있으면 TRUE, 아니면 FALSE)
int tree_insert(struct k_tree* tp, int a,int rear_check);  // k진 트리에 노드를 추가하는 함수(새로 추가했으면 TRUE, 원래 있는 노드이고 마지막 노드가 아니면 FALSE, 원래있는 노드이고 마지막 노드면 CAUTION)
void delete_tree(struct k_tree* tp);  // k진 트리의 모든 노드들을 동작할당 해제하는 함수

int main(void)
{
	int n;			// 테스트 케이스의 개수
	int i;			// 반복 제어 변수

	scanf("%d", &n);			// 테스트 케이스의 개수 입력 받음
	for (i = 0; i < n; i++) {				// 각 케이스마다 일관성 검사하고 결과 출력
		if (check_consistency() == TRUE)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

int check_consistency() {		// 전화번호 목록의 일관성을 검사하는 함수( 일관성이 있으면 TRUE, 아니면 FALSE)

	int n;				// 전화 번호의 수
	int i,j;			// 반복 제어 변수
	char input[11];		// 전화번호를 저장할 문자열 변수
	int consistency = TRUE;		// 일관성을 표시하는 변수 ( 일관성을 유지하고 있는 상태면 TRUE, 잃으면 FALSE)
	int return_value;	// tree_insert함수의 반환값을 저장하는 변수
	struct k_tree* tp;  // 트리 노드 추가시 위치를 가리키는 포인터 변수

	struct k_tree* root = (struct k_tree*)malloc(sizeof(struct k_tree)); // k-tree의 루트노드를 가리키는 포인터 변수
	for (i = 0; i < 10; i++)  // 루트 노드 초기화 과정
		root->child[i] = NULL;
	root->rear = FALSE;
	
	scanf("%d", &n);					// 전화 번호의 수 입력 받음
	for (i = 0; i < n; i++) {			// 전화 번호 수 만큼 반복
		tp = root;					    // 노드 추가 위치 초기화

		scanf("%s", input);					// 전화 번호 입력 받음
		for (j = 0; input[j] && !consistency; j++) {		// 전화 번호 자리수 하나씩 k_tree에 노드로 추가
			return_value = tree_insert(tp, input[j]-48, input[j+1]);	 // 노드 추가 시도
			if (return_value == CAUTION) {  // 입력한 전화번호가 가지고 있는 접두사 발견 
				consistency = FALSE;		// 일관성 없음 상태 표시
				break;
			}
			tp = tp->child[input[j] - 48];  // 다음 노드 추가 위치 설정
		}
		if (return_value == FALSE)		// 입력한 전화번호가 다른 전화번호의 접두사 임을 발견
			consistency = FALSE;		// 일관성 없음 상태 표시
	}
	delete_tree(root);		// k_tree 삭제
	return consistency;		// 일관성 상태 반환
}

int tree_insert(struct k_tree* tp, int a, int rear_check) {		// k진 트리에 노드를 추가하는 함수(새로 추가했으면 TRUE, 원래 있는 노드이고 마지막 노드가 아니면 FALSE, 원래있는 노드이고 마지막 노드면 CAUTION)
	if (tp->child[a] != NULL)        // 이미 해당 위치에 노드가 있고
	{
		if (tp->child[a]->rear == TRUE)    // 마지막 노드였으면 CAUTION 반환
			return CAUTION;
		else                               // 마지막 노드가 아니였으면 FALSE 반환
			return FALSE;
	}
	else {							  // 해당 위치에 노드가 없으면 (새로 추가해야되면) 노드 생성 및 초기화 후 저장
		int i;
		tp->child[a] = (struct k_tree*)malloc(sizeof(struct k_tree));
		for (i = 0; i < 10; i++)
			tp->child[a]->child[i] = NULL;
		if (rear_check == TRUE)
			tp->child[a]->rear = TRUE;
		else
			tp->child[a]->rear = FALSE;
		return TRUE;
	}
}

void delete_tree(struct k_tree* tp) {	// k진 트리의 모든 노드들을 동작할당 해제하는 함수
	int i;
	if (tp == NULL)
		return;
	for (i = 0; i < 10; i++)
		delete_tree(tp->child[i]);
	free(tp);
}
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 32000 + 1

typedef struct _node{
    int dest;
    struct _node* next;
}node;

node * adj_list[MAX_VERTICES];
int indegree[MAX_VERTICES];

int queue[MAX_VERTICES];
int front = 0;
int rear = -1;

int result_stack[MAX_VERTICES];
int result_stack_top = -1;

int main(void)
{
    for(int i = 0; i < MAX_VERTICES; i++){
        adj_list[i] = NULL;
        indegree[i] = 0;
    }
    
    int N, M;
    node* pointer;
    int v1, v2;

    scanf("%d %d", &N, &M);

    for(int i = 0; i < M; i++){
        scanf("%d %d", &v1, &v2);

        pointer = (node*)malloc(sizeof(node));
        pointer->dest = v2;
        pointer->next = adj_list[v1];

        adj_list[v1] = pointer;
        indegree[v2]++;
    }

    for(int i = 1; i <= N; i++){
        if(indegree[i] == 0){
            queue[++rear] = i;
        }
    }

    while(front <= rear){
        int now = queue[front++];

        result_stack[++result_stack_top] = now;

        pointer = adj_list[now];

        while(pointer){
            indegree[pointer->dest]--;

            if(indegree[pointer->dest] == 0){
                queue[++rear] = pointer->dest;
            }
            pointer = pointer->next;
        }
    }

    for(int i = 0; i <= result_stack_top; i++)
        printf("%d ", result_stack[i]);


    for(int i = 1; i <= N; i++){
        while(adj_list[i]){
            pointer = adj_list[i];
            adj_list[i] = adj_list[i]->next;
            free(pointer);
        }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define INF 100000000
#define CHANGED 1
#define NOT_CHANGED 2

#define CYCLE 1
#define NON_CYCLE 2

#define VISIT 1
#define NOT_VISIT 2

typedef struct _node{
    int dest;
    int weight;
    struct _node* next;
}node;

node* adj_list[501];
long long distance[501];
int visited[501];

int N, M;

int bellman_ford(int start_node){
    node* pointer;
    int start;
    int dest;
    long long dist;
    int update_flag;

    distance[start_node] = 0;
    visited[start_node] = VISIT;

    for(int i = 1; i <= N; i++){

        update_flag = NOT_CHANGED;
        for(int j = 1; j <= N; j++){
            pointer = adj_list[j];
            start = j;

            if(visited[start] == NOT_VISIT)
                continue;


            while(pointer){
                
                dest = pointer->dest;
                dist = distance[start] + pointer->weight;

                if(distance[dest] > dist){
                    distance[dest] = dist;
                    update_flag = CHANGED;
                    visited[dest] = VISIT;
                }
                
                pointer = pointer->next;
            }
        }
    }

    return update_flag;
}

int main(void)
{
    int v1, v2, weight;
    node* temp_node;

    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++){
        adj_list[i] = NULL;
        distance[i] = INF;
        visited[i] = NOT_VISIT;
    }

    for(int i = 0; i < M; i++){
        scanf("%d %d %d", &v1, &v2, &weight);

        temp_node = (node*)malloc(sizeof(node));
        temp_node->dest = v2;
        temp_node->weight = weight;
        temp_node->next = adj_list[v1];

        adj_list[v1] = temp_node;
    }

    int result = bellman_ford(1);

    if(result == CYCLE){
        printf("-1\n");
    }else{
        for(int i = 2; i <= N; i++){
            if(distance[i] >= INF)
                printf("-1\n");
            else
                printf("%lld\n", distance[i]);
        }
    }

    for(int i = 1; i <= N; i++){
        while(adj_list[i]){
            temp_node = adj_list[i];
            adj_list[i] = adj_list[i]->next;
            free(temp_node);
        }
    }

    return 0;
}
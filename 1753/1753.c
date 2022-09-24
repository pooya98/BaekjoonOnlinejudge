#include <stdio.h>
#include <stdlib.h>

#define NO 0
#define YES 1

#define INF 100000000

typedef struct _node{
    int dest;
    int distance;
    struct _node* next;
}node;

int V, E, K;

node* adj_list[20001];
int visited[20001];
int distance[20001];

int get_nearlist_and_not_yet_visited(){
    int min_distance = INF;
    int min_index = 0;
    for(int i = 1; i <= V; i++){
        if(visited[i] == NO && distance[i] < min_distance){
            min_distance = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

int main(void)
{
    node* pointer;
    scanf("%d %d", &V, &E);
    scanf("%d", &K);

    for(int i = 1; i <= 20000; i++){
        adj_list[i] = NULL;
        visited[i] = NO;
        distance[i] = INF;
    }

    for(int i = 0; i < E; i++){
        int v1, v2, weight;
        scanf("%d %d %d", &v1, &v2, &weight);

        node* newNode = (node*)malloc(sizeof(node));
        newNode->dest = v2;
        newNode->distance = weight;
        newNode->next = NULL;

        if(adj_list[v1]){
            newNode->next = adj_list[v1];
            adj_list[v1] = newNode;
        }
        else{
            adj_list[v1] = newNode;
        }
    }

    distance[K] = 0;
    visited[K] = YES;

    pointer = adj_list[K];

    while(pointer){
        int next_index = pointer->dest;
        int next_dist = pointer->distance;

        distance[next_index] = next_dist;

        pointer = pointer->next;
    }

    for(int i = 1; i <= (V - 1); i++){
        int cur_index = get_nearlist_and_not_yet_visited();

        visited[cur_index] = YES;
        pointer = adj_list[cur_index];

        while(pointer){
            int next_index = pointer->dest;
            int next_dist = pointer->distance;

            if(distance[next_index] > (distance[cur_index] + next_dist))
                distance[next_index] = distance[cur_index] + next_dist;

            pointer = pointer->next;
        }
    }

    for(int i = 1; i <= V; i++){
        if(distance[i] == INF)
            printf("INF\n");
        else
            printf("%d\n", distance[i]);
    }

    

    for(int i = 1; i <= V; i++){
        pointer = adj_list[i];

        while(pointer){
            node* deleted = pointer;
            pointer = pointer->next;

            free(deleted);
        }
    }

    return 0;
}
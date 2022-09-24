#include <stdio.h>
#include <stdlib.h>

#define UNKNOWN 0
#define ALPHA 1
#define BRAVO 2

#define VISITED 1
#define UNVISITED 2

#define TRUE 1
#define FALSE 2

int* adj_list[20001];
int count[20001];
int visited[20001];
int team[20001];

int queue[20001];
int queue_front = -1;
int queue_rear = -1;

int bfs(int start)
{
    int cur_index = start;
    int cur_team;

    int next_index;

    queue_front = -1;
    queue_rear = -1;

    if(visited[start] == VISITED)
        return TRUE;

    ++queue_rear;
    queue[queue_rear] = cur_index;
    visited[cur_index] = VISITED;
    team[cur_index] = ALPHA;

    while(queue_front < queue_rear){
        ++queue_front;
        cur_index = queue[queue_front];
        cur_team = team[cur_index];

        for(int i = 0; i < count[cur_index]; i++){
            next_index = adj_list[cur_index][i];

            if(visited[next_index] == UNVISITED){
                ++queue_rear;
                queue[queue_rear] = next_index;
                visited[next_index] = VISITED;

                if(team[cur_index] == ALPHA)
                    team[next_index] = BRAVO;
                else
                    team[next_index] = ALPHA;
            }
            else{
                if(team[cur_index] == team[next_index])
                    return FALSE;
            }
        }
    }

    return TRUE;
}

int main(void)
{
    int K;
    int V, E;
    int v1, v2;
    scanf("%d", &K);

    for(int i = 0; i < K; i++){
        scanf("%d %d", &V, &E);

        for(int j = 1; j <= V; j++){
            adj_list[j] = NULL;
            count[j] = 0;
            visited[j] = UNVISITED;
            team[j] = UNKNOWN;
        }

        for(int j = 0; j < E; j++){
            scanf("%d %d", &v1, &v2);

            if(count[v1] == 0){
                count[v1]++;
                adj_list[v1] = (int*)malloc(sizeof(int));
                adj_list[v1][count[v1] - 1] = v2;
            }
            else{
                count[v1]++;
                adj_list[v1] = (int*)realloc(adj_list[v1], sizeof(int) * (count[v1]));
                adj_list[v1][count[v1] - 1] = v2;
            }

            if(count[v2] == 0){
                count[v2]++;
                adj_list[v2] = (int*)malloc(sizeof(int));
                adj_list[v2][count[v2] - 1] = v1;
            }
            else{
                count[v2]++;
                adj_list[v2] = (int*)realloc(adj_list[v2], sizeof(int) * (count[v2]));
                adj_list[v2][count[v2] - 1] = v1;
            }
        }

        int result;

        for(int j = 1; j <= V; j++){
            result = bfs(j);

            if(result == FALSE)
                break;
        }

        if(result == TRUE)
            printf("YES\n");
        else
            printf("NO\n");

        for(int j = 0; j <= V; j++){
            free(adj_list[j]);
        }
    }

    return 0;
}
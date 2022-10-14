#include <stdio.h>

#define MAX_TEAM_NUM 500 + 1
#define INF 987654321

#define CLEAR 1
#define NOT_CLEAR 2

int rank_last_year[MAX_TEAM_NUM];
int new_rank[MAX_TEAM_NUM];
int new_rank_top = -1;

int adj_matrix[MAX_TEAM_NUM][MAX_TEAM_NUM];
int indegree[MAX_TEAM_NUM];

int queue[MAX_TEAM_NUM * 10];
int front = 0;
int rear = -1;

int input_list[MAX_TEAM_NUM];

int main(void)
{
    int T;
    scanf("%d", &T);

    int n;
    int m;
    int v1, v2;

    for(int i = 0; i < T; i++){
        scanf("%d", &n);

        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                adj_matrix[j][k] = INF;
            }
        }

        for(int j = 1; j <= n; j++){
            indegree[j] = 0;
        }

        new_rank_top = -1;
        front = 0;
        rear = -1;

        for(int j = 1; j <= n; j++){
            scanf("%d", &input_list[j]);
            rank_last_year[input_list[j]] = j;
        }

        for(int j = 1; j <= n; j++){
            int start = input_list[j];

            for(int k = j + 1; k <= n; k++){
                int next = input_list[k];
                adj_matrix[start][next] = 1;
                indegree[next]++;
            }
        }

        scanf("%d", &m);

        for(int j = 1; j <= m; j++){
            scanf("%d %d", &v1, &v2);

            if(adj_matrix[v1][v2] == 1){
                adj_matrix[v1][v2] = INF;
                adj_matrix[v2][v1] = 1;
                indegree[v2]--;
                indegree[v1]++;
            }
            else{
                adj_matrix[v2][v1] = INF;
                adj_matrix[v1][v2] = 1;
                indegree[v1]--;
                indegree[v2]++;
            }
        }

        for(int j = 1; j <= n; j++){
            if(indegree[j] == 0){
                queue[++rear] = j;
                new_rank[++new_rank_top] = j;
            }
        }

        int flag = CLEAR;

        while(front <= rear){
            if((rear - front) >= 1){
                flag = NOT_CLEAR;
            }

            int now = queue[front++];

            for(int j = 1; j <= n; j++){
                if(adj_matrix[now][j] == 1){
                    indegree[j]--;

                    if(indegree[j] == 0){
                        queue[++rear] = j;
                        new_rank[++new_rank_top] = j;
                    }
                }    
            }
        }

        //printf("->");
        if(flag == NOT_CLEAR){
            if(new_rank_top == (n - 1)){
                printf("?");
            }
            else{
                printf("IMPOSSIBLE");
            }
            printf("\n");
        }
        else{
            if(new_rank_top == (n - 1)){
                for(int j = 0; j <= new_rank_top; j++){
                    printf("%d ", new_rank[j]);
                }
            }
            else{
                printf("IMPOSSIBLE");
            }
            printf("\n");     
        }
    }
    return 0;
}
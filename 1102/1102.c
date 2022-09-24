#include <stdio.h>

#define MAX_N 16
#define ON 1
#define OFF 0
#define INF 999999999

int main(void)
{
    int N;
    int graph[MAX_N + 1][MAX_N + 1] = {0};
    int plantstate[MAX_N + 1] = {0};
    int cost[MAX_N + 1];
    int P;

    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
        cost[i] = INF;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    char statelist[MAX_N + 1];
    scanf("%s", statelist);

    for(int i = 1; i <= N; i++){
        if(statelist[i] == 'Y')
            plantstate[i] = ON;
    }

    scanf("%d", &P);

    return 0;
}
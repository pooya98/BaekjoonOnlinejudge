#include <stdio.h>

#define TRUE 1
#define FALSE 0

int N, M;
int arr[101][101] = {0};
int visited[101] = {0};

void dfs(int start){
    visited[start] = TRUE;

    for(int i = 1; i <= N; i++){

        if(arr[start][i] == 1 && visited[i] == FALSE){
            dfs(i);
        }
    }
}

int main(void)
{
    scanf("%d", &N);
    scanf("%d", &M);
    int a, b;
    
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);

        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    dfs(1);

    int count = 0;
    for(int i = 1; i <= N; i++){
        if(visited[i] == TRUE)
            count++;
    }

    printf("%d", count - 1);
    
    return 0;
}
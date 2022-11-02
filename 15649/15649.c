#include <stdio.h>

#define TRUE 1
#define FALSE 2

int arr[9];
int used[9];
int N, M;

void dfs(int depth){
    if(depth == M){
        for(int i = 1; i <= M; i++)
            printf("%d ", arr[i]);

        printf("\n");
    }
    else{
        for(int i = 1; i <= N; i++){
            if(used[i] == FALSE){
                arr[depth + 1] = i;
                used[i] = TRUE;
                dfs(depth + 1);
                used[i] = FALSE;
            }
        }
    }
}

int main(void)
{
    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++)
        used[i] = FALSE;

    for(int i = 1; i <= N; i++){
        arr[1] = i;
        used[i] = TRUE;
        dfs(1);
        used[i] = FALSE;
    }

    return 0;
}
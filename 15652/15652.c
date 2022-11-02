#include <stdio.h>

int arr[9];
int N, M;

void dfs(int depth){
    if(depth == M){
        for(int i = 1; i <= M; i++)
            printf("%d ", arr[i]);

        printf("\n");
    }
    else{
        int last_element = arr[depth];
        for(int i = last_element; i <= N; i++){
            arr[depth + 1] = i;
            dfs(depth + 1);
        }
    }
}

int main(void)
{
    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++){
        arr[1] = i;
        dfs(1);
    }

    return 0;
}
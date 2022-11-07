#include <stdio.h>

int matrix[101][101] = {0};
int input;

int main(void)
{
    int N, M;

    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++){
            scanf("%d", &input);
            matrix[i][j] += input;
        }

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++){
            scanf("%d", &input);
            matrix[i][j] += input;
        }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++)
            printf("%d ", matrix[i][j]);

        printf("\n");
    }
    
    
    return 0;
}
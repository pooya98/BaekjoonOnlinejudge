#include <stdio.h>

int main(void)
{
    int T;
    int N, M;
    int a, b;

    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        scanf("%d %d", &N, &M);

        for(int j = 0; j < M; j++)
            scanf("%d %d", &a, &b);

        printf("%d\n", N - 1);
    }
    return 0;
}
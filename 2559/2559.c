#include <stdio.h>

int sum[100001];

int main(void)
{
    sum[0] = 0;
    int N, K;
    int input;
    int max = -200000000;

    scanf("%d %d", &N, &K);

    for(int i = 1; i <= N; i++){
        scanf("%d", &input);
        sum[i] = sum[i - 1] + input;
    }

    for(int i = 1; (i + K - 1) <= N; i++){
        if((sum[i + K - 1] - sum[i - 1]) > max)
            max = sum[i + K - 1] - sum[i - 1];
    }

    printf("%d", max);

    return 0;
}
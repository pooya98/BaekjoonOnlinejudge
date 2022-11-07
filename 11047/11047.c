#include <stdio.h>

int coin_list[1000001];

int main(void)
{
    int N, K;
    int result = 0;
    int count;

    scanf("%d %d", &N, &K);

    for(int i = 1; i <= N; i++)
        scanf("%d", &coin_list[i]);

    int index_pointer = N;

    while(K > 0){
        count = K / coin_list[index_pointer];
        K -= coin_list[index_pointer] * count;
        result += count;
        index_pointer--;
    }

    printf("%d", result);
    return 0;
}
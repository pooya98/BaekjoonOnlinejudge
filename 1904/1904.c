#include <stdio.h>

int dp_table[1000001];

int main(void)
{
    int N;

    scanf("%d", &N);

    dp_table[1] = 1;
    dp_table[2] = 2;
    
    for(int i = 3; i <= 1000000; i++){
        dp_table[i] = (dp_table[i - 1] + dp_table[i - 2]) % 15746;
    }

    printf("%lld", dp_table[N]);
    return 0;
}
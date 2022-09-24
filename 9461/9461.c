#include <stdio.h>

long long dp_table[101];

int main(void)
{
    dp_table[1] = 1;
    dp_table[2] = 1;
    dp_table[3] = 1;
    dp_table[4] = 2;
    dp_table[5] = 2;


    for(int i = 6; i <= 100; i++){
        dp_table[i] = dp_table[i - 1] + dp_table[i - 5];
    } 

    int T;

    scanf("%d", &T);

    int N;

    for(int i = 0; i < T; i++){
        scanf("%d", &N);

        printf("%lld\n", dp_table[N]);
    }
    
    return 0;
}
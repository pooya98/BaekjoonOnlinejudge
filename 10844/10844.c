#include <stdio.h>

int dp_table[101][10] = {0};

int main(void)
{
    for(int i = 1; i <= 9; i++)
        dp_table[1][i] = 1;

    for(int i = 2; i <= 100; i++){
        for(int j = 1; j <= 8; j++){
            dp_table[i][j] = (dp_table[i - 1][j - 1] % 1000000000) +(dp_table[i - 1][j + 1] % 1000000000);
        }

        dp_table[i][0] = (dp_table[i - 1][1] % 1000000000);
        dp_table[i][9] = (dp_table[i - 1][8] % 1000000000);
    }

    int N;
    scanf("%d", &N);

    long long sum = 0;

    for(int i = 0; i <= 9; i++)
        sum += (long long)dp_table[N][i];

    printf("%lld", sum % 1000000000);

    return 0;
}
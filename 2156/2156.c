#include <stdio.h>

int wine[10001];

int dp_table[10001][3] = {0};

int main(void)
{
    int n;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%d", &wine[i]);

    dp_table[1][1] = wine[1];
    dp_table[2][1] = wine[2];
    dp_table[2][2] = wine[1] + wine[2];

    for(int i = 3; i <= n; i++){

        int max = 0;

        for(int j = 1; j <= i - 2; j++){
            if(max < dp_table[j][1]){
                max = dp_table[j][1];
            }

            if(max < dp_table[j][2]){
                max = dp_table[j][2];
            }
        }

        dp_table[i][1] = max + wine[i];

        dp_table[i][2] = dp_table[i - 1][1] + wine[i];
    }

    int max = 0;

    for(int i = 1; i <= 2; i++){
        for(int j = 1; j <= n; j++){
            if(max < dp_table[j][i])
                max = dp_table[j][i];
        }
    }

    printf("%d", max);
    return 0;
}
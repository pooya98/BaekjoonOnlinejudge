#include <stdio.h>

int arr[100001];
long long dp_table[100001];
int main(void)
{
    int N;
    
    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);

    dp_table[1] = arr[1];

    for(int i = 2; i <= N; i++){
        if((arr[i] + dp_table[i - 1]) > arr[i]){
            dp_table[i] = (arr[i] + dp_table[i - 1]);
        }
        else{
            dp_table[i] = arr[i];
        }
    }

    long long max_sum = -100000;

    for(int i = 1; i <= N; i++){
        if(dp_table[i] > max_sum)
            max_sum = dp_table[i];
    }

    printf("%lld", max_sum);

    return 0;
}
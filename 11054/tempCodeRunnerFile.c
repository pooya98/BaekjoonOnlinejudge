#include <stdio.h>

int arr[1001];
int dp_table_ascend[1001];
int dp_table_descend[1001];

int main(void)
{
    int N;
    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);

    int max;

    dp_table_ascend[1] = 1;

    for(int i = 2; i <= N; i++){
        max = 0;
        for(int j = 1; j <= i - 1; j++){
            if((arr[i] > arr[j]) && (dp_table_ascend[j] > max)){
                max = dp_table_ascend[j];
            }
        }
        dp_table_ascend[i] = max + 1;
    }

    dp_table_descend[N] = 1;

    for(int i = N - 1; i >= 1; i--){
        max = 0;
        for(int j = N; j >= i + 1; j--){
            if((arr[i] > arr[j]) && (dp_table_descend[j] > max)){
                max = dp_table_descend[j];
            }
        }
        dp_table_descend[i] = max + 1;
    }

    // for(int i = 1; i <= N; i++)
    //     printf("%d ", dp_table_ascend[i]);

    // printf("\n");
    // for(int i = 1; i <= N; i++)
    //     printf("%d ", dp_table_descend[i]);

    max = 0;

    for(int i = 1; i <= N; i++){
        if((dp_table_ascend[i] + dp_table_descend[i]) > max)
            max = (dp_table_ascend[i] + dp_table_descend[i]);
    }

    printf("%d", max - 1);

    return 0;
}
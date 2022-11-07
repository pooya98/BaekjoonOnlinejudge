#include <stdio.h>

int dp_table[100001] = {0};
int temp_table[100001] = {0};

int weight_list[101];
int value_list[101];
int result = 0;

int main(void)
{
    int N, K;
    int cur_weight;
    int cur_value;
    int next_weight;
    int next_value;

    scanf("%d %d", &N, &K);

    for(int i = 1; i <= N; i++)
        scanf("%d %d", &weight_list[i], &value_list[i]);

    for(int i = 1; i <= N; i++){
        cur_weight = weight_list[i];
        cur_value = value_list[i];

        for(int j = 1; j <= N; j++)
            temp_table[j] = 0;

        if(cur_value == 0)
            continue;

        for(int j = 1; j <= K; j++){
            if(dp_table[j]){
                next_weight = j + cur_weight;
                next_value = dp_table[j] + cur_value;

                if(next_weight <= K)
                    if(dp_table[next_weight] < next_value)
                        temp_table[next_weight] = next_value;
            }
        }

        for(int j = 1; j <= K; j++)
            if(dp_table[j] < temp_table[j])
                dp_table[j] = temp_table[j];

        if(cur_weight <= K)
            if(dp_table[cur_weight] < cur_value)
                dp_table[cur_weight] = cur_value;

    }
    
    for(int i = 1; i <= K; i++)
        if(dp_table[i] > result)
            result = dp_table[i];

    printf("%d", result);

    return 0;
}
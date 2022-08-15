#include <stdio.h>

int main(void)
{
    int N;
    int input;
    int count_array[10001] = {0};

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &input);
        count_array[input]++;
    }

    for(int i = 1; i <= 10000; i++){
        for(int j = 1; j <= count_array[i]; j++)
            printf("%d\n", i);
    }
    return 0;
}
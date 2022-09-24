#include <stdio.h>

int array[10001];
int length[10001];

int main(void)
{
    int N;

    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
        scanf("%d", &array[i]);

    int max;

    length[1] = 1;

    for(int i = 2; i <= N; i++){
        max = 0;
        for(int j = 1; j <= i; j++){
            if((array[j] < array[i]) && (length[j] > max))
                max = length[j];
        }

        length[i] = max + 1;
    }

    int max_length = 0;

    for(int i = 1; i <= N; i++){
        if(max_length < length[i])
            max_length = length[i];
    }

    printf("%d", max_length);

    return 0;
}
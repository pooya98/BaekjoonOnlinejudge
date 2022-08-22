#include <stdio.h>

int main(void)
{
    int input[6];
    int full_set[6] = {1, 1, 2, 2, 2, 8};

    for(int i = 0; i < 6; i++)
        scanf("%d", &input[i]);

    for(int i = 0; i < 6; i++)
        printf("%d ", full_set[i] - input[i]);
    return 0;
}
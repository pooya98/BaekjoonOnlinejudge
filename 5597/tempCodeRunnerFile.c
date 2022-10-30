#include <stdio.h>

int main(void)
{
    int arr[31] = {0};
    int input;

    for(int i = 1; i <= 28; i++){
        scanf("%d", &input);
        arr[input]++;
    }

    for(int i = 1; i <= 30; i++)
        if(arr[i] == 0)
            printf("%d\n", i);

    return 0;
}
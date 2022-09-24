#include <stdio.h>

int stack[100000];
int top = -1;

int main(void)
{
    int K;
    int input;
    int sum = 0;

    scanf("%d", &K);

    for(int i = 0; i < K; i++){
        scanf("%d", &input);

        if(input == 0)
            top--;
        else
            stack[++top] = input;
    }

    for(int i = 0; i <= top; i++)
        sum += stack[i];

    printf("%d", sum);

    return 0;
}
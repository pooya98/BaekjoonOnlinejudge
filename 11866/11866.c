#include <stdio.h>

int queue[1000000];
int front;
int rear;
int pointer;

int result_list[1000];
int top = -1;

int main(void)
{
    int N, K;
    int temp;

    scanf("%d %d", &N, &K);

    for(int i = 0; i < N; i++)
        queue[i] = i + 1;

    front = 0;
    rear = N - 1;

    while(front <= rear){
        for(int i = 0; i < K - 1; i++){
            temp = queue[front++];
            queue[++rear] = temp;
        }
        result_list[++top] = queue[front++];
    }

    printf("<");
    for(int i = 0; i < top; i++){
        printf("%d, ", result_list[i]);
    }
    printf("%d>", result_list[top]);
    return 0;
}
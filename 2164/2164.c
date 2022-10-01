#include <stdio.h>

#define ON 1
#define OFF 2

int queue[1000001];
int front = 0;
int rear = -1;

int main(void)
{
    int N;
    int toggle;
    int temp;

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
        queue[i] = i + 1;

    front = 0;
    rear = N - 1;
    toggle = ON;

    while(front < rear){
        if(toggle == ON){
            front++;
            toggle = OFF;
        }
        else{
            temp = queue[front++];
            queue[++rear] = temp;
            toggle = ON;
        }
    }

    printf("%d", queue[rear]);
    return 0;
}
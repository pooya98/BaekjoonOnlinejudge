#include <stdio.h>
#include <string.h>

int queue[2000000];

int front = 0;
int rear = -1;

int main(void)
{
    int N;
    int value_to_add;
    char input[10];

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%s", input);

        if(!strcmp(input, "push")){
            scanf("%d", &value_to_add);
            queue[++rear] = value_to_add;
        }
        else if(!strcmp(input, "pop")){
            if(front <= rear)
                printf("%d\n", queue[front++]);
            else
                printf("-1\n");
        }
        else if(!strcmp(input, "size")){
            printf("%d\n", rear - front + 1);
        }
        else if(!strcmp(input, "empty")){
            if(front <= rear)
                printf("0\n");
            else
                printf("1\n");
        }
        else if(!strcmp(input, "front")){
            if(front <= rear)
                printf("%d\n", queue[front]);
            else
                printf("-1\n");
        }
        else if(!strcmp(input, "back")){
            if(front <= rear)
                printf("%d\n", queue[rear]);
            else
                printf("-1\n");
        }
    }

    return 0;
}
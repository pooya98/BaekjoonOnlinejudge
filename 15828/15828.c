#include <stdio.h>

#define FULL 1
#define EMPTY 0

int main(void)
{
    int N;
    int queue[100001];
    int front = 0;
    int rear = 0;
    int task;

    scanf("%d", &N);

    N++;

    if(N == 2){
        int toggle = EMPTY;
        int box;

        for(;;){
            scanf("%d", &task);

            if(task > 0){
                if(toggle == EMPTY){
                    box = task;
                    toggle = FULL;
                }
            }
            else if(task == 0){
                if(toggle == FULL)
                    toggle = EMPTY;
            }
            else
                break;
        }

        if(toggle == EMPTY)
            printf("empty");
        else
            printf("%d", box);
    }
    else{
        for(;;){
            scanf("%d", &task);

            if(task > 0){
                if(front != ((rear + 1) % N)){
                    rear = (rear + 1) % N;
                    queue[rear] = task;
                }
            }
            else if(task == 0){
                if(front != rear)
                    front = (front + 1) % N;
            }
            else
                break;
        }

        if(front == rear){
            printf("empty");
        }
        else{
            while(front != rear){
                front = (front + 1) % N;
                printf("%d ", queue[front]);
            }
        }
    }

    return 0;
}
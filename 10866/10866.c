#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node{
    struct _node * prev;
    struct _node * next;
    int data;
}node;

node * front = NULL;
node * rear  = NULL;
int count = 0;

int main(void)
{
    int N;
    char operation[30];
    int X;
    node * temp_pointer = NULL;

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%s", operation);

        if(!strcmp(operation, "push_front")){
            scanf("%d", &X);

            temp_pointer = (node*)malloc(sizeof(node));
            temp_pointer->prev = NULL;
            temp_pointer->next = NULL;
            temp_pointer->data = X;

            if(!front){
                front = temp_pointer;
                rear = temp_pointer;
            }else{
                temp_pointer->next = front;
                front->prev = temp_pointer;

                front = temp_pointer;
            }

            count++;
        }
        else if(!strcmp(operation, "push_back")){
            scanf("%d", &X);

            temp_pointer = (node*)malloc(sizeof(node));
            temp_pointer->prev = NULL;
            temp_pointer->next = NULL;
            temp_pointer->data = X;

            if(!rear){
                front = temp_pointer;
                rear = temp_pointer;
            }else{
                temp_pointer->prev = rear;
                rear->next = temp_pointer;
                rear = temp_pointer;
            }

            count++;
        }
        else if(!strcmp(operation, "pop_front")){
            if(!front){
                printf("-1\n");
            }
            else if(front == rear){
                printf("%d\n", front->data);
                free(front);

                front = NULL;
                rear = NULL;

                count--;
            }
            else{
                temp_pointer = front;
                front = front->next;

                printf("%d\n", temp_pointer->data);
                free(temp_pointer);

                count--;
            }
        }
        else if(!strcmp(operation, "pop_back")){
            if(!rear){
                printf("-1\n");
            }
            else if(front == rear){
                printf("%d\n", rear->data);
                free(rear);

                front = NULL;
                rear = NULL;

                count--;
            }
            else{
                temp_pointer = rear;
                rear = rear->prev;

                printf("%d\n", temp_pointer->data);
                free(temp_pointer);

                count--;
            }
        }
        else if(!strcmp(operation, "size")){
            printf("%d\n", count);
        }
        else if(!strcmp(operation, "empty")){
            if(count == 0)
                printf("1\n");
            else    
                printf("0\n");
        }
        else if(!strcmp(operation, "front")){
            if(!front)
                printf("-1\n");
            else
                printf("%d\n", front->data);
        }
        else if(!strcmp(operation, "back")){
            if(!rear)
                printf("-1\n");
            else
                printf("%d\n", rear->data);
        }
        else{
            continue;
        }
    }

    return 0;
}
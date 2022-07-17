#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* prev;
    struct node* next;
}Node;

int main(void){
    
    int N, K;
    int count;
    int arr[5000];
    int index_count = 0;

    scanf("%d %d", &N, &K);

    count = N;
    Node* circular_queue = NULL;
    Node* rear_pointer = NULL;
    Node* newNode = NULL;
    Node* cur_pointer = NULL;
    Node* deleted_node = NULL;

    for(int i = 1; i <= N; i++){
        newNode = (Node*)malloc(sizeof(Node));
        newNode->value = i;
        newNode->next = NULL;

        if(circular_queue == NULL){
            circular_queue = newNode;
            rear_pointer = newNode;
        }else{
            rear_pointer->next = newNode;
            newNode->prev = rear_pointer;
            rear_pointer = newNode;
        }
    }

    rear_pointer->next = circular_queue;
    circular_queue->prev = rear_pointer;
    cur_pointer = rear_pointer;

    while(circular_queue){
        if(count == 1){
            deleted_node = circular_queue;
            arr[index_count++] = deleted_node->value;
            free(circular_queue);
            circular_queue = NULL;
        }
        else{
            for(int i = 0; i < K; i++)
                cur_pointer = cur_pointer->next;

            deleted_node = cur_pointer;
            cur_pointer = cur_pointer->prev;

            if(deleted_node == circular_queue)
                circular_queue = circular_queue->next;

            deleted_node->prev->next = deleted_node->next;
            deleted_node->next->prev = deleted_node->prev;

            arr[index_count++] = deleted_node->value;
            count--;
            free(deleted_node);
        }
    }

    printf("<");
    for(int i = 0; i < index_count - 1; i++)
        printf("%d, ", arr[i]);
    printf("%d", arr[index_count - 1]);
    printf(">");

    return 0;
}
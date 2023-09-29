#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX 50

typedef struct Node{
    int len;
    char string[STR_MAX + 1];
    struct Node* prev;
    struct Node* next;
}node;

int main(void)
{
    int N;
    node* list = NULL;
    node* new_node = NULL;
    node* pointer = NULL;
    node* rear = NULL;
    char input[STR_MAX + 1];
    char prev_output[STR_MAX + 1];

    scanf("%d", &N);

    // insert dummy node
    new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->string, "");
    new_node->len = 0;
    new_node->prev = NULL;
    new_node->next = NULL;
    
    rear = new_node;

    new_node = (node*)malloc(sizeof(node));
    new_node->len = STR_MAX + 2;
    new_node->prev = NULL;
    new_node->next = rear;

    rear->prev = new_node;

    list = new_node;

    for(int i = 0; i < N; i++){
        new_node = (node*)malloc(sizeof(node));
        scanf("%s", input);

        strcpy(new_node->string, input);
        new_node->len = strlen(new_node->string);
        new_node->prev = NULL;
        new_node->next = NULL;

        pointer = list;

        while(pointer->next->len > new_node->len){
            pointer = pointer->next;
        }

        while((pointer->next->len == new_node->len) && strcmp(pointer->next->string, new_node->string) > 0){
            pointer = pointer->next;
        }

        new_node->next = pointer->next;

        if(pointer->next)
            pointer->next->prev = new_node;

        pointer->next = new_node;
        new_node->prev = pointer;
    }

    pointer = rear->prev;

    strcpy(prev_output, " ");
    while(pointer){
        if(pointer->len == 52)
            break;
            
        if(strcmp(prev_output, pointer->string)){
            printf("%s\n", pointer->string);
            strcpy(prev_output, pointer->string);
        }
        pointer = pointer->prev;
    }

    while(list){
        pointer = list;
        list = list->next;
        free(pointer);
    }

    return 0;
}
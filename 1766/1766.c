#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 32000 + 1
#define MAX_HEAP_SIZE 32000 + 1

typedef struct _node{
    int dest;
    struct _node* next;
}node;

typedef struct{
    int key;
}element;

typedef struct{
    element array[MAX_HEAP_SIZE];
    int size;
}Heap;

node* adj_list[MAX_VERTICES];
int indegree[MAX_VERTICES];

int result[MAX_VERTICES];
int result_top = -1;

void min_heap_insert(Heap* heap, element item){
    int i = ++(heap->size);

    while((i != 1) && (item.key < heap->array[i / 2].key)){
        heap->array[i] = heap->array[i / 2];
        i /= 2;
    }

    heap->array[i] = item;
}

element min_heap_delete(Heap* heap){
    int parent, child;
    element item, temp;

    item = heap->array[1];
    temp = heap->array[(heap->size)--];

    parent = 1;
    child = 2;

    while(child <= heap->size){
        if((child < heap->size) && ((heap->array[child].key) > (heap->array[child + 1].key))){
            child++;
        }

        if(temp.key <= heap->array[child].key){
            break;
        }

        heap->array[parent] = heap->array[child];

        parent = child;
        child *= 2;
    }

    heap->array[parent] = temp;

    return item;
}

int main(void)
{
    int N, M;
    int v1, v2;
    node * pointer;

    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++){
        adj_list[i] = NULL;
        indegree[i] = 0;
    }

    for(int i = 0; i < M; i++){
        scanf("%d %d", &v1, &v2);

        pointer = (node*)malloc(sizeof(node));

        pointer->dest = v2;
        pointer->next = adj_list[v1];
        adj_list[v1] = pointer;

        indegree[v2]++;
    }

    Heap min_heap;
    min_heap.size = 0;

    element temp_element;

    for(int i = 1; i <= N; i++){
        if(indegree[i] == 0){
            temp_element.key = i;
            min_heap_insert(&min_heap, temp_element);
        }
    }

    while(min_heap.size > 0){
        element cur_element = min_heap_delete(&min_heap);

        result[++result_top] = cur_element.key;

        int cur_vertex = cur_element.key;

        int next_vertex;

        pointer = adj_list[cur_vertex];

        while(pointer){
            next_vertex = pointer->dest;

            indegree[next_vertex]--;

            if(indegree[next_vertex] == 0){
                temp_element.key = next_vertex;
                min_heap_insert(&min_heap, temp_element);
            }
            pointer = pointer->next;
        }
    }

    for(int i = 0; i <= result_top; i++)
        printf("%d ", result[i]);

    printf("\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 100001

typedef struct{
    int key;
}element;

typedef struct{
    element array[MAX_SIZE];
    int size;
}Heap;

void min_heap_insert(Heap* heap, element item){
    int i = ++(heap->size);

    while((i != 1) && ((abs(item.key) < abs(heap->array[i / 2].key)) || ((abs(item.key) == abs(heap->array[i / 2].key)) && (item.key < heap->array[i / 2].key)))){
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
        if((child < heap->size) && ((abs(heap->array[child].key) > abs(heap->array[child + 1].key)) || ((abs(heap->array[child].key) == abs(heap->array[child + 1].key)) && (heap->array[child].key > heap->array[child + 1].key)))){
            child++;
        }

        if((abs(temp.key) < abs(heap->array[child].key)) || ((abs(temp.key) == abs(heap->array[child].key)) && (temp.key <= heap->array[child].key))){
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
    Heap min_heap;
    min_heap.size = 0;

    element item;

    int N;
    int input;

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d", &input);

        if(input == 0){

            if(min_heap.size == 0){
                printf("0\n");
            }
            else{
                element deleted_element = min_heap_delete(&min_heap);
                printf("%d\n", deleted_element.key);
            }
        }
        else{
            item.key = input;
            min_heap_insert(&min_heap, item);
        }
    }

    return 0;
}
#include <stdio.h>
#define MAX_SIZE 100000

typedef struct{
    int key;
}element;

typedef struct{
    element array[MAX_SIZE + 1];
    int size;
}Heap;

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
    int N;
    int input;

    Heap min_heap;
    min_heap.size = 0;

    element item;

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d", &input);

        if(input == 0){
            if(min_heap.size == 0)
                printf("0\n");
            else
                printf("%d\n", min_heap_delete(&min_heap).key);

        }else{
            item.key = input;
            min_heap_insert(&min_heap, item);
        }
    }

    return 0;
}
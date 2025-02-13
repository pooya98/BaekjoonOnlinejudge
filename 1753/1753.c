#include <stdio.h>
#include <stdlib.h>

#define NO 0
#define YES 1

#define INF 100000000
#define MAX_SIZE 400000

typedef struct _node{
    int dest;
    int distance;
    struct _node* next;
}node;

typedef struct{
    int key;
    int index;
}element;

typedef struct{
    element array[MAX_SIZE];
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

int V, E, K;

node* adj_list[20001];
int visited[20001];
int distance[20001];
int visit_count = 0;

element get_nearlist_and_not_yet_visited(Heap* heap){
    if(heap->size > 0){
        return min_heap_delete(heap);
    }else{
        element temp_element;
        temp_element.index = -1;
        temp_element.key = INF + 1;
        return temp_element;
    }
}

int main(void)
{
    Heap heap;
    node* pointer;
    element temp_element;

    heap.size = 0;

    scanf("%d %d", &V, &E);
    scanf("%d", &K);

    for(int i = 1; i <= 20000; i++){
        adj_list[i] = NULL;
        visited[i] = NO;
        distance[i] = INF;
    }

    for(int i = 0; i < E; i++){
        int v1, v2, weight;
        scanf("%d %d %d", &v1, &v2, &weight);

        node* newNode = (node*)malloc(sizeof(node));
        newNode->dest = v2;
        newNode->distance = weight;
        newNode->next = NULL;

        if(adj_list[v1]){
            newNode->next = adj_list[v1];
            adj_list[v1] = newNode;
        }
        else{
            adj_list[v1] = newNode;
        }
    }

    temp_element.index = K;
    temp_element.key = 0;

    min_heap_insert(&heap, temp_element);

    while(heap.size > 0){
        element nearlist_element = get_nearlist_and_not_yet_visited(&heap);

        if((nearlist_element.index < 0) || (distance[nearlist_element.index] <= nearlist_element.key)){
            continue;
        }

        visited[nearlist_element.index] = YES;
        distance[nearlist_element.index] = nearlist_element.key;
        visit_count++;

        pointer = adj_list[nearlist_element.index];

        while(pointer){
            int next_index = pointer->dest;
            int next_dist = pointer->distance + distance[nearlist_element.index];

            temp_element.key = next_dist;
            temp_element.index = next_index;

            min_heap_insert(&heap, temp_element);

            pointer = pointer->next;
        }
    }

    for(int i = 1; i <= V; i++){
        if(distance[i] == INF)
            printf("INF\n");
        else
            printf("%d\n", distance[i]);
    }

    

    for(int i = 1; i <= V; i++){
        pointer = adj_list[i];

        while(pointer){
            node* deleted = pointer;
            pointer = pointer->next;

            free(deleted);
        }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define NO 0
#define YES 1

#define INF  1000000
#define MAX_SIZE 2001

typedef struct _node{
    int dest;
    int distance;
    struct _node* next;
}node;

typedef struct{
    long long key;
    int index;
}element;

typedef struct{
    element array[MAX_SIZE * 10];
    int size;
}Heap;

node* adj_list[MAX_SIZE];
long long distance[MAX_SIZE];
int target[101];
long long distance_from_s[MAX_SIZE];
long long distance_from_g[MAX_SIZE];
long long distance_from_h[MAX_SIZE];

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

element get_nearlist_and_not_yet_visited(Heap* heap){
    if(heap->size > 0){
        return min_heap_delete(heap);
    }else{
        element temp_element;
        temp_element.index = -1;
        temp_element.key = -1;
        return temp_element;
    }
}

void sort_target(int start, int end){
    int min_index;
    int min_value;
    int temp;

    for(int i = start; i <= end; i++){
        min_value = target[i];
        min_index = i;

        for(int j = i + 1; j <= end; j++){
            if(min_value > target[j]){
                min_index = j;
                min_value = target[j];
            }
        }
        temp = target[i];
        target[i] = target[min_index];
        target[min_index] = temp;
    }
}

void dijkstra(Heap* heap, int start){

    for(int j = 1; j < MAX_SIZE; j++){
        distance[j] = INF;
    }

    element temp_element;
    node* pointer;

    heap->size = 0;

    temp_element.index = start;
    temp_element.key = 0;

    min_heap_insert(heap, temp_element);

    while(heap->size > 0){
        element nearlist_element = get_nearlist_and_not_yet_visited(heap);

        if((nearlist_element.index < 0) || (distance[nearlist_element.index] < nearlist_element.key)){
            continue;
        }

        distance[nearlist_element.index] = nearlist_element.key;

        pointer = adj_list[nearlist_element.index];

        while(pointer){
            int next_index = pointer->dest;
            long long next_dist = pointer->distance + distance[nearlist_element.index];

            temp_element.key = next_dist;
            temp_element.index = next_index;

            min_heap_insert(heap, temp_element);

            pointer = pointer->next;
        }
    }
}

int main(void)
{
    int T;
    scanf("%d", &T);

    int n, m, t;
    int s, g, h;
    int a, b, d;

    Heap heap;
    node* pointer;

    int g_to_h;

    for(int i = 0; i < T; i++){

        for(int j = 1; j < MAX_SIZE; j++)
            adj_list[j] = NULL;

        scanf("%d %d %d", &n, &m, &t);
        scanf("%d %d %d", &s, &g, &h);

        for(int j = 0; j < m; j++){
            scanf("%d %d %d", &a, &b, &d);

            if(((a == g) && (b == h)) || ((a == h) && (b == g)))
                g_to_h = d;

            pointer = (node*)malloc(sizeof(node));
            pointer->next = adj_list[a];
            pointer->dest = b;
            pointer->distance = d;
            adj_list[a] = pointer;

            pointer = (node*)malloc(sizeof(node));
            pointer->next = adj_list[b];
            pointer->dest = a;
            pointer->distance = d;
            adj_list[b] = pointer;
        }

        dijkstra(&heap, s);

        for(int j = 1; j <= n; j++){
            distance_from_s[j] = distance[j];
        }

        dijkstra(&heap, g);

        for(int j = 1; j <= n; j++){
            distance_from_g[j] = distance[j];
        }

        dijkstra(&heap, h);

        for(int j = 1; j <= n; j++){
            distance_from_h[j] = distance[j];
        }


        for(int j = 0; j < t; j++)
            scanf("%d", &target[j]);

        sort_target(0, t - 1);

        for(int j = 0; j < t; j++){
            int dest = target[j];

            long long distance_s_g_h_t = distance_from_s[g] + g_to_h + distance_from_h[dest];

            if((distance_s_g_h_t < INF) && (distance_s_g_h_t == distance_from_s[dest])){
                printf("%d ", dest);
                continue;
            }

            long long distance_s_h_g_t = distance_from_s[h] + g_to_h + distance_from_g[dest];

            if((distance_s_h_g_t < INF) && (distance_s_h_g_t == distance_from_s[dest])){
                printf("%d ", dest);
                continue;
            }
        }
        printf("\n");


        for(int j = 1; j < MAX_SIZE; j++){
            while(adj_list[j]){
                node* deleted = adj_list[j];
                adj_list[j] = adj_list[j]->next;

                free(deleted);
            }
        }
    }

    return 0;
}
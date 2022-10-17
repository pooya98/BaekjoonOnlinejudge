#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINT_NUM 1000 + 1
#define MAX_EDGE_NUM 500500 + 1
#define TRUE 1
#define FALSE 2

typedef struct _point{
    int x;
    int y;
}point;

typedef struct _node{
    int dest;
    double weight;
    struct _node* next;
}node;

typedef struct _element{
    int dest;
    double distance;
}element;

typedef struct _heap{
    element array[MAX_EDGE_NUM];
    int size;
}Heap;


point point_list[MAX_POINT_NUM];
node* adj_list[MAX_POINT_NUM];
int visited[MAX_POINT_NUM];
double sum_weight = 0.0;


void min_heap_insert(Heap* heap, element item){
    int i = ++(heap->size);

    while((i != 1) && (item.distance < heap->array[i / 2].distance)){
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
        if((child < heap->size) && ((heap->array[child].distance) > (heap->array[child + 1].distance))){
            child++;
        }

        if(temp.distance <= heap->array[child].distance){
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
    for(int i = 0; i < MAX_POINT_NUM; i++){
        adj_list[i] = NULL;
        visited[i] = FALSE;
    }

    int N, M;
    point temp_point;
    node* pointer;
    int v1, v2;
    Heap heap;
    heap.size = 0;
    element temp_element;

    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++){
        scanf("%d %d", &temp_point.x, &temp_point.y);

        point_list[i] = temp_point;

        for(int j = 1; j < i; j++){
            point cur_point = point_list[i];
            point oppo_point = point_list[j];

            double distance = sqrt(pow((cur_point.x - oppo_point.x), 2) + pow((cur_point.y - oppo_point.y), 2));

            pointer = (node*)malloc(sizeof(node));
            pointer->dest = j;
            pointer->weight = distance;
            pointer->next = adj_list[i];
            adj_list[i] = pointer;

            pointer = (node*)malloc(sizeof(node));
            pointer->dest = i;
            pointer->weight = distance;
            pointer->next = adj_list[j];
            adj_list[j] = pointer;
        }
    }

    for(int i = 1; i <= M; i++){
        scanf("%d %d", &v1, &v2);

        if(visited[v1] == FALSE){
            visited[v1] = TRUE;

            for(pointer = adj_list[v1]; pointer; pointer = pointer->next){
                int next_index = pointer->dest;
                double next_distance = pointer->weight;

                if(visited[next_index] == TRUE || next_index == v2)
                    continue;

                temp_element.dest = next_index;
                temp_element.distance = next_distance;

                min_heap_insert(&heap, temp_element);

            }
        }

        if(visited[v2] == FALSE){
            visited[v2] = TRUE;

            for(pointer = adj_list[v2]; pointer; pointer = pointer->next){
                int next_index = pointer->dest;
                double next_distance = pointer->weight;

                if(visited[next_index] == TRUE)
                    continue;

                temp_element.dest = next_index;
                temp_element.distance = next_distance;

                min_heap_insert(&heap, temp_element);

            }
        }
    }

    while(heap.size > 0){
        element cur_element = min_heap_delete(&heap);

        int cur_vertex = cur_element.dest;
        double cur_distance = cur_element.distance;

        if(visited[cur_vertex] == TRUE)
            continue;

        visited[cur_vertex] = TRUE;
        sum_weight += cur_distance;

        for(pointer = adj_list[cur_vertex]; pointer; pointer = pointer->next){
            int next_vertex = pointer->dest;
            double next_distance = pointer->dest;

            if(visited[next_vertex] == TRUE)
                continue;
            
            temp_element.dest = next_distance;
            temp_element.distance = next_distance;
            min_heap_insert(&heap, temp_element);
        }
    }

    printf("%.2lf", sum_weight);

    return 0;
}
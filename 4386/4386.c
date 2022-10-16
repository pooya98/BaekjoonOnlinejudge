#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100 + 1
#define MAX_VERTICES 100 + 1
#define MAX_EDGES 4950 + 1

#define TRUE 1
#define FALSE 2

#define INF 10000.0

typedef struct _point{
    double x;
    double y;
}point;

typedef struct{
    int dest;
    double distance;
}element;

typedef struct{
    element array[MAX_EDGES];
    int size;
}Heap;


point point_list[MAX_POINTS];
int point_list_top = 0;

double adj_matrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
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
    int n;
    double x, y;
    point cur_point;
    point oppo_point;
    double distance;

    Heap heap;
    element temp_element;

    for(int i = 1; i < MAX_VERTICES; i++)
        for(int j = 1; j < MAX_VERTICES; j++)
            adj_matrix[i][j] = INF;

    for(int i = 1; i < MAX_VERTICES; i++)
        visited[i] = FALSE;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%lf %lf", &x, &y);

        cur_point.x = x;
        cur_point.y = y;

        point_list[++point_list_top] = cur_point;

        for(int j = 1; j < point_list_top; j++){
            int cur_point_index = point_list_top;
            int oppo_point_index = j;
            oppo_point = point_list[oppo_point_index];


            distance = sqrt(pow((oppo_point.x - cur_point.x), 2) + pow((oppo_point.y - cur_point.y), 2));

            adj_matrix[cur_point_index][oppo_point_index] = distance;
            adj_matrix[oppo_point_index][cur_point_index] = distance;
        }
    }

    heap.size = 0;
    temp_element.dest = 1;
    temp_element.distance = 0.0;

    min_heap_insert(&heap, temp_element);

    while(heap.size > 0){
        element cur_element = min_heap_delete(&heap);

        int cur_vertex = cur_element.dest;
        double cur_distance = cur_element.distance;

        if(visited[cur_vertex] == TRUE)
            continue;

        visited[cur_vertex] = TRUE;
        sum_weight += cur_distance;

        for(int i = 1; i < MAX_VERTICES; i++){
            point cur_point = point_list[cur_vertex];
            point next_point = point_list[i];

            int next_vertex = i;
            double next_distance = adj_matrix[cur_vertex][next_vertex];

            if(visited[next_vertex] == TRUE || next_distance == INF)
                continue;
            else{
                temp_element.dest = next_vertex;
                temp_element.distance = next_distance;
                min_heap_insert(&heap, temp_element);
            }
        }
    }

    printf("%.2lf", sum_weight);

    return 0;
}
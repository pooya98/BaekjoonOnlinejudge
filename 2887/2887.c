#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERTICES 100000 + 1
#define X 1
#define Y 2
#define Z 3

#define HEAP_MAX_SIZE 300000 + 1

typedef struct _point{
    int index;
    int x;
    int y;
    int z;
}point;

typedef struct _sorted_element{
    int degree;
    int index;
}sorted_element;

typedef struct{
    int v1;
    int v2;
    int weight;
}element;

typedef struct{
    element array[HEAP_MAX_SIZE];
    int size;
}Heap;

point point_list[MAX_VERTICES];
sorted_element sorted_list_x[MAX_VERTICES];
sorted_element sorted_list_y[MAX_VERTICES];
sorted_element sorted_list_z[MAX_VERTICES];
sorted_element temp_sorted_list[MAX_VERTICES];

int parent[MAX_VERTICES];
long long sum_weight = 0;

void min_heap_insert(Heap* heap, element item){
    int i = ++(heap->size);

    while((i != 1) && (item.weight < heap->array[i / 2].weight)){
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
        if((child < heap->size) && ((heap->array[child].weight) > (heap->array[child + 1].weight))){
            child++;
        }

        if(temp.weight <= heap->array[child].weight){
            break;
        }

        heap->array[parent] = heap->array[child];

        parent = child;
        child *= 2;
    }

    heap->array[parent] = temp;

    return item;
}

void merge_sort(sorted_element sort_list[], int start, int end){
    if(start >= end)
        return;

    int mid = (start + end) / 2;

    merge_sort(sort_list, start, mid);
    merge_sort(sort_list, mid + 1, end);

    int i = start;
    int j = mid + 1;
    int temp_list_pointer = start - 1;

    while((i <= mid) && (j <= end)){
        if(sort_list[i].degree <= sort_list[j].degree)
            temp_sorted_list[++temp_list_pointer] = sort_list[i++];
        else
            temp_sorted_list[++temp_list_pointer] = sort_list[j++];
    }

    while(i <= mid)
        temp_sorted_list[++temp_list_pointer] = sort_list[i++];

    while(j <= end)
        temp_sorted_list[++temp_list_pointer] = sort_list[j++];

    for(int i = start; i <= end; i++)
        sort_list[i] = temp_sorted_list[i];
}

void sort_list(sorted_element sort_list[], int start, int end){
    merge_sort(sort_list, start, end);
}

int find_parent(int vertex){
    if(vertex != parent[vertex])
        parent[vertex] = find_parent(parent[vertex]);

    return parent[vertex];
}

int main(void)
{
    int N;
    int x, y, z;
    point temp_point;
    sorted_element temp_sorted_element;
    Heap heap;
    heap.size = 0;
    element temp_element;
    int v1, v2;
    int weight;

    for(int i = 0; i < MAX_VERTICES; i++){
        parent[i] = i;
    }

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        temp_point.index = i;
        temp_sorted_element.index = i;

        scanf("%d %d %d", &x, &y, &z);

        temp_point.x = x;
        temp_point.y = y;
        temp_point.z = z;

        point_list[i] = temp_point;

        temp_sorted_element.degree = x;
        sorted_list_x[i] = temp_sorted_element;

        temp_sorted_element.degree = y;
        sorted_list_y[i] = temp_sorted_element;

        temp_sorted_element.degree = z;
        sorted_list_z[i] = temp_sorted_element;
    }

    sort_list(sorted_list_x, 0, N - 1);
    sort_list(sorted_list_y, 0, N - 1);
    sort_list(sorted_list_z, 0, N - 1);

    for(int i = 0; i < N - 1; i++){
        v1 = sorted_list_x[i].index;
        v2 = sorted_list_x[i + 1].index;
        weight = abs(sorted_list_x[i].degree - sorted_list_x[i + 1].degree);

        temp_element.v1 = v1;
        temp_element.v2 = v2;
        temp_element.weight = weight;

        min_heap_insert(&heap, temp_element);

        v1 = sorted_list_y[i].index;
        v2 = sorted_list_y[i + 1].index;
        weight = abs(sorted_list_y[i].degree - sorted_list_y[i + 1].degree);

        temp_element.v1 = v1;
        temp_element.v2 = v2;
        temp_element.weight = weight;

        min_heap_insert(&heap, temp_element);

        v1 = sorted_list_z[i].index;
        v2 = sorted_list_z[i + 1].index;
        weight = abs(sorted_list_z[i].degree - sorted_list_z[i + 1].degree);

        temp_element.v1 = v1;
        temp_element.v2 = v2;
        temp_element.weight = weight;

        min_heap_insert(&heap, temp_element);
    }

    while(heap.size > 0){
        element cur_element = min_heap_delete(&heap);

        v1 = cur_element.v1;
        v2 = cur_element.v2;
        weight = cur_element.weight;

        int v1_parent = find_parent(v1);
        int v2_parent = find_parent(v2);

        if(v1_parent != v2_parent){
            if(v1_parent < v2_parent)
                parent[v2_parent] = v1_parent;
            else
                parent[v1_parent] = v2_parent;

            sum_weight += (long long)weight;
        }
    }
    printf("%lld", sum_weight);
        
    return 0;
}
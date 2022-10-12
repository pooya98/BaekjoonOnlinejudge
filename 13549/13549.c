// 헤더파일 선언
#include <stdio.h>

// 상수 선언
#define MAX 100000 + 1
#define HEAP_MAX 100000 + 1

#define VISITED 1
#define NOT_VISITED 2

#define INF 987654321

// 구조체 선언
typedef struct{
    int time;
    int start;
}element;

typedef struct{
    element array[HEAP_MAX];
    int size;
}Heap;

// 전역 변수 선언
int time_array[MAX];
int visited[MAX];


// 함수 선언
void min_heap_insert(Heap* heap, element item){
    int i = ++(heap->size);

    while((i != 1) && ((item.time < heap->array[i / 2].time) || ((item.time == heap->array[i / 2].time) && (item.start < heap->array[i / 2].start)))){
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
        if((child < heap->size) && (((heap->array[child].time) > (heap->array[child + 1].time)) || (((heap->array[child].time) == (heap->array[child + 1].time)) && ((heap->array[child].start) > (heap->array[child + 1].start))))){
            child++;
        }

        if((temp.time <= heap->array[child].time) || (((temp.time == heap->array[child].time)) && ((temp.start <= heap->array[child].start)))){
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
    int N, K;
    Heap heap;
    element temp_element;

    heap.size = 0;

    scanf("%d %d", &N, &K);

    for(int i = 0; i < MAX; i++){
        visited[i] = NOT_VISITED;
        time_array[i] = INF;
    }

    temp_element.start = N;
    temp_element.time = 0;

    min_heap_insert(&heap, temp_element);
    visited[temp_element.start] = VISITED;
    time_array[temp_element.start] = 0;

    while(heap.size > 0){
        element cur_element = min_heap_delete(&heap);

        int cur_index = cur_element.start;
        int cur_time = cur_element.time;
        int next_index;
        int next_time;

        if(time_array[cur_index] < cur_time)
            continue;

        // X - 1 으로 이동
        next_index = cur_index - 1;
        next_time = cur_time + 1;

        if(next_index >= 0){
            if(visited[next_index] == NOT_VISITED){
                temp_element.start = next_index;
                temp_element.time = next_time;

                min_heap_insert(&heap, temp_element);
                visited[next_index] = VISITED;
                time_array[next_index] = next_time;
            }
            else{
                if(time_array[next_index] > next_time){
                    temp_element.start = next_index;
                    temp_element.time = next_time;

                    min_heap_insert(&heap, temp_element);
                    time_array[next_index] = next_time;
                }
            }
        }

        // X + 1 으로 이동
        next_index = cur_index + 1;
        next_time = cur_time + 1;

        if(next_index < MAX){
            if(visited[next_index] == NOT_VISITED){
                temp_element.start = next_index;
                temp_element.time = next_time;

                min_heap_insert(&heap, temp_element);
                visited[next_index] = VISITED;
                time_array[next_index] = next_time;
            }
            else{
                if(time_array[next_index] > next_time){
                    temp_element.start = next_index;
                    temp_element.time = next_time;

                    min_heap_insert(&heap, temp_element);
                    time_array[next_index] = next_time;
                }
            }
        }

        // 모든 2 * X 으로 이동
        next_index = cur_index * 2;
        next_time = cur_time;

        if(next_index != 0){
            while(next_index < MAX){
                if(visited[next_index] == NOT_VISITED){
                    temp_element.start = next_index;
                    temp_element.time = next_time;

                    min_heap_insert(&heap, temp_element);
                    visited[next_index] = VISITED;
                    time_array[next_index] = next_time;
                }
                else{
                    if(time_array[next_index] > next_time){
                        temp_element.start = next_index;
                        temp_element.time = next_time;

                        min_heap_insert(&heap, temp_element);
                        time_array[next_index] = next_time;
                    }
                }
                next_index *= 2;
            }
        }
    }

    printf("%d", time_array[K]);

    return 0;
}
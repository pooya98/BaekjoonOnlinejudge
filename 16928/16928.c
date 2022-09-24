#include <stdio.h>

int mapping_table[101];
int step_table[101];

int queue[101];
int queue_step[101];
int queue_front = -1;
int queue_rear = -1;

void bfs(int start){
    int cur_index = start;
    int cur_step = 0;

    int next_index;
    int next_step;

    ++queue_rear;
    queue[queue_rear] = cur_index;
    queue_step[queue_rear] = cur_step;
    step_table[cur_index] = 0;

    while(queue_front < queue_rear){
        ++queue_front;
        cur_index = queue[queue_front];
        cur_step = queue_step[queue_front];

        for(int i = 1; i <= 6; i++){
            if((cur_index + i) > 100)
                break;

            next_index = mapping_table[cur_index + i];
            next_step = cur_step + 1;

            if(step_table[next_index] > next_step){
                ++queue_rear;
                queue[queue_rear] = next_index;
                queue_step[queue_rear] = next_step;
                step_table[next_index] = next_step;
            }
        }
    }
}

int main(void)
{
    for(int i = 1; i <= 100; i++){
        mapping_table[i] = i;
        step_table[i] = 1000;
    }

    int N, M;
    int v1, v2;

    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++){
        scanf("%d %d", &v1, &v2);

        mapping_table[v1] = v2;
    }

    for(int i = 0; i < M; i++){
        scanf("%d %d", &v1, &v2);

        mapping_table[v1] = v2;
    }

    bfs(1);

    printf("%d", step_table[100]);

    return 0;
}
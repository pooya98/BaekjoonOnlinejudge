#include <stdio.h>

int N, M;

int matrix[1001][1001];
int shortest_distance_punch_0[1001][1001];
int shortest_distance_punch_1[1001][1001];

int queue_x[2000000];
int queue_y[2000000];
int queue_step[2000000];
int queue_punch[2000000];

int queue_front = -1;
int queue_rear = -1;

int move_x[4] = {-1, 0, 1, 0};
int move_y[4] = {0, 1, 0, -1};

void bfs(int x, int y){
    int cur_x, cur_y;
    int next_x, next_y;
    int cur_step, cur_punch;
    int next_step, next_punch;

    cur_x = x;
    cur_y = y;
    cur_step = 1;
    cur_punch = 0;

    ++queue_rear;
    queue_x[queue_rear] = cur_x;
    queue_y[queue_rear] = cur_y;
    queue_step[queue_rear] = cur_step;
    queue_punch[queue_rear] = cur_punch;
    shortest_distance_punch_0[cur_x][cur_y] = 1;

    while(queue_front < queue_rear){
        ++queue_front;
        cur_x = queue_x[queue_front];
        cur_y = queue_y[queue_front];
        cur_step = queue_step[queue_front];
        cur_punch = queue_punch[queue_front];

        for(int i = 0; i < 4; i++){
            next_x = cur_x + move_x[i];
            next_y = cur_y + move_y[i];
            next_step = cur_step + 1;
            
            if(((1 <= next_x) && (next_x <= N)) && ((1 <= next_y) && (next_y <= M))){
                if(matrix[next_x][next_y] == 0)
                    next_punch = cur_punch;
                else
                    next_punch = cur_punch + 1;

                if(next_punch == 0){
                    if(shortest_distance_punch_0[next_x][next_y] > next_step){
                        ++queue_rear;
                        queue_x[queue_rear] = next_x;
                        queue_y[queue_rear] = next_y;
                        queue_step[queue_rear] = next_step;
                        queue_punch[queue_rear] = next_punch;
                        shortest_distance_punch_0[next_x][next_y] = next_step;
                    }
                }
                else if(next_punch == 1){
                    if(shortest_distance_punch_1[next_x][next_y] > next_step){
                        ++queue_rear;
                        queue_x[queue_rear] = next_x;
                        queue_y[queue_rear] = next_y;
                        queue_step[queue_rear] = next_step;
                        queue_punch[queue_rear] = next_punch;
                        shortest_distance_punch_1[next_x][next_y] = next_step;
                    }
                }
                else{
                    continue;
                }
            }
        }
    }
}

int main(void)
{
    char input[1002];
    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++){
        scanf("%s", &input[1]);

        for(int j = 1; j <= M; j++){
            matrix[i][j] = (int)input[j] - '0';
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            shortest_distance_punch_0[i][j] = 10000000;
            shortest_distance_punch_1[i][j] = 10000000;
        }
    }

    bfs(1, 1);

    if((shortest_distance_punch_0[N][M] == 10000000) && (shortest_distance_punch_1[N][M] == 10000000))
        printf("-1");
    else{
        if(shortest_distance_punch_0[N][M] <= shortest_distance_punch_1[N][M])
            printf("%d", shortest_distance_punch_0[N][M]);
        else if(shortest_distance_punch_0[N][M] > shortest_distance_punch_1[N][M])
            printf("%d", shortest_distance_punch_1[N][M]);
    }

    return 0;
}
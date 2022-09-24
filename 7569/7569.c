#include <stdio.h>

#define TRUE 0
#define FALSE 1
#define INF 100000000

int N, M, H;
int box[101][101][101];
int visited[101][101][101] = {0};

int max_days = 0;
int result = 0;

int move_x[6] = {-1, 0, 1, 0, 0, 0};
int move_y[6] = {0, 1, 0, -1, 0, 0};
int move_z[6] = {0, 0, 0, 0, 1, -1};

int queue_x[1000001];
int queue_y[1000001];
int queue_z[1000001];
int queue_days[1000001];
int queue_rear = -1;
int queue_front = -1;

void bfs(int x, int y, int z){
    int cur_x;
    int cur_y;
    int cur_z;
    int cur_days;

    int next_x;
    int next_y;
    int next_z;
    int next_days;

    cur_x = x;
    cur_y = y;
    cur_z = z;
    cur_days = 0;

    queue_rear = -1;
    queue_front = -1;
    
    queue_rear++;
    queue_x[queue_rear] = cur_x;
    queue_y[queue_rear] = cur_y;
    queue_z[queue_rear] = cur_z;
    queue_days[queue_rear] = cur_days;
    box[cur_x][cur_y][cur_z] = 2;
    visited[cur_x][cur_y][cur_z] = cur_days;

    while(queue_front < queue_rear){
        queue_front++;
        cur_x = queue_x[queue_front];
        cur_y = queue_y[queue_front];
        cur_z = queue_z[queue_front];
        cur_days = queue_days[queue_front];

        for(int i = 0; i < 6; i++){
            next_x = cur_x + move_x[i];
            next_y = cur_y + move_y[i];
            next_z = cur_z + move_z[i];
            next_days = cur_days + 1;

            if(((1 <= next_x) && (next_x <= N)) && ((1 <= next_y) && (next_y <= M)) && ((1 <= next_z) && (next_z <= H))){
                if((box[next_x][next_y][next_z] % 2 == 0) && (visited[next_x][next_y][next_z] > next_days)){
                    queue_rear++;
                    queue_x[queue_rear] = next_x;
                    queue_y[queue_rear] = next_y;
                    queue_z[queue_rear] = next_z;
                    queue_days[queue_rear] = next_days;

                    visited[next_x][next_y][next_z] = next_days;
                    box[next_x][next_y][next_z] = 2;
                }
            }
        }
    }
}

int main(void)
{
    scanf("%d %d %d", &M, &N, &H);

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= M; k++){
                visited[j][k][i] = INF;
            }
        }
    }

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= M; k++){
                scanf("%d", &box[j][k][i]);
            }
        }
    }

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= M; k++){
                if(box[j][k][i] == 1)
                    bfs(j, k, i);
            }
        }
    } 

    int shortage_flag = FALSE;

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= M; k++){
                if(box[j][k][i] == 0){
                    shortage_flag = TRUE;
                }
            }
        }
    }

    if(shortage_flag == TRUE)
        result = -1;
    else{
        for(int i = 1; i <= H; i++){
            for(int j = 1; j <= N; j++){
                for(int k = 1; k <= M; k++){
                    if((visited[j][k][i] != INF) && (visited[j][k][i] > max_days)){
                        max_days = visited[j][k][i];
                    }
                }
            }
        }
        result = max_days;
    }

    printf("%d", result);
    return 0;
}
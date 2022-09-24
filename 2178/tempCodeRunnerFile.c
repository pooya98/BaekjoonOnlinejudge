#include <stdio.h>

int N, M;
int maze[101][101];
int min_count = 0;

int queue_x[100000];
int queue_y[100000];
int queue_step[100000];
int queue_front = -1;
int queue_rear = -1;

int move_x[4] = {-1, 0, 1, 0};
int move_y[4] = {0, 1, 0, -1};

void bfs(int x, int y){
    int cur_x;
    int cur_y;
    int cur_step;
    int next_x;
    int next_y;
    int next_step;

    queue_rear++;
    queue_x[queue_rear] = x;
    queue_y[queue_rear] = y;
    queue_step[queue_rear] = 1;

    while(queue_front < queue_rear){
        queue_front++;
        cur_x = queue_x[queue_front];
        cur_y = queue_y[queue_front];
        cur_step = queue_step[queue_front];
        

        if((cur_x == N) && (cur_y == M)){
            min_count = cur_step;
            break;
        }

        maze[cur_x][cur_y] = 2;

        for(int i = 0; i < 4; i++){
            next_x = cur_x + move_x[i];
            next_y = cur_y + move_y[i];
            next_step = cur_step + 1;

            if(((1 <= next_x) && (next_x <= N)) && ((1 <= next_y) && (next_y <= M))){
                if(maze[next_x][next_y] == 1){
                    queue_rear++;
                    queue_x[queue_rear] = next_x;
                    queue_y[queue_rear] = next_y;
                    queue_step[queue_rear] = next_step;
                }
            }
        }
    }
}

int main(void)
{
    scanf("%d %d", &N, &M);
    char input[102];

    for(int i = 1; i <= N; i++){
        scanf("%s", &input[1]);

        for(int j = 1; j <= M; j++)
            maze[i][j] = (int)input[j] - '0';
    }

    bfs(1, 1);

    printf("%d", min_count);

    return 0;
}
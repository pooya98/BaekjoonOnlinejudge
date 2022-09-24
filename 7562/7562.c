#include <stdio.h>

#define INF 100000000

int chess_board[300][300];

int l;
int cur_x, cur_y;
int des_x, des_y;

int move_x[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int move_y[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int queue_x[90001];
int queue_y[90001];
int queue_step[90001];

int queue_front = -1;
int queue_rear  = -1;

void bfs(int x, int y){
    int cur_x, cur_y, cur_step;
    int next_x, next_y, next_step;

    queue_front = -1;
    queue_rear  = -1;

    cur_x = x;
    cur_y = y;
    cur_step = 0;

    queue_rear++;
    queue_x[queue_rear] = cur_x;
    queue_y[queue_rear] = cur_y;
    queue_step[queue_rear] = cur_step;

    chess_board[cur_x][cur_y] = cur_step;

    while(queue_front < queue_rear){
        queue_front++;
        cur_x = queue_x[queue_front];
        cur_y = queue_y[queue_front];
        cur_step = queue_step[queue_front];

        for(int i = 0; i < 8; i++){
            next_x = cur_x + move_x[i];
            next_y = cur_y + move_y[i];
            next_step = cur_step + 1;

            if((0 <= next_x) && (next_x < l) && (0 <= next_y) && (next_y < l)){
                if(chess_board[next_x][next_y] > next_step){
                    queue_rear++;
                    queue_x[queue_rear] = next_x;
                    queue_y[queue_rear] = next_y;
                    queue_step[queue_rear] = next_step;

                    chess_board[next_x][next_y] = next_step;
                }
            }
        }
    }


}

int main(void)
{
    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        scanf("%d", &l);

        scanf("%d %d", &cur_x, &cur_y);
        scanf("%d %d", &des_x, &des_y);

        for(int i = 0; i < l; i++)
            for(int j = 0; j < l; j++)
                chess_board[i][j] = INF;

        bfs(cur_x, cur_y);

        printf("%d\n", chess_board[des_x][des_y]);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int N;
int chess_board[15][15] = {0};
int count = 0;

int x_stack[15];
int y_stack[15];
int top = 0;

void dfs(int row){
    if(row > N){
        count++;
        return;
    }
    
    for(int i = 1; i <= N; i++){
        int cur_x = row;
        int cur_y = i;
        int flag = 0;

        for(int j = 1; j <= top; j++){
            int x_gap = abs(cur_x - x_stack[j]);
            int y_gap = abs(cur_y - y_stack[j]);

            if((y_gap == 0) || (x_gap == y_gap)){
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            top++;
            x_stack[top] = cur_x;
            y_stack[top] = cur_y;
            dfs(row + 1);
            top--;
        }
    }
}

int main(void)
{
    scanf("%d", &N);

    for(int i = 1; i <= N; i++){
        top++;
        x_stack[top] = 1;
        y_stack[top] = i;
        dfs(2);
        top--;
    }

    printf("%d", count);
    return 0;
}
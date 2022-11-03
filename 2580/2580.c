#include <stdio.h>

int sudoku_board[10][10];

int x_stack[100];
int y_stack[100];
int x_zone_stack[100];
int y_zone_stack[100];
int blank_count = 0;
int find_flag = 0;

void print_board(){
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            printf("%d ", sudoku_board[i][j]);
        }
        printf("\n");
    }
}

void dfs(int depth){
    if(depth > blank_count){
        print_board();
        find_flag = 1;
        return;
    }

    for(int i = 1; i <= 9; i++){
        int cur_x = x_stack[depth];
        int cur_y = y_stack[depth];
        int cur_x_zone = x_zone_stack[depth];
        int cur_y_zone = y_zone_stack[depth];
        int flag = 0;

        for(int j = 1; j <= 9; j++){
            if((sudoku_board[cur_x][j] == i) || sudoku_board[j][cur_y] == i){
                flag = 1;
                break;
            }
        }

        int start_x = cur_x_zone * 3 + 1;
        int start_y = cur_y_zone * 3 + 1;
        int end_x = cur_x_zone * 3 + 3;
        int end_y = cur_y_zone * 3 + 3;

        for(int j = start_x; j <= end_x; j++){
            for(int k = start_y; k <= end_y; k++){
                if(sudoku_board[j][k] == i){
                    flag = 1;
                    break;
                }
            }
        }

        if(flag == 0){
            sudoku_board[cur_x][cur_y] = i;
            dfs(depth + 1);
            sudoku_board[cur_x][cur_y] = 0;
            if(find_flag == 1)
                break;
        }
    }
}

int main(void)
{
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            scanf("%d", &sudoku_board[i][j]);
            if(sudoku_board[i][j] == 0){
                blank_count++;
                x_stack[blank_count] = i;
                y_stack[blank_count] = j;
                x_zone_stack[blank_count] = (i - 1) / 3;
                y_zone_stack[blank_count] = (j - 1) / 3;
            }
        }
    }

    for(int i = 1; i <= 9; i++){
        int cur_x = x_stack[1];
        int cur_y = y_stack[1];
        int cur_x_zone = x_zone_stack[1];
        int cur_y_zone = y_zone_stack[1];
        int flag = 0;

        for(int j = 1; j <= 9; j++){
            if((sudoku_board[cur_x][j] == i) || sudoku_board[j][cur_y] == i){
                flag = 1;
                break;
            }
        }

        int start_x = cur_x_zone * 3 + 1;
        int start_y = cur_y_zone * 3 + 1;
        int end_x = cur_x_zone * 3 + 3;
        int end_y = cur_y_zone * 3 + 3;

        for(int j = start_x; j <= end_x; j++){
            for(int k = start_y; k <= end_y; k++){
                if(sudoku_board[j][k] == i){
                    flag = 1;
                    break;
                }
            }
        }
        
        if(flag == 0){
            sudoku_board[cur_x][cur_y] = i;
            dfs(2);
            sudoku_board[cur_x][cur_y] = 0;

            if(find_flag == 1)
                break;
        }
    }

    return 0;
}
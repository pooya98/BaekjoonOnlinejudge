#include <stdio.h>

int board[101][101] = {0};
int size = 0;

int main(void)
{
    int N;
    int start_x, start_y;
    int end_x, end_y;

    scanf("%d", &N);

    for(int i = 1; i <= N; i++){
        scanf("%d %d", &start_x, &start_y);

        end_x = start_x + 10;
        end_y = start_y + 10;

        for(int i = start_x; i < end_x; i++)
            for(int j = start_y; j < end_y; j++){
                if(board[i][j] == 0){
                    board[i][j] = 1;
                    size++;
                }
            }
    }

    printf("%d", size);

    return 0;
}
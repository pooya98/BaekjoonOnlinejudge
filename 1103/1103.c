#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n, m;
    int board[50][50];
    int stack_x[2500];
    int stack_y[2500];
    int stack_step[2500];
    int top = -1;

    int cur_x;
    int cur_y;

    int move_x[4] = {0, 1, 0, -1};
    int move_y[4] = {1, 0, -1, 0};

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
    {
        char input[51];

        scanf("%s", input);

        for(int j = 0; j < strlen(input); j++){
            if(input[j] == 'H')
                board[i][j] = 0;
            else
                board[i][j] = input[j] - '0';
        }
    }

    cur_x = 0;
    cur_y = 0;

    top++;
    stack_x[top] = cur_x;
    stack_y[top] = cur_y;

    while(top >= 0){

    }



    return 0;
}
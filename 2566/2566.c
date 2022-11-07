#include <stdio.h>

int matrix[10][10];
int max_value = 0;
int max_value_x = 1;
int max_value_y = 1;

int main(void)
{
    for(int i = 1; i <= 9; i++)
        for(int j = 1; j <= 9; j++)
            scanf("%d", &matrix[i][j]);

    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            if(max_value < matrix[i][j]){
                max_value = matrix[i][j];
                max_value_x = i;
                max_value_y = j;
            }
        }
    }

    printf("%d\n%d %d", max_value, max_value_x, max_value_y);

    return 0;
}
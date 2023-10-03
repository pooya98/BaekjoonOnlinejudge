#include <stdio.h>

char matrix[2188][2188];

void print_matrix(int x, int y, int n){
    if(n == 1)
        matrix[x][y] = '*';
    else{
        int count = 1;

        for(int i = x; i < x + n; i += n/3){
            for(int j = y; j < y + n; j += n/3){
                if(count != 5)
                    print_matrix(i, j, n/3);
                count++;
            }
        }
    }
}

int main(void)
{
    int n;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            matrix[i][j] = ' ';

    print_matrix(1, 1, n);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            printf("%c", matrix[i][j]);
        printf("\n");
    }

    return 0;
}
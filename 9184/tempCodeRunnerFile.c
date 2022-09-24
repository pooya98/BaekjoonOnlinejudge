#include <stdio.h>

int cube[101][101][101];

void print_matrix(int num){
    printf("\n");
    printf("\n");
    for(int k = 0; k <= 100; k++){
        for(int j = 0; j <= 100; j++){
            printf("%d ", cube[num][j][k]);
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");
}

int main(void)
{
    for(int i = 0; i <= 100; i++){
        for(int k = 0; k <= 100; k++){
            for(int j = 0; j <= 100; j++){
                if((i <= 50) || (j <= 50) || (k <= 50)){
                    cube[i][j][k] = 1;
                }
            }
        }
    }

    for(int i = 0; i <= 100; i++){
        for(int k = 0; k <= 100; k++){
            for(int j = 0; j <= 100; j++){

                if((i <= 50) || (j <= 50) || (k <= 50)){
                    continue;
                }

                if((i > 70) || (j > 70) || (k > 70)){
                    continue;
                }

                if((i < j) && (j < k)){
                    cube[i][j][k] = cube[i][j][k - 1] + cube[i][j - 1][k - 1] - cube[i][j - 1][k];
                    //print_matrix(i);
                    continue;
                }

                cube[i][j][k] = cube[i - 1][j][k] + cube[i - 1][j - 1][k] + cube[i - 1][j][k - 1] - cube[i - 1][j - 1][k - 1];
                //print_matrix(i);


            }
        }
    }

    for(int i = 0; i <= 100; i++){
        for(int k = 0; k <= 100; k++){
            for(int j = 0; j <= 100; j++){
                if((i > 70) || (j > 70) || (k > 70)){
                    cube[i][j][k] = cube[70][70][70];
                }
            }
        }
    }

    int a, b, c;

    while(1){
        scanf("%d %d %d", &a, &b, &c);

        if((a == -1) && (b == -1) && (c == -1))
            break;

        printf("w(%d, %d, %d) = %d\n", a, b, c, cube[a + 50][b + 50][c + 50]);
    }

    return 0;
}
#include <stdio.h>

int main(void)
{
    int N;
    int arr_x[35];
    int arr_y[35];
    int select_point_x[3];
    int select_point_y[3];

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
        scanf("%d %d", &arr_x[i], &arr_y[i]);

    for(int i = 0; i < N; i++){
        select_point_x[0] = arr_x[i];
        select_point_y[0] = arr_y[i];

        for(int j = i + 1; j < N; j++){
            for(int k = j + 1; k < N; k++){
                
            }
        }
    }
    return 0;
}
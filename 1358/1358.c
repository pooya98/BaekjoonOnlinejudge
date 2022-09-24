#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 2

int W, H, X, Y, P;
double radius = 0;
double left_center_x;
double left_center_y;
double right_center_x;
double right_center_y;

int is_player_in_the_field(int x, int y){
    int result = FALSE;
    double distance = 0.0;

    if(X <= x && x <= (X + W)){
        if(Y<= y && y <= (Y + H))
            result = TRUE;
    }
    else{
        if(x < X){
            distance = sqrt(pow(x - left_center_x, 2) + pow(y - left_center_y, 2));

            if(distance <= radius)
                result = TRUE;
        }
        else{
            distance = sqrt(pow(x - right_center_x, 2) + pow(y - right_center_y, 2));

            if(distance <= radius)
                result = TRUE;
        }
    }

    return result;
}

int main(void)
{
    int player_x[50];
    int player_y[50];
    int inside_player_count = 0;

    scanf("%d %d %d %d %d", &W, &H, &X, &Y, &P);

    radius = (double)H / 2;
    left_center_x = (double)X;
    left_center_y = Y + radius;
    right_center_x = (double)X + W;
    right_center_y = Y + radius;

    for(int i = 0; i < P; i++){
        scanf("%d %d", &player_x[i], &player_y[i]);
    }


    for(int i = 0; i < P; i++){
        if(is_player_in_the_field(player_x[i], player_y[i]) == TRUE)
            inside_player_count++;
    }

    printf("%d", inside_player_count);

    return 0;
}
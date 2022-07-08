#include <stdio.h>

#define ABLE 1
#define UNABLE 0

int main(void)
{
    int n;
    int arr[51];
    int a_up, a_down, b_up, b_down;
    int result_flag = ABLE;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }

    if(n < 2){
        printf("A");
    }
    else if(n == 2){
        if(arr[1] == arr[2]){
            printf("%d\n", arr[1]);
        }
        else{
            printf("A");
        }
    }
    else{
        a_up = (arr[3] - arr[2]);
        a_down = (arr[2] - arr[1]);

        b_up = arr[2]*(arr[2] - arr[1]) - (arr[3] - arr[2]) * arr[1];
        b_down = (arr[2] - arr[1]);

        if (arr[1] == arr[2]){
            a_up = 0;
            a_down = 1;
            b_up = arr[1];
            b_down = 1;
        }

        for(int i = 2; i <= n; i++){
            if((b_down * a_down * arr[i]) != ((b_down * a_up * arr[i - 1]) + a_down * b_up)){
                result_flag = UNABLE;
                break;
            }
        }

        if(result_flag == ABLE){
            if((a_up % a_down != 0 || b_up % b_down != 0)){
                printf("B");
            }
            else{
                printf("%d\n", (a_up)/(a_down)* arr[n] + b_up/b_down);
            }
        }
        else{
            printf("B");
        }
    }

    return 0;
}
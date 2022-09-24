#include <stdio.h>

int main(void)
{
    int K;
    scanf("%d", &K);

    int arr[7];
    int max_index;
    int max = 0;
    int A_1;
    int A_2;
    int B_1;
    int B_2;

    for(int i = 1; i <= 6; i++){
        int dump;
        scanf("%d %d", &dump, &arr[i]);
    }

    for(int i = 1; i <= 6; i++){
        if(max < arr[i]){
            max = arr[i];
            max_index = i;
        }
    }

    A_1 = (max_index + 1) % 6;
    A_2 = (max_index + 2) % 6;
    B_1 = (max_index + 4) % 6;
    B_2 = (max_index + 5) % 6;

    if(A_1 == 0)
        A_1 = 6;

    if(A_2 == 0)
        A_2 = 6;  

    if(B_1 == 0)
        B_1 = 6; 

    if(B_2 == 0)
        B_2 = 6;

    printf("%d", (arr[A_1] * arr[A_2] + arr[B_1] * arr[B_2]) * K);

    return 0;
}
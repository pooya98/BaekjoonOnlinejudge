#include <stdio.h>
#include <string.h>

#define AVAILABLE 0
#define OUT_OF_ORDER 1

#define ABLE 1
#define UNABLE 0

int n, m;
int arr[10] = {0};
int count[1000000] = {0};
int dp_number[1000000] = {0};

void calculate_dp_numbers(int digit, int sum){
    if(digit == 6){

        char text[7];
        sprintf(text, "%d", sum);
        
        dp_number[sum] = strlen(text);
        return;
    }

    for(int i = 0; i < 10; i++){
        if(arr[i] == AVAILABLE)
            calculate_dp_numbers(digit + 1, sum * 10 + i);
    }
}

int main(void)
{
    scanf("%d", &n);
    scanf("%d", &m);

    for(int i = 0; i < m; i++){
        int input;
        scanf("%d", &input);
        arr[input] = OUT_OF_ORDER;
    }

    count[100] = 0;

    for(int i = 99; i >= 0; i--)
        count[i] = 100 - i;

    for(int i = 101; i < 1000000; i++)
        count[i] = i - 100;

    for(int i = 5; i >= 0; i--){
        calculate_dp_numbers(i, 0);
    }

    for(int i = 0; i < 1000000; i++){
        if((dp_number[i] != UNABLE) && (dp_number[i] < count[i]))
            count[i] = dp_number[i];
    }

    for(int i = 99; i >= 0; i--){
        if((count[i + 1] + 1) < count[i])
            count[i] = count[i + 1] + 1;
    }

    for(int i = 1; i <= 99; i++){
        if((count[i - 1] + 1) < count[i])
            count[i] = count[i - 1] + 1;
    }

    for(int i = 101; i <= 999999; i++){
        if((count[i - 1] + 1) < count[i])
            count[i] = count[i - 1] + 1;
    }

    for(int i = 999998; i >= 101; i--){
        if((count[i + 1] + 1) < count[i])
            count[i] = count[i + 1] + 1;
    }

    printf("%d\n", count[n]);
    return 0;
}
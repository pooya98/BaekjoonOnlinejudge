#include <stdio.h>

int fibo_dp_count = 0;
int fibo_recursion_count = 0;

int fibo_dp(int n){
    int fibo[41];

    fibo[1] = 1;
    fibo[2] = 1;

    for(int i = 3; i <= n; i++){
        fibo_dp_count++;
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    return fibo[n];
}

int fibo_recursion(int n){
    if(n <= 2){
        fibo_recursion_count++;
        return 1;
    }
    else
        return fibo_recursion(n - 1) + fibo_recursion(n - 2);
}

int main(void)
{
    int n;
    scanf("%d", &n);

    fibo_dp(n);
    fibo_recursion(n);

    printf("%d %d", fibo_recursion_count, fibo_dp_count);
    return 0;
}
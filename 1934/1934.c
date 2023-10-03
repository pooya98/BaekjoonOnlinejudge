#include <stdio.h>

int get_GCD(int a, int b){
    int temp;
    while(b){
        temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

int get_LCM(int a, int b, int gcd){
    int sum = 1;

    sum *= gcd;
    sum *= (a / gcd);
    sum *= (b / gcd);

    return sum;
}

int main(void)
{
    int T;
    int a, b;
    int gcd, lcm;

    scanf("%d", &T);

    for(int i = 0; i < T; i++)
    {
        scanf("%d %d", &a, &b);

        gcd = get_GCD(a, b);
        lcm = get_LCM(a, b, gcd);

        printf("%d\n", lcm);
    }

    return 0;
}
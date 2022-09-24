#include <stdio.h>
#include <math.h>



int main(void)
{
    unsigned long long N; 
    unsigned long long L, W, H;

    scanf("%llu", &N);
    scanf("%llu %llu %llu", &L, &W, &H);

    double result = (double)(L * W * H) / N;

    result = pow(result, 1.0/3.0);
    

    printf("%f", result);
    return 0;
}
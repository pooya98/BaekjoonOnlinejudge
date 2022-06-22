#include <stdio.h>

int arr[1000001] = {0};
long long count_non_sqr = 0;

int main(void)
{
    long long min, max;

    scanf("%lld %lld", &min, &max);

    count_non_sqr = max - min + 1;

    for(long long i = 2; i <= 1001000 ;i++){
        long long step = i * i;
        long long start = min / step + 1;
        if (min % step == 0){
            start -= 1;
        }

        for(long long j = start; (j * step) <= max ; j += 1){
            arr[(j * step) - min] = 1;
        }
    }

    for(int i = 0; i <= 1000000; i++){
        count_non_sqr -= arr[i];
    }

    printf("%lld", count_non_sqr);

    return 0;
}
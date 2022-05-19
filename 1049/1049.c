#include <stdio.h>

int main(void)
{
    int N, M;
    int min = 10000000;
    int package_price, single_price;
    int min_package_price = 10000, min_single_price = 10000;
    int package_count;
    int single_count;

    scanf("%d %d", &N, &M);

    for(int i = 0; i < M; i++){
        scanf("%d %d", &package_price, &single_price);

        if(min_package_price > package_price)
            min_package_price = package_price;

        if(min_single_price > single_price)
            min_single_price = single_price;
    }

    package_count = N / 6;
    single_count = N % 6;

    if(((package_count + 1) * min_package_price) < min){
        min = ((package_count + 1) * min_package_price);
    }

    if((package_count * min_package_price + single_count * min_single_price) < min){
        min = (package_count * min_package_price + single_count * min_single_price);
    }

    if(N * min_single_price < min){
        min = N * min_single_price;
    }

    printf("%d", min);
    return 0;
}
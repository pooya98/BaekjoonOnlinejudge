#include <stdio.h>
#define MAX_TREES_NUM 1000000 + 1

int arr[MAX_TREES_NUM];
int N, M;
long long max_height = 0;

long long get_remain(long long height){
    long long return_value = 0;

    for(int i = 0; i < N; i++)
        if(arr[i] > height)
            return_value += (arr[i] - height);

    return return_value;
}

int main(void)
{
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    long long start = 1;
    long long end = 4000000000;
    long long mid;
    long long remain;

    while(start <= end){
        mid = (start + end) / 2;

        remain = get_remain(mid);

        if(remain >= M){
            if(max_height < mid)
                max_height = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    printf("%lld", max_height);

    return 0;
}
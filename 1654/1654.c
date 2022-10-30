#include <stdio.h>

#define MAX_K 10000 + 1

long long LAN_line[MAX_K];
long long max_piece_len = 0;
long long result = 0;

int K, N;

long long get_piece_num(long long divisor){
    long long return_value = 0;

    for(int i = 0; i < K; i++)
        return_value += (LAN_line[i] / divisor);

    return return_value;
}

int main(void)
{
    scanf("%d %d", &K, &N);

    for(int i = 0; i < K; i++){
        scanf("%lld", &LAN_line[i]);

        if(max_piece_len < LAN_line[i])
            max_piece_len = LAN_line[i];
    }

    long long left = 1;
    long long right = max_piece_len * 2;
    long long mid;
    long long piece_num;

    while(left <= right){
        mid = (left + right) / 2;

        piece_num = get_piece_num(mid);


        if(piece_num < N)
            right = mid - 1;
        else{
            if(result < mid)
                result = mid;
            left = mid + 1;
        }
    }

    printf("%lld", result);
    
    return 0;
}
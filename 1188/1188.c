#include <stdio.h>

int N, M;
int cut_count = 0;

void distribute_sausages(){

    if (M <= 1)
        return;

    if (N >= M){
        N = N % M;
    }

    if (N != 0){
        int people_per_sausage;

        people_per_sausage = M / N;

        cut_count += (people_per_sausage * N);

        M -= (people_per_sausage * N);

        if(M % N == 0){
            cut_count -= N;
            N = 0;
        }

        distribute_sausages();
    }
}

int main(void)
{
    scanf("%d %d", &N, &M);

    distribute_sausages();

    printf("%d", cut_count);
        
    return 0;
}
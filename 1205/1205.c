#include <stdio.h>

long long point[50];

void quick_sort(int left, int right){
    int pivot = left;
    int i = left;
    int j = right;

    if(left < right){
        while(i < j){
            while((point[i] >= point[pivot]) && (i < right))
                i++;

            while((point[j] <= point[pivot]) && (j > left))
                j--;

            if(i < j){
                long long temp = point[i];
                point[i] = point[j];
                point[j] = temp;
            }
        }

        long long temp = point[pivot];
        point[pivot] = point[j];
        point[j] = temp;

        quick_sort(left, j - 1);
        quick_sort(j + 1, right);
    }
}

int main(void)
{
    int N, P;
    long long new_point;
    int new_rank = 1;

    scanf("%d %lld %d", &N, &new_point, &P);

    for(int i = 0; i < P; i++)
        point[i] = 0;

    for(int i = 0; i < N; i++)
        scanf("%lld", &point[i]);

    quick_sort(0, N - 1);

    for(int i = 0; i < N; i++){
        if (i > (P - 1)){
            new_rank = -1;
            break;
        }
        if(point[i] > new_point)
            new_rank++;
        else if(point[i] == new_point)
            continue;
        else{
            break;
        }
    }

    if((point[P - 1] >= new_point) && N != 0)
        new_rank = -1;

    printf("%d\n", new_rank);
    return 0;
}
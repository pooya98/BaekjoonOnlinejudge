#include <stdio.h>

#define MAX_ARRAY_SIZE 500000 + 1

int arr[MAX_ARRAY_SIZE];
int temp_arr[MAX_ARRAY_SIZE];

int N, K;
int register_count = 0;
int result = -1;

void merge_sort(int start, int end){
    if(start >= end)
        return;

    int mid = (start + end) / 2;

    merge_sort(start, mid);
    merge_sort(mid + 1, end);

    int i = start;
    int j = mid + 1;
    int temp_pnr = start - 1;

    while((i <= mid) && (j <= end)){
        if(arr[i] <= arr[j])
            temp_arr[++temp_pnr] = arr[i++];
        else
            temp_arr[++temp_pnr] = arr[j++];
    }

    while(i <= mid)
        temp_arr[++temp_pnr] = arr[i++];
    
    while(j <= end)
        temp_arr[++temp_pnr] = arr[j++];

    for(int k = start; k <= end; k++){
        arr[k] = temp_arr[k];
        register_count++;
        if(register_count == K)
            result = arr[k];
    }
}

int main(void)
{
    scanf("%d %d", &N, &K);

    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    merge_sort(0, N - 1);

    if(result == -1)
        printf("-1");
    else
        printf("%d", result);
        
    return 0;
}
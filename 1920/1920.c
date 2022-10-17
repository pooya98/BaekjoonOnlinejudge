#include <stdio.h>

#define MAX_NUM 100000 + 1

int arr[MAX_NUM];
int temp_arr[MAX_NUM];

void merge_sort(int start, int end){
    if(start >= end)
        return;

    int mid = (start + end) / 2;

    merge_sort(start, mid);
    merge_sort(mid + 1, end);

    int i = start;
    int j = mid + 1;
    int temp_index = start - 1;

    while((i <= mid) && (j <= end)){
        if(arr[i] <= arr[j])
            temp_arr[++temp_index] = arr[i++];
        else
            temp_arr[++temp_index] = arr[j++];
    }

    while(i <= mid)
        temp_arr[++temp_index] = arr[i++];
    
    while(j <= end)
        temp_arr[++temp_index] = arr[j++];

    for(int i = start; i <= end; i++)
        arr[i] = temp_arr[i];
}

int binary_search(int start, int end, int target){
    
    int left = start;
    int right = end;
    int mid;

    while(left <= right){
        mid = (left + right) / 2;

        if(target == arr[mid])
            return 1;
        else if(arr[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    return 0;
}

int main(void)
{
    int N, M;
    int target;
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    merge_sort(0, N - 1);
    
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%d", &target);
        printf("%d\n",binary_search(0, N - 1, target));
    }
    return 0;
}
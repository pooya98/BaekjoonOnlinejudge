#include <stdio.h>

int arr[500001];
int temp[500001];

int N, M;
int input;

void merge_sort(int start, int end){
    if(start >= end)
        return;

    int mid = (start + end) / 2;

    merge_sort(start, mid);
    merge_sort(mid + 1, end);

    int left = start;
    int right= mid + 1;
    int pointer = start - 1;

    while((left <= mid) && (right <= end)){
        if(arr[left] <= arr[right])
            temp[++pointer] = arr[left++];
        else
            temp[++pointer] = arr[right++];
    }

    while(left <= mid)
        temp[++pointer] = arr[left++];

    while(right <= end)
        temp[++pointer] = arr[right++];

    for(int i = start; i <= end; i++)
        arr[i] = temp[i];
}   

int search_value(int value){
    int left = 1;
    int right = N;
    int mid;

    while(left <= right){
        mid = (left + right) / 2;

        if(arr[mid] == value)
            return 1;

        if(arr[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return 0;
}

int main(void)
{
    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);

    merge_sort(1, N);
    
    scanf("%d", &M);

    for(int i = 1; i <= M; i++){
        scanf("%d", &input);
        printf("%d ", search_value(input));
    }
    
    return 0;
}
#include <stdio.h>

int arr[1001];
int temp[1001];
int waiting_time_sum = 0;
int withdrawal_time_sum = 0;

void merge_sort(int start, int end){
    if(start >= end)
        return;
    
    int mid = (start + end) / 2;

    merge_sort(start, mid);
    merge_sort(mid + 1, end);

    int left = start;
    int right = mid + 1;
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

int main(void)
{
    int N;
    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);

    merge_sort(1, N);

    int cur_person_time;

    for(int i = 1; i <= N; i++){
        cur_person_time = arr[i];
        withdrawal_time_sum += arr[i];

        waiting_time_sum += (N - i) * cur_person_time;
    }

    printf("%d", withdrawal_time_sum + waiting_time_sum);

    return 0;
}
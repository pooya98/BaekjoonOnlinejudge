#include <stdio.h>

#define MAX 500000

typedef struct {
    int value;
    int count;
}count_node;

int arr[MAX];
int temp_arr[MAX];
int target[MAX];
count_node count_list[MAX];
int count_list_top = -1;

void merge_sort(int start, int end){
    if(start >= end)
        return;
    
    int mid = (start + end) / 2;

    merge_sort(start, mid);
    merge_sort(mid + 1, end);

    int i = start;
    int j = mid + 1;
    int point = start - 1;

    while((i <= mid) && (j <= end)){
        if(arr[i] <= arr[j])
            temp_arr[++point] = arr[i++];
        else
            temp_arr[++point] = arr[j++];
    }

    while(i <= mid)
        temp_arr[++point] = arr[i++];
        
    while(j <= end)
        temp_arr[++point] = arr[j++];

    for(int i = start; i <= end; i++)
        arr[i] = temp_arr[i];
}

int binary_search(int start, int end, int target){
    int left = start;
    int right = end;
    int mid;

    while(left <= right){

        mid = (left + right) / 2;

        if(count_list[mid].value == target)
            return count_list[mid].count;

        if(count_list[mid].value < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main(void)
{
    int N, M;
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
        count_list[i].count = 0;

    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    merge_sort(0, N - 1);

    int prev_num = 10000001;

    for(int i = 0; i < N; i++){
        if(arr[i] != prev_num){
            count_list[++count_list_top].value = arr[i];
            (count_list[count_list_top]).count++;
            prev_num = arr[i];
        }
        else{
            count_list[count_list_top].count++;
        }
    }

    scanf("%d", &M);

    for(int i = 0; i < M; i++){
        scanf("%d", &target[i]);

        int result = binary_search(0, count_list_top, target[i]);

        if(result == -1)
            printf("0 ");
        else
            printf("%d ", result);
    }

    return 0;
}
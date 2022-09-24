#include <stdio.h>

int N;
int original_arr[1000000];    
int arr_to_sort[1000000];
int temp_arr[1000000];
int final_arr[1000000];
int final_index = -1;

void MergeSort(int start, int end)
{
    int mid;

    if(start < end) {
        mid = (start + end) / 2;

        MergeSort(start, mid);
        MergeSort(mid + 1, end);

        int i = start;
        int j = mid + 1;
        int temp_index = start;

        while(i <= mid && j <= end) {
            if(arr_to_sort[i] <= arr_to_sort[j])
                temp_arr[temp_index++] = arr_to_sort[i++];
            else
                temp_arr[temp_index++] = arr_to_sort[j++];
        }

        while(i <= mid)
            temp_arr[temp_index++] = arr_to_sort[i++];
        
        while(j <= end)
            temp_arr[temp_index++] = arr_to_sort[j++];

        for(int i = start; i <= end; i++)
            arr_to_sort[i] = temp_arr[i];
    }
}

void removeDuplicate(int start, int end)
{
    final_arr[++final_index] = arr_to_sort[start];
    
    for(int i = start + 1; i <= end; i++){
        if(final_arr[final_index] != arr_to_sort[i]){
            final_arr[++final_index] = arr_to_sort[i];
        }
    }
}

int searchData(int target){
    int start = 0;
    int end = final_index;
    int mid;

    while(start <= end){
        mid = (start + end) / 2;

        if(final_arr[mid] == target)
            return mid;
        else if(final_arr[mid] > target){
            end = mid - 1;
            continue;
        }
        else{
            start = mid + 1;
            continue;
        }
    }
    return -1;
}

int main(void)
{
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d", &original_arr[i]);
        arr_to_sort[i] = original_arr[i];
    }

    MergeSort(0, N - 1);
    removeDuplicate(0, N - 1);

    for(int i = 0; i < N; i++){
        printf("%d ", searchData(original_arr[i]));
    }

    return 0;
}
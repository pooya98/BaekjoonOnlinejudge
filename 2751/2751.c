#include <stdio.h>

int temp_arr[1000000];

// Merge-sort used
void sort_array(int arr[], int start, int end)
{
    int mid;

    if(start < end) {
        mid = (start + end) / 2;

        sort_array(arr, start, mid);
        sort_array(arr, mid + 1, end);

        int i = start;
        int j = mid + 1;
        int temp_index = start;

        while(i <= mid && j <= end) {
            if(arr[i] <= arr[j])
                temp_arr[temp_index++] = arr[i++];
            else
                temp_arr[temp_index++] = arr[j++];
        }
        while(i <= mid)
            temp_arr[temp_index++] = arr[i++];
        
        while(j <= end)
            temp_arr[temp_index++] = arr[j++];

        for(int k = start; k <= end; k++){
            arr[k] = temp_arr[k];
        }
    }
}

int main(void)
{
    int N;
    int arr[1000000];

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    sort_array(arr, 0, N - 1);

    for(int i = 0; i < N; i++)
        printf("%d\n", arr[i]);

    return 0;
}
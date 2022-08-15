#include <stdio.h>

void quickSort(int arr[], int start, int end){
    int pivot = start;
    int left = start;
    int right = end;

    if(start < end){
        while(left <= right){
            while((arr[left] <= arr[pivot]) && (left <= end))
                left++;

            while((arr[right] > arr[pivot]) && (right > start))
                right--;

            if(left < right){
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
            }
        }

        int temp = arr[pivot];
        arr[pivot] = arr[right];
        arr[right] = temp;

        quickSort(arr, start, right - 1);
        quickSort(arr, right + 1, end);
    }
}

int main(void)
{
    int N;
    int k;
    int arr[1000];

    scanf("%d %d", &N, &k);

    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, N - 1);

    printf("%d", arr[N - 1 - k + 1]);

    return 0;
}
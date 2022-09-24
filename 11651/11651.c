#include <stdio.h>

int temp_x[100000];
int temp_y[100000];

void MergeSort(int arr_x[], int arr_y[], int start, int end)
{
    int mid;

    if(start < end) {
        mid = (start + end) / 2;

        MergeSort(arr_x, arr_y, start, mid);
        MergeSort(arr_x, arr_y, mid + 1, end);

        int i = start;
        int j = mid + 1;
        int temp_index = start;

        while(i <= mid && j <= end) {
            if((arr_y[i] < arr_y[j]) || ((arr_y[i] == arr_y[j]) && (arr_x[i] < arr_x[j]))){
                temp_x[temp_index] = arr_x[i];
                temp_y[temp_index++] = arr_y[i++];
            }
            else{
                temp_x[temp_index] = arr_x[j];
                temp_y[temp_index++] = arr_y[j++];
            }
        }
        while(i <= mid){
            temp_x[temp_index] = arr_x[i];
            temp_y[temp_index++] = arr_y[i++];
        }
        
        while(j <= end){
            temp_x[temp_index] = arr_x[j];
            temp_y[temp_index++] = arr_y[j++];
        }

        for(int k = start; k <= end; k++){
            arr_x[k] = temp_x[k];
            arr_y[k] = temp_y[k];
        }
    }
}

int main(void)
{
    int N;
    int arr_x[100000];
    int arr_y[100000];

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
        scanf("%d %d", &arr_x[i], &arr_y[i]);

    MergeSort(arr_x, arr_y, 0, N - 1);

    for(int i = 0; i < N; i++){
        printf("%d %d\n", arr_x[i], arr_y[i]);
    }
    return 0;
}
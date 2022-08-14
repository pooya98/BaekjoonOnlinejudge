#include <stdio.h>

// Selection-sort used
void sort_array(int arr[], int start, int end)
{
    int min_index;
    int min_value;

    for(int i = start; i <= end; i++){
        min_index = i;
        min_value = arr[i];

        for(int j = i + 1; j <= end; j++){
            if(min_value > arr[j]){
                min_index = j;
                min_value = arr[j];
            }
        }

        int temp_value = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp_value;
    }
}

int main(void)
{
    int N;
    int arr[1000];

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    sort_array(arr, 0, N - 1);

    for(int i = 0; i < N; i++)
        printf("%d\n", arr[i]);
    return 0;
}
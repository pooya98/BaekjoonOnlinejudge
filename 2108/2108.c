#include <stdio.h>

int temp_arr[500000];

void mergeSort(int arr[], int start, int end)
{
    int mid;

    if(start < end) {
        mid = (start + end) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

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
    int arr[500000];
    
    int sum = 0;
    long double arithmetic_mean;
    int median;
    int mode;
    int range;

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    mergeSort(arr, 0, N - 1);

    arithmetic_mean = (double)sum / N;
    if(arithmetic_mean < 0.5 && arithmetic_mean >= -0.5)
        arithmetic_mean = 0.0;

    median =  arr[(N - 1) / 2];
    
    int max_count = 0;
    int cur_value = 0;
    int next_value = 0;
    int count = 0;

    int stack[500000];
    int top = -1;

    for(int i = 0; i < N; i++){
        cur_value = arr[i];
        count++;

        if(i == N - 1){
            if(max_count < count){
                max_count = count;
                top = -1;
                stack[++top] = cur_value;
            }
            else if(max_count == count){
                stack[++top] = cur_value;
            }
        }
        else{
            next_value = arr[i + 1];

            if(cur_value != next_value){
                if(max_count < count){
                    max_count = count;
                    top = -1;
                    stack[++top] = cur_value;
                }
                else if(max_count == count){
                    stack[++top] = cur_value;
                }
                count = 0;
            }
        }
    }


    if(top > 0){
        mode = stack[1];
    }
    else{
        mode = stack[0];
    }

    range = arr[N - 1] - arr[0];

    printf("%.0Lf\n", arithmetic_mean);
    printf("%d\n", median);
    printf("%d\n", mode);
    printf("%d\n", range);

    return 0;
}
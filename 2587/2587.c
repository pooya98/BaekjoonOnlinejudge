#include <stdio.h>

int main(void)
{
    int arr[5];
    int sum = 0;
    int average;
    int mid_value;

    for(int i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    for(int i = 0; i < 5; i++){
        int min = arr[i];
        int min_index = i;

        for(int j = i + 1; j < 5; j++)
            if(min > arr[j])
                min_index = j;

        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }

    average = sum / 5;
    mid_value = arr[2];

    printf("%d\n%d", average, mid_value);
    
    return 0;
}
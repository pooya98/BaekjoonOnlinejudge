#include <stdio.h>
#include <string.h>

void SelectionSort(char arr[], int start, int end){
    char temp;
    int max_index;

    for(int i = start; i <= end; i++){
        temp = arr[i];
        max_index = i;

        for(int j = i; j <= end; j++){
            if (arr[j] > arr[max_index]){
                max_index = j;
            }
        }

        arr[i] = arr[max_index];
        arr[max_index] = temp;
    }
}

int main(void)
{
    char N[11];

    scanf("%s", N);

    SelectionSort(N, 0, strlen(N) - 1);

    printf("%s\n", N);
}
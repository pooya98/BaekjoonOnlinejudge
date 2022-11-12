#include <stdio.h>

int A[200001];
int temp[200001];
int A_minus_B = 0;
int B_minus_A = 0;

void merge_sort(int start, int end){
    if (start >= end)
        return;

    int mid = (start + end) / 2;

    merge_sort(start, mid);
    merge_sort(mid + 1, end);

    int left = start;
    int right = mid + 1;
    int pointer = start - 1;

    while((left <= mid) && (right <= end)){
        if(A[left] <= A[right])
            temp[++pointer] = A[left++];
        else
            temp[++pointer] = A[right++];
    }

    while(left <= mid)
        temp[++pointer] = A[left++];

    while(right <= end)
        temp[++pointer] = A[right++];
    
    for(int i = start; i <= end; i++)
        A[i] = temp[i];
}

int search(int value, int start, int end){
    int left = start;
    int right = end;
    int mid;

    while(left <= right){
        mid = (left + right) / 2;

        if(A[mid] == value)
            return mid;
        
        if(A[mid] < value)
            left = mid + 1;
        else    
            right = mid - 1;
    }

    return -1;
}

int main(void)
{
    int A_num, B_num;
    int input;

    
    scanf("%d %d", &A_num, &B_num);

    for(int i = 0; i < A_num; i++)
        scanf("%d", &A[i]);

    A_minus_B = A_num;
    merge_sort(0, A_num - 1);

    for(int j = 0; j < B_num; j++){
        scanf("%d", &input);

        if(search(input, 0, A_num - 1) >= 0)
            A_minus_B--;
        else
            B_minus_A++;
    }

    printf("%d", A_minus_B + B_minus_A);
    return 0;
}
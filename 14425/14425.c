#include <stdio.h>
#include <string.h>

int N, M;

char S[10001][501];
char temp[10001][501];

char input[501];
int count = 0;

void merge_sort(int start, int end){
    if(start >= end)
        return;

    int mid = (start + end) / 2;

    merge_sort(start, mid);
    merge_sort(mid + 1, end);

    int left = start;
    int right = mid + 1;
    int pointer = start - 1;

    while((left <= mid) && (right <= end)){
        if(strcmp(S[left], S[right]) <= 0)
            strcpy(temp[++pointer], S[left++]);
        else
            strcpy(temp[++pointer], S[right++]);
    }

    while(left <= mid)
        strcpy(temp[++pointer], S[left++]);

    while(right <= end)
        strcpy(temp[++pointer], S[right++]);

    for(int i = start; i <= end; i++)
        strcpy(S[i], temp[i]);
}

int search(char target[]){
    int left = 1;
    int right = N;
    int mid;

    while(left <= right){
        mid = (left + right) / 2;

        if(!strcmp(S[mid], target))
            return 1;

        if(strcmp(S[mid], target) < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return 0;
}

int main(void)
{
    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++)
        scanf("%s", S[i]);

    merge_sort(1, N);

    for(int i = 1; i <= M; i++){
        scanf("%s", input);

        if(search(input))
            count++;
    }

    printf("%d", count);

    return 0;
}
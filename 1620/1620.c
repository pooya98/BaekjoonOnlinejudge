#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int N, M;

char pokemon_list[100001][21];
int index_list[100001];
int temp_list[100001];
char input[100];

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
        if(strcmp(pokemon_list[index_list[left]], pokemon_list[index_list[right]]) <= 0)
            temp_list[++pointer] = index_list[left++];
        else
            temp_list[++pointer] = index_list[right++];
    }

    while(left <= mid)
        temp_list[++pointer] = index_list[left++];

    while(right <= end)
        temp_list[++pointer] = index_list[right++];

    for(int i = start; i <= end; i++)
        index_list[i] = temp_list[i];
}

int search(char target[]){
    int left = 1;
    int right = N;
    int mid;

    while(left <= right){
        mid = (left + right) / 2;

        if(strcmp(pokemon_list[index_list[mid]], target) == 0)
            return index_list[mid];

        if(strcmp(pokemon_list[index_list[mid]], target) < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return 0;
}

int main(void)
{
    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++){
        scanf("%s", pokemon_list[i]);
        index_list[i] = i;
    }

    merge_sort(1, N);
    
    for(int i = 1; i <= M; i++){
        scanf("%s", input);

        int flag = 0;
        int input_length = strlen(input);

        for(int j = 0; j < input_length; j++)
            if(isdigit(input[j]) == 0){
                flag = 1;
                break;
            }

        if(flag == 0)
            printf("%s\n", pokemon_list[atoi(input)]);
        else
            printf("%d\n", search(input));
    }

    return 0;
}
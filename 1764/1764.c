#include <stdio.h>
#include <string.h>

int N, M;
char never_heard[500001][21];
int never_heard_index_list[500001];
char never_heard_and_seen[500001][21];
int never_heard_and_seen_index_list[500001];
int temp[500001];
int nhas_count = 0;
char never_seen[21];

void nh_merge_sort(int start, int end){
    if(start >= end)
        return;

    int mid = (start + end) / 2;

    nh_merge_sort(start, mid);
    nh_merge_sort(mid + 1, end);

    int left = start;
    int right = mid + 1;
    int pointer = start - 1;

    while((left <= mid) && (right <= end)){
        if(strcmp(never_heard[never_heard_index_list[left]], never_heard[never_heard_index_list[right]]) <= 0)
            temp[++pointer] = never_heard_index_list[left++];
        else
            temp[++pointer] = never_heard_index_list[right++];
    }

    while(left <= mid)
        temp[++pointer] = never_heard_index_list[left++];

    while(right <= end)
        temp[++pointer] = never_heard_index_list[right++];

    for(int i = start; i <= end; i++)
        never_heard_index_list[i] = temp[i];
}

void nhas_merge_sort(int start, int end){
        if(start >= end)
        return;

    int mid = (start + end) / 2;

    nhas_merge_sort(start, mid);
    nhas_merge_sort(mid + 1, end);

    int left = start;
    int right = mid + 1;
    int pointer = start - 1;

    while((left <= mid) && (right <= end)){
        if(strcmp(never_heard_and_seen[never_heard_and_seen_index_list[left]], never_heard_and_seen[never_heard_and_seen_index_list[right]]) <= 0)
            temp[++pointer] = never_heard_and_seen_index_list[left++];
        else
            temp[++pointer] = never_heard_and_seen_index_list[right++];
    }

    while(left <= mid)
        temp[++pointer] = never_heard_and_seen_index_list[left++];

    while(right <= end)
        temp[++pointer] = never_heard_and_seen_index_list[right++];

    for(int i = start; i <= end; i++)
        never_heard_and_seen_index_list[i] = temp[i];
}

int search(char target[]){
    int left = 1;
    int right = N;
    int mid;

    while(left <= right){
        mid = (left + right) / 2;

        if(strcmp(never_heard[never_heard_index_list[mid]], target) == 0)
            return never_heard_index_list[mid];

        if(strcmp(never_heard[never_heard_index_list[mid]], target) < 0)
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
        scanf("%s", never_heard[i]);
        never_heard_index_list[i] = i;
    }

    nh_merge_sort(1, N);

    for(int i = 1; i <= M; i++){
        scanf("%s", never_seen);

        if(search(never_seen)){
            strcpy(never_heard_and_seen[++nhas_count], never_seen);
            never_heard_and_seen_index_list[nhas_count] = nhas_count;
        }
    }

    nhas_merge_sort(1, nhas_count);

    printf("%d\n", nhas_count);
    for(int i = 1; i <= nhas_count; i++)
        printf("%s\n", never_heard_and_seen[never_heard_and_seen_index_list[i]]);

    return 0;
}
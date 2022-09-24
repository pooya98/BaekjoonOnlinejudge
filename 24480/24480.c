#include <stdio.h>
#include <stdlib.h>

#define YES 1
#define NO 0

int visit_count = 1;

int* adj_list[100001];
int visited[100001] = {NO};
int visit_order[100001] = {0};
int adj_count[100001] = {0};
int last_adj_index[100001] = {0};

int temp_list[100001];

void dfs(int start_vertex){
    
    visited[start_vertex] = YES;
    visit_order[start_vertex] = visit_count++;

    int* pointer = adj_list[start_vertex];

    for(int i = 0; i < adj_count[start_vertex]; i++)
        if(visited[pointer[i]] == NO)
            dfs(pointer[i]);
}

void mergeSort(int number[], int first, int last){
    if(first < last){
        int left = first;
        int right = last;
        int mid = (left + right) / 2;

        mergeSort(number, left, mid);
        mergeSort(number, mid + 1, right);

        int i = left;
        int j = mid + 1;
        int temp_index = left;

        while(i <= mid && j <= right){
            if(number[i] >= number[j])
                temp_list[temp_index++] = number[i++];
            else
                temp_list[temp_index++] = number[j++];
        }

        while(i <= mid)
            temp_list[temp_index++] = number[i++];

        while(j <= right)
            temp_list[temp_index++] = number[j++];

        for(int k = left; k <= right; k++)
            number[k] = temp_list[k];
    }
}

int main(void)
{
    int N, M, R;
    int v1, v2;
    
    scanf("%d %d %d", &N, &M, &R);

    for(int i = 0; i < M; i++){
        scanf("%d %d", &v1, &v2);

        adj_count[v1]++;

        if(adj_count[v1] == 1)
            adj_list[v1] = (int*)malloc(sizeof(int) * (adj_count[v1]));
        else
            adj_list[v1] = (int*)realloc(adj_list[v1], sizeof(int) * (adj_count[v1]));
        
        adj_list[v1][adj_count[v1] - 1] = v2;


        adj_count[v2]++;

        if(adj_count[v2] == 1)
            adj_list[v2] = (int*)malloc(sizeof(int) * (adj_count[v2]));
        else
            adj_list[v2] = (int*)realloc(adj_list[v2], sizeof(int) * (adj_count[v2]));
        
        adj_list[v2][adj_count[v2] - 1] = v1;
    }

    for(int i = 1; i <= N; i++)
        if(adj_count[i] > 1)
            mergeSort(adj_list[i], 0, adj_count[i] - 1);

    dfs(R);

    for(int i = 1; i <= N; i++)
        printf("%d\n", visit_order[i]);

    for(int i = 1; i <= N; i++)
        free(adj_list[i]);

    return 0;
}
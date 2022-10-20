#include <stdio.h>
#include <string.h>

#define NAME_MAX_LENGTH 20 + 1
#define MAX_USERS_NUM 200000 + 1
#define MAX_EDGES_NUM 100000 + 1

typedef struct _vertex{
    char name[NAME_MAX_LENGTH];
}vertex;

typedef struct _edge{
    int v1;
    int v2;
}edge;

vertex vertex_list[MAX_USERS_NUM];
int vertex_list_index = 0;

edge edge_list[MAX_EDGES_NUM];
int edge_list_index = 0;

char input[MAX_USERS_NUM][NAME_MAX_LENGTH];
char temp[MAX_USERS_NUM][NAME_MAX_LENGTH];
char copy[MAX_USERS_NUM][NAME_MAX_LENGTH];

int parent[MAX_USERS_NUM];
int team_num[MAX_USERS_NUM];

void merge_sort(int start, int end){
    if (start >= end)
        return;

    int mid = (start + end) / 2;

    merge_sort(start, mid);
    merge_sort(mid + 1, end);

    int i = start;
    int j = mid + 1;
    int temp_pointer = start - 1;

    while((i <= mid) && (j <= end)){
        if(strcmp(input[i], input[j]) <= 0)
            strcpy(temp[++temp_pointer], input[i++]);
        else
            strcpy(temp[++temp_pointer], input[j++]);
    }

    while(i <= mid) 
        strcpy(temp[++temp_pointer], input[i++]);
    
    while(j <= end)
        strcpy(temp[++temp_pointer], input[j++]);

    for(int k = start; k <= end; k++)
        strcpy(input[k], temp[k]);
}

void sort_input(int start, int end){
    merge_sort(start, end);
}

int find_index(char target[]){
    int left = 0;
    int right = vertex_list_index;
    int mid;

    while(left <= right){
        mid = (left + right) / 2;

        if(strcmp(vertex_list[mid].name, target) == 0)
            return mid;

        if(strcmp(vertex_list[mid].name, target) < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int find_parent(int vertex){
    if(vertex != parent[vertex])
        parent[vertex] = find_parent(parent[vertex]);

    return parent[vertex];
}

int main(void){
    int T;
    int F;
    char name1[NAME_MAX_LENGTH];
    char name2[NAME_MAX_LENGTH];
    char prev_string[NAME_MAX_LENGTH];

    scanf("%d", &T);

    for(int t = 0; t < T; t++){
        scanf("%d", &F);

        for(int i = 0, end = 2 * F; i < end; i++){
            scanf("%s", &input[i][0]);
            strcpy(copy[i], input[i]);
        }

        sort_input(0, F * 2 - 1);
        
        strcpy(prev_string, "----");
        for(int i = 0; i < 2 * F; i++){
            if(strcmp(prev_string, input[i]) != 0){
                strcpy(vertex_list[++vertex_list_index].name, input[i]);
                strcpy(prev_string, input[i]);
            }
        }

        for(int i = 1; i <= vertex_list_index; i++){
            parent[i] = i;
            team_num[i] = 1;
        }

        for(int i = 0; i < 2 * F; i = i + 2){
            strcpy(name1, copy[i]);
            strcpy(name2, copy[i + 1]);

            int v1 = find_index(name1);
            int v2 = find_index(name2);

            int v1_parent = find_parent(v1);
            int v2_parent = find_parent(v2);

            if(v1_parent != v2_parent){
                if(v1_parent < v2_parent){
                    parent[v2_parent] = v1_parent;
                    team_num[v1_parent] += team_num[v2_parent];
                    team_num[v2_parent] = 0;
                    printf("%d\n", team_num[v1_parent]);
                }
                else{
                    parent[v1_parent] = v2_parent;
                    team_num[v2_parent] += team_num[v1_parent];
                    team_num[v1_parent] = 0;
                    printf("%d\n", team_num[v2_parent]);
                }
            }
            else{
                printf("%d\n", team_num[v1_parent]);
            }
        }
    }

    return 0;
}
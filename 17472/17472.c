#include <stdio.h>

#define SEA 0
#define LAND -1
#define N_MAX 10 + 1
#define M_MAX 10 + 1
#define MAX_QUEUE_SIZE 1000 + 1
#define MAX_EDGES_NUM 500000 + 1
#define MAX_ISLANDS_NUM 6 + 1

#define TRUE 1
#define FALSE 2

typedef struct _edge{
    int v1;
    int v2;
    int weight;
}edge;

int map[N_MAX][M_MAX];
int land_index = 0;

int queue_x[MAX_QUEUE_SIZE];
int queue_y[MAX_QUEUE_SIZE];
int front;
int rear;

int move_x[5] = {0, -1, 0, 1, 0};
int move_y[5] = {0, 0, 1, 0, -1};

int N, M;

int parent[MAX_ISLANDS_NUM];
edge edge_list[MAX_EDGES_NUM];
edge temp_edge_list[MAX_EDGES_NUM];
int edge_list_top = -1;

int sum_weight = 0;

void bfs(int start_x, int start_y, int index){
    int cur_x;
    int cur_y;
    int next_x;
    int next_y;

    front = 0;
    rear = -1;

    rear++;
    queue_x[rear] = start_x;
    queue_y[rear] = start_y;

    while(front <= rear){
        cur_x = queue_x[front];
        cur_y = queue_y[front];
        front++;

        map[cur_x][cur_y] = index;

        for(int i = 1; i <= 4; i++){
            next_x = cur_x + move_x[i];
            next_y = cur_y + move_y[i];

            if(((1 <= next_x) && (next_x <= N)) && ((1 <= next_y) && (next_y <= M))){
                if(map[next_x][next_y] == LAND){
                    rear++;
                    queue_x[rear] = next_x;
                    queue_y[rear] = next_y;
                }
            }
        }
    }
}

void find_edge(int x, int y){
    int weight;
    int cur_x;
    int cur_y;
    int start = map[x][y];
    int dest;

    for(int i = 1; i <= 4; i++){
        cur_x = x;
        cur_y = y;
        weight = 0;
        dest = start;

        while(1){
            cur_x += move_x[i];
            cur_y += move_y[i];

            if(((1 <= cur_x) && (cur_x <= N)) && ((1 <= cur_y) && (cur_y <= M))){
                if(map[cur_x][cur_y] == SEA)
                    weight++;
                else if(map[cur_x][cur_y] == start){
                    break;
                }
                else{
                    dest = map[cur_x][cur_y];
                    break;
                }
            }
            else
                break;
        }

        if(start == dest || weight < 2)
            continue;
        else{
            edge_list_top++;
            edge_list[edge_list_top].v1 = start;
            edge_list[edge_list_top].v2 = dest;
            edge_list[edge_list_top].weight = weight;
        }
    }
}

void merge_sort(int start, int end){
    if(start >= end)
        return;

    int mid = (start + end) / 2;

    merge_sort(start, mid);
    merge_sort(mid + 1, end);

    int i = start;
    int j = mid + 1;
    int temp_pointer = start - 1;

    while((i <= mid) && (j <= end)){
        if(edge_list[i].weight <= edge_list[j].weight)
            temp_edge_list[++temp_pointer] = edge_list[i++];
        else
            temp_edge_list[++temp_pointer] = edge_list[j++];
    }  

    while(i <= mid)
        temp_edge_list[++temp_pointer] = edge_list[i++];

    while(j <= end)
        temp_edge_list[++temp_pointer] = edge_list[j++];

    for(int k = start; k <= end; k++)
        edge_list[k] = temp_edge_list[k];
}

int find_parent(int vertex){
    if(vertex != parent[vertex])
        parent[vertex] = find_parent(parent[vertex]);

    return parent[vertex];
}

void sort_edge_list(int start, int end){
    merge_sort(start, end);
}

int main(void)
{
    int input;

    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            scanf("%d", &input);
            map[i][j] = -1 * input;
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(map[i][j] == LAND){
                land_index++;
                bfs(i, j, land_index);
            }
        }
    }

    for(int i = 1; i <= land_index; i++)
        parent[i] = i;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(map[i][j] > 0)
                find_edge(i, j);

    sort_edge_list(0, edge_list_top);

    for(int i = 0; i <= edge_list_top; i++){
        edge cur_edge = edge_list[i];

        int v1 = cur_edge.v1;
        int v2 = cur_edge.v2;
        int weight = cur_edge.weight;

        int v1_parent = find_parent(v1);
        int v2_parent = find_parent(v2);

        if(v1_parent != v2_parent){
            if(v1_parent < v2_parent)
                parent[v2_parent] = v1_parent;
            else
                parent[v1_parent] = v2_parent;

            sum_weight += weight;
        }
    }
    
    for(int i = 1; i <= land_index; i++)
        parent[i] = find_parent(i);

    int final_num = parent[1];
    int success_flag = TRUE;
    for(int i = 1; i <= land_index; i++)
        if(final_num != parent[i])
            success_flag = FALSE;

    if(success_flag == TRUE)
        printf("%d", sum_weight);
    else
        printf("-1");

    return 0;
}
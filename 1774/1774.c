#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000 + 1
#define MAX_EDGES 500000 + 1

typedef struct _point{
    int x;
    int y;
}point;

typedef struct _edge{
    int p1;
    int p2;
    double distance;
}edge;

point point_list[MAX_POINTS];
int parent[MAX_POINTS];
edge edge_list[MAX_EDGES];
int edge_list_top = -1;
edge temp_list[MAX_EDGES];
double sum_weight = 0.0;

void merge_sort(int start, int end){
    if(start >= end)
        return;

    int mid = (start + end) / 2;

    merge_sort(start, mid);
    merge_sort(mid + 1, end);

    int pointer1 = start;
    int pointer2 = mid + 1;
    int temp_list_pointer = start - 1;

    while((pointer1 <= mid) && (pointer2 <= end)){
        if(edge_list[pointer1].distance <= edge_list[pointer2].distance)
            temp_list[++temp_list_pointer] = edge_list[pointer1++];
        else
            temp_list[++temp_list_pointer] = edge_list[pointer2++];
    }

    while(pointer1 <= mid)
        temp_list[++temp_list_pointer] = edge_list[pointer1++];

    while(pointer2 <= end)
        temp_list[++temp_list_pointer] = edge_list[pointer2++];

    for(int i = start; i <= end; i++)
        edge_list[i] = temp_list[i];
}

void sort_edge_list(){
    merge_sort(0, edge_list_top);
}


int find_parent(int vertex){
    if(vertex != parent[vertex])
        parent[vertex] = find_parent(parent[vertex]);

    return parent[vertex];
}

int main(void)
{
    int N, M;

    for(int i = 0; i < MAX_POINTS; i++){
        parent[i] = i;
    }

    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++){
        scanf("%d %d", &point_list[i].x, &point_list[i].y);

        int cur_point_index = i;
        point cur_point = point_list[i];

        for(int j = 1; j < i; j++){
            int oppo_point_index = j;
            point oppo_point = point_list[j];

            double distance = sqrt(pow((cur_point.x - oppo_point.x), 2) + pow((cur_point.y - oppo_point.y), 2));

            edge temp_edge;
            temp_edge.p1 = cur_point_index;
            temp_edge.p2 = oppo_point_index;
            temp_edge.distance = distance;

            edge_list[++edge_list_top] = temp_edge;
        }
    }

    int v1, v2;
    int v1_parent, v2_parent;

    for(int i = 0; i < M; i++){
        scanf("%d %d", &v1, &v2);

        v1_parent = find_parent(v1);
        v2_parent = find_parent(v2);

        if(v1_parent != v2_parent){
            if(v1_parent < v2_parent)
                parent[v2_parent] = v1_parent;
            else
                parent[v1_parent] = v2_parent;
        }
    }

    sort_edge_list();

    for(int i = 0; i <= edge_list_top; i++){
        edge cur_edge = edge_list[i];

        int p1 = cur_edge.p1;
        int p2 = cur_edge.p2;
        double distance = cur_edge.distance;

        int p1_parent = find_parent(p1);
        int p2_parent = find_parent(p2);

        if(p1_parent != p2_parent){
            if(p1_parent < p2_parent)
                parent[p2_parent] = p1_parent;
            else
                parent[p1_parent] = p2_parent;

            sum_weight += distance;
        }
    }

    printf("%.2lf", sum_weight);

    
    return 0;
}
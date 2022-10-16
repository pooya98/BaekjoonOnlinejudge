#include <stdio.h>

#define MAX_EDGES 100000 + 1
#define MAX_VERTICES 10000 + 1


typedef struct _edge{
    int v1;
    int v2;
    int weight;
}edge;


edge edge_list[MAX_EDGES];
int edge_top = -1;

edge temp_edge_list[MAX_EDGES];
int parent[MAX_VERTICES];
long long sum_weight = 0;


void merge_sort(int start, int end){
    if(start >= end)
        return ;

    int mid = (start + end) / 2;

    merge_sort(start, mid);
    merge_sort(mid + 1, end);

    int p1 = start;
    int p2 = mid + 1;
    int temp_edge_list_p = start - 1;

    while((p1 <= mid) && (p2 <= end)){
        if(edge_list[p1].weight <= edge_list[p2].weight){
            temp_edge_list[++temp_edge_list_p] = edge_list[p1];
            p1++;
        }
        else{
            temp_edge_list[++temp_edge_list_p] = edge_list[p2];
            p2++;
        }
    }

    while((p1 <= mid)){
        temp_edge_list[++temp_edge_list_p] = edge_list[p1];
        p1++;
    }

    while((p2 <= end)){
        temp_edge_list[++temp_edge_list_p] = edge_list[p2];
        p2++;
    }

    for(int i = start; i <= end; i++)
        edge_list[i] = temp_edge_list[i];
}

void sort_edge_list(){
    merge_sort(0, edge_top);
}

int find_parent(int vertex){
    if(vertex != parent[vertex])
        parent[vertex] = find_parent(parent[vertex]);
    
    return parent[vertex];
}

int main(void)
{
    int V, E;
    int A, B, C;

    scanf("%d %d", &V, &E);

    for(int i = 1; i <= V; i++)
        parent[i] = i;

    for(int i = 0; i < E; i++){
        scanf("%d %d %d", &A, &B, &C);

        ++edge_top;
        edge_list[edge_top].v1 = A;
        edge_list[edge_top].v2 = B;
        edge_list[edge_top].weight = C;
    }

    sort_edge_list();

    for(int i = 0; i <= edge_top; i++){
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

            sum_weight += (long long)weight;
        }
    }

    printf("%lld", sum_weight);

    return 0;
}
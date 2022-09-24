#include <stdio.h>

int parent[500000];
int cycle_occurence = 0;

int find_parent(int x){
    if (x != parent[x])
        parent[x] = find_parent(parent[x]);

    return parent[x];
}

int main(void)
{
    int n, m;
    int v1, v2;
    int v1_parent, v2_parent;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        parent[i] = i;

    for(int i = 0; i < m; i++){
        scanf("%d %d", &v1, &v2);
        
        v1_parent = find_parent(v1);
        v2_parent = find_parent(v2);

        if(v1_parent == v2_parent){
            if(cycle_occurence == 0)
                cycle_occurence = i + 1;
        }
        else{
            if(v1_parent < v2_parent)
                parent[v2_parent] = v1_parent;
            else
                parent[v1_parent] = v2_parent;
        }
    }

    printf("%d", cycle_occurence);
    return 0;
}
#include <stdio.h>

#define UNION 0
#define FIND 1

int parent[1000001];

int n, m;

int find_parent(int x){
    if(x != parent[x])
        parent[x] = find_parent(parent[x]);

    return parent[x];
}

void union_parent(int a, int b){
    a = find_parent(a);
    b = find_parent(b);

    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main(void)
{
    scanf("%d %d", &n, &m);

    for(int i = 0 ; i <= n; i++)
        parent[i] = i;

    for(int i = 0; i < m; i++){
        int operation, a, b;

        scanf("%d %d %d", &operation, &a, &b);

        if(operation == UNION){
            union_parent(a, b);
        }
        else{
            int a_parent, b_parent;

            a_parent = find_parent(a);
            b_parent = find_parent(b);

            if(a_parent == b_parent)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}
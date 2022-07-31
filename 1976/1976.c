#include <stdio.h>

#define DISCONNECT 0
#define CONNECT 1

#define POSSIBLE 0
#define IMPOSSIBLE 1

int N, M;
int parent[201];

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
    scanf("%d", &N);
    scanf("%d", &M);

    for(int i = 1; i <= N; i++){
        parent[i] = i;
    }

    int connection;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            scanf("%d", &connection);

            if(connection == CONNECT){
                union_parent(i, j);
            }
        }
    }

    int city;
    int belong = 0;
    int flag = POSSIBLE;

    for(int i = 0; i < M; i++){
        scanf("%d", &city);

        if(belong == 0){
            belong = parent[city];
            continue;
        }
        else{
            if(parent[city] != belong)
                flag = IMPOSSIBLE;
        }
    }

    if(flag == POSSIBLE)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
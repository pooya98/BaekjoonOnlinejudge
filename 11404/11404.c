#include <stdio.h>

#define INF 987654321

int adj_matrix[101][101];

int main(void)
{
    int n, m;
    int v1, v2, weight;

    scanf("%d", &n);
    scanf("%d", &m);

    for(int i = 1; i <= 100; i++)
        for(int j = 1; j <= 100; j++)
            adj_matrix[i][j] = INF;

    for(int i = 1; i <= 100; i++)
        adj_matrix[i][i] = 0;

    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &v1, &v2, &weight);

        if(adj_matrix[v1][v2] > weight)
            adj_matrix[v1][v2] = weight;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(j == k)
                    continue;

                int new_distance = adj_matrix[j][i] + adj_matrix[i][k];

                if(new_distance < adj_matrix[j][k])
                    adj_matrix[j][k] = new_distance;
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(adj_matrix[i][j] == INF)
                printf("0 ");
            else
                printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 400 + 1
#define INF 200000000

int adj_matrix[MAX_VERTICES][MAX_VERTICES];



int main(void)
{
    int V, E;
    int v1, v2, weight;

    scanf("%d %d", &V, &E);

    for(int i = 1; i <= V; i++)
        for(int j = 1; j <= V; j++)
            adj_matrix[i][j] = INF;

    for(int i = 1; i <= V; i++)
        adj_matrix[i][i] = 0;

    for(int i = 0; i < E; i++){
        scanf("%d %d %d", &v1, &v2, &weight);

        adj_matrix[v1][v2] = -weight;
    }

    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            for(int k = 1; k <= V; k++){

                int new_distance = adj_matrix[j][i] + adj_matrix[i][k];

                if(new_distance < adj_matrix[j][k])
                    adj_matrix[j][k] = new_distance;
            }
        }
    }

    int max = INF * -1;

    for(int i = 1; i <= V; i++)
        if((adj_matrix[i][i] != 0) && (max < adj_matrix[i][i]))
            max = adj_matrix[i][i];

    max *= -1;

    if(max == INF)
        printf("-1");
    else
        printf("%d", max);
    
    return 0;
}
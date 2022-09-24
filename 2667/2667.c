#include <stdio.h>

int N;
int map[25][25];
int count = 0;

int count_list[1000];
int my_index = -1;

int total_count = 0;

int move_x[4] = {-1, 0, 1, 0};
int move_y[4] = {0, 1, 0, -1};

void dfs(int x, int y){
    if(((0 <= x) && (x < N)) && ((0 <= y) && (y < N))){
        if(map[x][y] == 1){
            count++;

            map[x][y] = 2;

            for(int i = 0; i < 4; i++){
                int next_x = x + move_x[i];
                int next_y = y + move_y[i];

                dfs(next_x, next_y);
            }
        }
    }
}

void sort_list(){
    int min_value;
    int min_index;

    for(int i = 0; i <= my_index; i++){
        min_value = count_list[i];
        min_index = i;

        for(int j = i + 1; j <= my_index; j++){
            if(min_value > count_list[j]){
                min_value = count_list[j];
                min_index = j;
            }
        }
        int temp = count_list[i];
        count_list[i] = min_value;
        count_list[min_index] = temp;
    }
}

int main(void)
{
    char input[26];

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%s", input);

        for(int j = 0; j < N; j++){
            map[i][j] = (int)(input[j]) - (int)'0';
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){

            count = 0;
            dfs(i, j);

            if(count != 0){
                total_count++;
                count_list[++my_index] = count;
            }
        }
    }

    printf("%d\n", total_count);

    sort_list();

    for(int i = 0; i <= my_index; i++)
        printf("%d\n", count_list[i]);
    
    return 0;
}
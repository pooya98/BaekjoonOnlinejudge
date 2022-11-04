#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_OF_PLAYERS 20 + 1

#define PICK 1
#define NOT_PICK 2

int N;
int team_size;
int synergy_table[MAX_NUM_OF_PLAYERS][MAX_NUM_OF_PLAYERS];
int pick_table[MAX_NUM_OF_PLAYERS];
int result = 2000000000;

int start_team[MAX_NUM_OF_PLAYERS];
int link_team[MAX_NUM_OF_PLAYERS];
int start_team_top;
int link_team_top;

int get_start_team_synergy(){
    int return_value = 0;
    start_team_top = 0;

    for(int i = 1; i <= N; i++)
        if(pick_table[i] == PICK)
            start_team[++start_team_top] = i;

    for(int i = 1; i <= start_team_top; i++)
        for(int j = 1; j <= start_team_top; j++)
            return_value += synergy_table[start_team[i]][start_team[j]];

    return return_value;
}

int get_link_team_synergy(){
    int return_value = 0;
    link_team_top = 0;

    for(int i = 1; i <= N; i++)
        if(pick_table[i] == NOT_PICK)
            link_team[++link_team_top] = i;

    for(int i = 1; i <= link_team_top; i++)
        for(int j = 1; j <= link_team_top; j++)
            return_value += synergy_table[link_team[i]][link_team[j]];

    return return_value;
}

void dfs(int last_pick, int depth){
    if(depth > team_size){
        int team_start_synergy = get_start_team_synergy();
        int team_link_synergy = get_link_team_synergy();
        int gap = abs(team_link_synergy - team_start_synergy);

        if(gap < result)    
            result = gap;

        return;
    }

    for(int i = last_pick + 1; i <= N; i++){
        if(pick_table[i] == NOT_PICK){
            pick_table[i] = PICK;
            dfs(i, depth + 1);
            pick_table[i] = NOT_PICK;
        }
    }
}

int main(void)
{
    scanf("%d", &N);
    team_size = N / 2;

    for(int i = 1; i <= N; i++)
        pick_table[i] = NOT_PICK;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            scanf("%d", &synergy_table[i][j]);

    dfs(0, 1);
    printf("%d", result);

    return 0;
}
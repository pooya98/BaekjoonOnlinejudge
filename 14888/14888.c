#include <stdio.h>

#define MAX_NUM_OF_INTEGERS 11 + 1
#define MAX_NUM_OF_OPERATORS 10 + 1

#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4

int N;
int arr_integers[MAX_NUM_OF_INTEGERS];
int arr_num_of_operators[5];
int arr_count_of_operators[5];

int min_result = 1000000001;
int max_result = -1000000001;

void dfs(int result, int depth){
    if(depth > (N - 1)){
        if(result > max_result)
            max_result = result;
        
        if(result < min_result)
            min_result = result;

        return;
    }

    for(int i = 1; i <= 4; i++){
        if(i == ADD){
            if(arr_count_of_operators[ADD] < arr_num_of_operators[ADD]){
                arr_count_of_operators[ADD]++;
                dfs(result + arr_integers[depth + 1], depth + 1);
                arr_count_of_operators[ADD]--; 
            }
        }
        else if(i == SUB){
            if(arr_count_of_operators[SUB] < arr_num_of_operators[SUB]){
                arr_count_of_operators[SUB]++;
                dfs(result - arr_integers[depth + 1], depth + 1);
                arr_count_of_operators[SUB]--; 
            }
        }
        else if(i == MUL){
            if(arr_count_of_operators[MUL] < arr_num_of_operators[MUL]){
                arr_count_of_operators[MUL]++;
                dfs(result * arr_integers[depth + 1], depth + 1);
                arr_count_of_operators[MUL]--; 
            }
        }
        else if(i == DIV){
            if(arr_count_of_operators[DIV] < arr_num_of_operators[DIV]){
                arr_count_of_operators[DIV]++;
                dfs(result / arr_integers[depth + 1], depth + 1);
                arr_count_of_operators[DIV]--; 
            }
        }
        else
            continue;
    }
}

int main(void)
{
    scanf("%d", &N);

    for(int i = 1; i <= 4; i++)
        arr_count_of_operators[i] = 0;

    for(int i = 1; i <= N; i++)
        scanf("%d", &arr_integers[i]);

    scanf("%d", &arr_num_of_operators[ADD]);
    scanf("%d", &arr_num_of_operators[SUB]);
    scanf("%d", &arr_num_of_operators[MUL]);
    scanf("%d", &arr_num_of_operators[DIV]);

    dfs(arr_integers[1], 1);
    printf("%d\n%d", max_result, min_result);
    
    return 0;
}
#include <stdio.h>
#include <string.h>

void sort_list(int left, int right)
{

}

void remove_duplicate(int left, int right)
{

}

int main(void)
{
    int T;
    scanf("%d", &T);

    int F;
    char user_a[100000][21];
    char user_b[100000][21];
    char first_step_list[200000][21];
    char second_step_list[200000][21];

    int first_count = -1;

    for(int i = 0; i < T; i++){
        scanf("%d", &F);

        for(int j = 0; j < F; j++){
            scanf("%s %s", &user_a[j][0], &user_b[j][0]);

            strcpy(first_step_list[++first_count], &user_a[j][0]);
            strcpy(first_step_list[++first_count], &user_b[j][0]);
        }

        sort_list(0, first_count);
        remove_duplicate(0, first_count);
    }
    return 0;
}
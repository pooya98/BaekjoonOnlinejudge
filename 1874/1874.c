#include <stdio.h>

#define POSSIBLE 1
#define IMPOSSIBLE 2

int stack[100000];
int top = -1;

int target[100000];

int count = 1;

char oper_list[1000000];
int oper_list_top = -1;

int main(void)
{
    int n;
    int cur_number;
    int possible_flag = POSSIBLE;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &target[i]);

    for(int i = 0; i < n; i++){
        cur_number = target[i];

        if(top == -1 || stack[top] < cur_number){
            while(count <= cur_number){
                stack[++top] = count;
                count++;
                oper_list[++oper_list_top] = '+';
            }
            top--;
            oper_list[++oper_list_top] = '-';
        }
        else if (stack[top] == cur_number){
            top--;
            oper_list[++oper_list_top] = '-';
        }
        else if (stack[top] > cur_number){
            possible_flag = IMPOSSIBLE;
            break;
        }
    }

    if(possible_flag == POSSIBLE){
        for(int i = 0; i <= oper_list_top; i++)
            printf("%c\n", oper_list[i]);
    }
    else
        printf("NO\n");

    return 0;
}
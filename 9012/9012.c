#include <stdio.h>
#include <string.h>

#define VALID 1
#define INVALID 2

char input[51];

char stack[51];
int top = -1;

int main(void)
{
    int T;
    char cur_digit;
    int vps_flag;

    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        top = -1;
        vps_flag = VALID;

        scanf("%s", input);

        for(int j = 0; j < strlen(input); j++){
            cur_digit = input[j];

            if(cur_digit == '(')
                stack[++top] = cur_digit;
            else{
                if(stack[top] == '(')
                    top--;
                else{
                    vps_flag = INVALID;
                    break;
                }
            }
        }

        if(top != -1)
            vps_flag = INVALID;

        if(vps_flag == VALID)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
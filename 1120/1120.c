#include <stdio.h>
#include <string.h>

int main(void)
{
    int a_len, b_len;
    char str_a[51];
    char str_b[51];
    int count = 0;
    int min = 50;

    scanf("%s %s", str_a, str_b);

    a_len = strlen(str_a);
    b_len = strlen(str_b);

    for(int i = 0; i < (b_len - a_len) + 1; i++){
        count = 0;
        for(int j = 0; j < a_len; j++){
            if(str_a[j] != str_b[i + j])
                count++;
        }
        if(min > count)
            min = count;
    }

    printf("%d\n", min);

    return 0;
}
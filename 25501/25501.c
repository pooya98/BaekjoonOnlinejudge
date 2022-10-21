#include <stdio.h>
#include <string.h>

#define MAX_STRING_LEN 1000 + 1
#define TRUE 1
#define FALSE 0

char input_string[MAX_STRING_LEN];
int result;
int call_count;

int recursion(char string[], int l, int r){
    call_count++;
    if(l >= r)
        return 1;
    else if(string[l] != string[r])
        return 0;
    else
        return recursion(string, l + 1, r - 1);
}

int isPalindrome(char string[]){
    call_count = 0;
    return recursion(string, 0, strlen(string) - 1);
}

int main(void)
{
    int T;
    scanf("%d", &T);

    for(int t = 0; t < T; t++){
        scanf("%s", input_string);

        result = isPalindrome(input_string);

        printf("%d %d\n", result, call_count);
    }
    return 0;
}
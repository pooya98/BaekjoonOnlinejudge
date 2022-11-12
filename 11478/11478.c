#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXIST 1
#define NOT_EXIST 2

typedef struct _bucket{
    char value[1001];
    struct _bucket* next;
}bucket;

bucket* hash_table[3000000];

char string[1001];
int string_len;
char temp_string[1001];
int count = 0;

int get_hash_code(char str[]){
    int hash_code = (str[0] - 'a') * 1000 + strlen(str);
    if(strlen(str) >= 2)
        hash_code += (str[1] - 'a') * 100000;
    return hash_code;
}

int search_value(int index, char str[]){
    bucket* bucket_pointer = hash_table[index];
    int flag = NOT_EXIST;

    while(bucket_pointer){
        if(strcmp(bucket_pointer->value, str) == 0){
            flag = EXIST;
            break;
        }
        bucket_pointer = bucket_pointer->next;
    }

    return flag;
}

void insert_value(int index, char str[]){
    bucket* new_bucket = (bucket*)malloc(sizeof(bucket));
    strcpy(new_bucket->value, str);
    new_bucket->next = hash_table[index];
    hash_table[index] = new_bucket;
}

void test(char str[]){
    int index = get_hash_code(str);

    if(search_value(index, str) == EXIST){
        return;
    }
    else{
        insert_value(index, str);
        count++;
    }
}

int main(void)
{
    scanf("%s", string);
    string_len = strlen(string);

    for(int i = 1; i <= string_len; i++)
        hash_table[i] = NULL;

    for(int i = 1; i <= string_len; i++){
        for(int j = 0; j <= string_len - i; j++){

            strncpy(temp_string, string + j, i);
            test(temp_string);
        }
    }

    printf("%d", count);
    return 0;
}
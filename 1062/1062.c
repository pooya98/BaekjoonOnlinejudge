#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _TreeNode{
    char value;
    int weight;
    struct _TreeNode* next[26];
}TreeNode;

TreeNode * root;
int max_possible = 0;


void sort_target(char target[], int length){
    int i, j, min;

    for (i = 0; i < length - 1; i++){
        min = i;
        for (j = i + 1; j < length; j++){
            if(target[j] < target[min])
                min = j;
        }

        char temp = target[i];
        target[i] = target[min];
        target[min] = temp;
    }
}

void extend_tree(char target[], int length){
    TreeNode * pointer = root;

    for(int i = 0; i < length; i++)
    {
        if(pointer->next[target[i] - 'a'] != NULL){
            pointer = pointer->next[target[i] - 'a'];
        }
        else{
            TreeNode * newNode = (TreeNode*)malloc(sizeof(TreeNode));
            newNode->value = target[i];
            newNode->weight = 0;
            for(int i = 0; i < 26; i++)
            {
                newNode->next[i] = NULL;
            }
            pointer->next[target[i] - 'a'] = newNode;
            pointer = newNode;
        }
    }
    pointer->weight += 1;
}

void FindMax(TreeNode * head, int sum_weight){
    TreeNode * pointer = head;

    if((pointer->weight + sum_weight) > max_possible){
        max_possible = (pointer->weight + sum_weight);
    }

    for(int i = 0; i < 26; i++){
        if(pointer->next[i] != NULL){
            FindMax(pointer->next[i], sum_weight + pointer->weight);
        }
    }
}

void free_tree(TreeNode * head){
    for(int i = 0; i < 26; i++){
        if(head->next[i] != NULL){
            free_tree(head->next[i]);
        }
    }
    free(head);
}

int main(void)
{
    int N, K;
    char input_string[16];
    int string_length = 0;

    char target_string[8];
    int target_length;

    root = (TreeNode*)malloc(sizeof(TreeNode));
    root->value = '!';
    root->weight = 0;
    for(int i = 0; i < 26; i++)
    {
        root->next[i] = NULL;
    }

    scanf("%d %d", &N, &K);

    for(int i = 0; i < N; i++)
    {
        scanf("%s", input_string);

        string_length = strlen(input_string);

        target_length = -1;

        for(int i = 4; i < string_length - 4; i++)
        {
            if(input_string[i] == 'a' 
            || input_string[i] == 'n' 
            || input_string[i] == 't'
            || input_string[i] == 'i'
            || input_string[i] == 'c'){
                continue;
            }
            else{
                int flag = 1;
                for(int j = 0; j <= target_length; j++){
                    if(target_string[j] == input_string[i]){
                        flag = 0;
                        break;
                    }
                }

                if(flag){
                    target_string[++target_length] = input_string[i];
                }
            }
        }

        target_length++;

        if((target_length + 5) > K){
            continue;
        }
        else{
            sort_target(target_string, target_length);
            extend_tree(target_string, target_length);
        }
    }

    FindMax(root, 0);
    free_tree(root);

    printf("%d", max_possible);
    return 0;
}
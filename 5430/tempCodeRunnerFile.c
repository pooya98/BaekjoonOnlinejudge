#include <stdio.h>
#include <string.h>

#define FORWARD 1
#define BACKWARD 2

#define ERROR 1
#define NORMAL 2

int arr[1000001];
int arr_top = -1;
int front;
int rear;

int n;
char operation_list[1000001];
char arr_string[1000005];

int cur_direction;
int error_flag;

int main(void){
    int T;
    char operation;
    int sum;

    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        cur_direction = FORWARD;
        error_flag = NORMAL;
        arr_top = -1;
        sum = 0;

        scanf("%s", operation_list);
        scanf("%d", &n);
        scanf("%s", arr_string);
        
        arr_string[strlen(arr_string) - 1] = ',';

        printf("%s\n", arr_string);

        int arr_string_length = strlen(arr_string);

        for(int j = 1; j < arr_string_length; j++){
            if(arr_string[j] == ','){
                arr[++arr_top] = sum;
                sum = 0;
            }
            else{
                sum *= 10;
                sum += (int)(arr_string[j] - '0');
            }
        }

        for(int j = 0; j <= arr_top; j++)
            printf("%d ", arr[j]);

        printf("\n");

        front = 0;
        rear = arr_top;

        int operation_list_length = strlen(operation_list);

        for(int j = 0; j < operation_list_length; j++){
            operation = operation_list[j];

            if(operation == 'R'){
                if(cur_direction == FORWARD)
                    cur_direction = BACKWARD;
                else
                    cur_direction = FORWARD;
            }
            else{
                if(front > rear){
                    error_flag = ERROR;
                    break;
                }

                if(cur_direction == FORWARD)
                    front++;
                else
                    rear--;
            }
        }

        if(error_flag == ERROR){
            printf("error\n");
        }else{
            if(cur_direction == FORWARD){
                printf("[");
                for(int j = front; j < rear; j++)
                    printf("%d,", arr[j]);

                if(front <= rear)
                    printf("%d", arr[rear]);
                printf("]\n");
            }
            else{
                printf("[");
                for(int j = rear; j > front; j--)
                    printf("%d,", arr[j]);

                if(front <= rear)
                    printf("%d", arr[front]);
                printf("]\n");
            }
        }
    }

    return 0;
}
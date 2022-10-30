#include <stdio.h>

typedef struct _wire{
    int A_location;
    int B_location;
}wire;

wire wire_list[101];
int dp_table[101] = {0};

void sort_wire_list(int start, int end){
    for(int i = start; i <= end; i++){
        wire min_wire = wire_list[i];
        int min_index = i;

        for(int j = i + 1; j <= end; j++){
            if(min_wire.A_location > wire_list[j].A_location){
                min_wire = wire_list[j];
                min_index = j;
            }
            else if(min_wire.A_location == wire_list[j].A_location){
                if(min_wire.B_location > wire_list[j].B_location){
                    min_wire = wire_list[j];
                    min_index = j;
                }
            }
            else{
                continue;
            }
        }

        wire temp_wire = wire_list[i];
        wire_list[i] = min_wire;
        wire_list[min_index] = temp_wire;
    }
}

int main(void)
{
    int N;
    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
        scanf("%d %d", &wire_list[i].A_location, &wire_list[i].B_location);

    sort_wire_list(1, N);

    for(int i = 1; i <= N; i++){
        int max_index;
        int max_value = 0;
        for(int j = 1; j < i; j++){
            if(wire_list[j].B_location <= wire_list[i].B_location){
                if(max_value < dp_table[j]){
                    max_index = j;
                    max_value = dp_table[j];
                }
            }
        }
        dp_table[i] = max_value + 1;
    }

    int max_value = 0;

    for(int i = 1; i <= N; i++)
        if(max_value < dp_table[i])
            max_value = dp_table[i];

    printf("%d", N - max_value);


    return 0;
}
#include <stdio.h>

typedef struct _city{
    int cost;
    int customer;
    double efficiency;
}city;

int c, n;
city cities[21];
int dp_table[1101];
int result = 100000000;

void sort_cities(){
    int i , j;
    city temp_city;

    for(int i = 0; i <= 1100; i++){
        dp_table[i] = -1;
    }

    for(i = 1; i < n; i++){
        temp_city.cost = cities[i].cost;
        temp_city.customer = cities[i].customer;
        temp_city.efficiency = cities[i].efficiency;

        for(j = i - 1; j >= 0 && cities[j].efficiency < temp_city.efficiency; j--){
            cities[j + 1].cost = cities[j].cost;
            cities[j + 1].customer = cities[j].customer;
            cities[j + 1].efficiency = cities[j].efficiency;
        }
        cities[j + 1].cost = temp_city.cost;
        cities[j + 1].customer = temp_city.customer;
        cities[j + 1].efficiency = temp_city.efficiency;
    }
}

int main(void)
{
    scanf("%d %d", &c, &n);

    for(int i = 0; i < n; i++){
        scanf("%d %d", &cities[i].cost, &cities[i].customer);
        cities[i].efficiency = (double)cities[i].customer / cities[i].cost;
    }

    sort_cities();

    for(int i = 0; i < n; i++){
        int customer = cities[i].customer;
        int cost = cities[i].cost;

        if((dp_table[customer] > cost) || (dp_table[customer] == -1)){
            dp_table[customer] = cost;
        }
    }    

    for(int i = 1; i <= (c + 100); i++){
        if(dp_table[i] == -1)
            continue;

        int cur_customer = i;
        int cur_cost = dp_table[i];

        for(int j = 0; j < n; j++){
            int addtional_customer = cities[j].customer;
            int addtional_cost = cities[j].cost;

            if((cur_customer + addtional_customer) > (c + 100))
                continue;

            if((dp_table[cur_customer + addtional_customer] == -1) || dp_table[cur_customer + addtional_customer] > (cur_cost + addtional_cost))
                dp_table[cur_customer + addtional_customer] = (cur_cost + addtional_cost);
        }
    }

    for(int i = c; i <= 1100; i++){
        if(dp_table[i] != -1 && result > dp_table[i]){
            result = dp_table[i];
        }
    }

    printf("%d", result);

    return 0;
}
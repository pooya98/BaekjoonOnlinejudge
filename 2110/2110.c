#include <stdio.h>

#define MAX_ARR_SIZE 200000 + 1

int N, C;

int house_arr[MAX_ARR_SIZE];
int temp_arr[MAX_ARR_SIZE];
int max_distance = 0;

void merge_sort(int start, int end){

    if(start >= end)
        return;

    int mid = (start + end) / 2;

    merge_sort(start, mid);
    merge_sort(mid + 1, end);

    int i = start;
    int j = mid + 1;
    int temp_pnr = start - 1;

    while((i <= mid) && (j <= end)){
        if(house_arr[i] <= house_arr[j])
            temp_arr[++temp_pnr] = house_arr[i++];
        else
            temp_arr[++temp_pnr] = house_arr[j++];
    }

    while(i <= mid)
        temp_arr[++temp_pnr] = house_arr[i++];

    while(j <= end)
        temp_arr[++temp_pnr] = house_arr[j++];

    for(int k = start; k <= end; k++)
        house_arr[k] = temp_arr[k];
}

int find_next_location(int next_min_limit){

    int left = 0;
    int right = N - 1;
    int mid;
    int nearlist_index = N;

    if(next_min_limit > house_arr[N - 1])
        return -1;

    while(left <= right){
        mid = (left + right) / 2;

        if(house_arr[mid] == next_min_limit)
            return house_arr[mid];

        if(house_arr[mid] < next_min_limit){
            left = mid + 1;
        }
        else{
            if(nearlist_index > mid)
                nearlist_index = mid;
            
            right = mid - 1;
        }
    }

    return house_arr[nearlist_index];
}

void get_install_count(int distance, int* install_count){

    int first_location = house_arr[0];
    int cur_location;
    int next_min_limit;
    int next_location;
    int cur_count;
    int max_count = 0;

    for(int i = 0; (i < N) && ((house_arr[i] - first_location) <= distance );i++){
        cur_count = 1;
        cur_location = house_arr[i];

        while(1){
            next_min_limit = cur_location + distance;

            next_location = find_next_location(next_min_limit);

            if(next_location == -1)
                break;
            else{
                cur_count++;
                cur_location = next_location;
            }
        }
        if(max_count < cur_count)
            max_count = cur_count;
    }
    *install_count = max_count;
}

int main(void)
{
    scanf("%d %d", &N, &C);

    for(int i = 0; i < N; i++)
        scanf("%d", &house_arr[i]);

    merge_sort(0, N - 1);

    int left = 0;
    int right = (house_arr[N - 1] - house_arr[0]) * 2;
    int mid;
    int install_count;

    while(left <= right){
        mid = (left + right) / 2;
        install_count = 0;

        get_install_count(mid, &install_count);

        if(install_count >= C){
            if(max_distance < mid)
                max_distance = mid;

            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    printf("%d", max_distance);
    
    return 0;
}
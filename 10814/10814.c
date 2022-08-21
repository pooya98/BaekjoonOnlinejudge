#include <stdio.h>
#include <string.h>

int N;
int age[10001];
char name[10001][101];

int temp_age[10001];
char temp_name[10001][101];

void MergeSort(int start, int end)
{
    if (start < end){
        int mid = (start + end) / 2;

        MergeSort(start, mid);
        MergeSort(mid + 1, end);

        int i = start;
        int j = mid + 1;
        int temp_index = start;

        while(i <= mid && j <= end) {
            if((age[i] <= age[j])){
                temp_age[temp_index] = age[i];
                strcpy(temp_name[temp_index], name[i]);
                temp_index++;
                i++;
            }
            else{
                temp_age[temp_index] = age[j];
                strcpy(temp_name[temp_index], name[j]);
                temp_index++;
                j++;
            }
        }
        while(i <= mid){
            temp_age[temp_index] = age[i];
            strcpy(temp_name[temp_index], name[i]);
            temp_index++;
            i++;
        }
        
        while(j <= end){
            temp_age[temp_index] = age[j];
            strcpy(temp_name[temp_index], name[j]);
            temp_index++;
            j++;
        }

        for(int k = start; k <= end; k++){
            age[k] = temp_age[k];
            strcpy(name[k], temp_name[k]);
        }
    }
}

int main(void)
{

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d", &age[i]);
        scanf("%s", &name[i][0]);
    }

    MergeSort(0, N - 1);

    for(int i = 0; i < N; i++){
        printf("%d ", age[i]);
        printf("%s\n", name[i]);
    }

    return 0;
}
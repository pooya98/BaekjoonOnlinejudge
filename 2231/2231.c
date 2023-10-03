#include <stdio.h>

int main(void)
{
    int N;
    int arr[1000001];
    int sum;
    int i = 1;
    int temp;

    scanf("%d", &N);

    for(int i = 0; i <= N; i++)
        arr[i] = 0;

    while(arr[N] == 0){
        sum = i;
        temp = i;
        while(temp){
            sum += (temp % 10);
            temp /= 10;
        }

        if((sum <= N) && (arr[sum] == 0))
            arr[sum] = i;

        i++;
        if(i > N)
            break;
    }
    
    printf("%d", arr[N]);
    return 0;
}
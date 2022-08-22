#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);

    int count = 0;
    int temp;
    int six_count;

    for(int i = 0; ; i++){
        temp = i;
        six_count = 0;

        while(temp > 0){
            if(temp % 10 == 6){
                six_count++;

                if(six_count == 3){
                    
                    count++;
                    break;
                }
            }
            else{
                six_count = 0;
            }
            temp /= 10;
        }

        if(count == N){
            printf("%d", i);
            break;
        }
    }

    return 0;
}
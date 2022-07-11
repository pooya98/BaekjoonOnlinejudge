#include <stdio.h>

int main(void){
    long long  W, H, f, c, x1, y1, x2, y2;
    long long height_of_floor = 0;
    unsigned long long result = 0;
    long long color_number_of_column = 0;

    scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &W, &H, &f, &c, &x1, &y1, &x2, &y2);

    height_of_floor = H / (c + 1);

    long long start = 0;
    long long end_double = 0;
    long long end_single = 0;
    long long double_duration = 0;
    long long single_duration = 0;

    if((W - f) > f){
        end_double = f;
        end_single = W - f;
    }
    else{
        end_double = W - f;
        end_single = f;
    }

    color_number_of_column = (y2 - y1);

    if(x1 < end_double && end_double < x2){
        result += 2 * (color_number_of_column) * (end_double - x1);
        result += ((color_number_of_column)) * (x2 - end_double);
    }
    else if(x2 <= end_double){
        result += 2 * (color_number_of_column) * (x2 - x1);
    }
    else if(end_double <= x1){
        result += (color_number_of_column) * (x2 - x1);
    }

    result *= (c + 1);

    printf("%lld\n", W * H - result);
    
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define PI 3.141592653589793238462643383

int main(void)
{
	int R;

	scanf("%d", &R);

	printf("%f\n", R * R * PI);
	printf("%f\n", R * R * 2.0);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{	
	int A, B, C;
	double break_even_point;

	scanf("%d %d %d", &A, &B, &C);

	if (C > B) {
		break_even_point = ((double)A) / (C - B);
		if (break_even_point == ceil(break_even_point)) {
			break_even_point += 1;
		}
		else {
			break_even_point = ceil(break_even_point);
		}
	}
	else {
		break_even_point = -1;
	}

	printf("%.0f", break_even_point);
	return 0;
}
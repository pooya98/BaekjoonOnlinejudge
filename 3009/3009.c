#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int point_x[3];
	int point_y[3];

	int dest_x, dest_y;

	for (int i = 0; i < 3; i++)
		scanf("%d %d", &point_x[i], &point_y[i]);

	if (point_x[0] == point_x[1])
		dest_x = point_x[2];
	else if (point_x[0] == point_x[2])
		dest_x = point_x[1];
	else
		dest_x = point_x[0];

	if (point_y[0] == point_y[1])
		dest_y = point_y[2];
	else if (point_y[0] == point_y[2])
		dest_y = point_y[1];
	else
		dest_y = point_y[0];

	printf("%d %d", dest_x, dest_y);
	
	return 0;
}
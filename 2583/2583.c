#include <stdio.h>
#define MAX_INDEX 102

typedef struct node {
	int x;
	int y;
};

short maze[MAX_INDEX][MAX_INDEX]; // 우측 위의 좌표가 해당 칸
short dir[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
short node_dir[MAX_INDEX][MAX_INDEX] = {0};
short area[5001];
struct node stack[10001];

short front = -1;
short area_count = 0;

void initialize_maze(int , int);
void set_lectangle(int x1, int x2, int y1, int y2);
void find_area(int m, int n);
int calculate_area(int i, int j);
void insertion_sort(void);
void print_arealist(void);

int main(void)
{
	int m, n, k;
	int x1, x2, y1, y2;

	scanf("%d %d %d", &m, &n, &k);
	initialize_maze(n, m);

	for (int i = 0; i < k; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		set_lectangle(x1+1, x2, y1+1, y2);
	}

	find_area(m,n);
	insertion_sort();
	print_arealist();
	
	return 0;
}

void initialize_maze(int x, int y) {
	for (int i = 0; i <= y + 1; i++) { //세로 두줄
		maze[0][i] = 1;
		maze[x + 1][i] = 1;
	}
	for (int i = 1; i <= x; i++) { // 가로 두줄
		maze[i][0] = 1;
		maze[i][y + 1] = 1;
	}
}

void set_lectangle(int x1, int x2, int y1, int y2){
	for (int i = y1; i <= y2; i++)
		for (int j = x1; j <= x2; j++)
			maze[j][i] = 1;
}

void find_area(int m,int n) {
	for (int y = 1; y <= m ;y++) {
		for (int x = 1; x <= n ;x++){
			if (!maze[x][y])
				area[area_count++] = calculate_area(x, y);
		}
	}
}

int calculate_area(int i, int j) {
	int area=1;
	int cur_x, cur_y, next_x, next_y;

	stack[++front].x = i;
	stack[front].y = j;
	maze[i][j] = 1;

	while (front !=-1) {
		cur_x = stack[front].x;
		cur_y = stack[front].y;

		while(1){
			if (node_dir[cur_x][cur_y] > 3) {
				front--;
				break;
			}
			next_x = cur_x + dir[node_dir[cur_x][cur_y]][0];
			next_y = cur_y + dir[node_dir[cur_x][cur_y]][1];
			node_dir[cur_x][cur_y]++;

			if (!maze[next_x][next_y]) {
				stack[++front].x = next_x;
				stack[front].y = next_y;
				maze[next_x][next_y] = 1;
				area++;
				break;
			}
		}
	}
	return area;
}

void insertion_sort(void) {
	int i, j, key;

	for(i =1;i<area_count;i++){
		key = area[i];
		for (j = i - 1; j >= 0 && area[j] > key; j--)
			area[j + 1] = area[j];
		area[j + 1] = key;
	}
}

void print_arealist() {
	printf("%d\n", area_count);

	for (int i = 0; i < area_count; i++)
		printf("%d ", area[i]);
}
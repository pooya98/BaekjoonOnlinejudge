#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned short count[3000000] = { 0 };

void function(int n)
{
	if (n == 1)
		printf("%d", count[1]);
	else {
		for (int i = 1; i <= n; i++) {
			if (!count[i + 1] || count[i + 1] > count[i] + 1)
				count[i + 1] = count[i] + 1;
			if (!count[2 * i] || count[2 * i] > count[i] + 1)
				count[2 * i] = count[i] + 1;
			if (!count[3 * i] || count[3 * i] > count[i] + 1)
				count[3 * i] = count[i] + 1;
		}
		printf("%d", count[n]);
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	function(n);
	return 0;
}

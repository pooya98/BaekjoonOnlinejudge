#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 1000
#define INF 1000000000         // 무한대를 의미하는 상수

int turnOffLamp(int N, int EE[][ARRAY_MAX + 1][3], int WS[], int D[])
{
	int L, R;
	int Case[5];
	for (int diagonal = 1; diagonal <= N - 1; diagonal++) {
		for (L = 1; L <= N - diagonal; L++) {
			R = L + diagonal;
			Case[1] = (EE[L + 1][R][1] + (D[L + 1] - D[L])*(WS[N] - WS[R] + WS[L]));
			Case[2] = (EE[L + 1][R][2] + (D[R] - D[L])*(WS[N] - WS[R] + WS[L]));
			Case[3] = (EE[L][R - 1][1] + (D[R] - D[L])*(WS[N] - WS[R - 1] + WS[L - 1]));
			Case[4] = (EE[L][R - 1][2] + (D[R] - D[R - 1])*(WS[N] - WS[R - 1] + WS[L - 1]));

			if (Case[1] <= Case[2])
				EE[L][R][1] = Case[1];
			else
				EE[L][R][1] = Case[2];
			if (Case[3] <= Case[4])
				EE[L][R][2] = Case[3];
			else
				EE[L][R][2] = Case[4];
		}
	}
	return (EE[1][N][1] < EE[1][N][2]) ? EE[1][N][1] : EE[1][N][2];
}

int main(void)
{
	int N;
	int start;

	scanf("%d", &N);
	scanf("%d", &start);

	int D[ARRAY_MAX + 1];
	int W[ARRAY_MAX + 1];

	int WS[ARRAY_MAX + 1];
	int EE[ARRAY_MAX + 1][ARRAY_MAX + 1][3];

	for (int i = 1; i <= N; i++)
		scanf("%d %d", &D[i], &W[i]);

	WS[0] = 0;
	for (int i = 1; i <= N; i++) {
		EE[i][i][1] = INF;
		EE[i][i][2] = INF;
		WS[i] = WS[i - 1] + W[i];
	}

	EE[start][start][1] = 0;
	EE[start][start][2] = 0;

	printf("%d", turnOffLamp(N, EE, WS, D));

	return 0;
}
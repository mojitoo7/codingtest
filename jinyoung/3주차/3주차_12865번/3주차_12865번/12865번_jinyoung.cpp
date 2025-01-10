#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 100001

int main()
{
	int N, K, W[SIZE], V[1001];
	int value[101][SIZE] = { 0 };

	scanf("%d %d", &N, &K);
	for (int i = 0; i < N;i++)
	{
		scanf("%d %d", &W[i], &V[i]);
	}

	for (int i = 1;i <= N;i++)
	{
		for (int j = 1;j <= K;j++)
		{
			if (j - W[i] > 0)
			{
				if (value[i - 1][j] < (value[i - 1][j - W[i]] + V[i]))
				{
					value[i][j] = value[i - 1][j - W[i]] + V[i];
				}
				else
					value[i][j] = value[i - 1][j];
			}
			else 
				value[i][j] = value[i - 1][j];
		}
	}

	printf("%d", value[N][K]);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 1001

int main()
{
	int T, N;
	int answer[SIZE] = { 1 };
	int DP[SIZE] = { 0 };

	scanf("%d", &T);
	for (int i = 0;i < T;i++)
	{
		scanf("%d", &N);

		DP[1] = 1;
		for (int i = 2; i <= N;i++)
		{
			for (int j = 1;j <= i / 2;j++)			
			{
				DP[i] += DP[j];						// 시그마 부분
			}
			DP[i] += 1;								// + 1
		}
		answer[i] = DP[N];

		for (int i = 0;i < SIZE; i++)				// DP를 초기화
		{
			DP[i] = 0;
		}
	}

	for (int i = 0;i < T;i++)
	{
		printf("%d \n", answer[i]);
	}

	return 0;
}
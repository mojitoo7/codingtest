#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 128

int paper[SIZE][SIZE];
int N, count;
int white = 0, blue = 0;

void cut(int x, int y, int N)
{
	count = 0;
	for (int i = x;i < x + N;i++)
	{
		for (int j = y;j < y + N;j++)
		{
			if (paper[i][j] == 1)				// 정사각형 부분이 파란색인지 검사
				count++;
		}
	}
		
	if (count == N * N)							// 파란색인 경우 
		blue++;
	else if (count == 0)						// 하얀색인 경우
		white++;
	else                                        // 한 가지 색으로만 정사각형이 채워지지 않는 경우 4등분해서 다시 탐색
	{
		cut(x, y, N / 2);						
		cut(x + N / 2, y, N / 2);
		cut(x, y + N / 2, N / 2);
		cut(x + N / 2, y + N / 2, N / 2);
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			scanf("%d", &paper[i][j]);
		}
	}

	cut(0, 0, N);

	printf("%d\n%d", white, blue);

	return 0;
}
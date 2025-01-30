#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 300

int visited[SIZE][SIZE] = {0};
int bit[SIZE][SIZE];
int N, M;
int answer = 0;

void dfs(int x, int y)
{
	if (x == M - 1 && y == N - 1)			// 거래소에 도착한 경우
	{
		answer = 1;
	}

	if (x < M && y < N && visited[x][y] == 0 && bit[x][y] == 1)		
	{
		visited[x][y] = 1;					// 시간초과 : 어차피 최단거리로 가기때문에 왔던길 초기화를 안했음
		dfs(x + 1, y);
		dfs(x, y + 1);						
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0;i < M; i++)
	{
		for (int j = 0;j < N;j++)
		{
			scanf("%d", &bit[i][j]);
		}
	}

	dfs(0, 0);

	if (answer)
		printf("Yes");
	else
		printf("No");

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 100

int count;
int network[SIZE][SIZE];
int visited[SIZE];

void dfs(int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		if (network[m][i] == 1 && !visited[i])			// m과 i가 연결되어있는 경우에 count 그리고 i번 컴퓨터와 연결되어 있는 컴퓨터를 다시 탐색
		{
			visited[i] = 1;								// 방문한 컴퓨터 번호 체크
			dfs(n, i);
			count++;									
		}
	}
}

int main()
{
	int n, computer, a, b;

	scanf("%d", &n);
	scanf("%d", &computer);
	for (int i = 0; i < computer;i++)
	{
		scanf("%d %d", &a, &b);

		network[a - 1][b - 1] = 1;						// 입력받음과 동시에 서로 연결된 번호를 체크해놓기
		network[b - 1][a - 1] = 1;						
	}
	visited[0] = 1;
	dfs(n, 0);											// m이 0인 경우(1번 컴퓨터)부터 연결된 컴퓨터 탐색 시작

	printf("%d", count);

	return 0;
}
	
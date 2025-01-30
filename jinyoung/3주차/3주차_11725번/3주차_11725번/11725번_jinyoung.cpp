#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#define SIZE 100001
using namespace std;

int N;
vector<int> tree[SIZE];
int answer[SIZE];

void dfs(int x)
{
	for (int i = 0; i < tree[x].size();i++)
	{
		int k = tree[x][i];						

		if (answer[k] == 0)							
		{
			answer[k] = x;
			dfs(k);
		}
	}
}

int main()
{
	int x, y;

	scanf("%d", &N);

	for (int i = 0;i < N - 1;i++)
	{
		scanf("%d %d", &x, &y);
		tree[x].push_back(y);		
		tree[y].push_back(x);
	}

	dfs(1);

	for (int i = 2;i <= N; i++)
	{
		printf("%d\n", answer[i]);
	}


	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int n, m, r, c, d, answer;
int room[51][51];
int visited[51][51];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int clean()
{
	int cnt = 0;
	int left = d - 1 + (d - 1 < 0 ? 4 : 0);
	int repeat = 0;
	while (1)
	{
		if (repeat >= 4)
		{
			left = d - 2 + (d - 2 < 0 ? 4 : 0);
			if (room[r + dy[left]][c + dx[left]])
				break;

			r += dy[left];
			c += dx[left];
			repeat = 0;
			left = d - 1 + (d - 1 < 0 ? 4 : 0);
			continue;
		}

		if (!visited[r][c])
		{
			visited[r][c] = 1;
			cnt++;
		}

		int ny = r + dy[left];
		int nx = c + dx[left];

		if (ny < n && ny >= 0 && nx < m && nx >= 0)
		{
			if (visited[ny][nx])
			{
				left = left - 1 + (left - 1 < 0 ? 4 : 0);
				repeat++;
				continue;
			}

			if (room[ny][nx])
			{
				left = left - 1 + (left - 1 < 0 ? 4 : 0);
				repeat++;
				continue;
			}

			r = ny;
			c = nx;
			d = left;
			repeat = 0;
			left = d - 1 + (d - 1 < 0 ? 4 : 0);
		}
		else
		{
			left = left - 1 + (left - 1 < 0 ? 4 : 0);
			repeat++;
			continue;
		}
	}

	return cnt;
}


int stop()
{
	int answer = clean();
	return answer;
}

int main()
{
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &r, &c, &d);
	for (int i = 0;i < n;i++)
	{
		for (int j = 0; j < m;j++)
		{
			scanf("%d", room[i][j]);
		}
	}
	answer = stop();
	
	printf("%d", answer);

	return 0;
}
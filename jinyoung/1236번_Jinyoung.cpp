#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int n, m;
	char castle[50][50] = { 0 };

	scanf("%d %d", &n, &m);

	for (int i = 0;i < n;i++)
	{
		scanf("%s", &castle[i]);
	}

	int count_n = n, count_m = m;

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (castle[i][j] == 'x')
			{
				count_n--;
			}
		}
	}

	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (castle[j][i] == 'x')
			{
				count_m--;
			}
		}
	}

	if (n > m)
	{
		printf("%d", count_n);
	}
	else
		printf("%d", count_m);

	return 0;

}
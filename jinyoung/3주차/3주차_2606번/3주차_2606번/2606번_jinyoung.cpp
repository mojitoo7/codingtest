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
		if (network[m][i] == 1 && !visited[i])			// m�� i�� ����Ǿ��ִ� ��쿡 count �׸��� i�� ��ǻ�Ϳ� ����Ǿ� �ִ� ��ǻ�͸� �ٽ� Ž��
		{
			visited[i] = 1;								// �湮�� ��ǻ�� ��ȣ üũ
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

		network[a - 1][b - 1] = 1;						// �Է¹����� ���ÿ� ���� ����� ��ȣ�� üũ�س���
		network[b - 1][a - 1] = 1;						
	}
	visited[0] = 1;
	dfs(n, 0);											// m�� 0�� ���(1�� ��ǻ��)���� ����� ��ǻ�� Ž�� ����

	printf("%d", count);

	return 0;
}
	
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
			if (paper[i][j] == 1)				// ���簢�� �κ��� �Ķ������� �˻�
				count++;
		}
	}
		
	if (count == N * N)							// �Ķ����� ��� 
		blue++;
	else if (count == 0)						// �Ͼ���� ���
		white++;
	else                                        // �� ���� �����θ� ���簢���� ä������ �ʴ� ��� 4����ؼ� �ٽ� Ž��
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
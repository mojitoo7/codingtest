#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#define SIZE 10001

int main()
{
	int T, n;
	int GP;
	int prime[SIZE] = { 0 };
	int answer[SIZE][2] = { 0 };

	// �ε����� �Ҽ����� ��쿡�� ���� 0���� ����
	for (int i = 2;i <= (int)sqrt(SIZE);i++)
	{
		for (int j = i * i; j <= SIZE;j++)
		{
			if (j % i == 0)
				prime[j] = 1;
		}
	}

	// �Է�
	scanf("%d", &T);

	for (int i = 0;i < T;i++)
	{
		scanf("%d", &n);

		// �Ҽ����� ���̰� ���� �۾ƾ� �ϹǷ�, ¦���� ���ݰ����� �Ҽ������� �˻�
		for (int j = n / 2; j > 0;j--)
		{
			if (prime[j] == 0 && prime[n - j] == 0)
			{
				answer[i][0] = j;
				answer[i][1] = n - j;
				break;
			}
		}
	}

	for (int i = 0;i < T;i++)
	{
		printf("%d %d\n", answer[i][0], answer[i][1]);
	}

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int N, M;
	int card[100] = { 0 };
	int sum, black_jack = 0;

	scanf("%d %d", &N, &M);
	 
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &card[i]);
	}


	// 3���� ���� ���� �˱� ���ؼ� 3�߹迭 ���
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				sum = card[i] + card[j] + card[k]; // 3�� ���� ���� sum�� ����
					
				if (sum <= M && sum > black_jack) // sum�� ���� ���� black_jack ���� M �� ���̿� ������ black_jack ���� �ֽ�ȭ
					black_jack = sum;
			}
		}
	}

	printf("%d", black_jack);

	return 0;
}
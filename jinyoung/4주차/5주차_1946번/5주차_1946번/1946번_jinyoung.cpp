#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#define SIZE 100000

int T, N;

struct rank {
	int test;
	int interview;
} rank;

int compare(const void* a, const void* b)
{
	struct rank num1 = *(struct rank*)a;
	struct rank num2 = *(struct rank*)b;
	if (num1.test > num2.test)
	{
		return 1;
	}
	else if (num1.test < num2.test)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	scanf("%d", &T);
	for (int i = 0;i < T;i++)
	{
		struct rank score[SIZE];

		scanf("%d", &N);
		for (int j = 0;j < N;j++)
		{
			scanf("%d %d", &score[j].test, &score[j].interview);
		}

		qsort(score, N, sizeof(struct rank), compare);									// �Է¹��� �ڷḦ test ������ ���������� �ǰ� ����, test ������ �հݿ��� Ȯ��

		int count = 0;
		struct rank min;
		for (int k = 0;k < N;k++)														
		{
			if (score[k].interview > min.interview && score[k].test > min.test)			// test�� interview ������ �� �� min���� ���� �������� count
			{
				continue;
			}
			else
			{
				count++;
			}
			min = score[k];																// �հ��� ��쿡 k��° test, interview ���� min �� ����
		}
		printf("%d\n", count);
	}

	return 0;
}
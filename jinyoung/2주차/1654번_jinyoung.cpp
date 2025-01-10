#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int K, N, max=0;
	long long lan[10000];
	int left, mid, right;
	int answer = 0, num = 0;

	scanf("%d %d", &K, &N);
	for (int i = 0; i < K; i++)
	{
		scanf("%d\n", lan[i]);
		if (lan[i] > max)
			max = lan[i];
	}

	left = 1;
	right = max;								// ���� �߿� ���� �� ���� �ִ����� �ϰ� 1�� �ּڰ����� �ؼ� �̺�Ž��

	while (left <= right)						
	{
		mid = (left + right) / 2;

		for (int i = 0;i < K;i++)
		{
			num += lan[i] / mid;				// mid�� ���̷� ������ ���� �߶��� �� ������ ������ ���� num 
		}

		if (num >= N && answer < mid)			// num�� ������ �ʿ��� ������ ���� �̻����� + ���� ������ ���̰� �ִ������� Ž��
			answer = mid;

		if (num < N)
			right = mid - 1;
		else
			left = mid + 1;
	}

	printf("%d", answer);

	return 0;
}
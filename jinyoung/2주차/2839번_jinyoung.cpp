#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int N;
	int sugar[5001];

	scanf("%d", &N);

	// N�� 1~5�� ����� ���� ����
	sugar[1] = -1;
	sugar[2] = -1;
	sugar[3] = 1; 
	sugar[4] = -1;
	sugar[5] = 1;

	for (int i = 6; i < N + 1; i++)
	{
		if (sugar[i - 3] != -1 && sugar[i - 5] == -1) // 3kg ���ϱ⸸ ������ ���
			sugar[i] = sugar[i - 3] + 1;

		else if (sugar[i - 3] == -1 && sugar[i - 5] != -1) // 5kg ���ϱ⸸ ������ ���
			sugar[i] = sugar[i - 5] + 1;

		else if (sugar[i - 3] != -1 && sugar[i - 5] != -1) // �� �� ������ ��쿡�� �ּڰ��� ����
		{
			if (sugar[i - 3] < sugar[i - 5])
				sugar[i] = sugar[i - 3] + 1;
			else
				sugar[i] = sugar[i - 5] + 1;
		}
		else if (sugar[i - 3] == -1 && sugar[i - 5] == -1) // ��Ȯ�ϰ� N kg�� ���� �� ���� ���
			sugar[i] = -1;
	}

	printf("%d", sugar[N]);

	return 0;
}
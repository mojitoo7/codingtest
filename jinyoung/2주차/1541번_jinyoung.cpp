#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
{
	int len, sum = 0, answer = 0, temp_1 = 0, temp_2 = 0;
	char num[50];
	
	scanf("%s", num);
	len = strlen(num);

	for (int i = 0;i < len;i++)
	{
		if (num[i] == '-') // '-' ��ȣ ���ķ� ���� ���ڵ��� ���� ���س���
		{
			for (int j = i; j < len;j++)
			{
				if (num[j] != '+' && num[j] != '-')		// ���ڰ� ���� �����ִ� ���ڸ� �� �ڸ��� ���̸鼭 temp_1�� ����
				{
					temp_1 = temp_1 * 10;				
					temp_1 = temp_1 + num[j] - '0';
				}
				else									// '-'�� '+'�� ���� temp_1�� sum�� ���Ͽ� ����
				{
					sum = sum + temp_1;		
					temp_1 = 0;
				}
			}
			break;
		}

		else if (num[i] == '+')							// '+'�� ���� temp_2�� answer�� ���Ͽ� ����
		{
			answer = answer + temp_2;
			temp_2 = 0;
		}

		else											// ���ڰ� ���� �����ִ� ���ڸ� �� �ڸ��� ���̸鼭 tem_2�� ����
		{
			temp_2 = temp_2 * 10;
			temp_2 = temp_2 + num[i] - '0';
		}

	}

	answer = answer + temp_2;							// ���������� ����� �� �� temp_1�� temp_2�� ���� �����ְ�
	sum = sum + temp_1;

	answer = answer - sum;								// answer���� sum�� �� ���� ���

	printf("%d", answer);

	return 0;
}

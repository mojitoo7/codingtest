#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

long long int gcm, lcm, x, y; 
int sum = 0, min = 0;

int G(int a, int b)								
{
	if (a % gcm == 0 && b % gcm == 0)				// gcm �� �ִ������� �´����� �˻��ϴ� �Լ�
	{
		for (int i = gcm + 1;i < b;i++)
		{
			if (a % i == 0 && b % i == 0)			
			{
				return 0;
				break;
			}
		}
		return 1;
	}
	else
		return 0;
}

int main()
{
	scanf("%d %d", &gcm, &lcm);

	for (int i = gcm;i < (gcm+lcm)/2 + 1;i += gcm)			// i�� �ִ������� ����θ� ����
	{
		if (lcm % i == 0)							// �ּҰ������ i�� ����� �������� �˻�
		{
			sum = i + ((gcm * lcm) / i);			// gcm * lcm = x * y ���� �̿�
			if (min > sum || min == 0)
			{
				if (G(i, (gcm * lcm) / i))			// gcm�� �ִ������� ���������� �˻��ؾ��� 
				{
					x = i;
					y = (gcm * lcm) / i;

					min = x + y;
				}
			}
		}
	}

	printf("%d %d", x, y);

	return 0;
}
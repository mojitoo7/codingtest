#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

long long int gcm, lcm, x, y; 
int sum = 0, min = 0;

int G(int a, int b)								
{
	if (a % gcm == 0 && b % gcm == 0)				// gcm 이 최대공약수가 맞는지를 검사하는 함수
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

	for (int i = gcm;i < (gcm+lcm)/2 + 1;i += gcm)			// i를 최대공약수의 배수로만 설정
	{
		if (lcm % i == 0)							// 최소공배수가 i를 약수로 가지는지 검사
		{
			sum = i + ((gcm * lcm) / i);			// gcm * lcm = x * y 임을 이용
			if (min > sum || min == 0)
			{
				if (G(i, (gcm * lcm) / i))			// gcm을 최대공약수로 가지는지를 검사해야함 
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
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

	// 인덱스가 소수들인 경우에만 값을 0으로 유지
	for (int i = 2;i <= (int)sqrt(SIZE);i++)
	{
		for (int j = i * i; j <= SIZE;j++)
		{
			if (j % i == 0)
				prime[j] = 1;
		}
	}

	// 입력
	scanf("%d", &T);

	for (int i = 0;i < T;i++)
	{
		scanf("%d", &n);

		// 소수들의 차이가 가장 작아야 하므로, 짝수의 절반값부터 소수인지를 검사
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

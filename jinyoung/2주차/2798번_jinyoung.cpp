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


	// 3개씩 더한 값을 알기 위해서 3중배열 사용
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				sum = card[i] + card[j] + card[k]; // 3개 더한 값을 sum에 저장
					
				if (sum <= M && sum > black_jack) // sum의 값이 기존 black_jack 값과 M 값 사이에 있으면 black_jack 값을 최신화
					black_jack = sum;
			}
		}
	}

	printf("%d", black_jack);

	return 0;
}
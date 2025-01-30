#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int N;
	int sugar[5001];

	scanf("%d", &N);

	// N이 1~5인 경우의 값들 설정
	sugar[1] = -1;
	sugar[2] = -1;
	sugar[3] = 1; 
	sugar[4] = -1;
	sugar[5] = 1;

	for (int i = 6; i < N + 1; i++)
	{
		if (sugar[i - 3] != -1 && sugar[i - 5] == -1) // 3kg 더하기만 가능한 경우
			sugar[i] = sugar[i - 3] + 1;

		else if (sugar[i - 3] == -1 && sugar[i - 5] != -1) // 5kg 더하기만 가능한 경우
			sugar[i] = sugar[i - 5] + 1;

		else if (sugar[i - 3] != -1 && sugar[i - 5] != -1) // 둘 다 가능한 경우에는 최솟값을 구함
		{
			if (sugar[i - 3] < sugar[i - 5])
				sugar[i] = sugar[i - 3] + 1;
			else
				sugar[i] = sugar[i - 5] + 1;
		}
		else if (sugar[i - 3] == -1 && sugar[i - 5] == -1) // 정확하게 N kg을 만들 수 없는 경우
			sugar[i] = -1;
	}

	printf("%d", sugar[N]);

	return 0;
}
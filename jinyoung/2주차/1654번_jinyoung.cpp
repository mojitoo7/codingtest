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
	right = max;								// 랜선 중에 가장 긴 값을 최댓값으로 하고 1을 최솟값으로 해서 이분탐색

	while (left <= right)						
	{
		mid = (left + right) / 2;

		for (int i = 0;i < K;i++)
		{
			num += lan[i] / mid;				// mid의 길이로 랜선을 각각 잘랐을 때 나오는 랜선의 수를 num 
		}

		if (num >= N && answer < mid)			// num이 실제로 필요한 랜선의 개수 이상인지 + 각각 랜선의 길이가 최댓값인지를 탐색
			answer = mid;

		if (num < N)
			right = mid - 1;
		else
			left = mid + 1;
	}

	printf("%d", answer);

	return 0;
}
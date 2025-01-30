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

		qsort(score, N, sizeof(struct rank), compare);									// 입력받은 자료를 test 순위가 오름차순이 되게 정렬, test 등수대로 합격여부 확인

		int count = 0;
		struct rank min;
		for (int k = 0;k < N;k++)														
		{
			if (score[k].interview > min.interview && score[k].test > min.test)			// test와 interview 순위가 둘 다 min보다 높지 않을때만 count
			{
				continue;
			}
			else
			{
				count++;
			}
			min = score[k];																// 합격인 경우에 k번째 test, interview 값을 min 에 저장
		}
		printf("%d\n", count);
	}

	return 0;
}
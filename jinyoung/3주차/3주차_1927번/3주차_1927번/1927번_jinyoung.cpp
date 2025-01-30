#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 100000

int heap[SIZE] = { 0 };
int N, x;
int count = 0;


void push()										// 0이 아닌 새로운 값이 들어오면 작은 값 순서대로 쌓아놓기
{
	for (int i = 0;i < count;i++)
	{
		if (heap[i] == 0)
		{
			heap[i] = x;
		}
		else if (heap[i] > x)
		{
			heap[i + 1] = heap[i];
			heap[i] = x;
		}
	}
}

int pop()									// 최솟값 (heap[0]) 을 출력해주기
{
	return heap[0];
}

void reduce()								// 출력한 후에 초기화
{
	for (int i = 0;i < count - 1;i++)
	{
		heap[i] = heap[i + 1];
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N;i++)
	{
		scanf("%d", &x);
		count++;

		if (x == 0)
		{
			printf("%d\n", pop());
			reduce();
		}
		else
			push();
	}

	return 0;
}
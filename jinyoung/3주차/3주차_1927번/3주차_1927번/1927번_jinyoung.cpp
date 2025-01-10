#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 100000

int heap[SIZE] = { 0 };
int N, x;
int count = 0;


void push()										// 0�� �ƴ� ���ο� ���� ������ ���� �� ������� �׾Ƴ���
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

int pop()									// �ּڰ� (heap[0]) �� ������ֱ�
{
	return heap[0];
}

void reduce()								// ����� �Ŀ� �ʱ�ȭ
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
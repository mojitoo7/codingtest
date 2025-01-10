#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n, top = -1;
	int stack[100000];
	char answer[200000];
	int count = 1, index = 0, answer_index = 0;

	scanf("%d", &n);
	
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n;i++)
		scanf("%d", &arr[i]);

	while (1) {
		if (top == -1 || stack[top] < arr[index])		// ������ �� �� ���ڰ� �Է°����� ���� ��� -> push : '+'
		{
			stack[++top] = count++;
			answer[answer_index++] = '+';
		}

		else if (stack[top] == arr[index])				// ������ �� �� ���ڰ� �Է°��� ���� ��� -> pop : '-'
		{
			top--;
			answer[answer_index++] = '-';
			index++;
		}

		else											// ������ �� �� ���ڰ� �Է°����� ū ��� -> ������ �Ұ����ϹǷ� "NO" ���
		{
			printf("NO");
			return 0;
		}

		if (answer_index == n * 2)
			break;
	}

	for (int i = 0;i < answer_index;i++)
	{
		printf("%c\n", answer[i]);
	}

	return 0;
}
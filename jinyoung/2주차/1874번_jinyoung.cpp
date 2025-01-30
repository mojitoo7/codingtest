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
		if (top == -1 || stack[top] < arr[index])		// 스택의 맨 위 숫자가 입력값보다 낮은 경우 -> push : '+'
		{
			stack[++top] = count++;
			answer[answer_index++] = '+';
		}

		else if (stack[top] == arr[index])				// 스택의 맨 위 숫자가 입력값과 같은 경우 -> pop : '-'
		{
			top--;
			answer[answer_index++] = '-';
			index++;
		}

		else											// 스택의 맨 위 숫자가 입력값보다 큰 경우 -> 수열이 불가능하므로 "NO" 출력
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
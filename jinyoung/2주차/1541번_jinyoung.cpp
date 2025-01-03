#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
{
	int len, sum = 0, answer = 0, temp_1 = 0, temp_2 = 0;
	char num[50];
	
	scanf("%s", num);
	len = strlen(num);

	for (int i = 0;i < len;i++)
	{
		if (num[i] == '-') // '-' 기호 이후로 오는 숫자들은 전부 더해놓기
		{
			for (int j = i; j < len;j++)
			{
				if (num[j] != '+' && num[j] != '-')		// 숫자가 오면 원래있던 숫자를 한 자리씩 높이면서 temp_1에 저장
				{
					temp_1 = temp_1 * 10;				
					temp_1 = temp_1 + num[j] - '0';
				}
				else									// '-'나 '+'가 오면 temp_1을 sum에 더하여 저장
				{
					sum = sum + temp_1;		
					temp_1 = 0;
				}
			}
			break;
		}

		else if (num[i] == '+')							// '+'가 오면 temp_2를 answer에 더하여 저장
		{
			answer = answer + temp_2;
			temp_2 = 0;
		}

		else											// 숫자가 오면 원래있던 숫자를 한 자리씩 높이면서 tem_2에 저장
		{
			temp_2 = temp_2 * 10;
			temp_2 = temp_2 + num[i] - '0';
		}

	}

	answer = answer + temp_2;							// 마지막으로 계산이 덜 된 temp_1과 temp_2를 각각 더해주고
	sum = sum + temp_1;

	answer = answer - sum;								// answer에서 sum을 뺀 값을 출력

	printf("%d", answer);

	return 0;
}

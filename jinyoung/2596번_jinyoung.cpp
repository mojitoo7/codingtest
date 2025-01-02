#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int str, count, error = 0;
	int a = 0;
	char num[10][7];
	char answer[10] = { 0 };
	char sol[8][7] = { {0,0,0,0,0,0}, { 0,0,1,1,1,1 }, { 0,1,0,0,1,1 },	{ 0,1,1,1,0,0 }, { 1,0,0,1,1,0 }, { 1,0,1,0,0,1 }, { 1,1,0,1,0,1 }, { 1,1,1,0,1,0 } };

	scanf("%d", &str);
	for (int i = 0;i < str;i++)
	{
		for (int j = 0;j < 6;j++)
		{
			scanf("%c", &num[i][j]);
		}
	}

	for (int k = 0;k < str;k++)
	{ 
	
		for (int i = 0;i < 8;i++)
		{
			count = 0;
			for (int j = 0;j < 6;j++)
			{
				if (sol[i][j] == num[k][j])
					count++;
			}

			if (count >= 5)
			{
				answer[a] = 'A' + i;
				a++;
				break;
			}
		}
		if (answer[k] == 0)
		{
			error = k + 1;
			break;
		}

	}

	if (error == 0)
		printf("%s", answer);

	else
		printf("%d", error);

	return 0;
}
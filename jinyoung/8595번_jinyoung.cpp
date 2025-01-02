#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int n, count = 0;
	long long int sum = 0, hidden = 0;
	char a[] = { 0 };

	scanf("%d", &n);
	scanf("%s", a);

	for (int i = 0; i < n;i++)
	{
		if ('0' <= a[i] <= '9')
		{
			if (count == 0)
			{
				hidden = a[i];
				count++;
			}
			else if (0 < count && count < 7)
			{
				hidden = 10 * hidden + a[i];
				count++;
			}
			else if (count >= 7)
			{
				sum = 0;
			}
		}
		else
		{
			count = 0;
			sum = sum + hidden;
			hidden = 0;
		}
	}


	printf("%d", sum);

	return 0;
}
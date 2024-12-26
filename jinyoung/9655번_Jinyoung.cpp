#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int n;

	scanf("%d", &n);

	if (((n / 3) + (n % 3)) % 2 == 0)
	{
		printf("CY");
	}
	else
		printf("SK");

	return 0;
}
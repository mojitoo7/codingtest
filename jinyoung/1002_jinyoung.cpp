#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main(void)
{
	int T;
	int x1, x2, y1, y2, r1, r2;
	int answer[] = { 0 };

	scanf("%d", &T);
	for (int i = 0;i < T;i++)
	{
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		double X = x1 - x2;
		double Y = y1 - y2;

		if (x1 == x2 && y1 == y2 && r1 == r2)
			answer[i] = -1;
		else if (x1 == x2 && y1 == y2 && r1 != r2)
			answer[i] = 0;
		else if (sqrt(X * X + Y * Y) == r1 + r2)
			answer[i] = 1;
		else if (sqrt(X * X + Y * Y) > r1 + r2)
			answer[i] = 0;
		else
			answer[i] = 2;
	}

	for (int i = 0;i < T; i++)
	{
		printf("%d \n", answer[i]);
	}

	return 0;
}
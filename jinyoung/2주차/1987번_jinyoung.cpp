#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int	R, C, answer = 0, count = 0;
char board[21][21];

void check(int x, int y, int count, int alp[])
{
	if (x >= 0 && x < R && y >= 0 && y < C && !alp[board[x][y]]) // x,y ��ǥ�� ���� ���� �ְ�, �ѹ� �鷶�� ���ĺ��� �ƴ� ��쿡 �ǽ���.
	{
		alp[board[x][y]]++; // �� ���ĺ��� �� �� �鷶�ٴ� üũ
		count++; // ������ ĭ +1

		if (answer < count) // ��� �߿� ������ ĭ�� ���� ���� ���� ������ ����
			answer = count;

		//�����¿�� ��ĭ�� �̵��ϸ鼭 �˻�
		check(x + 1, y, count, alp);
		check(x, y + 1, count, alp);
		check(x - 1, y, count, alp);
		check(x, y - 1, count, alp);

		//�����¿� ��� �˻翡�� �����Դ� ���ĺ��� �ִ� ��쿡�� 
		alp[board[x][y]]--;
	}
}

int main(void)
{
	int alp[128] = { };

	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0;j < C;j++)
		{
			scanf("%c", &board[i][j]);
		}
	}
	
	check(0, 0, 0, alp);

	printf("%d", answer);	

	return 0;
}
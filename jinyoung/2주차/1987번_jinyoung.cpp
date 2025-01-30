#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int	R, C, answer = 0, count = 0;
char board[21][21];

void check(int x, int y, int count, int alp[])
{
	if (x >= 0 && x < R && y >= 0 && y < C && !alp[board[x][y]]) // x,y 좌표가 범위 내에 있고, 한번 들렀던 알파벳이 아닌 경우에 실시함.
	{
		alp[board[x][y]]++; // 이 알파벳을 한 번 들렀다는 체크
		count++; // 지나온 칸 +1

		if (answer < count) // 경로 중에 지나온 칸이 가장 많은 것을 답으로 지정
			answer = count;

		//상하좌우로 한칸씩 이동하면서 검사
		check(x + 1, y, count, alp);
		check(x, y + 1, count, alp);
		check(x - 1, y, count, alp);
		check(x, y - 1, count, alp);

		//상하좌우 모든 검사에서 지나왔던 알파벳이 있는 경우에는 
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
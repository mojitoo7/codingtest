#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compare(const void* a, const void* b)		// ������ ������ ���� ���Լ�
{
	strcmp((char*)a, (char*)b);
}

struct name {				
	char name[21];
};

struct DB {
	char DB[21];
};

struct name name[];
struct DB DB[];

int main(void)
{
	int N, M, count = 0;

	scanf("%d %d", &N, &M);
	for (int i = 0;i < N + M;i++)
	{
		scanf("%s", name[i].name);
	}

	qsort(name, N + M, sizeof(name[0]), compare);  // �Է¹��� �赵 ���� �̸��� ���� ���� �̸����� ���������� ����

	for (int i = 0; i < N + M; i++)
	{
		if (strcmp(name[i].name, name[i + 1].name) == 0)  // i��°�� i+1��° ���ڿ��� ������ �� 
		{
			strcpy(DB[count].DB, name[i].name); // �� ���ڿ��� ������ �赵 ���� ���� �̸��̹Ƿ� �� �̸��� ���� ���� 
			i++;			// i �� i+1��° ���ڿ��� �����Ƿ� i++
			count++;		// count�� �赵���� ���� �̸��� ����
		}
	}

	printf("%d\n", count);
	for (int i = 0;i < count;i++)
	{
		printf("%s\n", DB[i].DB);
	}


	return 0;
}
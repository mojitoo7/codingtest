#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compare(const void* a, const void* b)		// 사전순 정렬을 위한 비교함수
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

	qsort(name, N + M, sizeof(name[0]), compare);  // 입력받은 듣도 못한 이름과 보도 못한 이름들을 사전순으로 정렬

	for (int i = 0; i < N + M; i++)
	{
		if (strcmp(name[i].name, name[i + 1].name) == 0)  // i번째와 i+1번째 문자열이 같은지 비교 
		{
			strcpy(DB[count].DB, name[i].name); // 두 문자열이 같으면 듣도 보도 못한 이름이므로 이 이름을 따로 복사 
			i++;			// i 와 i+1번째 문자열은 같으므로 i++
			count++;		// count는 듣도보도 못한 이름의 순서
		}
	}

	printf("%d\n", count);
	for (int i = 0;i < count;i++)
	{
		printf("%s\n", DB[i].DB);
	}


	return 0;
}
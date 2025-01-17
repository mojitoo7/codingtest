#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int arr[300][300] = { 0 };
bool visited[300][300] = { false };
int N, M;

void dfs() {  //dfs를 이용해여 진행

	int dx[2] = { 1,0 }; int dy[2] = { 0,1 }; // 갈수 있는 곳은 오른쪽, 아래 밖에 없으므로 좌표 값 설정
	stack<pair<int, int>> bitcoin;  //스택을 이용하여 갈 곳을 저장

	bitcoin.push({ 0,0 }); // 시작 지점 저장
	visited[0][0] = true;

	while (!bitcoin.empty()) { // 스택이 빌때까지 진행
		pair<int, int> next = bitcoin.top(); bitcoin.pop();  // 스택에서 하나 꺼내서 비교 

		for (int i = 0; i < 2; i++) { // 아래쪽, 오른쪽 검색을 위해 2번 진행

			int x = dx[i] + next.first; int y = dy[i] + next.second;

			if (x >= M || y >= N) continue;  // 범위 밖을나가면 넘어감 
			if (visited[x][y] || arr[x][y] == 0) continue; // 이미 갔던 곳이나 0쪽으로 가면 넘어감

			visited[x][y] = true;
			bitcoin.push({ x, y }); //정답 저장

		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			if (num == 1) arr[i][j] = 1;

		}
	}
	dfs();

	if (visited[M - 1][N - 1]) {  // 만약 목표한 지점에 방문한 적이 있으면 Yes 아니면 No 출력
		cout << "Yes";
	}
	else if (!visited[M - 1][N - 1]) {
		cout << "No";
	}

}